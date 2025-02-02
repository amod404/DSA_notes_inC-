//recursion-07 question(subeset/subsequence)

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string s,string output,int index,vector<string> &ans){
    // base case 
    if(index>=s.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(s,output,index+1,ans);
    //include
    output.push_back(s[index]);
    solve(s,output,index+1,ans);
}

vector<string> subsequence(string &s){
    vector<string> ans;
    string output;
    int index=0;
    solve(s,output,index,ans);
    return ans;
}

void sol(string &s, string output,int index,vector<string> &ans){
    //base case
    if(index==s.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    sol(s,output,index+1,ans);
    //include
    output.push_back(s[index]);
    sol(s,output,index+1,ans);
}
vector<string> Subs(string &s){
    vector<string> ans;
    string output;
    int index=0;
    sol(s,output,index,ans);
    return ans;
}
//solved myself

void solve(vector<int> v,vector<int> output,int index,vector<vector<int>> &ans){
    // base case 
    if(index==v.size()){
        //storing all the final answers
        ans.push_back(output);
        return;
    }
    //exclude
    solve(v,output,index+1,ans);
    //include
    output.push_back(v[index]);
    solve(v,output,index+1,ans);
}

vector<vector<int>> subset(vector<int>&v){
    vector<vector<int>> ans;
    vector<int>output;
    int index=0;
    solve(v,output,index,ans);
    return ans;
}

int main()
{
    //set of all subset is called power set-->2^n
    // vector<int>v={1,2,3,4}; 
    // vector<vector<int>> ans;
    // ans=subset(v); 

    // for(int i=0;i<ans.size()-1;i++){
    //     for(int j=i+1;j<ans.size();j++){
    //         if(ans[i].size()>ans[j].size()){
    //             swap(ans[i],ans[j]);
    //         }
    //     }
    // }

    // for(int i=0;i<ans.size();i++){
    //     cout<<"{ ";
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j];
    //         if(j<ans[i].size()-1){
    //             cout<<", ";
    //         }
    //     }
    //     cout<<" }"<<endl;
    // }

    //subsequence of a string
    // string s="abc"; 
    // vector<string> ans;
    // ans=subsequence(s); 

    // for(int i=0;i<ans.size()-1;i++){
    //     for(int j=i+1;j<ans.size();j++){
    //         if(ans[i].size()>ans[j].size()){
    //             swap(ans[i],ans[j]);
    //         }
    //     }
    // }

    // for(int j=0;j<ans.size();j++){
    //     cout<<ans[j]<<endl;
    // }

    //just practicing:
    // string s="abc";
    // vector<string> ans;
    // ans=Subs(s);

    // for(int i=0;i<ans.size()-1;i++){
    //     for(int j=i+1;j<ans.size();j++){
    //         if(ans[i].size()>ans[j].size()){
    //             swap(ans[i],ans[j]);
    //         }    
    //     }
    // }
    // for(int j=0;j<ans.size();j++){
    //     cout<<ans[j]<<endl;
    // }
    return 0;
}


