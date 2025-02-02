//prime factor

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
using namespace std;


#include <iostream>
#include <vector>
using namespace std;

#define MAXN 10001
vector<int> spf(MAXN + 1, 1);

// Calculating SPF (Smallest Prime Factor) for every number till MAXN.
void sieve() {
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { // If the number is prime
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j] == 1) // Update SPF for multiples
                    spf[j] = i;
            }
        }
    }
}

// Function returning prime factorization
void getFactorization(vector<int>&ret,int x) {
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return;
}


// .........................................................................//


//for a number O(n*root(n))
void findPrimeFactor(vector<int>&ans,int n){
    
    //search till root(n)
    for(int i=2; i*i<=n; i++){

        while(n%i==0){
            ans.push_back(i);
            n=n/i;
        }
    }

    //check if last number is remained a prime number
    if(n!=1){
        ans.push_back(n);
    }
}

int main()
{
    sieve();

    // Input range
    int low, high;
    cout << "Enter range (low high): ";
    cin >> low >> high;

    // Find prime factorizations for all numbers in the range
    for (int i = low; i <= high; i++) {
        vector<int> factors;
        getFactorization(factors,i);
        cout << "Prime factors of " << i << ": ";
        for (int f : factors) {
            cout << f << " ";
        }
        cout << endl;
    }


    return 0;
}
