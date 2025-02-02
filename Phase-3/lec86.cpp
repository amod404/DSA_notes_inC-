// graph - question

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

void prepareAdjList(unordered_map<int,list<int>> &adjList, vector<pair<int,int>>& edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &ans,int node){
    queue<int>q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //store frontNode into ans
        ans.push_back(frontNode);

        //traverse all neighbours of frontNode
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int,int>>& edges){
    //here V is number of vertexs...as 1->V 
    unordered_map<int,list<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    
    prepareAdjList(adjList,edges);

    //traverse all components of a graph
    for(int i=0;i<vertex;i++){
        //this loop is used so that all the components of the graph will be covered
        if(!visited[i]){
            bfs(adjList,visited, ans,i);
        }
    }
    return ans;

}

int main()
{
    // Breadth First Search (traversal technique)
    // graph can be disconnected
    // use for both directed and undirected graph
    vector<pair<int,int>> edges={{0,1},
                                {1,2},
                                {1,3},
                                };
    vector<int>ans = BFS(4,edges);
    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;
    
    // TC -> O(V+E)  SC->O(V+E)

    // you can use set instead of list as datas are store in sorted order in set
    

    return 0;
}