// dp-21

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

long long solve(int dice, int faces, int target){
    //base case

    if(target<0){
        return 0;
    }

    if(dice==0 && target!=0){
        return 0;
    }

    if(target == 0 && dice!=0){
        return 0;
    }

    if(target ==0 && dice==0){
        return 1;
    }

    long long int ans =0;
    for(int i=1; i<=faces; i++){
        ans = ans + solve(dice-1,faces,target-i);
    }

    return ans;
}

long long solveMem(int dice, int faces, int target, vector<vector<long long int>>&dp){
    //base case

    if(target<0){
        return 0;
    }

    if(dice==0 && target!=0){
        return 0;
    }

    if(target == 0 && dice!=0){
        return 0;
    }

    if(target ==0 && dice==0){
        return 1;
    }

    if(dp[dice][target]!=-1){
        return dp[dice][target];
    }

    long long int ans =0;
    for(int i=1; i<=faces; i++){
        ans = ans + solveMem(dice-1,faces,target-i,dp);
    }
    return dp[dice][target] = ans;
    
}

long long noOfWays(int M, int N, int X){
    // return solve(N,M,X);
    
    vector<vector<long long int>> dp(N+1,vector<long long int>(X+1,-1));
    return solveMem(N,M,X,dp);
}

long long int solveTab(int M, int N, int X){
    vector<vector<long long int>> dp(N+1,vector<long long int>(X+1,0));
    dp[0][0]=1;

    for(int dice=1; dice <= N; dice++){
        for(int target=1; target <= X; target++){
            long long int ans=0;
            for(int i=1; i<=M; i++){
                if(target-i>=0)
                ans += dp[dice-1][target-i];
            }
            dp[dice][target]=ans;
        }
    }
    return dp[N][X];
}

long long int solveTab_optimized(int M, int N, int X){
    vector<long long> curr(X+1,0);
    vector<long long> prev(X+1,0);

    prev[0]=1;

    for(int dice=1; dice <= N; dice++){
        for(int target=1; target <= X; target++){
            long long int ans=0;
            for(int i=1; i<=M; i++){
                if(target-i>=0)
                ans += prev[target-i];
            }
            curr[target]=ans;
        }
        prev=curr;
    }
    return prev[X];
}

int main()
{	CLEAR;

    cout<<noOfWays(6,3,12)<<endl;
    cout<<solveTab(6,3,12)<<endl;
    cout<<solveTab_optimized(6,3,12)<<endl;
    
    return 0;
}