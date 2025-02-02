#include <iostream>
using namespace std;

// Function to perform binary exponentiation
long long binaryExponentiation(long long a, long long b) {
    long long result = 1; // Initialize result

    while (b > 0) {
        // If b is odd, multiply a with the result
        if (b & 1) {
            result *= a;
        }

        // Square the base and divide b by 2
        a *= a;
        b >>= 1; // Equivalent to b = b / 2
    }

    return result;
}

int main() {
    long long a, b;
    cout << "Enter the base (a): ";
    cin >> a;
    cout << "Enter the exponent (b): ";
    cin >> b;

    // Compute a^b using binary exponentiation
    long long result = binaryExponentiation(a, b);
    cout << a << "^" << b << " = " << result << endl;

    return 0;
}