//   o(n)
#include<iostream>
using namespace std;

int main()
{
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int b[n];
    for(int i=0,j=n-1;i< n,j>=0;i++,j--)
    {
        b[i]=arr[j];
    }
    for(int i=0;i< n;i++)
    {
        arr[i]=b[i];
        cout<<arr[i]<<" ";
    }
    return 0;
}