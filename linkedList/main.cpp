//
//  main.cpp
//  linkedList
//
//  Created by Swapnil Bhalerao on 14/09/21.
//  clang++ -std=c++14 -stdlib=libc++ main.cpp
//  Question : Remove duplicate from unsored Linked List
#include <iostream>
#include <unordered_set>
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
    void removeDuplicate();
};
LinkedList::LinkedList() : head(nullptr), tail(nullptr)
{
}
LinkedList::~LinkedList()
{
    deleteLinkList();
}
void LinkedList::removeDuplicate()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    std::unordered_set<int> s;
    Node *fast = head;
    Node *pre = head;
    s.insert(fast->data);
    fast = fast->next;
    while (fast != nullptr)
    {
        std::unordered_set<int>::iterator it = s.find(fast->data);
        if (it == s.end()) // element not found
        {
            s.insert(fast->data);
            fast = fast->next;
            pre = pre->next;
        }
        else
        {
            Node *temp = fast->next;
            pre->next = temp;
            fast->next = nullptr;
            delete fast;
            fast = temp;
        }
    }
}
void LinkedList::printLL()
{
    Node *p = head;
    cout << "\nLinked List => ";
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void LinkedList::createLinkList()
{
    cout << "Creating LinkedList with 5 nodes\n";
    int val = 0;
    cout << "Enter data\n";
    cin >> val;
    head = new Node(val);
    tail = head;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter data\n";
        cin >> val;
        Node *temp = new Node(val);
        tail->next = temp;
        tail = temp;
    }

    Node *p = head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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
    else
    {
        cout << "Empty LinkList\n";
    }
}

int main(int argc, const char *argv[])
{
    // insert code here...
    LinkedList list;
    list.createLinkList();
    list.printLL();
    list.removeDuplicate();
    list.printLL();
    list.deleteLinkList();
    return 0;
}
