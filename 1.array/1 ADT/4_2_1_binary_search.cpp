/*  min time is f(n)=1        o(1) constant  best case
    max time is f(n)=log(n+1) o(log(n)) worst case*/

#include <iostream>
#include <string.h>
using namespace std;
struct A
{
    int size;
    int *a = new int[size];
    int length;
} arr;
int Search(struct A *arr, int num)
{
    int count = 0, mid = 0;
    int s = 0, e = arr->length-1;
    // for(int i=0; i<arr->length;i++)
    while(s<=e)
    {
        mid = (e + s) / 2;
        if (num == arr->a[mid])
        {
            return mid;
        }
        else if (num > arr.(a[mid]))
        {
            s = mid + 1;
        }
        else if (num < mid)
        {
            e = mid- 1;
        }
    }
    
    return -1;
}
int main()
{
    arr;
    int n;
    cout << "Size of elements: ";
    cin >> arr.size;
    cout << "Number of elements: ";
    cin >> n;

        arr.length = n;
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr.a[i];
        }
        cout << "Array is : ";
        for (int i = 0; i < arr.length; i++)
        {
            cout << arr.a[i] << " ";
        }

        int num;
        cout << "\nElement to search : ";
        cin >> num;
        int index=Search(&arr, num);
        if (index>=0)
        {
            cout<<"index is "<<index;
        }
        else
        {
            cout<<"not present";
        }
        

        free(arr.a);
        arr.a = NULL;

    return 0;
}