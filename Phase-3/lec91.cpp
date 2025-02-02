// topological sort in Directed Acyclic Graph using kahn's algorithm

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

vector<int> topoSort(vector<vector<int>> &edges, int v, int e){
    //create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0;i<e;i++){
        int u= edges[i][0];
        int v= edges[i][1];
        adj[u].push_back(v);
    }

    //find all indegree
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    //0indegree walo ko push kardo
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //do bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        //neighbour indegree upgrade
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}


int main()
{
    
        vector<vector<int>> edges={{0,1},
                                {1,2},
                                {1,3},
                                {2,4},
                                {2,5},
                            };

    vector<int> ans = topoSort(edges,6,5);

    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;

    // again O(V+E);



    return 0;
}