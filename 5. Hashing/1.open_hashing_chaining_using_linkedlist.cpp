#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class Myhash
{
    int bucket;
    node **hash;

public:
   
    Myhash()
    {
        cout << "\nEnter the size of hash table: ";
        int a;
        cin >> a;
        bucket = a;

        // creating hash table of size bucket
        hash = new node *[bucket];
        for (int i = 0; i < bucket; i++)
        {
            hash[i] = NULL;
        }
    }

    int hash_function(int n)
    {
        return   n % bucket;
    }
    
    void storing_in_hastable_using_chaining(int arr[], int n)
    {
        int index, i = 0;
        int value;
        node *head;

        while (n--)
        {
            index = hash_function(arr[i]);

            if (hash[index] == 0)
            {
                node *t = new node;
                t->data = arr[i];
                t->next = 0;
                hash[index] = t;
                i++;
            }
            else if (hash[index] != 0)
            {
                int value = arr[i];
                node *head = hash[index];

                node *t = head->next;
                node *q = head;
                while (t)
                {
                    if (head->data > value)
                    {
                        node *it = new node;
                        it->data = value;
                        it->next = head;
                        head = it;
                        break;
                    }
                    else if (t->data > value)
                    {
                        node *it = new node;
                        it->data = value;
                        it->next = t;
                        break;
                    }
                    q = q->next;
                    t = q->next;
                }
                if (t == 0)
                {
                    node *it = new node;
                    it->data = value;
                    it->next = t;
                    q->next = it;
                }
            }
        }
    }

    bool search(int key)
    {
        int index = hash_function(key);
        node *t = hash[index];
        if (hash[index] == 0)
        {
            return false;
        }
        else if (hash[index] != 0)
        {
            while (t)
            {
                if (t->data == key)
                    return true;
                if (t->data > key)
                    return false;
                if (t->data < key)
                    t = t->next;
            }
            return false;
        }
    }

};

int main()
{
    Myhash m;

    cout << "Enter the size of array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    m.storing_in_hastable_using_chaining(arr, n);

    int key;
    cout << "Enter the key to find: ";
    cin >> key;
    bool a = m.search(key);
    if (a)
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }

    return 0;
}