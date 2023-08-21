#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	int x = log2(n);

	//(2^(x-1))*x  //sum of bits of numbers less than highest power of two in n
	int first = (1 << (x - 1)) * x;

	// count biggest set bits from highest power of 2 to n
	int second = n - (1 << x) + 1;

	// solve for for n-highest_power_of_two
	int third = n - (1 << x);
	return first + second + countSetBits(third);
}
int main()
{
	cout<<countSetBits(5)<<endl;

	return 0;
}