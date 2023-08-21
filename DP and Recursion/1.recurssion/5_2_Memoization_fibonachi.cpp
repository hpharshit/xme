// storing value of function calls in static array to avoid multiple calls for same fumction
// this is memoization
// this educes no. of function calls
// here no. of calls is n+1
// so time complexity is o(n)

#include <iostream>
using namespace std;
int fib(int n)
{
    static int M[20];  //static array can't have variable length  eg. static int M[n] is invalid
    for (int i = 0; i < 20; i++)
    {
        M[i]=false;
        // or M[i]=-1;
    }
    
    if (n == 0 || n == 1)
    {
        M[n] = n;
        return n;
    }
    else
    {
        if(M[n-1]==false)
        // if(M[n-1]==-1)
        {
            M[n-1]=fib(n-1);
        }
        if(M[n-2]==false)
        // if(M[n-2]==-1)
        {
            M[n-2]=fib(n-2);
        }
    }
    return M[n-1]+M[n-2];
}
int main()
{
    int n;
    cin >> n;
    int c = fib(n);
    cout << c;
    return 0;
}
