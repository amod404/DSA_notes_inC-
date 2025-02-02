//dp-07

#include<bits/stdc++.h>
#define CLEAR system("cls")
#define MOD 1000000007
using namespace std;

long long int solve(int n , vector<long long int>&dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = (((n-1)%MOD)*(((solve(n-2,dp)%MOD)+(solve(n-1,dp)%MOD))%MOD))%MOD;
    return dp[n];
}

long long int countDerangements(int n){
    vector<long long int> dp(n+1,-1);
    return solve(n,dp);
}

long long int solveTab(int n){
    vector<long long int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;

    for(int i=3; i<=n; i++){
        long long int first=dp[i-1]%MOD;
        long long int second=dp[i-2]%MOD;

        long long int sum=(first+second)%MOD;

        long long int ans=(((i-1)%MOD)*sum)%MOD;
        dp[i]=ans;
    }

    return dp[n];
}


long long int solveTab_optimized(int n){
    long long int prev1=1;
    long long int prev2=0;

    for(int i=3; i<=n; i++){

        long long int sum=(prev1%MOD+prev2%MOD)%MOD;

        long long int ans=(((i-1)%MOD)*sum)%MOD;
        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}

int main()
{	CLEAR;

    // count number of dearrangements, take modulus with 10^9+7
    // array will be in the form of..n=7 means {0,1,2,3,4,5,6}
    int n;
    cin>>n;
    cout<<countDerangements(n)<<endl;
    cout<<solveTab(n)<<endl;
     


    return 0;
}