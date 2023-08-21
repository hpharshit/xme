#include<iostream>
using namespace std;
double combi(double n, double r)
{
    if (r==0||n==r)
    {
        return 1;
    }
    else
    {
       return combi(n-1,r-1)+combi(n-1,r);
    //    nCr = (n-1 C r-1)   + (n-1 C r)  
    }
}
int main()
{
    double n,r;
    cin>>n>>r;
    double a=combi(n,r);
    cout<<"nCr= "<<a;
    return 0;
}