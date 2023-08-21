#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *head = 0, *last = 0;

void create_circular_ll(int *ptr, int size)
{
    head = new node;
    head->data = ptr[0];
    head->next = head;
    last = head;
    node *t = 0;
    for (int i = 1; i < size; i++)
    {
        t = new node;
        t->data = ptr[i];
        t->next = last->next;
        last->next = t;
        last = t;
        t=0;
    }
};
void display_circular(node *p)
{
    do
    {
        cout << p->data;
        p = p->next;
    } while (p != head);
}
int main()
{
    // creating
    int size;
    cout << "Enter the size of linked list : ";
    cin >> size;

    int *ptr = new int[size];
    cout << "Enter values in nodes: ";
    for (int i = 0; i < size; i++)
    {
        cin >> ptr[i];
    }
    create_circular_ll(ptr, size);
    delete[] ptr;
    display_circular(head);
    return 0;
}