#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;


class DisjointSet{
    vector<int>rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(node == parent[node])
            return node;
            return parent[node]=findUpar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution{
    public :

    int spanningTree(int V, vector<vector<int>>adj[]){
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                // every edge is added twice... the second one will auto matically discarded
                edges.push_back({wt,{node,adjNode}});
            }
        }

        sort(edges.begin(),edges.end());
        int mstWt = 0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            DisjointSet ds(V);
            if(ds.findUpar(u) != ds.findUpar(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};


// TC -> O(N+E) + O(Mlog(M)) + O(M x 4 x alfa)
// SC -> O(M)

int main()
{

    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<vector<int>>adj[V];
        int i = 0;
        while(i++<E){
            int u,v,w;
            cin>>u>>v>>w;   
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        Solution obj;
        cout<< obj.spanningTree(V,adj) << endl;
    }
    return 0;
}