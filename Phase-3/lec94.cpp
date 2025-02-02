// shortest path in DAG (weighted)

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;


class Graph{
    public:
    unordered_map<int, list<pair<int,int>>>adj;

    void addEdge(int u, int v, int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i: adj){
            cout<< i.first<< " -> ";
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }cout<<endl;
        }
    }

    //for topological sort
    void dfs(int node, unordered_map<int,bool> &vis, stack<int>& topo){
        vis[node]=true;
        //first one will give neighbour's value and second will give its weight
        for(auto neighbour: adj[node]){
            if(! vis[neighbour.first]){
                dfs(neighbour.first,vis,topo);
            }
        }

        //values will be pushed in return time...
        //and return will happen when there is no adjacent node..,,
        //so no next node will appera after pushing in topo
        topo.push(node);
    }

    void getSHortestPath(int src, vector<int>& dist, stack<int> &s){
        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX){
                //we can reach this node and now will update their neighbour
                for(auto i: adj[top]){
                    // i -> neighbour
                    // i.first -> neighbour value
                    // i.second -> weight to reach neighbour from curret node
                    if(dist[top]+ i.second < dist[i.first]){ // for some initial cases dist[i.first] should have INT_MAX
                        //update the shorter distance
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
            // else we can't reach that node 
            // for example we cant reach the root node with any inbetween node 
            // if that in between node is the src node
        }

    }
};


int main()
{
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    
    g.printAdj();

    //topological sort
    int n= g.adj.size();
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }


    int src = 1;
    vector<int> distance(n,INT_MAX);
    distance[src] = 0;

    g.getSHortestPath(src,distance,s);

    for(auto i: distance){
        cout<< i<< " ";
    }cout<<endl;

    // (done) HW-> do dry run for some example
    // (done) HW-> read article from this lec in discription of video
    
    return 0;
}