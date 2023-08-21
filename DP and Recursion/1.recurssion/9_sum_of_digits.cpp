#include<bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if(!n)
      return 0;
    return n%10 + sum(n/10);
}

int main()
{
    int n;
    cin>>n;
    int a=sum(n);
    cout<<"sum is : "<<a;
    return 0;
}