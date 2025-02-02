// Graphs-01...introdution
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>
class graph{
public:
    // map<int,list<int>> adj;
    unordered_map<T,list<T>> adj;
    int node = -1;

    void addEdge(T u, T v, bool direction){
        //direction = 0 -> undirected
        //direction = 1 -> directed
    
        //create an edge between  u to v
        adj[u].push_back(v);

        //for undirected graph
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout<< i.first<< " --> ";
            for(auto j: i.second){
                cout<< j<<" ";
            }
            cout<<endl;
        }
    }

    //breath first search
    void bfs(vector<int> &ans,int node){
        unordered_map<int,bool> &visited;
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



};
