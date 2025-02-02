// graph - find the minimu distance using Bellman ford algorithm

#include<bits/stdc++.h>
using namespace std;




int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> & edges){

    vector<int> dist(n+1, INT_MAX);
    dist[src]=0;

    for( int i=1; i<n; i++){
        // traverse on edge list
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != INT_MAX && (dist[u] + wt) < dist[v] ){
            dist[v] = dist[u] + wt;
            }
        }
    }

    //check for negative cycle
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != INT_MAX && (dist[u] + wt) < dist[v] ){
            return -1;
        }
    }

    return dist[dest];

}

int main()
{

    // this algo is needed because the dijksira's algorithm do not 
    // work on negative weighted edges as it is a greedy algorithm



    return 0;
}