// graph--> cycle detection( in directed graph )
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

bool checkCycleDFS(int node, unordered_map<int,bool>& visited,
    unordered_map<int,bool>& dfsVisited,unordered_map<int,list<int>>& adj ){

    //mark the dfs path
    visited[node]=true;
    dfsVisited[node]=true;
    for(auto neighbour: adj[node]){
        //check if not visited then cll for cycle detection in that part
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour,visited,dfsVisited,adj);
            if(cycleDetected){
                //this is used to break the the next dfds calls and return true behind the line
                return true;
            }
        }
        //if it is visited as well as it is on same path then it is cycle
        else if(dfsVisited[neighbour]){
            // cycle detected 
            return true;
        }

        // else it is visited but not from curr path...
        // also we dont have to check if it is visited as 
        // it already have been checked from another dfs path 
    }

    //remove the dfs path
    dfsVisited[node]=false;
    return false;
}

bool detectCycleInDirectedGraph( int n, vector<pair<int,int>>& edges){
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // this is to avoid going backward during a dfs call
    unordered_map<int,bool> visited;
    // this is to check if that particular dfs path visited
    unordered_map<int,bool> dfsVisited;
    
    //call dfs for all componenets
    for(int i=0; i<n;i++){
        if(!visited[i]){
            bool cycleFound = checkCycleDFS(i,visited,dfsVisited,adj);
            if(cycleFound){
                return true;
            } 
        }
    }
    
    return false;
}



int main()
{

    //for directed graph.....we call cycle only if it directed in 
    //either clockwise or clockwise sense for all the elements of that cycle

   vector<pair<int,int>> edges={{1,0},
                                {0,2},
                                {0,3},
                                {0,4},
                                {4,5},
                                {5,6},
                                {6,1},
                            };

    cout<<detectCycleInDirectedGraph(7,edges)<<endl;        

    // TC->O(V+E) SC->O(V+E)
    return 0;
}