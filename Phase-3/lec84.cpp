// Backtracking-03...Sudoku solver

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> & board, int value,int n){
    
    for(int i=0;i<n;i++){
        //row check
        if(board[row][i]==value ||board[i][col]==value){
            return false;
        }
        //col check
        if(board[3*(row/3) +i/3][3*(col/3)+i%3]==1){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> & board){
    int n= board[0].size();

    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            //cell empty
            if(board[row][col]==0){
                for(int val = 1; val<=9; val++){
                    if(isSafe(row,col,board,val,n)){
                        board[row][col]=val;
                        //recursion call
                        bool possible = solve(board);
                        if(possible){
                            return true;
                        }
                        else{
                            //backtracking
                        }
                        board[row][col]=0;
                    }
                }
                //if didntwork for any value, then answer is not possible
                return false;
            }
        }
    }
}

void solveSudoku(vector<vector<int>>& sudoku){
    solve(sudoku);
}

int main()
{
    //TC---> O(9^m)... where m is number of empty space
    //SC--> O(81)---O(1)

    


    return 0;
}