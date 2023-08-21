// O(n)
#include<bits/stdc++.h>
using namespace std;

int jos(int p, int k)
{
    if(p==1)
      return 0;


    return (jos(p-1,k) +k)%p;
}
int main()
{
    int people;
    int killing;
    cout<<"Enter the no. of persons: ";
    cin>>people;
    cout<<"Enter the no. of killings: ";
    cin>>killing;
    int left=jos(people,killing);
    cout<<"Survivor is: "<<left;
    return 0;
}