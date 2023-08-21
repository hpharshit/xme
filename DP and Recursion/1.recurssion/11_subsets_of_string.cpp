#include<bits/stdc++.h>
using namespace std;
void subset(vector<string>& v, string st,string s="",int i=0)
{
    if(i==st.length())
    {
      v.push_back(s);    //storing
      return;
    }
    subset(v,st,s,i+1);   // not adding
    subset(v,st,s+st[i],i+1);// adding
    
}

int main()
{
    string st;
    cout<<"Enter the string: ";
    cin>>st;
    vector<string>v;
    subset(v,st);
    cout<<"Subs are: ";
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}