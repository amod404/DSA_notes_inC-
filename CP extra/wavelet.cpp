#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Wavelet Tree class
class WaveletTree {
private:
    int low, high;               // Range of elements in the current node
    WaveletTree *left, *right; // Pointers to child nodes
    vector<int> freq;         // Frequency array to store counts of elements going to the left

public:
    // Constructor to build the wavelet tree
    WaveletTree(vector<int>::iterator from, vector<int>::iterator to, int x, int y) {
        low = x, high = y;
        if (low == high || from >= to) {
            left = right = nullptr;
            return;
        }
        
        int mid = (low + high) / 2;

        // Create frequency array
        freq.reserve(to - from + 1);
        freq.push_back(0);
        for (auto it = from; it != to; it++) {
            freq.push_back(freq.back() + (*it <= mid));
        }

        // Separate elements into two groups based on mid
        auto pivot = stable_partition(from, to, [mid](int x) { return x <= mid; });

        // Build child nodes
        left = new WaveletTree(from, pivot, low, mid);
        right = new WaveletTree(pivot, to, mid + 1, high);
    }

    // Function to find frequency of 'element' in range [l, r]
    int freqInRange(int l, int r, int element) {
        if (l > r || element < low || element > high)
            return 0;
        if (low == high)
            return r - l + 1;
        int leftCountL = freq[l - 1];
        int leftCountR = freq[r];
        int mid = (low + high) / 2;
        if (element <= mid)
            return left->freqInRange(leftCountL + 1, leftCountR, element);
        else
            return right->freqInRange(l - leftCountL, r - leftCountR, element);
    }

    // Function to find the k-th smallest element in range [l, r]
    int kthSmallest(int l, int r, int k) {
        if (l > r)
            return -1; // Invalid range
        if (low == high)
            return low; // Leaf node
        int leftCountL = freq[l - 1];
        int leftCountR = freq[r];
        int inLeft = leftCountR - leftCountL;
        if (k <= inLeft)
            return left->kthSmallest(leftCountL + 1, leftCountR, k);
        else
            return right->kthSmallest(l - leftCountL, r - leftCountR, k - inLeft);
    }

    ~WaveletTree() {
        delete left;
        delete right;
    }
};

int main() {
    // Input array
    vector<int> arr = {5, 1, 2, 5, 7, 8, 5, 1, 9};
    int n = arr.size();

    // Find the range of elements in the array
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    // Build the wavelet tree
    WaveletTree wt(arr.begin(), arr.end(), minVal, maxVal);

    // Query 1: Find frequency of an element in range [l, r]
    int l = 2, r = 7, element = 5;
    cout << "Frequency of " << element << " in range [" << l << ", " << r << "]: ";
    cout << wt.freqInRange(l, r, element) << endl;

    // Query 2: Find the k-th smallest element in range [l, r]
    int k = 3;
    cout << "The " << k << "-th smallest element in range [" << l << ", " << r << "]: ";
    cout << wt.kthSmallest(l, r, k) << endl;

    return 0;
}