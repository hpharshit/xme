// order of fibonachi nth term code using recursion is o(2^n)
#include<iostream>
using namespace std;
int fib(int n)
{
    if (n==0||n==1)
    {
    return n;
    }
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    cin>> n;
    int c=  fib(n);
    cout<<c;
    return 0;
}

/*   using loop
    iterative
// order of fibonachi nth term code using loop is o(n)
#include <iostream>
using namespace std;
void fib(int n)
{
    if(n<=1)
    {
        cout<<n<<" ";
    }
    int a = 0, b = 1, ne = 0;
    for (int i = 1; i <= n; i++)
    {
        a = b;
        b = ne;
        ne = a + b;
    }
        cout << ne << " ";
}
int main()
{
    int n;
    cin >> n;
    fib(n);
    return 0;
}
*/