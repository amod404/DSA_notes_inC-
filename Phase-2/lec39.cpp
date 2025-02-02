//recursion-09   (permutation in an array/string)

#include<iostream>
#include<vector>
#include<string>
using namespace  std;

void solve(vector<int> num,int index, vector<vector<int>> &ans){
    if(index==num.size()){
        ans.push_back(num);
        return;
    }

    for(int i=index;i<num.size();i++){
            swap(num[index],num[i]);
            solve(num,index+1,ans);
            //backtrack
            swap(num[index],num[i]);
    }
}

vector<vector<int>> permutation(vector<int> & num){
    int index=0;
    vector<vector<int>>ans;
    solve(num,index,ans);
    for(int i=0;i<ans.size()-1;i++){
        for(int j=i+1;j<ans.size()-1;j++){
            if(ans[i]==ans[j]){
                ans.erase(ans.begin()+j);
            }     
        }
    }
    return ans;
}

int main()
{
    vector<int> num={1,1,2,3};
    vector<vector<int>> ans;
    ans=permutation(num);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }cout<<endl;
    }
    return 0;
}

