#include<iostream>
using namespace std;
int main()
{
    int arr[5]={-5,5,6,-10,8};
    int n= sizeof(arr)/sizeof(arr[0]);
    int i=0,j=n-1;
    while (i<j)
    {
        while (arr[i]<0) //for -ve
        {
            i++;
        }
        while (arr[j]>=0)   //for +ve
        {
            j--;
        }
        if (i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
    cout<<arr[i]<<" ";
    }
    return 0;
}