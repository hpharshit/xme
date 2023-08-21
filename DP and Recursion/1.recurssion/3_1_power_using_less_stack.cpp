#include <iostream>
using namespace std;
int pow(int base, int degree)
{
    if (degree == 0)
    {
        return 1;
    }
    if (degree % 2 == 0)
    {
        // 2^8= (2^2)^4
        return (pow((base) * (base), (degree / 2)));
    }
    else
    {
        // 2^7= 2*(2^2)^3
        return (base) * (pow((base) * (base), ((degree - 1) / 2)));
    }
}
int main()
{
    int base, degree;
    cin >> base >> degree;
    int ans = pow(base, degree);
    cout << ans;
    return 0;
}