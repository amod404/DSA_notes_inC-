//dp-16

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(vector<int> & obs,int currLane, int pos,int &n){
    if(pos == n){
        return 0;
    }

    if(obs[pos+1] != currLane){
        return solve(obs, currLane, pos+1,n);
    }
    else{

        int ans = INT_MAX;
        for(int i=1; i<=3; i++){
            if(i!=currLane && obs[pos]!=i) 
            ans=min(ans, 1+solve(obs,i,pos,n));
        }
        return ans;
    }
}


int solveMem(vector<int> & obs,int currLane, int pos,int &n,vector<vector<int>>&dp){
    if(pos == n){
        return 0;
    }

    if(dp[currLane][pos]!=-1){
        return dp[currLane][pos];
    }

    if(obs[pos+1] != currLane){
        return solveMem(obs, currLane, pos+1,n,dp);
    }
    else{

        int ans = INT_MAX;
        for(int i=1; i<=3; i++){
            if(i!=currLane && obs[pos]!=i) 
            ans=min(ans, 1+solveMem(obs,i,pos,n,dp));
        }
        dp[currLane][pos]=ans;
        return dp[currLane][pos];
    }
}

int minSideJumps(vector<int> & obstacles){
    // int n= obstacles.size();
    // return solve(obstacles,2,0,n);

    int n=obstacles.size();
    vector<vector<int>> dp(4,vector<int> (n,-1));
    return solveMem(obstacles,2,0,n,dp);
}

int solveTab(vector<int>&obs){
    int n=obs.size();
    vector<vector<int>> dp(4,vector<int>(n+1,1e9));

    dp[0][n]=0;
    dp[1][n]=0;
    dp[2][n]=0;
    dp[3][n]=0;

    for(int pos=n-1; pos>=0; pos--){
        for(int currLane = 1; currLane<=3; currLane++){ //why this extra loop?
            
            if(obs[pos+1] != currLane){
                dp[currLane][pos] = dp[currLane][pos+1];
            }
            else{
                int ans = 1e9;
                for(int i=1; i<=3; i++){
                    if(currLane!=i && obs[pos]!=i){
                        ans = min(ans, 1+dp[i][pos+1]);
                    }
                }
                dp[currLane][pos]=ans;
            }
        }
    }

    return min(dp[2][0], min(1+dp[1][0],1+dp[3][0]));
}

int solveTab_optimized(vector<int>&obs){
    int n=obs.size();
    vector<int> curr(4,1e9);
    vector<int> next(4,0);

    for(int pos=n-1; pos>=0; pos--){
        for(int currLane = 1; currLane<=3; currLane++){ //why this extra loop?
            
            if(obs[pos+1] != currLane){
                curr[currLane] = next[currLane];
            }
            else{
                int ans = 1e9;
                for(int i=1; i<=3; i++){
                    if(currLane!=i && obs[pos]!=i){
                        ans = min(ans, 1+next[i]);
                    }
                }
                curr[currLane]=ans;
            }

        }
        next=curr;
    }

    return min(next[2], min(1+next[1],1+next[3]));
}

int main()
{	CLEAR;

    vector<int> obstacles={0,1,2,3,0};

    cout<<minSideJumps(obstacles)<<endl;
    cout<<solveTab(obstacles)<<endl;
    cout<<solveTab_optimized(obstacles)<<endl;


    return 0;
}   