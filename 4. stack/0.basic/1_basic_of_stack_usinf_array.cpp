#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top;        // as no top element is present as array is empty
    int *a;         // to create array dynamically
} *obj = new stack; // creating global pointer object

void display()
{
    cout << "\n\t\t******DISPLAYING STACK******\n";
    if (obj->top == -1) // displaying   if stack is empty
    {
        cout << "Stack Overflow\n";
    }
    else if (obj->top >= 0) // displaying   if stack is not empty
    {
        for (int i = 0; i <= obj->top; i++)
        {
            cout << obj->a[i] << " ";
        }
        cout << endl;
    }
}

void create()
{
    cout << "\n\t\t******CREATING STACK******\n";
    obj->top = -1;
    
    cout << "Enter size of array : ";
    cin >> obj->size;

    obj->a = new int[obj->size]; // creating array dynamically
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
        obj->a[obj->top] = element;
    }
}

void pop()
{
    cout << "\n\t\t******POPING STACK******\n";

    int temp;
    if (obj->top == -1) // if stack is empty then show stack underflow
    {
        cout << "Stack Underflow\n";
    }
    while (obj->top >= 0) // while top is not -1; i.e while the stack is not empty
    {
        temp = obj->a[obj->top]; // storing the value in temp and deleting
        obj->top--;
    }
}

void peak(int q) // value of index from last
{
    if (obj->top < 0)
    {
        cout << "\nStack is empty";
    }
    else if (obj->top < q)
    {
        cout << "INVALID INDEX\n";
    }
    else
    {
        cout << obj->a[obj->top - q]; // element from the top i.e element from the end
    }
}

void stacktop() // knowing the top most value i.e the last value
{
    if (obj->top < 0)
    {
        cout << "\nStack is empty";
    }
    else
    {
        cout << obj->a[obj->top];
    }
}

void isempty()
{
    if (obj->top == -1)
    {
        cout << " Stack is empty\n";
    }
    else if (obj->top >= 0)
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
    int enter;

label:
    cout << "\nEnter 1 to continue ;else to exit : ";
    cin >> enter;
    if (enter == 1)
    {
        int choice;
        cout << "\nEnter:\t1 to create\n\t2 to push\n\t3 to pop\n\t4 peep\n\t5 for stack at top\n\t6 to check empty\n\t7 to check full\n\t0 else to display:  ";
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