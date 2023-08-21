// o(n)
#include <iostream>
using namespace std;

int fact(int n , int val=1)
{
  if (n == 0 || n==1 )
  {
    return 1;
  }
  
  return fact(n-1, n*val);     // made tail recursion
}
int main()
{
  int n;
  cin >> n;
  int b = fact(n);
  cout << b;
  return 0;
}