#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    void KNP(string s,int k,set<int>&present){
        vector<int>lps(s.size(),0);

        for(int i=1; i<s.size(); i++){
            int prev_ind = lps[i-1];

            while(prev_ind>0 && s[prev_ind] != s[i]){
                prev_ind = lps[prev_ind-1];
            }

            lps[i] = prev_ind + (s[i]==s[prev_ind] ? 1 : 0);
            if(lps[i]==k){
                present.insert(i-2*k);
            }
        }
    }

    bool solve(string&s,int& m,int& n,int index, vector<set<int>>&present, vector<int>&size, vector<int>&dp){
        
        if(index==m){
            return true;
        }
        else if(index>m){
            return false;
        }

        if(dp[index]!=-1){
            return dp[index]==1 ? true : false;
        }


        bool flag = false;
        for(int i=0; i<n; i++){
            if(!present[i].empty()){

                auto it = present[i].lower_bound(index);

                if(it != present[i].end() && *it == index){
                    flag = flag | solve(s,m,n,index+size[i],present,size,dp);
                }
            }

            if(flag){
                dp[index]=1;
                return flag;
            }
        }


        dp[index] = flag == true ? 1:0;
        return flag;
    }

    int wordBreak(int n, string s, vector<string>&dictionary){
        //code here
        int m = s.length();
        vector<set<int>>present(n);
        for(int i=0; i<n; i++){
            KNP(dictionary[i]+"#"+s,dictionary[i].size(),present[i]);
        }

        vector<int>size(n);
        for(int i=0; i<n; i++){
            size[i] = dictionary[i].size();
        }
        vector<int>dp(m+1,-1);

        return solve(s,m,n,0,present,size,dp) ? 1 : 0;
    }
};