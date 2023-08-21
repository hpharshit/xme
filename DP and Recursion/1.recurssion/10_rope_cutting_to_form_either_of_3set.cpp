// O(3^n)

#include<bits/stdc++.h>
using namespace std;
int count(int n, int a, int b, int c)
{
   if(n==0)
     return 0;
   if(n<0)
     return -1;

    int aa=count(n-a,a,b,c);
    int bb=count(n-b,a,b,c);
    int cc= count(n-c,a,b,c);
    int res;
    if(aa>bb && aa>cc)
     res=aa;
    else if(cc>bb && cc>aa)
     res=cc;
    else if(aa<bb && bb>cc)
     res=bb;
    if(res==-1)
      return -1;
      return res+1;
}

int main()
{
    cout<<"enter the rope size: ";
    int size;
    cin>>size;
    int a,b,c;
    cout<<"enter the set: ";
    cin>>a>>b>>c;
    int max_pieces=count(size,a,b,c);
    cout<<max_pieces;


    return 0;
}