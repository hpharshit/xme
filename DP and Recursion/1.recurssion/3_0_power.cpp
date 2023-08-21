#include<iostream>
using namespace std;
int pow(int base, int degree)
{
    if (degree==0)
    {
        return 1;
    }
    return base*pow(base,degree-1);
}
int main()
{
    int base, degree;
    cin>> base>>degree;
    int ans=pow(base,degree);
    cout<<ans;
    return 0;
}