#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *recursion(Node *p, int key)
{
    if (p->data == key)
    {
        return p;
    }
    else if (p == NULL)
    {
        return NULL;
    }
    return recursion(p->next, key);
}
Node *linear(Node *p, int key)
{
    while (p != NULL)
    {

        if (p->data == key)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    if (p == NULL)
    {
        return NULL;
    }
}

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
    int key;
    cout << "Elememt to search : ";
    cin >> key;
    // 1. linear                  //binary search is not possible
    
    Node *index = recursion(first, key);
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
