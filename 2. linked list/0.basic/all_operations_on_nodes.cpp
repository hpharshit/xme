/*
                   head -> node1 -> node2 -> node3
position of
node                         1        2        3                  ####

while inserting
position                 0        1       2          3
*/
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
} *head = NULL, *last = 0, *second_linked_list_head=0;

void create_node(int *ptr, int size)
{
    head = new node;
    last = head;
    head->data = ptr[0];
    head->next = 0;
    node *t = 0;
    for (int i = 1; i < size; i++)
    {
        t = new node;
        t->data = ptr[i];
        last->next = t;
        last = t;
        t->next = 0;
        t = 0;
    }
};

void insert(node *p, int element, int position)
{
    if (head == 0) //if all nodes are deleted the if we want to insert
    {
        node *i1 = new node;
        i1->data = element;
        i1->next = 0;
        head = i1;
        i1 = 0;
    }
    else if (head != 0) //if atleast 1 node is present
    {
        node *i = new node;
        i->data = element;

        if (position == 0)
        {
            i->next = head;
            // or i->next = p;
            head = i;
            i = 0;
        }
        else if (position > 0) //inserting after "position" ####
        {
            for (int j = 0; j < position - 1 && p != 0; j++)
            {
                // for moving pointer to n-1 position (position after which insertion is to be done)
                p = p->next;
            }
            // if (p!=0)    or
            if (p)
            {
                i->next = p->next;
                p->next = i;
                i = 0;
            }
        }
    }
}

void display(node *p)
{
    if (head == 0)
    {
        cout << "No Node Present \n";
    }
    else
    {
        while (p != 0)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}

void insert_last(node *p, int element)
{

    while (p->next != 0)
    {
        p = p->next;
    }
    node *t = new node;
    t->data = element;
    p->next = t;
    t->next = 0;
    t = 0;
}

int delete_node(node *p, int index)
{
    node *q = 0;
    q = p->next;
    if (p == 0)
    {
        cout << "No node present \n";
        return 0;
    }
    //   moving q to delete node and p to its previous node
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = p->next;
    }
    if (p->next == 0 && index > 1)
    {
        cout << "Invalid Index \n";
        return 0;
    }

    //    if we have to delete first node
    if (index == 1)
    {
        head = p->next;
        p->next = 0;
        delete p;
    }
    else
    {
        p->next = q->next;
        q->next = 0;
        delete q;
    }
    p = head;
    return 0;
}

void sort(node *p)
{
    // selection sort
    node *q = p->next;
    while (p->next != 0)
    {
        while (q != 0)
        {
            if (p->data > q->data)
            {
                int *temp = new int();
                *temp = p->data;
                p->data = q->data;
                q->data = *temp;
                free(p);
            }
            q = q->next;
        }
        p = p->next;
        q = p->next;
    }
}

void insertINsorted(node *p, int element)
{
    node *in = new node;
    in->data = element;
    in->next = NULL;

    node *q = NULL;
    if (head== NULL)
    {
        head= in;
    }
    else //means elements are present already
    {
        while (p != NULL && p->data < element)
        {
            q = p;
            p = p->next;
        }
        if (p == head)
        {
            in->next = p;
            head = in;
        }
        else
        {
            in->next = q->next;
            q->next=in;
        }
    }
}

int check_sortion(node *p)
{

    node *q = NULL;
    q = p;
    p = p->next;

    if (q->data > p->data)
    {
        while (p != NULL)
        {
            if (q->data < p->data)
            {
                return false;
            }
            q = p;
            p = p->next;
        }
        cout<<"Descending order\n";
    }
    else if (q->data < p->data)
    {
        while (p != NULL)
        {
            if (q->data > p->data)
            {
                return false;
            }
            q = p;
            p = p->next;
        }
        cout<<"Ascending order\n";
    }
   return true;
};

void concatenate(node *p, node *q)
{
    while (p->next != 0)
    {
        p = p->next;
    }
    p->next = q;
    second_linked_list_head = NULL;
}

void reversinglinks(node *p)
{
    node *r = NULL,*q = NULL;
    while (p != 0)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r; //changing link
    }
    head = q;
}
void recursivereversinglinks(node *r, node *p)
{
    if (p != 0)
    {
        recursivereversinglinks(p, p->next);
        p->next = r; //on returning time changing link
    }
    else
    {
        head = r;
    }
}

int main()
{
    // creating
    int size;
    cout << "Enter the size of linked list : ";
    cin >> size;

    int *ptr = new int[size];
    if (size == 0)
    {
        cout << "No Node can be created using size=0 \n";
    }
    else
    {
        cout << "Enter values in nodes: ";
        for (int i = 0; i < size; i++)
        {
            cin >> ptr[i];
        }
        create_node(ptr, size);

        //  INSERTING:
        /*
    cout << "No. of elements to insert : ";
    int n;
    cin >> n;

    int element[n], position[n];
    cout << "Elements to insert: ";
    for (int i = 0; i < n; i++)
    {
        cin >> element[i];
    }

    cout << "Position after which we want to insert: ";
    for (int i = 0; i < n; i++)
    {
        cin >> position[i];
    }
    for (int i = 0; i < n; i++)
    {
        insert(head, element[i], position[i]);
    }
    */

        //    for inserting at last
        /*
    int m;
    cout << "No. of elements to insert at last: ";
    cin >> m;
    int laste[m];
    cout << "Elements to insert at last: ";
    for (int i = 0; i < n; i++)
    {
        cin >> laste[i];
    }
    for (int i = 0; i < n; i++)
    {
        insert_last(head, laste[i]);
    }
    */
        node *it = head;
        int del;
        cout << "Enter the node to delete: ";
        cin >> del;
        delete_node(it, del);
        it = head;
        display(it);
        it = head;

        /*selection sort

        sort(head);
    cout<<"\nDisplaying: ";
    while (it!=0)
    {
        cout<<it->data<<" ";
        it=it->next;
    }
    it=head;
        */
    }
    return 0;
}
