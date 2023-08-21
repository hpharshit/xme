#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
int summing(Node *p)
{
      if (p!=0)
      {
      return p->data+summing(p->next);
      }
      else if(p==0)
       return 0;
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
    int sum = 0;
    // while (it!=0)
    // {
    //     sum+=it->data;
    //     it=it->next;
    // }

    //through recursion
    sum=summing(first);
    cout << "Sum: " << sum;
    return 0;
}
