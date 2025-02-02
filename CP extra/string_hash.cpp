#include <bits/stdc++.h>
using namespace std;

int p = 31;
const int N = 100003, m = 1000000007;
vector<long long> power(N);

long long calculate_hash(string &s) {
    long long hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash = (hash + (s[i] - 'a' + 1) * power[i]) % m;
    }
    return hash;
}

int main() {
    // Precompute powers of p
    power[0] = 1;
    for (int i = 1; i < N; i++) {
        power[i] = (power[i - 1] * p) % m;
    }

    // Input strings
    vector<string> strings = {"ca", "ab", "aa", "c", "aa"};
    vector<long long> hashes;

    // Calculate hashes for all strings
    for (auto &w : strings) {
        hashes.push_back(calculate_hash(w));
    }

    // Sort and count distinct hashes
    sort(hashes.begin(), hashes.end());
    int distinct = 1; // At least one distinct element
    for (int i = 1; i < hashes.size(); i++) {
        if (hashes[i] != hashes[i - 1]) {
            distinct++;
        }
    }

    cout << distinct << endl;

    return 0;
}
