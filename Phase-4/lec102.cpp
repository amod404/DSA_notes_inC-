//dynamic programming-01

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

int fibo_helper(int n, int*arr){
    //base case
    if(n==0 || n==1){
        return n;
    }

    if(arr[n]!=-1){
        return arr[n];
    }

    arr[n] = fibo_helper(n-1,arr)+fibo_helper(n-2,arr);
    return arr[n];
}

int fibo(int n){
    int arr[n+1];
    for(int i=0; i<=n; i++){
        arr[i]=-1;
    }
    return fibo_helper(n,arr);
}

int main()
{

    //dp is used where there is overlapping subproblem

    int n;

    // for(int i=0; i<10; i++){
    //     cin>>n;
    //     cout<<fibo(n)<<endl;
    // }


    // cin>>n;
    // vector<int> dp(n+1);
    // dp[1]=1;
    // dp[0]=0;

    // for(int i=2; i<=n; i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    // }

    // cout<<dp[n]<<endl;
    
    
    int n;
    cin>>n;
    int prev1=1;
    int prev2=0;

    for(int i=2; i<=n; i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }

    cout<<prev1<<endl;
    return 0;
}