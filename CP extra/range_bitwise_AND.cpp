
// Function to calculate bitwise AND for range [l, r]
long long rangeBitwiseAND(long long l, long long r) {
    // If l and r are the same, the AND is just l or r
    if (l == r) return l;

    // Move l and r closer together until they match
    long long shift = 0;
    while (l != r) {
        l >>= 1;
        r >>= 1;
        shift++;
    }

    // Return the AND result by shifting back and setting lower bits
    return l << shift;
}
