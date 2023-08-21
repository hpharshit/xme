#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
    int arr[]={5,5,10,5,10,12,12};
    unordered_map<int, int> mp;
    for(int x: arr)
    {
        mp[x]++;
    }

    unordered_map<int,int> :: iterator it;
    it=mp.find(5);
    cout<<it->first<<" "<<it->second<<endl;
    it=mp.find(10);
    cout<<it->first<<" "<<it->second<<endl;
    it=mp.find(12);
    cout<<it->first<<" "<<it->second<<endl;

    return 0;
}