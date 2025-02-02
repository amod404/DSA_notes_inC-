// dp-14

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(vector<vector<int>>& mat, int i, int j, int &maxi){
    if(i>=mat.size() || j>=mat[0].size()){
        return 0;
    }

    int right = solve(mat,i,j+1,maxi);
    int diagnol = solve(mat,i+1,j+1,maxi);
    int down =solve(mat,i+1,j,maxi);

    if(mat[i][j]==1){
        int ans = 1 + min(right, min(diagnol,down));
        maxi=max(maxi,ans);
        return ans; 
    }
    else{
        return 0;
    }
}

int solveMem(vector<vector<int>>& mat, int i, int j, int &maxi,vector<vector<int>>dp){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int right = solve(mat,i,j+1,maxi);
    int diagnol = solve(mat,i+1,j+1,maxi);
    int down = solve(mat,i+1,j,maxi);

    if(mat[i][j]==1){
        dp[i][j] = 1 + min(right, min(diagnol,down));
        maxi=max(maxi,dp[i][j]);
        return dp[i][j]; 
    }
    else{
        dp[i][j]=0;
        return dp[i][j];
    }
}

int maxSquare(vector<vector<int>> mat){
    // int maxi=0;
    // solve(mat,0,0,maxi);
    // return maxi;

    int n=mat.size();
    int m=mat[0].size();
    int maxi=0;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    solveMem(mat,0,0,maxi,dp);
    return maxi;
}

int solveTab(vector<vector<int>>&mat){
    int maxi=0;
    int row=mat.size();
    int col=mat[0].size();
    vector<vector<int>> dp(row+1,vector<int>(col+1,0));

    for(int i=row-1; i>=0; i--){

        for(int j=col-1;j>=0; j--){

            //wont go out of bound as we take row +1 and col+1 in our dp
            int right = dp[i][j+1];
            int diagnol = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(mat[i][j]==1){
                dp[i][j]= 1+ min(right,min(diagnol,down));
                maxi=max(maxi,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return maxi;
}

int solveTab_optimized(vector<vector<int>>&mat){
    int maxi=0;
    int row=mat.size();
    int col=mat[0].size();
    vector<int>curr(col+1,0);
    vector<int>next(col+1,0);

    for(int i=row-1; i>=0; i--){

        for(int j=col-1;j>=0; j--){

            //wont go out of bound as we take row +1 and col+1 in our dp
            int right = curr[j+1];
            int diagnol = next[j+1];
            int down = next[j];

            if(mat[i][j]==1){
                curr[j]= 1+ min(right,min(diagnol,down));
                maxi=max(maxi,curr[j]);
            }
            else{
                curr[j]=0;
            }
        }
        next=curr;
    }
    return maxi;
}


int main()
{	CLEAR;

    vector<vector<int>> mat={{1,1,1,0},
                             {1,1,1,1},
                             {0,1,1,1},
                             {0,1,1,0}
                            };    

    cout<<maxSquare(mat)<<endl;
    cout<<solveTab(mat)<<endl;
    cout<<solveTab_optimized(mat)<<endl;

    return 0;
}