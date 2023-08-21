#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
int maxelement(Node *p)
{
    if (p==0)
    {
        return INT_MIN;
    }
    
    int x=maxelement(p->next);
    return (x>p->data)? x:p->data;    
    
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
    // 1.
    // int counter = INT_MIN;
    // while (it != 0)
    // {
    //     if (counter < it->data)
    //     {
    //         counter = it->data;
    //         it = it->next;
    //     }
    //     else
    //     {
    //         it = it->next;
    //     }
    // }
    // 2. recursive
    int max=maxelement(first);
    cout<<"max: "<<max;
    return 0;
}
