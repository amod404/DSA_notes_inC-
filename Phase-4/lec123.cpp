//dp-22

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(int index, vector<int> &arr, int n, int target){

    if(target==0){
        return 1;
    }
    if(index>=n || target<0){
        return 0;
    }

    //include
    int incl = solve(index+1,arr,n, target-arr[index]);

    if(incl) return 1;

    //exclude
    int excl = solve(index+1, arr, n, target-0);

    return excl;

}

int solveMem(int index, vector<int> &arr, int n, int target,vector<vector<int>>& dp){

    if(target==0){
        return 1;
    }
    if(index>=n || target<0){
        return 0;
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    //include
    int incl = solveMem(index+1,arr,n, target-arr[index],dp);

    //exclude
    int excl = solveMem(index+1, arr, n, target-0,dp);

    dp[index][target] = incl || excl;

    return dp[index][target];
}


int equalPartition(int n, vector<int>arr){

    long long int total=0;
    for(int i=0; i<n; i++){
        total+=arr[i];
    }

    if(total & 1){
        return 0;
    }

    int target=total/2;
    // return solve(0,arr,n,target);
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    return solveMem(0,arr,n,target,dp);
}

bool solveTab(int n, vector<int>arr){
    long long int total=0;
    for(int i=0; i<n; i++){
        total+=arr[i];
    }
    if(total & 1){
        return 0;
    }
    int t=total/2;
    vector<vector<bool>> dp(n+1,vector<bool>(t+1,0));

    for(int i=0; i<=n; i++){
        dp[i][0]=true;
    }

    for(int index=n-1; index>=0; index--){
        for(int target = 0; target<=t; target++){

            bool incl=false;
            if(target - arr[index]>=0)
                incl = dp[index+1][target-arr[index]];

            bool excl = dp[index+1][target-0];

            dp[index][target] = incl || excl;
        }
    }
    return dp[0][t];
}

int solveTab_optimized(int n, vector<int>arr){
    long long int total=0;
    for(int i=0; i<n; i++){
        total+=arr[i];
    }
    if(total & 1){
        return 0;
    }
    int t=total/2;

    vector<int>curr(t+1,0);
    vector<int>next(t+1,0);

    next[0]=1;
    curr[0]=1;

    for(int index=n-1; index>=0; index--){
        for(int target = t; target>=0; target--){

            if(target-arr[index]>=0)
            curr[target] = next[target-arr[index]]||
                                next[target-0];
            else{
                curr[target]=next[target];
            }

        }
        next = curr;
    }

    return next[t];
}

int main()
{	CLEAR;

    //two equal subsequencses
    // nothinf but..... a subsequence having sum total/2

    vector<int> arr1={1,5,11,5};
    vector<int> arr2={1,5,3};

    cout<<equalPartition(arr1.size(),arr1)<<" ";
    cout<<equalPartition(arr2.size(),arr2)<<endl;
    cout<<solveTab(arr1.size(),arr1)<<" ";
    cout<<solveTab(arr2.size(),arr2)<<endl;
    cout<<solveTab_optimized(arr1.size(),arr1)<<" ";
    cout<<solveTab_optimized(arr2.size(),arr2)<<endl;

    return 0;
}