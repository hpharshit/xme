/*e of e^x = 1 + x/1! + x^2/2! ------------*/

#include <iostream>
using namespace std;
double pow=1,fac=1;
double r;
double e(double n, double degree)
{
    if (degree == 0)
    {
        return 1;
    }
    r=e(n,degree-1);
    pow=pow*n;
    fac=fac*degree;
    return r+pow/fac;
}
int main()
{
    double n, degree;
    cin >> n >> degree;
    double b = e(n, degree);
    cout << b;
    return 0;
}