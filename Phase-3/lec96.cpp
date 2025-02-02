// graph -> prim's algorithm

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;


vector<pair<pair<int,int>,int>> calculatePrimsMST(
    int n, int m, vector<pair<pair<int,int>, int>>&g){
    
    //create adj list
    unordered_map<int, list<pair<int,int>>> adj;

    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1,INT_MAX);   // will store the minimum distance
    vector<bool> mst(n+1,false);     // to check if the node is visisted or not
    vector<int> parent(n+1,-1);     // to mark and update the parents while traversing through all node

    //algo
    key[1]=0;
    parent[1]=-1;

    for(int i=1; i<n; i++){
        int mini = INT_MAX;  // minimum lenght of that u below
        int u;     // the minimum node that is still false in mst means not traverse

        for(int v=1; v<=n;v++){
            if(mst[v]== false && key[v]<mini){
                u=v;
                mini = key[v];
            }
        }

        // mark mini node as true;
        mst[u]=true;
        for(auto it: adj[u]){   // checking the neighbour
            int v = it.first;
            int w = it.second;
            if(mst[v]== false && w<key[v]){  // if found a shorted part
                key[v]=w;
                parent[v]=u;
            }        
        }
    }

    vector<pair<pair<int,int>, int>> result;
    for(int i=2; i<=n; i++){
        result.push_back(make_pair(make_pair(parent[i],i),key[i]));  
    }

    return result;
}


int main()
{
    // (pending)HW -> use min heap to find the minimum value
    // (pending)HW -> dry run
    // (pending)HW -> can you decrease the data structure used and compress the code?
    


    return 0;
}