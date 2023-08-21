#include<bits/stdc++.h>
using namespace std;

bool check(string st, int s,int e )
{
        if(s==e || s>e)   //for even and odd string
          return true;
        if(st[s]!=st[e])
             return false;
        return check(st,s+1,e-1);
}

int main()
{
    string st;
    cin>>st;
    bool a=check(st,0,st.size()-1);
    if(a)
      cout<<"Palindrome";
    else
      cout<<"Not";
    return 0;
}