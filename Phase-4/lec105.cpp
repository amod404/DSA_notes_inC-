//dp-04

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

void maxSum_helper(vector<int>&arr,int i, int &n, int currSum, int& ans){
    if(i>=n){
        ans=max(ans,currSum);
        return;
    }

    //include
    maxSum_helper(arr,i+2,n,currSum+arr[i],ans);

    //exclude
    maxSum_helper(arr,i+1,n,currSum,ans);
}

int solveMem(vector<int> &nums, int n , vector<int>&dp){
    //base csae
    if(n<0)
    return 0;
    if(n==0)
    return nums[0];

    if(dp[n]!=-1){
        return dp[n];
    }

    int incl = solveMem(nums, n-2,dp)+nums[n];
    int excl = solveMem(nums, n-1,dp)+0;

    dp[n]= max(incl,excl);

    return dp[n];
}

int solveTab(vector<int>&nums){
    int n = nums.size();
    vector<int> dp(n,0);

    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);

    for(int i=2;i<n; i++){
        int incl=dp[i-2]+nums[i];
        int excl=dp[i-1]+0;
        dp[i]=max(incl,excl);
    }

    return dp[n-1];
}

int solveTab_optimized(vector<int>&nums){
    int n = nums.size();

    int prev2=0;
    int prev1=nums[0];

    for(int i=1;i<n; i++){
        int incl=prev2+nums[i];
        int excl=prev1+0;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}

int maxSUM(vector<int>&arr){
    // int index=0;
    // int n=arr.size();
    // int currSum=0;
    // int ans=0;
    // maxSum_helper(arr,index,n,currSum,ans);
    // return ans;

    int n=arr.size();
    vector<int> dp(n,-1);
    solveMem(arr,n-1,dp);
    return dp[n-1];
}

int main()
{
    //maximum sum of non-adjacent elements
    vector<int> arr={9,2,7,8};
    cout<<maxSUM(arr)<<endl;
    cout<<solveTab(arr)<<endl;
    cout<<solveTab_optimized(arr)<<endl;



    return 0;
}