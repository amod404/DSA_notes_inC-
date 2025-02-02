//reverse

#include <iostream>
#include <climits>
using namespace std;

int reverse(int a)
{
    int bin, m;

    for (bin = 0; a;)
    {
        m = a % 10;
        if (bin > INT_MAX / 10 || bin < INT_MIN / 10)
        {
            return 0;
        }
        bin = bin * 10 + m;
        a /= 10;
    }
    return bin;
}
int main()
{
    int n;
    cin >> n;
    cout << reverse(n);
    return 0;
}