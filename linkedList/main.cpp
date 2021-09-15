//
//  main.cpp
//  linkedList
//
//  Created by Swapnil Bhalerao on 14/09/21.
//  clang++ -std=c++14 -stdlib=libc++ main.cpp
//  Question : Palindrome - Write function to check linked list is palindrome or not.

#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node() : data(100), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList();
    ~LinkedList();
    void createLinkList();
    void deleteLinkList();
    void printLL();
    bool checkPalindrome();
};
LinkedList::LinkedList() : head(nullptr), tail(nullptr)
{
}
LinkedList::~LinkedList()
{
    deleteLinkList();
}
bool LinkedList::checkPalindrome()
{
    // 1-2-3-3-2-1 ==> fast = null EVEN
    //s=1,f=1 st=1 |    s=2 f=3 st= 2,1    |    s=3 f=2 st=3 2 1    |    s=3 f=null break loop
    // 1-2-3-4-3-2-1 ==> fast->next=null ODD
    // s=1,f=1 st=1==> s=2,f=3 st=2 1 ==> s=3,f=3 st= 3 2 1 ==> s=4,f=1 st=f->next=null break loop
    std::stack<int> st;
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != nullptr && fast->next == nullptr)
    {
        slow = slow->next;
    }
    while (!st.empty())
    {
        if (st.top() != slow->data)
        {
            return false;
        }
        st.pop();
        slow = slow->next;
    }
    return true;
}
void LinkedList::printLL()
{
    Node *p = head;
    cout << "Linked List => ";
    while (p != nullptr)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}
void LinkedList::createLinkList()
{
    int num = 0;
    cout << "Enter Linked List length\n";
    cin >> num;
    int val = 0;
    cout << "Enter data\n";
    cin >> val;
    head = new Node(val);
    tail = head;
    for (int i = 0; i < num - 1; i++)
    {
        cout << "Enter data\n";
        cin >> val;
        Node *temp = new Node(val);
        tail->next = temp;
        tail = temp;
    }
}
void LinkedList::deleteLinkList()
{
    if (head != nullptr)
    {
        Node *temp1 = head;
        Node *temp2 = head->next;
        while (temp1 != nullptr)
        {
            cout << "deleting node: " << temp1->data << "\n";
            delete temp1;
            temp1 = temp2;
            if (temp2 != nullptr)
            {
                temp2 = temp2->next;
            }
        }
        head = nullptr;
    }
}

int main(int argc, const char *argv[])
{
    // insert code here...
    LinkedList list;
    list.createLinkList();
    list.printLL();
    if (list.checkPalindrome())
    {
        cout << "Linked list is Palindrome" << endl;
    }
    else
    {
        cout << "Linked list is Not Palindrome" << endl;
    }
    return 0;
}