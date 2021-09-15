//
//  main.cpp
//  linkedList
//
//  Created by Swapnil Bhalerao on 14/09/21.
//  clang++ -std=c++14 -stdlib=libc++ main.cpp
//  Question : Return Kth to last element
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
    Node *ReturnKthElement(int);
};
LinkedList::LinkedList() : head(nullptr), tail(nullptr)
{
}
LinkedList::~LinkedList()
{
    deleteLinkList();
}
Node *LinkedList::ReturnKthElement(int pos)
{
    int len = 0;
    Node *p = head;
    while (p != nullptr)
    {
        len++;
        p = p->next;
    }
    if (pos > len)
    {
        cout << "Invalid position - returned head pointer" << endl;
        return head;
    }
    p = head;
    for (int i = 0; i < len - pos; i++)
    {
        p = p->next;
    }
    return p;
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
    cout << "Enter Kth element\n";
    int pos = 0;
    cin >> pos;
    cout << pos << "th Element => ";
    Node *ret = list.ReturnKthElement(pos);
    if (ret != nullptr)
    {
        cout << ret->data << endl;
    }
    else
    {
        cout << "WARNING - NULL POINTER" << endl;
    }
    list.deleteLinkList();
    return 0;
}
