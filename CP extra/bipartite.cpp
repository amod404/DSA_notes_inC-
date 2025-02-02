#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

// Check if the graph is bipartite and extract its connected component
    bool isBipartite(vector<vector<int>>& adj, vector<int>& color, int start) {
        queue<int> q;
        q.push(start);
        color[start] = 0;  // Color start node
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;  // Odd-length cycle → Not bipartite
                }
            }
        }
        return true;
    }