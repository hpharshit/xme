// f(n)=2^(n+1)-1
// o(2^n)
#include<iostream>
using namespace std;
void TOH(int n, char a,char b,char c)
{
    if (n>0)
    {
    TOH(n-1,a,c,b);
    cout<<"Move "<<n<<" from : "<<a<<" to "<<c<<endl;
    TOH(n-1,b,a,c);
    }
}
int main()
{
    // a to c
    int n;    //no. of disc
    char a='a',b='b',c='c';      //tower name
    cout<<"No. of disc = ";
    cin>>n;
    cout<<endl<<"****Remove one disc at a time in order : ****"<<endl;
    TOH(n,a,b,c);      //move dics from tower a to c using b
    return 0;
}