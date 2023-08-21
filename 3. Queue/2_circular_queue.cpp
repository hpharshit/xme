/*                                                  TREE:
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *lchild;
    node *rchild;
    node(int x)
    {
        data = x;
        lchild = rchild = 0;
    };
};

class tree
{
    node *root;

public:
    tree()
    {
        root = 0;
    }

    node *getroot() { return root; }

    void create()
    {
        cout << endl;
        queue<node *> q;
        int x;
        cout << "Enter the data for the root: ";
        cin >> x;
        root = new node(x);
        q.push(root);
        node *p;
        node *it;
        while (!q.empty())
        {
            p = q.front();
            q.pop();

            cout << endl
                 << "Enter the lchild of " << p->data << " : ";
            cin >> x;
            if (x != -1)
            {
                it = new node(x);
                p->lchild = it;
                q.push(it);
            }

            cout << endl
                 << "Enter the rchild of " << p->data << " : ";
            cin >> x;
            if (x != -1)
            {
                it = new node(x);
                p->rchild = it;
                q.push(it);
            }
        }
    }

    void preorder(node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }

    void inorder(node *p)
    {
        if (p)
        {
            inorder(p->lchild);
            cout << p->data << " ";
            inorder(p->rchild);
        }
    }

    void postorder(node *p)
    {
        if (p)
        {
            postorder(p->lchild);
            postorder(p->rchild);
            cout << p->data << " ";
        }
    }

    bool search(node *node, int key)
    {
        if (node == NULL)
            return false;

        if (node->data == key)
            return true;

        bool res1 = search(node->lchild, key);
        // node found, no need to look further
        if (res1)
            return true;

        bool res2 = search(node->rchild, key);

        return res2;
    }

    void levelorder(node *p)
    {
        queue<node*> q;
        cout << p->data << " ";
        q.push(p);

        while (!q.empty())
        {
            p = q.front();;
            q.pop();
            if (p->lchild)
            {
                cout << (p->lchild)->data << " ";
                q.push(p->lchild);
            }
            if (p->rchild)
            {
                cout << p->rchild->data << " ";
                q.push(p->rchild);
            }
        }
    }

};
int main()
{

    tree t;
    t.create();
    t.preorder(t.getroot());
    cout << endl;
    t.inorder(t.getroot());
    cout << endl;
    t.postorder(t.getroot());
    cout << endl;
    t.levelorder(t.getroot());
    cout << endl;

    bool a = t.search(t.getroot(), 49);
    if (a)
        cout << "\nfound";
    else
        cout << "\nnot found";
    return 0;
}
*/

/*                                                   BST:
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* lchild;
    node* rchild;
    node (int x)
    {
        data=x;
        lchild=rchild=0;
    }
};

class bst
{
    node* root;
    public:
    bst()
    {
        root=0;
    }

    node* getroot()
    {
        return root;
    }

    void insert()
    {
        int key;
        cout<<"\nenter value to insert: ";
        cin>>key;
         node* p=root;

         if(!p)
         {
              node*t= new node(key);
              root=t;
              return;
         }

        node* r;
         while(p)
         {
             r=p;
             if(p->data==key)
               return;
             else if(p->data > key)
               p=p->lchild;
             else if(p->data < key)
               p=p->rchild;
         }
         node*t=new node(key);
         if(key <r->data)
             r->lchild=t;
         else if(key> r->data)
             r->rchild=t;
         else if( key== r->data)
          return;
    }

    bool search(int key)
    {

        node* p=root;
        while(p)
        {
            if(p->data==key)
              return 1;
            else if(p->data > key)
              p=p->lchild;
            else if(p->data < key)
              p=p->rchild;
        }
        return 0;
    }

    void preorder(node* p)
    {
        if(p)
        {
            cout<<p->data<<" ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }

    void inorder(node* p)
    {
        if(p)
        {
            inorder(p->lchild);
            cout<<p->data<<" ";
            inorder(p->rchild);
        }
    }

    void postorder(node* p)
    {
        if(p)
        {
            postorder(p->lchild);
            postorder(p->rchild);
            cout<<p->data<<" ";
        }
    }

};

int main()
{
    bst t;
    t.insert();
    t.insert();
    t.insert();
    t.insert();
    t.insert();

    cout<<endl;
    t.preorder(t.getroot());
    cout<<endl;
    t.inorder(t.getroot());
    cout<<endl;
    t.postorder(t.getroot());
    cout<<endl;

    bool a=t.search(54);

     if(a)
       cout<<"\nfound";
    else
       cout<<"\nnot found";



    return 0;
}
*/

/*                                                   Hash:
#include <iostream>
using namespace std;

class MyHash
{
    int size;
    int *ht;

public:
    MyHash()
    {
        cout << "\nEnter the size of hash table: ";
        cin >> size;

        ht = new int[size];
        for (int i = 0; i < size; i++)
        {
            ht[i] = -1;
        }
    }

    int hash_function(int x, int i)
    {
        return (x % size + i) % size;
    }

    void insert(int x)
    {
        int i = 0;
        int index = hash_function(x, i);
        if (ht[index] == -1)
        {
            ht[index] = x;
            return;
        }
        index = hash_function(x, i++);
        while (ht[index] != -1 && ht[index] != hash_function(x, 0))
        {
            index = hash_function(x, i++);
        }
        if (ht[index] == hash_function(x, 0))
            cout << "\nHash Table is Full!!!\n";
        else
            ht[index] = x;
    }

    void display_hash_table()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            cout << ht[i] <<"\t";
            count++;
            if (count == 10)
            {
                cout << endl;
                count = 0;
            }
        }
    }

    void display_value_with_index()
    {
        for (int i = 0; i < size; i++)
        {
            if (ht[i] != -1)
            {
                cout <<"| "<<i<<"\t "<<ht[i] <<" |"<< endl;
            }
        }
    }

    bool search(int key)
    {
        for (int i = 0; i < size; i++)
        {
            if (ht[i] == key)
                return true;
        }
        return false;
    }
};

int main()
{
cout<<"\n____________________________________________________________________________________\n";

    MyHash h;

    h.insert(1234);
    h.insert(2548);
    h.insert(3476);
    h.insert(3448);

    cout << endl;
    cout<<" \t\t\tHASH TABLE ( 10 x 10 )\n\n";
    h.display_hash_table();
    cout << endl;
    cout<<" INDEX\tVALUE \n";
    h.display_value_with_index();
    cout << endl;

    cout<<endl<<"Enter the value to search: ";
    int x;
    cin>>x;
    bool a = h.search(x);
    if (a)
        cout << "\tFOUND : "<<x<<endl;
    else
        cout << "\tNOT FOUND : "<<x<<endl;
cout<<"\n____________________________________________________________________________________\n";

    return 0;
}

*/

/*                                           INSERTION / SELECTION:
void insertion_sort(int arr[], int n)
{


    int j, x;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        x = arr[i];
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

void selection_sort(int arr[], int n)
{

    for (int j = 0; j < n - 1; j++) // taking n-1 passes as the element will ne automatically sorted
    {
        int min = j;                    // considering first index having the smallest element
        for (int i = j + 1; i < n; i++) // this loop is just to get the smallest index
        {
            if (arr[min] > arr[i])
            {
                min = i;
            }
        }
        if (arr[j] != arr[min]) // if we got another smaller number then min the swap the values at that index
        {
            swap(arr + j, arr + min);
        }
    }
}
*/

/*                                                POLYNOMIAL:
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int coeff;
    int pow;
    node *next;
    node()
    {
        next = 0;
    };
    node(int a, int b)
    {
        coeff = a;
        pow = b;
        next = 0;
    }
};

void sort_ll(node *l)
{
    node *i;
    while (l->next)
    {
        i = l->next;
        while (i)
        {
            if (l->pow < i->pow)
            {
                int temp1, temp2;
                temp1 = i->pow;
                i->pow = l->pow;
                l->pow = temp1;

                temp2 = i->coeff;
                i->coeff = l->coeff;
                l->coeff = temp2;
            }
            i = i->next;
        }
        l = l->next;
    }
}

node *create(int c, int po, node **p)
{
    node *r;
    if (*p == 0)
    {
        r = new node(c, po);
        *p = r;
        return *p;
    }
    r = *p;
    while (r->next)
    {
        r = r->next;
    }
    r->next = new node(c, po);
    return *p;
};

void add(node *a, node *b, node *p)
{
    // node* head=p;
    while (a && b)
    {
        if (a->pow > b->pow)
        {
            p->coeff = a->coeff;
            p->pow = a->pow;
            a = a->next;
        }
        else if (a->pow < b->pow)
        {
            p->coeff = b->coeff;
            p->pow = b->pow;
            b = b->next;
        }
        else if (a->pow == b->pow)
        {
            p->coeff = (a->coeff) + (b->coeff);
            p->pow = a->pow;
            a = a->next;
            b = b->next;
        }
        if (a && b)
        {
            p->next = new node;
            p = p->next;
        }
    }

    while (a || b)
    {
        if (a)
        {
            p->next = new node(a->coeff,a->pow);
            p = p->next;
            a = a->next;
        }
        if (b)
        {
            p->next = new node(b->coeff,b->pow);
            p = p->next;
            b = b->next;
        }
    }
    // return head;
};

void display(node *p)
{
    while (p)
    {
        cout << p->coeff << "x^(" << p->pow << ") ";
        if (p->next && p->next->coeff > 0)
            cout << "+";
        p = p->next;
    }
};

int eval(node *p, int x)
{
    int sum=0;
    while(p)
    {
        sum=sum+(p->coeff * pow(x,p->pow));
        p=p->next;
    }
    return sum;
}

int main()
{
    int n1, n2;
    static int a = 1;
    int n;
    cout<<"________________________________________________________\n";
    cout << "\nEnter the no. of terms in f(x) : ";
    cin >> n;

    node *poly1 = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "coeff & power of term no. " << a << " : ";
        cin >> n1 >> n2;
        poly1 = create(n1, n2, &poly1);
        a++;
    }
    cout << "\nf(x) = ";
    sort_ll(poly1);
    display(poly1);
    cout << endl;
    cout<<"________________________________________________________\n";




    a = 1;
    cout << "\nEnter the no. of terms in g(x) : ";
    cin >> n;
    node *poly2 = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "coeff & power of term no. " << a << " : ";
        cin >> n1 >> n2;
        poly2 = create(n1, n2, &poly2);
        a++;
    }
    cout << "\ng(x) = ";
    sort_ll(poly2);
    display(poly2);
    cout<<endl;
    cout<<"________________________________________________________\n";



    cout << endl
         << "ADDDING f(x) and g(x) \n";
    node *poly = 0;
    poly = new node;
    poly->next = 0;
    add(poly1, poly2, poly);
    cout << "\np(x) = f(x) + g(x) : ";
    sort_ll(poly);
    display(poly);
    cout<<endl;

    cout<<"_____________________________________________________________";
    cout<<"\n\nEnter the value of 'x' : ";
    int x;
    cin>>x;
    cout<<"p(x) = "<<eval(poly, x);
    cout<<"\n_____________________________________________________________";

    return 0;
}

*/

/*                                              INFIX TO POSTFIX:
#include <iostream>
#include <stack>
using namespace std;

int priority(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return -1;
}

string convert(string infix)
{
    string postfix = "";
    stack<char> st;
    int i = 0;
    while (infix[i] != '\0')
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix = postfix + infix[i];
        }
        else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            if (infix[i] == ')')
            {
                while (st.top() != '(')
                {
                    postfix = postfix + st.top();
                    st.pop();
                }
                st.pop();
            }
            if (infix[i] == '}')
            {
                while (st.top() != '{')
                {
                    postfix = postfix + st.top();
                    st.pop();
                }
                st.pop();
            }
            if (infix[i] == ']')
            {
                while (st.top() != '[')
                {
                    postfix = postfix + st.top();
                    st.pop();
                }
                st.pop();
            }
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            if (!st.empty())
            {
                while (priority(st.top()) >= priority(infix[i]))
                {
                    postfix = postfix + st.top();
                    st.pop();
                    if (st.empty())
                        break;
                }
            }
            st.push(infix[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        postfix = postfix + st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string i;
    cout << "Enter an infix expression: ";
    cin >> i;
    cout << "The equivalent postfix expression is " << convert(i) << "\n";
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
class c_queue
{
    int rear;
    int front;
    int size;
    int *q;

public:
    c_queue(int n)
    {
        rear = 0;
        front = 0;
        size = n;
        q = new int[size];
    }

    bool isfull()
    {
        if (front == (rear + 1) % size)
        {
            return true;
        }
        return false;
    }

    bool isempty()
    {
        if (rear == front)
        {
            front=0;
            rear=0;
            return true;
        }
        return false;
    }

    void push(int n)
    {
        if (isfull())
        {
            cout << "\nOVERFLOW";
        }
        else
        {
            rear = (rear + 1) % size;
            q[rear] = n;
        }
    }

    void pop()
    {
        if (isempty())
        {
            cout << "\nUNDERFLOW";
        }
        else
        {
            front = (front + 1) % size;
            cout << endl
                 << q[front] << " has been popped ";
            q[front] = -1;
        }
    }

    void display()
    {

        if (isempty())
            cout << endl
                 << "Can't Display : UnderFlow";
        else
        {
            cout<<endl;
            int i = front + 1;
            do
            {
                cout << q[i];
                if (i < rear)
                {
                    cout << " <- ";
                }
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
        }
    }
};
int main()
{
    c_queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.display();
    return 0;
}