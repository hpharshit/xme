/*e of e^x = 1 + x/1! + x^2/2! ------------*/

#include <iostream>
using namespace std;
double e(double n, double degree)
{
    static double sum=1;
    if (degree==0)
    {
        return sum;
    }
    sum=1+((sum*n)/degree);
    return e(n,degree-1); 
    
}
int main()
{
    int n, degree;
    cin >> n >> degree;
    double b = e(n, degree);
    cout << b;
    return 0;
}




/*    using loop
// e of e^x = 1 + x/1! + x^2/2! ------------

#include <iostream>
using namespace std;
double e(double n, double degree)
{
    double sum=1;
    double num=1,den=1;

    for(int i=1;i<=n;i++)
    {
        sum=sum*(num/den);
    }
    return sum; 
}
int main()
{
    int n, degree;
    cin >> n >> degree;
    double b = e(n, degree);
    cout << b;
    return 0;
}
*/