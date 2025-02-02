#include <iostream>
using namespace std;

// Function to calculate bitwise OR for range [l, r]
long long rangeBitwiseOR(long long l, long long r) {
    // If l and r are the same, the OR is just l or r
    if (l == r) return l;

    // Move l and r closer together until they match
    long long shift = 0;
    while (l != r) {
        l >>= 1;
        r >>= 1;
        shift++;
    }

    // Return the OR result by shifting back and setting lower bits
    return l << shift | ((1LL << shift) - 1);
}

int main(){

    cout<<rangeBitwiseOR(8,10)<<endl;
    cout<<(8|9|10)<<endl;
    return 0;
}