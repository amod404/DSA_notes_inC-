//dp-12

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(int n, vector<int>& days, vector<int>& cost, int index){

    //base case
    if(index>=n){
        return 0;
    }
    
    int option1=cost[0]+solve(n,days,cost,index+1);
    
    int i;
    for(int i=index; i<n && days[i]<days[index]+7; i++){};

    int option2=cost[1]+solve(n,days,cost,i);
    
    for(int i=index; i<n&& days[i]<days[index]+30; i++){};

    int option3=cost[2]+solve(n,days,cost,i);

    return min(option1,min(option2,option3));
}

int solveMem(int n, vector<int>& days, vector<int>& cost, int index, vector<int>& dp){

    //base case
    if(index>=n){
        return 0;
    }
    
    if(dp[index]!=-1){
        return dp[index];
    }

    int option1=cost[0]+solveMem(n,days,cost,index+1,dp);
    
    int i;
    for(i=index; i<n && days[i]<days[index]+7; i++){};

    int option2=cost[1]+solveMem(n,days,cost,i,dp);
    
    for(i=index; i<n && days[i]<days[index]+30; i++){};

    int option3=cost[2]+solveMem(n,days,cost,i,dp);

    dp[index]=min(option1,min(option2,option3));

    return dp[index];

}


int solveTab(vector<int> &days, vector<int>&cost){
    int n=days.size(); 
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;

    for(int index=n-1; index>=0; index--){
       int option1 = cost[0]+dp[index+1];

       int i;
       for(i=index; i<n && days[i]<days[index]+7;i++);
       int option2 = cost[1]+dp[i];
       
       for(i=index; i<n && days[i]<days[index]+30;i++);
       int option3 = cost[2]+dp[i];

       dp[index]=min(option1,min(option2,option3));
    }

    return dp[0];
}

int minimumCoins(vector<int> &days, vector<int>& cost){
    // return solve(n,days,cost,0);

    int n=days.size();

    vector<int> dp(n+1,-1);
    return solveMem(n,days,cost,0,dp);
}

int main()
{	CLEAR;

    // minimum cost for ticket
    vector<int> days={1,3,4,5,7,8,10};
    vector<int> cost={2,7,20};

    cout<<minimumCoins(days,cost)<<endl;
    cout<<solveTab(days,cost)<<endl;


    return 0;
}

//dpsce optimization (pending)