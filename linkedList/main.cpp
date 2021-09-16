//
//  main.cpp
//  linkedList
//
//  Created by Swapnil Bhalerao on 14/09/21.
//  clang++ -std=c++14 -stdlib=libc++ main.cpp
//  Question : Intersetion - Determine two Linked list interset and return interset node.

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
    void deleteLinkList();

public:
    LinkedList();
    ~LinkedList();
    void createLinkList();
    void printLL();
    Node *getIntersectionPointer();
    void jointLL(Node *);
    int getLength();
    Node *getHeadPtr() { return head; }
    Node *getTailPtr() { return tail; }
};
LinkedList::LinkedList() : head(nullptr), tail(nullptr)
{
}
LinkedList::~LinkedList()
{
    //    deleteLinkList();
}
int LinkedList::getLength()
{
    Node *p = head;
    int len = 0;
    while (p != nullptr)
    {
        len++;
        p = p->next;
    }
    return len;
}
void LinkedList::jointLL(Node *p)
{
    tail->next = p;
}
Node *LinkedList::getIntersectionPointer()
{
    return head->next->next->next;
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
            //            cout << "deleting node: " << temp1->data << "\n";
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

bool findIntersecion(LinkedList &L1, LinkedList &L2)
{
    int len1 = L1.getLength();
    int len2 = L2.getLength();
    Node *p1 = L1.getHeadPtr();
    Node *p2 = L2.getHeadPtr();
    if (p1 == nullptr || p2 == nullptr)
    {
        return false;
    }
    // 1->2->3->4->5->6 L1=6
    //10->20->4->5->6   L2=5
    // L1-L2 = 1
    // move L1 by 1 step and then start compare.
    if (len1 > len2)
    {
        int diff = len1 - len2;
        while (diff > 0)
        {
            diff--;
            p1 = p1->next;
        }
    }
    else if (len2 > len1)
    {
        int diff = len2 - len1;
        while (diff > 0)
        {
            diff--;
            p2 = p2->next;
        }
    }
    else
    {
        if (L1.getTailPtr() == L2.getTailPtr())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1 == p2)
        {
            return true;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return false;
}
int main(int argc, const char *argv[])
{
    // insert code here...
    LinkedList L1;
    L1.createLinkList();
    L1.printLL();

    LinkedList L2;
    L2.createLinkList();
    L2.printLL();

    L2.jointLL(L1.getIntersectionPointer());
    L2.printLL();

    if (findIntersecion(L1, L2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
