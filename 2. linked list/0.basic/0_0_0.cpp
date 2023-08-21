// 0 and NULL are same  ==nothing==false
#include <iostream>
using namespace std;
class Node //self refrential class
{
public:
    int data;
    Node *next;
};
int main()
{
    Node *p;   //p is a head pointer created in stack
    p = new Node; //a node is created in heap;   node has data and pointer to "next" node
    p->data = 10;
    p->next=NULL;          //pointing to nothing
    // p->next=0;          //pointing to nothing
    return 0;
}