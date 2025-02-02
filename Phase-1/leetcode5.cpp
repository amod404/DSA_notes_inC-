// binary to decimal
#include <iostream>
#include <math.h>
using namespace std;

int decimal(long int n)
{
    int bin, i;
    for (i = 0, bin = 0; n; n/=10, i++)
    {
        int m = n % 10;
        bin = bin + m * pow(2, i);
    }
    return bin;
}

bool check(long int n)
{
    int count;
    for (count = 0; n; n /= 10)
    {
        int m = n % 10;
        if (m != 0 && m != 1)
        {
            count++;
        }
    }
    if (count)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    long int n;
    cout << "Enter a binary number: ";
    cin >> n;
    if (check(n))
    {
        cout << "Your number is: " << decimal(n);
    }
    else
    {
        cout << "you entered a invalid binary number.";
    }
    return 0;
}