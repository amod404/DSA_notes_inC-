// can also do we single hash but chances are there for spucial hits

#include <bits/stdc++.h>
using namespace std;

// Define primes and moduli for double hashing
const int p1 = 31, p2 = 37;
const int m1 = 1e9 + 7, m2 = 1e9 + 33;
const int N = 100005;
vector<long long> power1(N), power2(N);

void precompute_powers() {
    power1[0] = 1;
    power2[0] = 1;
    for (int i = 1; i < N; i++) {
        power1[i] = (power1[i - 1] * p1) % m1;
        power2[i] = (power2[i - 1] * p2) % m2;
    }
}

// Function to calculate the double hash of a string
pair<long long, long long> calculate_hash(const string &s) {
    long long hash1 = 0, hash2 = 0;
    for (int i = 0; i < s.size(); i++) {
        hash1 = (hash1 + (s[i] - 'a' + 1) * power1[i]) % m1;
        hash2 = (hash2 + (s[i] - 'a' + 1) * power2[i]) % m2;
    }
    return {hash1, hash2};
}

// Rabin-Karp implementation with double hashing
vector<int> rabin_karp(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    if (m > n) return {};

    // Precompute pattern hash
    auto pattern_hash = calculate_hash(pattern);

    // Calculate rolling hashes for the text
    vector<long long> hash1(n + 1, 0), hash2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        hash1[i + 1] = (hash1[i] + (text[i] - 'a' + 1) * power1[i]) % m1;
        hash2[i + 1] = (hash2[i] + (text[i] - 'a' + 1) * power2[i]) % m2;
    }

    // Find matches
    vector<int> occurrences;
    for (int i = 0; i + m - 1 < n; i++) {
        long long current_hash1 = (hash1[i + m] - hash1[i] + m1) % m1;
        long long current_hash2 = (hash2[i + m] - hash2[i] + m2) % m2;

        // Normalize hash values for comparison
        if (current_hash1 == (pattern_hash.first * power1[i]) % m1 &&
            current_hash2 == (pattern_hash.second * power2[i]) % m2) {
            occurrences.push_back(i); // Match found at index i
        }
    }

    return occurrences;
}

int main() {
    // Precompute powers
    precompute_powers();

    // Example usage
    string text = "ababcabcab";
    string pattern = "abc";

    vector<int> occurrences = rabin_karp(text, pattern);

    // Output the occurrences
    for (int pos : occurrences) {
        cout << "Pattern found at index " << pos << endl;
    }

    return 0;
}
