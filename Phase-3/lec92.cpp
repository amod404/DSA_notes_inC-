// directed graph cycle detectionusing bfs(left topic)

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


bool cycleDetection(vector<vector<int>> &edges, int v, int e){
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

    //0-indegree walo ko push kardo
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //for a cycle the indegree or any elemet is not zero
    // thus they never be included in bfs call....if bs calls are less then your v means cycle is present

    //do bfs
    int cnt=0;    
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // increment count...(no of bfs calls)
        cnt++;

        //neighbour indegree upgrade
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            //if cycle then it wont be enter
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    // cnt must be v for no cycle
    if(cnt == v){
        return false;
    }
    else{
        return true;
    }
}

int main()
{
    vector<vector<int>> edges={ {0,1},
                                {1,2},
                                {3,1},
                                {2,4},
                                {2,5},
                                {4,3},
                            };

    cout<<cycleDetection(edges,6,6)<<endl;
    
    //avg TC is not good as dfs breaks after one cycle detection
    //but this will total graph and at last give the answer

    return 0;
}