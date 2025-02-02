// graph - Kosaraju's Algorithm

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


void dfs(int node, unordered_map<int, bool> & vis,
stack<int> & st, unordered_map<int, list<int>> &adj){

    vis[node]=true;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr,vis,st,adj);
        }
    }

    //in return push in stack
    st.push(node);
}

void revDfs(int node, unordered_map<int,bool> & vis,
            unordered_map<int, list<int>> & adj){
    vis[node] = true;

    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            revDfs(nbr,vis,adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> & edges){
    
    //adj list
    //transpose grap
    unordered_map<int, list<int>>adj;
    unordered_map<int,list<int>> transpose;
    for(int i=0; i<edges.size(); i++){
        int u= edges[i][0];
        int v= edges[i][1];
        adj[u].push_back(v);
        transpose[v].push_back(u);
    }
    
    //toposort
    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    
    // initialize visited array
    for(int i=0; i<edges.size(); i++){
        vis[i]=false;
    }

    //dfs call using transpose 
    int cnt=0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            cnt++; // as this loop will only seperate the components
            revDfs(top,vis,transpose);
        }
    }
    return cnt;
}


int main()
{

    



    return 0;
}