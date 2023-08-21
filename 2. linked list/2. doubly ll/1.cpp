#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x)
  {
      data = x;
      next = prev = NULL;
  }
};
Node*head=NULL;
Node*last=NULL;

void addnode(int x)
{
    if (head == NULL)
    {
        head=new Node(x);
        last=head;
        return;
    }
    Node *n = new Node(x);
    
    last->next = n;
    n->prev = last;
    last = n;
    
}
void insertbeg(int a){
    if(head==NULL)
    {head=new Node(a);
    last=head;
    return;
    }
    Node*temp=new Node(a);
    temp->next=head;
    head->prev=temp;
    head=temp;

}
void insertend(int a){
    if(head==NULL)
    {head=new Node(a);
    last=head;
    return;
    }
    Node*temp=new Node(a);
    temp->prev=temp;
    last->next=temp;
    last=temp;

}
void insert_at_pos(int a){
    int pos;
    cin>>pos;
    Node*temp=head;
    Node*temp1=new Node(a);
    pos=pos-1;
    while(pos--){

        temp=temp->next;
    }
    temp1->next=temp->next;
    temp->next=temp1;
    temp1->prev=temp;
    temp1=temp1->next;
    if(temp1){
        temp1->prev=temp->next;
    }
    
}
void printList(Node *head)
{
  // The purpose of below two loops is
  // to test the created DLL
  Node *temp=head;
  if (temp != NULL) {
 
  while (temp->next!=NULL)
    temp=temp->next;
  while (temp->prev!=NULL)
   temp = temp->prev;
  }
  while (temp != NULL)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  
  cout << endl;
}
 Node* deleteNode(Node *head, int x)
    {
      //Your code here
      Node*temp=head;
      if(x==1){
          head=head->next;
          head->prev=NULL;
          delete(temp);
          return head;
      }
      int i=1;
      Node*temp1=NULL;
      while(i<x&&temp!=NULL){
          temp1=temp;
          temp=temp->next;
          i++;
      }
      temp1->next=temp->next;
      if(temp->next!=NULL)
      temp->next->prev=temp1;
      delete(temp);
      return head; 
    }
int main()
{ 
  //Node*head=NULL;
   addnode(10);
   //cout<<head<<" ";
   addnode(20);
   addnode(40);
   addnode(30);
   printList(head);
//    while(true){
//        cout<<"enter your choice:"<<endl;
//        int n;
//        cin>>n;
//        cout<<"press 1. addnode;<<"<<endl;
//        cout<<"press 2. insert at begining"<<endl;
//        cout<<"press 2. insert at end"<<endl;
//        cout<<"press 2. insert at pos"<<endl;
//        cout<<"delete at pos"<<endl;
//        switch(n){
//            case 1:addnode();
//        }

// }
insert_at_pos(22);
 printList(head);
  return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	 Node *next;
};
 Node *last = NULL;
 Node* head=NULL;
 int size=0;
void addNode( int data)
{   
	if(head==NULL)
    {
        head= new Node();
        head->data=data;
        last=head;
        last->next=head;
        size++;
        return;
    }
    Node*temp=new Node();
    temp->data=data;
    temp->next=last->next;
    last->next=temp;
    last=temp;
    size++;

}
void insertbeg(int a){
    if(head==NULL)
    {
        addNode(a);
        return;
    }
    Node*temp=new Node();
    temp->data=a;
    last->next=temp;
    temp->next=head;
    head=temp;
}
void insert_at_pos(int a )
{
    if(head==NULL)
    {addNode(a);
    return;}
    int pos;

    cout<<"\nenter the pos"<<endl;
    cin>>pos;

    Node*temp=head;
    if(pos==1){
    insertbeg(a);
    return;
}
    pos =pos-2;
    while(pos--){
        temp=temp->next;
    }
    //cout<<temp<<" "<<head<<endl;
    Node*temp1=new Node();
    temp1->data=a;
    temp1->next=temp->next;
    temp->next=temp1;
    
    size++;
}
void deletebeg(){
    if(head==NULL)
    return ;
    Node*temp=head;
    last->next=head->next;
    head=head->next;
    free(temp);
}
void delete_at_pos(){
    int pos;

    cout<<"\nenter the pos"<<endl;
    cin>>pos;
    if(pos==1){
        deletebeg();
        return;
    }
    pos =pos-1;
    Node*pre=NULL;
    Node*temp=head;
    while(pos--){
        pre=temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    delete(temp);
    
}
void traverse()
{
	struct Node *p;

	// If list is empty, return.
	if (last == NULL)
	{
		cout << "List is empty." << endl;
		return;
	}

	// Pointing to first Node of the list.
	p = head;
    
    
	// Traversing the list.
	do
	{
		cout << p -> data << " ";
		p = p -> next;

	}
	 while(p != last->next);

}

// Driven Program
int main()
{
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);
      //cout<<head<<" "<<last->next<<endl;
      traverse();

    //insertbeg(42);
      //cout<<head<<" "<<last->next<<endl;
      //deletebeg();
      delete_at_pos();
    //insert_at_pos(22);
      //cout<<head<<" "<<last->next<<endl;
    //cout<<head<<" "<<last->next<<endl;
	 
	// addAfter(last, 10, 8);

	traverse();

	return 0;
}


*/

/*
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = 0, *last = 0;

void add_new_node(int arr[], int no)
{
    int i = 0;
    while (i != no)
    { 
        node *temp = new node();
        temp->data = arr[i];
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp; // storing this node address in the previous node next part
            last = temp;       //now last pointer is pointing on the address of temp node
        }
        i++;
    }
}
int max_ele(node *n, int *arr)
{
    int i = 0;
    int max = INT32_MIN;
    while (n != 0)
    {

        if (n->data > max)
        {
            max = n->data;
        }
        n = n->next;
    }
    return max;
}

void display(node *n)
{
    while (n != 0)
    {
        cout << n->data << " ";
        n = n->next;
    }
}
node *search(node *n, int key)
{
    while (n != 0)
    {
        if (n->data == key)
        {
            return n;
        }
        n = n->next;
    }
    return NULL;
}
void insert(node *n, int pos)
{
    node *p = NULL;
    if(pos==1)
    {   node*temp=new node();
        temp->data=233;
        temp->next=head;
        head=temp;
        return;

    }
    int index = 1;
    while (index != pos&&n!=NULL)
    {
        index++;
        p = n;
        n = n->next;
    }
    node *temp = new node();
    temp->data = 12;

    p->next = temp;
    temp->next = n;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9, 11};
    int n=sizeof(arr)/sizeof(arr[0]);
    add_new_node(arr, n);
    display(head);
    cout<<endl;
    insert(head,10);
    display(head);

    return 0;
}



*/