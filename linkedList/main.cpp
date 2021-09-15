//
//  main.cpp
//  linkedList
//
//  Created by Swapnil Bhalerao on 14/09/21.
//clang++ -std=c++14 -stdlib=libc++ main.cpp
// Question : Create and Delete LinkedList
#include <iostream>
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
};
LinkedList::LinkedList() : head(nullptr), tail(nullptr)
{
}
LinkedList::~LinkedList()
{
    deleteLinkList();
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

    cout << "\nLinked List => ";
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
    list.deleteLinkList();
    return 0;
}
