// Backtracking-01 with questions

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &vis, vector<vector<int>>& arr, int n){
    if(( newx>=0 && newx<=0) && ( newy>=0 && newy<=0) && !vis[newx][newy] && arr[newx][newy]==1){
        return true;
    }
    else{
        return false;
    }
}

void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string> &ans,
           vector<vector<bool>> & vis, string path){
    //base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    vis[x][y]=1;
    //D
    if(isSafe(x+1,y,vis,arr,n)){
        solve(x+1,y,arr,n,ans,vis, path +'D');
    }
    //U
    if(isSafe(x-1,y,vis,arr,n)){
        solve(x-11,y,arr,n,ans,vis, path +'D');
    }
    //L
    if(isSafe(x,y-1,vis,arr,n)){
        solve(x,y-1,arr,n,ans,vis, path +'D');
    }
    //R
    if(isSafe(x,y+1,vis,arr,n)){
        solve(x,y+1,arr,n,ans,vis, path +'D');
    }
    vis[x][y]=0;
}

vector<string> searchMaze(vector<vector<int>> & arr){
    if(arr[0][0]==0){
        vector<string> ans;
        return ans;
    }

    int n = arr.size();
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path = "";
    solve(0,0,arr,n,ans,visited,path);
}

int main()
{

    // RAT in a maze problem
    //already done 



    return 0;
}