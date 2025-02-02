//dp-09 (2D dp).....it means n^2 space not 2*n space

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(vector<int>& weight, vector<int> &value, int index, int W){
    //going last to first...right to left
    if(index==0){
        if( weight[0] <= W){
            return value[0];
        }
        else{
            return 0;
        }
    }

    int include=0;
    if(weight[index]<=W){
        include = value[index] +  solve(weight,value,index-1,W-weight[index]);
    }

    int exclude=solve(weight,value,index-1,W);

    return max(include,exclude);
}



int solveMem(vector<int>& weight, vector<int> &value, int index, int W, vector<vector<int>>dp){
    //going last to first...right to left
    if(index==0){
        if( weight[0] <= W){
            return value[0];
        }
        else{
            return 0;
        }
    }

    if(dp[index][W]!=-1){
        return dp[index][W];
    }

    int include=0;
    if(weight[index]<=W){
        include = value[index] +  solveMem(weight,value,index-1,W-weight[index],dp);
    }

    int exclude=solveMem(weight,value,index-1,W,dp);

    dp[index][W]=max(include,exclude);
    return dp[index][W];
}


int knapsack(vector<int> weight, vector<int> value, int maxWeight){
    // int n=value.size();
    // return solve(weight,value,n-1,maxWeight);

    int n=value.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight+1,-1));
    return solveMem(weight,value,n-1,maxWeight,dp);
}

int solveTab(vector<int> weight, vector<int> value,int capacity){
    //step1
    int n= value.size();
    vector<vector<int>> dp(n,vector<int>(capacity,0));

    //step2
    for(int w=weight[0];w<=capacity; w++){
        if(weight[0]<=capacity){
            dp[0][w]=value[0];
        }
    }

    //step3 take care of remaining recursivw call
    for(int index=1; index<n; index++){
        for(int w=0; w<=capacity; w++){

            int include=0;
            if(weight[index]<=w){
                include = value[index] +  dp[index-1][w-weight[index]];
            }
            
            int exclude=dp[index-1][w];

            dp[index][w] = max(include,exclude);
        }
    }
    return dp[n-1][capacity];
}



// space optimization can be done for index as it is depending on previous index....so make two vector curr and prev
int solveTab_optimized(vector<int> weight, vector<int> value,int capacity){
    //step1
    int n= value.size();
    vector<int> prev(capacity+1,0);
    vector<int> curr(capacity+1,0);
    
    //step2
    for(int w=weight[0];w<=capacity; w++){
        if(weight[0]<=capacity){
            prev[w]=value[0];
        }
    }

    //step3 take care of remaining recursivw call
    for(int index=1; index<n; index++){
        for(int w=0; w<=capacity; w++){

            int include=0;
            if(weight[index]<=w){
                include = value[index] +  prev[w-weight[index]];
            }
            
            int exclude=prev[w];

            curr[w] = max(include,exclude);
        }

        prev=curr;
    }

    return prev[capacity];
}

int main()
{	CLEAR;

    //Knapsack Problem
    // find maximum value with constrainted weight
    vector<int> weight={1,2,4,5};
    vector<int> value={5,4,8,6};
    int maxWeight=5;

    cout<<knapsack(weight,value,maxWeight)<<endl;
    cout<<solveTab(weight,value,maxWeight)<<endl;
    cout<<solveTab_optimized(weight,value,maxWeight)<<endl;

    //last optimization? (pending)

    return 0;
}