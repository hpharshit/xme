//   o(n)
#include <iostream>
#include<string>
using namespace std;

int main()
{
     string st="Harshit";
    int i,count=0;
    l1:
    
    int b=st[0];
    for (i = 0; i < st.length()-1; i++)
    {
       st[i]=st[i+1];//shifting each element to left
    }
    st[i]=b;//rotation of elemets 
    cout<<endl;
    for (int i = 0; i < st.length(); i++)
    {
        cout << st[i] << " ";
    }
    count++;
    if(count>6)
    {
        goto l2;
    }
    goto l1;
    l2:
    return 0;
}