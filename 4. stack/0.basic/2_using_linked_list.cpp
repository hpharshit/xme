#include <iostream>
using namespace std;

int no_of_elements;

class stack
{
public:
    int size;
    int top = -1;   //as no top element is present as array is empty
} *obj = new stack; //creating global pointer object

class node
{
public:
    int data;
    node *next;
} *head = 0, *last = 0;

void display()
{
    cout << "\n\t\t******DISPLAYING STACK******\n";
    node *it = head;
    if (obj->top == -1) // displaying   if stack is empty
    {
        cout << "Stack Overflow\n";
    }
    else if (obj->top >= 0) // displaying   if stack is not empty
    {
        while (it != 0)
        {
            cout << it->data << " ";
            it = it->next;
        }
        cout << endl;
    }
}

void create()
{
    cout << "\n\t\t******CREATING STACK******\n";

    cout << "Enter the no. of elements to enter : ";
    cin >> no_of_elements;
    if (no_of_elements < 1)
    {
        cout << "invalid input";
    }
    else if (no_of_elements > obj->size)
    {
        cout << "Stack Overflow!!";
    }
    else
    {
        cout << "Enter the elements to enter : ";
        head = new node;
        cin >> head->data;
        head->next = 0;
        last = head;
        for (int i = 1; i < no_of_elements; i++)
        {
            node *it = new node;
            cin >> it->data;
            last->next = it;
            it->next = 0;
            last = it;

            obj->top++; //to point at the top element i.e at the last inserted element
        }
    }
}

void push()
{
    cout << "\n\t\t******PUSHING STACK******\n";
    int element;
    cout << "Enter the element to push at the end : ";
    cin >> element;

    if (obj->top == obj->size - 1)
    {
        cout << "Stack Overflow";
    }
    else
    {
        obj->top++;

        node *it = head;
        while (it->next != 0)
        {
            it = it->next;
        }
        node *p = new node;
        p->data = element;
        p->next = 0;
        it->next = p;
        p = 0;
    }
}

void pop()
{
    cout << "\n\t\t******POPING STACK******\n";
    cout << "No. of elements to pop: ";
    int pope;
    cin >> pope;

    if (obj->top == -1) // if stack is empty then show stack overflow
    {
        cout << "Stack Overflow\n";
    }
    else if (pope > obj->top + 1) //if pop is done for more elements then the no. of present elements then first pop the elements then once stack is empty then print stack overflow
    {
        while (obj->top >= 0) //while top is not -1; i.e while the stack is not empty
        {
            obj->top--;
        }
        head=0;
        cout << "Stack Overflow\n";
    }
    else
    {
        for (int i = 1; i <= pope; i++) //moving top pointer to the the last element to point after poping
        {
            obj->top--;
        }
        int flag = 0;
        node *it = head;
        while (flag != obj->top) //moving node pointer to the top pointer after pointing
        {
            it = it->next;
            flag++;
        }
        it->next = 0; //making node at top pointer to point at null and hence poping
    }
}

void peak(int q) //value of index from last
{
    node *it = head;
    if (obj->top < 0)
    {
        cout << "\nStack is empty";
    }
    else if (obj->top+1 < q)
    {
        cout << "INVALID INDEX\n";
    }
    else
    {
        for (int i = 0; i <= obj->top - q; i++)
        {
            it = it->next;
        }
        cout << it->data << endl;
    }
}

void stacktop() //knowing the top most value i.e the last value
{
    node *it = head;
    if (obj->top < 0)
    {
        cout << "\nStack is empty";
    }
    else
    {
        for (int i = 0; i <= obj->top; i++)
        {
            it = it->next;
        }
        cout << it->data << endl;
    }
}

void isempty()
{
    if (obj->top < 0)
    {
        cout << " Stack is empty\n";
    }
    else
    {
        cout << "Stack is not empty\n";
    }
}

void isfull()
{
    if (obj->top == obj->size - 1)
    {
        cout << " Stack is full\n";
    }
    else
    {
        cout << "Stack is not full\n";
    }
}

int main()
{
    cout << "Enter size of array : ";
    int n;
    cin >> n;

    obj->size = n; //giving size of array

    int enter;

label:
    cout << "\nEnter 1 to continue ;else to exit : ";
    cin >> enter;
    if (enter == 1)
    {
        int choice;
        cout << "\nEnter :\t1 to create\n\t2 to push\n\t3 to pop\n\t4 peep\n\t5 for stack at top\n\t6 to check empty\n\t7 to check full\n\t0 to display:  ";
        cin >> choice;
        switch (choice)
        {

        case 1:
            // 1. creating through stack data type
            create();
            break;

        case 2:
            // 2. push(x)    //done at end    as time is constant ; while from front time is order of n i.e O(n)
            push();
            break;

        case 3:
            // 3. pop()  //done from end always    //one pop() pops one element from the last
            pop();
            break;

        case 4:
            // 4. peak(at index)
            int q;
            cout << "Enter the index to see from top: ";
            cin >> q;
            peak(q);
            break;

        case 5:
            // 5. stacktop()   value of top most element of the stack
            stacktop();
            break;

        case 6:
            // 6. isempty()
            isempty();
            break;

        case 7:
            // 7. isfull()
            isfull();
            break;

        default:
            display();
            break;
        }
    }
    else
    {
        goto label1;
    }
    goto label;

label1:
    cout << "\n\t\t\t*******************PROGRAM EXITED SUCCESSFULLY******************************\n\n";

    free(obj);
    obj = 0;
    return 0;
}