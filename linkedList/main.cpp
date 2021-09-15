//
//  main.cpp
//  linkedList
//
//  Created by Swapnil Bhalerao on 14/09/21.
//  clang++ -std=c++14 -stdlib=libc++ main.cpp
//  Question : Sum List
//  i/p: (6->1->7) + (2->9->5) that is, 617+295 = 912
//  o/p: 9->1->2
#include <iostream>
#include <vector>
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
    void deleteLinkList();
    void printLL();
    void createLinkList(int);
    void AppendNode(int);
    void sumList(Node *, Node *);
    void copyLinkedList(Node *);
    Node *getHeadPtr() { return head; }
};
LinkedList::LinkedList() : head(nullptr), tail(nullptr)
{
}
LinkedList::~LinkedList()
{
    deleteLinkList();
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
void LinkedList::copyLinkedList(Node *p)
{
    if (nullptr != p)
    {
        while (p != nullptr)
        {
            AppendNode(p->data);
            p = p->next;
        }
    }
    else
    {
        cout << "NULL pointer head" << endl;
    }
}
void LinkedList::sumList(Node *p1, Node *p2)
{
    if (p1 == nullptr && p2 == nullptr)
    {
        cout << "Invalid Lisked Lists" << endl;
    }
    else if (p1 == nullptr)
    {
        copyLinkedList(p2);
        cout << "same as p2 Linked List" << endl;
    }
    else if (p2 == nullptr)
    {
        copyLinkedList(p1);
        cout << "same as p1 Linked List" << endl;
    }
    else
    {
        int carry = 0;
        int val = 0;
        while (p1 != nullptr || p2 != nullptr)
        {
            if (p1 != nullptr && p2 != nullptr)
            {
                val = p1->data + p2->data + carry;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1 != nullptr)
            {
                val = p1->data + carry;
                p1 = p1->next;
            }
            else
            {
                val = p2->data + carry;
                p2 = p2->next;
            }
            carry = val / 10;
            val = val % 10;
            AppendNode(val);
        }
        if (carry)
        {
            AppendNode(carry);
        }
    }
}
void LinkedList::AppendNode(int num)
{
    if (head == nullptr)
    {
        head = new Node(num);
        tail = head;
        return;
    }
    else
    {
        Node *p = new Node(num);
        tail->next = p;
        tail = tail->next;
    }
}
void LinkedList::createLinkList(int num)
{
    std::vector<int> vec;
    while (num != 0)
    {
        int data = num % 10;
        num = num / 10;
        vec.push_back(data);
    }
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        AppendNode(vec[i]);
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
            // cout << "deleting node: " << temp1->data << "\n";
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
    LinkedList L1;
    cout << "Enter 1st number" << endl;
    int num = 0;
    cin >> num;
    L1.createLinkList(num);
    L1.printLL();

    LinkedList L2;
    cout << "Enter 2st number" << endl;
    cin >> num;
    L2.createLinkList(num);
    L2.printLL();

    LinkedList L3;
    L3.sumList(L1.getHeadPtr(), L2.getHeadPtr());
    cout << "\n\n";
    L3.printLL();
    return 0;
}
