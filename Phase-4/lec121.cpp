//dp-20

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(int index,vector<int>& slices, int n, int endindex){
    //base case
    if(n == 0 || index >= endindex){
        return 0;
    }

    int take = slices[index] + solve(index+2, slices, n-1,endindex);
    int notTake = 0 + solve(index+1,slices,n,endindex);

    return max(take, notTake);

}

int solveMem(int index,vector<int>& slices, int n, int endindex, vector<vector<int>>& dp){
    //base case
    if(n == 0 || index > endindex){
        return 0;
    }

    if(dp[index][n]!=-1){
        return dp[index][n];
    }

    int take = slices[index] + solveMem(index+2, slices, n-1,endindex,dp);
    int notTake = 0 + solveMem(index+1,slices,n,endindex,dp);

    dp[index][n] = max(take, notTake);
    return dp[index][n];
}


int maxSizeSlices(vector<int>& slices){
    // int k = slices.size();
    // int case1 = solve(0, slices, k/3,k-1);
    // int case2 = solve(1, slices, k/3,k);
    // return max(case1,case2);

    int k = slices.size();
    vector<vector<int>> dp1(k,vector<int>(k,-1));
    vector<vector<int>> dp2(k,vector<int>(k,-1));
    int case1 = solveMem(0,slices,k/3,k-2,dp1);
    int case2 = solveMem(1,slices,k/3,k-1,dp2);
    return max(case1,case2);
}

int solveTab(vector<int>& slices){
    int k = slices.size();
    vector<vector<int>> dp1(k+2, vector<int> (k,0));
    vector<vector<int>> dp2(k+2, vector<int> (k,0));

    for(int index = k-2; index >= 0; index--){
        for(int n = 1; n<= k/3; n++){

            int take = slices[index] + dp1[index+2][n-1];
            int notTake = 0 + dp1[index+1][n];
            dp1[index][n] = max(take,notTake);
        }
    }

    for(int index = k-1; index >= 1; index--){
        for(int n = 1; n<= k/3; n++){

            int take = slices[index] + dp2[index+2][n-1];
            int notTake = 0 + dp2[index+1][n];
            dp2[index][n] = max(take,notTake);
        }
    }

    return max(dp1[0][k/3], dp2[1][k/3]);
}

int solveTab_optimized(vector<int>& slices){
    int k = slices.size();

    vector<int>prev1(k+2,0);
    vector<int>curr1(k+2,0);
    vector<int>next1(k+2,0);

    vector<int>prev2(k+2,0);
    vector<int>curr2(k+2,0);
    vector<int>next2(k+2,0);

    for(int index = k-2; index >= 0; index--){
        for(int n = 1; n<= k/3; n++){

            int take = slices[index] + next1[n-1];
            int notTake = 0 + curr1[n];
            prev1[n] = max(take,notTake);
        }
        next1=curr1;
        curr1=prev1;
    }
    

    for(int index = k-1; index >= 1; index--){
        for(int n = 1; n<= k/3; n++){

            int take = slices[index] + next2[n-1];
            int notTake = 0 + curr2[n];
            prev2[n] = max(take,notTake);
        }
        next2=curr2;
        curr2=prev2;
    }

    return max(curr1[k/3], curr2[k/3]);
}

int main()
{	CLEAR;

    vector<int> pizza={9,5,1,7,8,4,4,5,5,8,7,7};

    cout<<maxSizeSlices(pizza)<<endl;
    cout<<solveTab(pizza)<<endl;
    cout<<solveTab_optimized(pizza)<<endl;

    return 0;
}