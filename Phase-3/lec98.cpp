// graph - bridges

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

void dfs(int node, int parent, int &timer, vector<int> &disc,
        vector<int> &low, vector<vector<int>> &result, 
        unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis){
        
    vis[node]=true;
    disc[node] = low[node] = timer++;    

    for(auto nbr : adj[node]){
        if(nbr == parent){
            continue;
        }
        //not parent and...
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            //return time
            low[node] = min(low[node],low[nbr]);  // this is to fix the possible low time if back edge present
            // check edge is bridge
            if(low[nbr]> disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }

        }
        else{
            // visited and also not parent, means cycle exist
            //back edge
            low[node] = min(low[node], disc[nbr]);
        }

    }
    

}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e){
    //adj list
    unordered_map<int,list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer =0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent=-1;
    unordered_map<int,bool> vis;

    for(int i=0; i<v; i++){
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;
    //dfs
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }
}

int main()
{

    // the edge whose removal will increase the number of components is called bridge edge




    return 0;
}