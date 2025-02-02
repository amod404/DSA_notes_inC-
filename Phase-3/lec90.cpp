// topological sort for directed Acyclic graph

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

void topoSort(int node, unordered_map<int,bool> & visited,
        stack<int> &s, unordered_map<int,list<int>> & adj){
    visited[node]=true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited,s,adj);
        }
    }
    // during return
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> & edges, int n, int e){

    unordered_map<int,list<int>> adj;
    // imp : sometime it got TLE in unordered map, so you can use vector
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs topological sort until function for all component
    unordered_map<int,bool> visited;
    // can use stack... or just use a vector and reverse it
    stack<int>s;

    //to get hold of all the disconnected componenets
    for(int i=0; i<n; i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);    
        }
    }

    //store your ans in a vector to return
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{

    
    vector<vector<int>> edges={{0,1},
                                {1,2},
                                {1,3},
                                {2,4},
                                {2,5},
                            };

    vector<int> ans = topologicalSort(edges,6,5);      

    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;

    // again O(V+E);

    return 0;
}