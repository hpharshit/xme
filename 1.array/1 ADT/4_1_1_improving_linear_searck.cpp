

#include <iostream>
#include <string.h>
using namespace std;
struct A
{
    int *a = new int[10];
    int length;
    int size;
} arr;
void Search(struct A *arr, int num)
{
    int count = 0;
    for (int i = 0; i < arr->length; i++)
    {
        if (num == arr->a[i])
        {
            cout << "Index of " << num << " is " << i << endl;

            int temp;                                   //swaping to decrease time complexity next time
            temp = arr->a[i];
            // moving to head
            arr->a[i] = arr->a[0];
            arr->a[0] = temp;
            /* transposition
                arr->a[i]=arr->a[i-1];
                arr->a[i-1]=arr->a[i];*/
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Number is not present " << endl;
    }
}
int main()
{
    arr;
    int n;
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
    Search(&arr, num);
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.a[i] << " ";
    }
    cout << "\nArray has become after swaping\n";
    Search(&arr, num);

    free(arr.a);
    arr.a = NULL;

    return 0;
}