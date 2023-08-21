#include <bits/stdc++.h>
using namespace std;

int main()
{
  // int arr[] = {1,1,1,1,2,2,2,2,4,5};
  int arr[] = {8,8,4,6,2,2};
  int n=6;
  int xor1 = arr[0];
  for (int i = 1; i < n; i++)
    xor1 ^= arr[i];

   int count=0;
  // finding right most set bit
  xor1 = xor1 ^ (xor1 & (xor1 - 1)); // to get rightmost set bit only
  count = (int)(log2(xor1));
  int xor2 = 0, xor3 = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] & (1 << count))
      xor2 ^= arr[i];
    else
      xor3 ^= arr[i];
  }
  cout << xor2 << " " << xor3 << endl;
  return 0;
}