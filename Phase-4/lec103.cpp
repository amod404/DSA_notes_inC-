//dynamic programming-03

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

int solve4(vector<int>&cost,int n){
    //tabulation
    int prev2=cost[0];
    int prev1=cost[1];

    for(int i=2; i<n; i++){
        int curr = cost[i]+ min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
}

int solve3(vector<int>&cost,int n){
    //tabulation
    vector<int> dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2; i<n; i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }

    return min(dp[n-1],dp[n-2]);
}

int solve(vector<int>&cost, int n,vector<int>&dp){
    //memoization
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]= cost[n] + min(solve(cost, n-1,dp),solve(cost,n-2,dp));
    return dp[n];
}

int minCost(vector<int>&cost){
    int n=cost.size();
    vector<int> dp(n+1,-1);
    int ans = min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return ans;
}

int main()
{

    // //number of distint way to climb stairsin 1 or 2steps
    // //noting but fibo
// 
    // int n;
    // cin>>n;
// 
    // if(n==1){
    //     cout<<1<<endl;
    //     return 0;
    // }
// 
    // int prev1=1;
    // int prev2=2;
// 
    // for(int i=3; i<=n; i++){
    //     int curr=prev1+prev2;
    //     prev1=prev2;
    //     prev2=curr;
    // }
    // 
    // cout<<prev2<<endl;


    //min cost climbing

    vector<int> cost={2,100,1,1,2,3,1,1,2,1,1};
    int n= cost.size();

    cout<<solve3(cost,n)<<endl;
    cout<<solve4(cost,n)<<endl;
    cout<<minCost(cost)<<endl;
    

    return 0;
}