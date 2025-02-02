//dp-11

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(int n){
    //base case
    if(n==0){
        return 0;
    }

    int ans = n; //all one
    for(int i=1; i*i<=n; i++){
        ans=min(ans, 1+solve(n-i*i));
    }

    return ans;
}


int solveMem(int n, vector<int>&dp){
    //base case
    if(n==0){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int ans = n; //all one
    for(int i=1; i*i<=n; i++){
        ans=min(ans, 1+solveMem(n-i*i,dp));
    }

    dp[n]=ans;

    return dp[n];
}


int MinSquares(int n){
    // return solve(n);

    vector<int> dp(n+1,-1);
    return solveMem(n,dp); 
}

int solveTab(int n){
    //base case
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j*j<=n; j++){
            if(i-j*j >=0)
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
    }

    return dp[n];
}

int main()
{	CLEAR;

    //minimum number of perfect square to form a number

    cout<<MinSquares(100)<<endl;
    cout<<solveTab(100)<<endl;
    
    return 0;
}