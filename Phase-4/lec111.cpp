//dp-10

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(vector<int>&num, int &n, int tar){

    if(tar<0){
        return 0;
    }

    if(tar==0){
        return 1;
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans+= solve(num, n, tar-num[i]);
    }

    return ans;
}


int solveMem(vector<int>&num, int &n, int tar,vector<int>&dp){

    if(tar<0){
        return 0;
    }

    if(tar==0){
        return 1;
    }

    if(dp[tar]!=-1){
        return dp[tar];
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans+=solveMem(num, n, tar-num[i],dp);
    }

    dp[tar]=ans;
    return dp[tar];
}

int findWays(vector<int>&num,int tar){
    // int n=num.size();
    // return solve(num,n,tar);

    vector<int> dp(tar+1,-1);
    int n= num.size();

    return solveMem(num,n,tar,dp);
}

int solveTab(vector<int>num, int tar){

    int n= num.size();
    vector<int> dp(tar+1,0);
    dp[0]=1;  //1 way to this
    
    //traversing tar 1 to tar
    for(int i=0; i<=tar; i++){

        //traversing on the num vector
        for(int j=0; j<n; j++){
            if(i-num[j] >= 0)
            dp[i]+=dp[i-num[j]];
        }

    }

    return dp[tar];
}

int main()
{	CLEAR;

    vector<int> num={1,2,5};

    cout<<findWays(num,5)<<endl;
    cout<<solveTab(num,5)<<endl;



    return 0;
}