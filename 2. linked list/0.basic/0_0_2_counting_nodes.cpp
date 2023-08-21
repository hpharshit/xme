#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
int nodecount(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return 1 + nodecount(p->next);
}

int main()
{
    Node *first, *last = 0, *t = 0, *it;
    first = new Node;
    it = first;
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
    int count = 0;
    // 1.
    // while (it != 0)
    // {
    //     count++;
    //     it=it->next;
    // }

    // 2. counting node recursevily
    count = nodecount(it);
    cout << "No. of nodes: " << count;

    return 0;
}
