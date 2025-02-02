#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

vector<int> primes(int a, int b){

    vector<bool> isPrime(b+1,true);
    isPrime[0] = isPrime[1] = false;
    int count=0;
    vector<int>ans;

    for(int p=2; p*p<=b; p++){
        if(isPrime[p]){
            for(int j = p*p; j<=b; j+=p){
                isPrime[j]=false;
            }
        }
    }
    for(int i=a; i<=b; i++){
        if(isPrime[i]){
            ans.push_back(i);
        }
    }

    //can return count
    // return count;
    return ans;
}


int main()
{	CLEAR;

    int n=10,m=100;
    vector<int> ans = primes(n,m);
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;
    

    return 0;
}