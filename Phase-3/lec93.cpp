// shortest path in undirected graph

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

vector<int> shortestPath(vector<pair<int,int>>& edges, int n, int m, int s, int t){

    // n is vertexs, m is edges, s is start node, t is target node

    //create a adjanceny list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    
    while(!q.empty()){
        
        int front = q.front();
        q.pop();

        for(auto neighbour: adj[front]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour]=front;

                if(neighbour==t){
                    goto end_bfs;
                }
            }
        }
    }
    end_bfs:

    vector<int> ans;
    int curNode=t;
    ans.push_back(t);
    while(curNode!= s){
        curNode=parent[curNode];
        ans.push_back(curNode);
    }

    reverse(ans.begin(),ans.end());
    return ans;

}


int main()
{

    //(done)
    vector<pair<int,int>> edges={ {0,1},
                                {1,2},
                                {2,3},
                                {3,4},
                                {4,5},
                                {5,0},
                            };

    vector<int>ans=shortestPath(edges,6,6,1,5);
    
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;


    return 0;
}




// vector<int> shortestPath(vector<pair<int,int>>& edges, int n, int m, int s, int t){

//     // Create an adjacency list to represent the graph
//     unordered_map<int, list<int>> adj;
//     for(int i = 0; i < edges.size(); i++){
//         int u = edges[i].first;
//         int v = edges[i].second;

//         // Since the graph is undirected, add both directions
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     // Perform BFS to find the shortest path
//     unordered_map<int, bool> visited;  // To keep track of visited nodes
//     unordered_map<int, int> parent;   // To store the parent of each node
//     queue<int> q;                     // Queue for BFS
//     q.push(s);                        // Start BFS from the source node
//     visited[s] = true;                // Mark the source node as visited
//     parent[s] = -1;                   // The source has no parent

//     while(!q.empty()){
//         int front = q.front();        // Get the current node
//         q.pop();

//         // Traverse all neighbors of the current node
//         for(auto neighbour: adj[front]){
//             if(!visited[neighbour]){
//                 q.push(neighbour);         // Push unvisited neighbors into the queue
//                 visited[neighbour] = true; // Mark the neighbor as visited
//                 parent[neighbour] = front; // Update the parent for the neighbor
//             }
//         }
//     }

//     // Backtrack from the target node `t` to the source node `s` to construct the path
//     vector<int> ans;
//     int curNode = t;
//     ans.push_back(t);  // Start with the target node
//     while(curNode != s){  // Continue until we reach the source node
//         curNode = parent[curNode];
//         ans.push_back(curNode); // Add the parent to the path
//     }

//     // Reverse the path to get it from source to target
//     reverse(ans.begin(), ans.end());
//     return ans;
// }
