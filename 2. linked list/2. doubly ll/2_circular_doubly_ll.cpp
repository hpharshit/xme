#include <iostream>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;

} *head = 0, *last = 0;

void create_doubly_circular_ll(int *p, int size)
{
    node *t = 0;
    head = new node;
    head->data = p[0];
    head->next = head;
    head->prev = 0;
    last = head;
    for (int i = 1; i < size; i++)
    {
        t = new node;
        t->data = p[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
        t = 0;
    }
}




void display(node *it)
{
    cout << "displaying: ";
    while (it != 0)
    {
        cout << it->data << " ";
        it = it->next;
    }
}

int main()
{
    int n;
    cout << "no. of elements in doubly linked list: ";
    cin >> n;
    int *ptr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ptr[i];
    }
    create_doubly_circular_ll(ptr, n);
    free(ptr);
    node *it = head;
    it = head;
    display(it);

    return 0;
}