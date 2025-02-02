// recursion-10  (Rat in a maze problem)
//overall very f_ed up ques

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool is_present(vector<int>&v,int i){
    for(int j=0;j<v.size();j++){
        if(i==v[j]){
            return true;
        }
    }
    return false;
}

bool isSafe(vector<vector<int>> &m, vector<vector<int>> visited,int newx, int newy, int r, int c){
    // m at new x and y shouldnt be 0
    // visited at new x and y shouldnt be 1
    // the new x and y should not escape matrix
    if((newx>=0 && newx<r)&&(newy>=0 && newy<c) && visited[newx][newy]==0 && m[newx][newy]==1){
        return true;
    }
    else
        return false;
}

//recursive function
void solve(vector<vector<int>>&m,string path, int x, int y, int r ,int c, vector<vector<int>> visited,vector<string>&ans){
    //base case when mouse reach the position
    if(x==r-1 && y==c-1){
        ans.push_back(path);  // have to store the path in our ans
        return;
    }

    //marking during run
    visited[x][y]=1;

    //down
    int newx=x+1;
    int newy=y;
    if(isSafe(m,visited,newx,newy,r,c)){
        path.push_back('D');    //store our dirextion during run
        solve(m,path,newx,newy,r,c,visited,ans);
        //backtracking
        path.pop_back();        //remove the direction during return
    }
    
    //up
    newx=x-1;
    newy=y;
    if(isSafe(m,visited,newx,newy,r,c)){
        path.push_back('U');
        solve(m,path,newx,newy,r,c,visited,ans);
        path.pop_back();
    }

    //right
    newx=x;
    newy=y+1;
    if(isSafe(m,visited,newx,newy,r,c)){
        path.push_back('R');
        solve(m,path,newx,newy,r,c,visited,ans);
        path.pop_back();
    }

    //left
    newx=x;
    newy=y-1;
    if(isSafe(m,visited,newx,newy,r,c)){
        path.push_back('L');
        solve(m,path,newx,newy,r,c,visited,ans);
        path.pop_back();
    }

    // demarking during return 
    visited[x][y]=0;
}
//Helper function
vector<string> maze_(vector<vector<int>>&m){
    int r=m.size();
    int c=m[0].size();
    vector<string> ans;  //final answer
    //base case
    if(m[0][0]==0){
        return ans;
    }
    //making a visited 2-D array of same dimension
    vector<vector<int>> visited=m;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            visited[i][j]=0;
        }
    }
    int srcx=0,srcy=0;
    string path="";   //outputs of various path
    solve(m,path,srcx,srcy,r,c,visited,ans);
    return ans;
}

int main()
{
    int r,c;
    cout<<"enter rows: ";
    cin>>r;
    cout<<"enter columns: ";
    cin>>c;
    cout<<endl;
    vector<vector<int>> maze;
    //taking input
    for(int i=0;i<r;i++){
        vector<int> v;
        for(int j=0;j<c;j++){
            int t;
            cin>>t;
            v.push_back(t);
        }
        maze.push_back(v);
    }

    vector<string> ans=maze_(maze);
    //marking shortest paths
    vector<int> shortest;
    int minIndex=0;
    shortest.push_back(minIndex);
    for(int i=1;i<ans.size()-1;i++){
        if(ans[i].length()<ans[minIndex].length()){
            shortest.clear();
            shortest.push_back(i);
            minIndex=i;
        }
        else if(ans[i].length()==ans[minIndex].length()){
            shortest.push_back(i);
        }
    }

    //printing answers
    for(int i=0;i<ans.size();i++){
        if(is_present(shortest,i)){
            cout<<ans[i]<<" (shortest) "<<endl;
        }
        else{
            cout<<ans[i]<<endl;
        }
    }
    
    return 0;
}















//...............................................................................................
//waste

// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;
//
// bool solve(vector<vector<int>> &maze,int r, int c){
//     if(r==maze.size()-1 && c==maze.size()-1){
//         return 1;
//     }
//
//
//     if(maze[r+1][c] && r<maze.size()){
//         return solve(maze,r+1,c);
//     }
//     if(maze[r][c+1] && c<maze.size()){
//         return solve(maze,c,r+1);
//     }
//     else{
//         return false;
//     }
// }
//
// bool can_he(vector<vector<int>> &maze){
//     int n=maze.size()-1;
//     if(maze[0][0]==0 || maze[n][n]==0){
//         return 0;
//     }
//     int r=0,c=0;
//     return solve(maze,r,c);
// }
// int main()
// {
//     vector<vector<int>>maze={{1,0,0,0,0},{1,1,0,0,0},{1,1,0,0,0},{1,1,1,1,0},{0,0,1,1,1}};
//     cout<<can_he(maze)<<endl;
//     return 0;
// }


