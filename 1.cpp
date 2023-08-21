#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[9];
    int n = 9;
    vector<int> ans(2, 0);
    int xor1 = 0;
    for (int i = 0; i < n; i++)
        xor1 ^ arr[i];
    for (int i = 0; i < n; i++)
        xor1 ^= i + 1;
    xor1 = xor1 ^ (xor1 & (xor1 - 1));
    int count = log2(xor1) + 1;
    int xor2 = 0, xor3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & (1 << count))
            xor2 ^= arr[i];
        else
            xor3 ^= arr[i];
        if ((i + 1) & (1 << count))
            xor2 ^= i + 1;
        else
            xor3 ^= i + 1;
    }
    cout << count << " " << xor1 << endl;
    // return ans;

    return 0;
}