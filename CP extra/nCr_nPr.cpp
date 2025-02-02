#include <bits/stdc++.h>
using namespace std;

const int N = 1e5; // Maximum value for n
const int MOD = 1e9+7; // Modulus for calculations
vector<long long> fact(N + 1), invFact(N + 1);

// Fast modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and modular inverses
void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    // Compute inverses using Fermat's Little Theorem
    invFact[N] = modExp(fact[N], MOD - 2, MOD);
    for (int i = N - 1; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

// Function to calculate nCr
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// Function to calculate nPr
long long nPr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[n - r] % MOD;
}

int main() {
    // Precompute factorials and inverses
    precomputeFactorials();

    // Example queries
    int q;
    cin >> q;
    while (q--) {
        int n, r;
        cin >> n >> r;
        cout << "nCr(" << n << ", " << r << ") = " << nCr(n, r) << endl;
        cout << "nPr(" << n << ", " << r << ") = " << nPr(n, r) << endl;
    }
    return 0;
}
