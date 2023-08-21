//   o(n)
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp=0,i=0;
    for (; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
/*or
//   o(n)
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp=0,i=0,j=n-1;
    for (; i < j; i++,j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}*/