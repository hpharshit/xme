#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int front;
    int rear;
    int *Q;
} *obj1 = new Queue;

void create()
{
    cout << "Enter the size of Queue: ";
    cin >> obj1->size;

    // creating array of "size" that can be used as array
    obj1->Q = new int[obj1->size];
    obj1->front = -1;
    obj1->rear = -1;
}

void display()
{
    for (int i = obj1->front + 1; i <= obj1->rear; i++)
    {
        cout << obj1->Q[i] << " ";
    }
    cout << endl;
}

void enqueue()
{

    if (obj1->rear == obj1->size - 1)
    {
        cout << "Queue is Full: Queue Overflow\n";
    }
    else
    {
        obj1->rear++;
        cout << "\n Enter the element to enter : ";
        cin >> obj1->Q[obj1->rear];
    }
}

int dequeue()
{
    int x = -1;
    if (obj1->rear == obj1->front)
    {
        cout << "Queue is empty: Queue Underflow\n";
    }
    else
    {
        obj1->front++;
        x = obj1->Q[obj1->front];
    }
    return x; // if x return -1 then the queue is empty
}

int main()
{
    create();

    enqueue();
    display();

    dequeue();
    cout << "After dequeuing: ";
    display();

    return 0;
}