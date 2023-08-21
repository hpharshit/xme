// Find Missing And Repeating gfg : repition is twice
#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= arr[i];
        xor1 ^= (i + 1);
    }
    int count = log2(xor1 ^ (xor1 & (xor1 - 1)));
    int xor2 = 0, xor3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & (1 << count))
            xor2 ^= arr[i];
        else
            xor3 ^= arr[i];
        if ((i + 1) & (1 << count))
            xor2 ^= (i + 1);
        else
            xor3 ^= (i + 1);
    }
    count = 0;
    for (int i : arr)
    {
        if (i == xor2)
            count++;
    }
    if (count == 2)
        return {xor2, xor3};
    return {xor3, xor2};
}

int main()
{
    return 0;
}