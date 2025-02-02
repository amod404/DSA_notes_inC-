//dp-19

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

bool check(vector<int>&base,vector<int>&newBox){
    if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2]){
        return true;
    }
    return false;
}

int solveTab(int n, vector<vector<int>>& a){
    vector<int> currRow(n+1,0);
    vector<int> nextRow(n+1,0);

    for(int curr = n-1 ; curr>=0; curr--){
        for(int prev = curr-1; prev>=-1; prev--){
            int take=0;
            if(prev==-1 || check(a[curr],a[prev])){
                take = a[curr][2] + nextRow[curr+1];  // curr +1 because it is prav and we have to adjust pre by +1
            }

            int notTake = 0 + nextRow[prev+1];

            currRow[prev+1]=max(take,notTake);
        }
        nextRow=currRow;
    }
    return nextRow[0];
}


int maxHeight(vector<vector<int>>& cuboids){

    for(auto &a:cuboids){
        sort(a.begin(),a.end());
    }

    sort(cuboids.begin(),cuboids.end());

    return solveTab(cuboids.size(),cuboids);
}

int main()
{	CLEAR;

    vector<vector<int>> cuboids = { {20,50,45},
                                    {45,12,23}, 
                                    {53,37,95}, 
                                };
    
    cout<<maxHeight(cuboids)<<endl;


    return 0;
}