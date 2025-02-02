// Graphs-01...introdution
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


int main()
{

    //(pending)HW-> adjancency matrix 


    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<< "enter the number of edges : ";
    cin>>m;

    graph<int> g;

    for(int i=0; i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        //creating an undirected graph
        g.addEdge(u,v,d);    
    }

    //printing graph
    cout<<endl;
    g.printAdjList();
    //(done)HW--> find TC:O(V+E) and SC:O(V+E)


    return 0;
}