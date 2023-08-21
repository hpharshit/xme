//   o(n)
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    int b=arr[0];
    for (i = 0; i < n-1; i++)
    {
       arr[i]=arr[i+1];//shifting each element to left
    }
    arr[i]=b;//rotation of elemets 
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}