// backtracking - 02  the N-queen problem

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

void addSolution(vector<vector<int>> & ans, vector<vector<int>> & board,int n){
    vector<int> temp;
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row,int col, vector<vector<int>> & board, int n ){
    int x= row;
    int y= col;
    // check for row...(only left side)
    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
    }
    // no need to check for col
    // check for diagnol
    x = row;
    y = col;
    while(y>=0 && x>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
        x--;
    }

    x = row;
    y = col;
    while(y>=0 && x<n){
        if(board[x][y]==1){
            return false;
        }
        y--;
        x++;
    }
    return true;
}

void solve(int col, vector<vector<int>> & ans, vector<vector<int>> & board, int &n){
    // base case
    if(col==n){
        addSolution(ans, board, n);
        return;
    }

    //solve 1 case
    for(int row = 0; row<n;row ++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            solve(col+1,ans,board,n);
            //backtrack
            board[row][col]=0;
        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0,ans,board,n);
    return ans;
}

int main()
{

    vector<vector<int>> ans = nQueens(10);
    for(auto i: ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }

    // TC-> O(N!)
    // SC-> O(N^2)

    //(pending)HW-> optimize the isSafe function using hashmap
    //(pending)HW-> write without cpy, using row traversal and column calling
    
    return 0;
}

