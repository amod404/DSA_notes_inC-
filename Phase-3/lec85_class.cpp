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

template <typename T>
class graph{
public:
    // map<int,list<int>> adj;
    unordered_map<T,list<T>> adj;

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
};

