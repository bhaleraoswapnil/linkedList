//
//  main.cpp
//  linkedList
//
//  Created by Swapnil Bhalerao on 14/09/21.
//  clang++ -std=c++14 -stdlib=libc++ main.cpp
//  Question : Loop Detection - Return loop in node form Linked List.
//  i/p : A -> B -> C -> D -> E -> C
//  o/p : C

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    bool flag;
    Node() : data(100), next(nullptr), flag(false) {}
    Node(int d) : data(d), next(nullptr), flag(false) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();
    void createLinkList();
    void printLL();
    void detectLoop();
};
LinkedList::LinkedList() : head(nullptr)
{
}
LinkedList::~LinkedList()
{
}
void LinkedList::detectLoop()
{
    Node *ptr = head;

    while (ptr != nullptr)
    {
        if (true == ptr->flag)
        {
            cout << "Loop Detected at " << ptr->data << endl;
            return;
        }
        ptr->flag = true;
        ptr = ptr->next;
    }
    cout << "Loop Not Detected" << endl;
}
void LinkedList::printLL()
{
    Node *p = head;
    cout << "Linked List => ";
    int br = 0;
    while (p != nullptr)
    {
        cout << p->data << " -> ";
        p = p->next;
        br++;
        if (br > 10)
        {
            break;
        }
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
    Node *t = head;
    Node *corrupt = nullptr;
    for (int i = 0; i < num - 1; i++)
    {
        cout << "Enter data\n";
        cin >> val;
        Node *temp = new Node(val);
        if (i == 2)
        {
            corrupt = temp;
        }
        t->next = temp;
        t = temp;
    }
    t->next = corrupt;
}

int main(int argc, const char *argv[])
{
    // insert code here...
    LinkedList list;
    list.createLinkList();
    list.printLL();
    list.detectLoop();

    return 0;
}
