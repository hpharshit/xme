#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *linear(Node *p, int key)
{

    Node *first = p;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        { 
            // move to head
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    if (p == NULL)
    {
        return NULL;
    }
};
int main()
{
    Node *first, *last = 0, *t = 0, *it;
    first = new Node;
    it = first; //just to print values //iterator
    cout << "1st Node: ";
    cin >> first->data;
    first->next = 0;
    last = first;
    int element;
    cout << "other nodes: ";
    for (int i = 1; i < 5; i++)
    {
        t = new Node;
        cin >> element;
        t->data = element;
        t->next = 0;
        last->next = t;
        last = t;
        t = NULL;
    }
    // 1. linear                  //binary search is not possible
    int key;
    cout << "Elememt to search : ";
    cin >> key;
    Node *index = linear(first, key);
    if (index == NULL)
    {
        cout << "Not found";
    }
    else if (index != 0)
    {
        cout << "found";
    }

    return 0;
}
