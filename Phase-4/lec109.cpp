//dp-08

#include<bits/stdc++.h>
#define CLEAR system("cls")
#define MOD 1000000007
using namespace std;

int add(int a, int b){
    return (a%MOD +b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD) * 1LL * (b%MOD))%MOD;
}

int solve(int n, int &k){
    ///base case
    if(n==1){
        return k;;
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }

    // ans = solve(n-2)*(k-1) + solve(n-1)*(k-1)
    int ans = add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}

int solveMem(int n, int &k, vector<int> &dp){
    ///base case
    if(n==1){
        return k;;
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1));
    return dp[n];
}

int solveTab(int n, int k){
    vector<int> dp(n+1,0);

    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));

    for(int i=3; i<=n; i++){
        dp[n]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }

    return dp[n];
}


int solveTab_optimized(int n, int k){

    int prev2=k;
    int prev1=add(k,mul(k,k-1));

    for(int i=3; i<=n; i++){
        int ans = add(mul(prev2,k-1),mul(prev1,k-1));
        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}



int numberOfWays(int n, int k){
    // return solve(n,k);

    vector<int>dp(n+1,-1);
    return solveMem(n,k,dp);
}


int main()
{	CLEAR;

    // Paniting Fence algorithm 
    // N-posts and K-colors
    // last two post have same colour : solve(n-2)*(k-1)
    // last two post have different colour : solve(n-1)*(k-1)
    cout<<numberOfWays(3,3)<<endl;
    cout<<solveTab(3,3)<<endl;
    cout<<solveTab_optimized(3,3)<<endl;


    return 0;
}