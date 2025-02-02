// graph--> DFS(depth first search)

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

void prepareAdjList(unordered_map<int,list<int>> &adjList, vector<vector<int>>& edges,int &E){
    //here n is number of edges
    for(int i=0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(int node, unordered_map<int,bool> &visited, 
        unordered_map<int,list<int>> &adj, vector<int> &component){
    component.push_back(node);
    visited[node]=true;

    //hr connected node k liye recursive call
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> & edges){

    unordered_map<int,list<int>> adj;
    prepareAdjList(adj,edges,E);
    
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;


    //this is to cover all disconnected component
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;

}

int main()
{

    vector<vector<int>> edges={{0,1},
                                {1,2},
                                {2,3},
                                {3,4},
                                {4,5},
                                {5,1},
                                };
    vector<vector<int>>ans;
    ans = depthFirstSearch(6,6,edges);

    for(int i=0; i<ans.size();i++){
        for(int j= 0; j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
    }


    return 0;
}