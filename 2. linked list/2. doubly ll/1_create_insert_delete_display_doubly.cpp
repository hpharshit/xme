#include <iostream>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;

} *head = 0, *last = 0;

void create_doubly_ll(int *p, int size)
{
    node *t = 0;
    head = new node;
    head->data = p[0];
    head->next = 0;
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
        // t = 0;
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

void insert(int index, int value)
{
    node *t = new node;
    t->data = value;
    t->next = 0;
    t->prev = 0;
    last = head;
    if (index == 0) //before head node
    {
        t->next = head;
        head->prev = t;
        head = t;
    }
    else if (index > 0)
    {
        node *p = head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        node *q = new node;
        q->data = value;
        q->next = p->next;
        p->next = q;
        q->prev = p;
        if (p->next != 0) //checking if previous nde is not null
        {
            (p->next)->prev = q;
        }
        q = 0;
        p = 0;
    }
    else if (index < 0)
    {
        cout << "Invalid input of index";
        exit(0);
    }
}

int delete_node(int node_index)
{
    node *p = head;
    node *q = p->next;
    if (head == 0)
    {
        cout << "Null Linked list";
        return 0;
    }
    for (int i = 0; i < node_index - 2 && p->next != 0; i++) //moving p to just before node and q to that node which is to be deleted
    {
        p = p->next;
        q = p->next;
    }

    if (node_index == 1)
    {
        p->next = 0;
        delete p;
        if (q != 0)
        {
            q->prev = 0;
            head = q; //now head is pointing on second node and 1st node is deleted
        }
    }
    else if (node_index > 1)
    {
        p->next = q->next;
        if (q->prev != 0)
        {
            q->prev = p;
            delete q;
        }
    }
    else
    {
        cout << "Invalid index input \n";
    }
    return 0;
}

void reverse_linked_list(node *it)
{
    while (it != 0)
    {
        node *temp; //swaping next and prev
        temp = it->next;
        it->next = it->prev;
        // temp->prev=it->prev;
        it->prev = temp;
        it = it->prev; //moves forward as next and prev are swaped above
        if (it != 0 && it->next == 0)
        {
            head = it;
        }
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
    create_doubly_ll(ptr, n);
    free(ptr);
    node *it = head;
    // insert(2,45);  //means after 2nd index
    // delete_node(1);
    reverse_linked_list(it);
    it = head;
    display(it);

    return 0;
}

/*
struct Node* reverseList(struct Node *head)
    {
        struct Node *r = NULL,*q = NULL;
       while (head != 0)
       {
        r = q;
        q = head;
        head = head->next;
        q->next = r; //changing link
      }
     head = q;
    }

*/

