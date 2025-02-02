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

int lcs(int i, int j, string& s1, string&s2,vector<vector<int>>&dp){
    if(i<0 || j<0){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int a = lcs(i-1,j,s1,s2,dp);
    int b = lcs(i,j-1,s1,s2,dp);
    int c = lcs(i-1,j-1,s1,s2,dp) + (s1[i]==s2[j]);

    dp[i][j] = max(a,max(b,c)); 
    return dp[i][j];
}

int main()
{

    string s1, s2;
    s1 = "abcde";
    s2 = "adcef";
    vector<vector<int>> dp (s1.length(),vector<int>(s2.length(),-1));
    cout<<lcs(s1.length()-1,s2.length()-1,s1,s2,dp)<<endl;



    return 0;
}