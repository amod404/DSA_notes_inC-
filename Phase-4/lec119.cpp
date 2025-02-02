//dp-18

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(int n, int a[], int curr, int prev){
    //base case
    if(curr == n){
        return 0;
    }
    int take=0;
    if(prev == -1 || a[curr] > a[prev]){
        take = 1 + solve(n,a,curr+1,curr);
    }

    int notTake = 0 + solve(n,a,curr+1,prev);

    return max(take,notTake);
}

int solveMem(int n, int a[], int curr, int prev,vector<vector<int>>dp){
    //base case
    if(curr == n){
        return 0;
    }

    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }

    int take=0;
    if(prev == -1 || a[curr] > a[prev]){
        take = 1 + solveMem(n,a,curr+1,curr,dp);
    }

    int notTake = 0 + solveMem(n,a,curr+1,prev,dp);

    dp[curr][prev+1]=max(take,notTake);

    return dp[curr][prev+1];
}

int longestSubsequence(int n, int a[]){
    // return solve(n,a,0,-1);

    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // previous array is n+1, as indexing is from -1 to n-1...... -1 -> 0 and n-1 -> n 
    return solveMem(n,a,0,-1,dp);
}

int solveTab(int n, int a[]){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int curr = n-1 ; curr>=0; curr--){
        for(int prev = curr-1; prev>=-1; prev--){
            int take=0;
            if(prev==-1 || a[curr] > a[prev]){
                take = 1 + dp[curr+1][curr+1];  // curr +1 because it is prav and we have to adjust pre by +1
            }

            int notTake = 0 + dp[curr+1][prev+1];

            dp[curr][prev+1]=max(take,notTake);
        }
    }
    return dp[0][0];
}


int solveTab_optimized(int n, int a[]){
    vector<int> currRow(n+1,0);
    vector<int> nextRow(n+1,0);

    for(int curr = n-1 ; curr>=0; curr--){
        for(int prev = curr-1; prev>=-1; prev--){
            int take=0;
            if(prev==-1 || a[curr] > a[prev]){
                take = 1 + nextRow[curr+1];  // curr +1 because it is prav and we have to adjust pre by +1
            }

            int notTake = 0 + nextRow[prev+1];

            currRow[prev+1]=max(take,notTake);
        }
        nextRow=currRow;
    }
    return nextRow[0];
}

int solve_binary(int n, int a[]){
    if(n==0){
        return 0;
    }

    vector<int> ans;
    ans.push_back(a[0]);

    for(int i=1; i<n; i++){
        if(a[i]>ans.back()){
            ans.push_back(a[i]);
        }
        else{
            //find index of just bade index
            int index = lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();  //pointer arithematic
            ans[index] = a[i];
        }
    }
    
    return ans.size();
}


int maxEnvelopes(vector<vector<int>>&env){
    // we have to sort.....increaing width but decreasing height for same width 
    //ten use longest subsequence
    int n = env.size();

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(env[j][0] < env[i][0]){
                int temp0 = env[j][0];
                int temp1 = env[j][1];

                env[j][0]=env[i][0];
                env[j][1]=env[i][1];

                env[i][0]=temp0;
                env[i][1]=temp1;
            }
            
            if(env[j][0]==env[i][0]){
                if(env[j][1] > env[i][1]){
                    int temp0 = env[j][0];
                    int temp1 = env[j][1];

                    env[j][0]=env[i][0];
                    env[j][1]=env[i][1];

                    env[i][0]=temp0;
                    env[i][1]=temp1;
                }
            }

        }
    }

    int arr[n];

    for(int i=0; i<n; i++){
        arr[i]=env[i][1];
    }

    return solveTab_optimized(n,arr);
}

int main()
{	CLEAR;

    // int a[]={1,8,3,5,9,2};
    // int s = sizeof(a)/sizeof(int);
    // cout<<longestSubsequence(s,a)<<endl;
    // cout<<solveTab(s,a)<<endl;
    // cout<<solveTab_optimized(s,a)<<endl;
    // cout<<solve_binary(s,a)<<endl;

    vector<vector<int>>envelopes={{6,4},
                                  {5,4},        
                                  {2,3},        
                                  {6,7},        
                                };

    cout<<maxEnvelopes(envelopes)<<endl;
    
    return 0;
}
