#include <iostream>
#include <string.h>
using namespace std;
struct A
{
    int size;
    int *a = new int[size];
    int length;
} arr;
void Search(struct A *arr, int num, int &s, int &e)
{
    static int count = 0;

    if (s <= e)
    {
        int mid = (e + s) / 2;
        if (num == arr->a[mid])
        {
            cout << "Index is " << mid << endl;
            count++;
        }
        else if (num > mid)
        {
            s = mid + 1;
            Search(arr, num, s, e);
        }
        else if (num < mid)
        {
            e = mid-1;
            Search(arr, num, s, e);
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
    int s = 0, e = arr.length-1;
    Search(&arr, num, s, e);

    free(arr.a);
    arr.a = NULL;

    return 0;
}