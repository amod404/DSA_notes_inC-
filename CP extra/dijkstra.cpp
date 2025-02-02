// graph - dijkstra's shortest path

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
#include<set>
#include<limits.h>
using namespace std;

vector<int> myDij(vector<vector<int>>& edges, int v, int e, int source) {
    // Making the adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v, w));
        // Uncomment the next line if the graph is undirected
        // adj[v].push_back(make_pair(u, w));
    }

    // Distance vector and priority queue
    vector<int> distance(v, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Initialize the source
    distance[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int d = pq.top().first; // Current distance
        int curr = pq.top().second; // Current vertex
        pq.pop();

        // Traverse neighbors
        for (auto neighbour : adj[curr]) {
            int next = neighbour.first;  // Neighbor vertex
            int weight = neighbour.second; // Edge weight
            if (weight + d < distance[next]) {
                distance[next] = weight + d;
                pq.push(make_pair(distance[next], next));
            }
        }
    }

    return distance;
}



vector<int> dijkstra(vector<vector<int>>& vec,int vertices, int edges, int source){
    // create adjacency list
    unordered_map<int, list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++){
        int u= vec[i][0];
        int v= vec[i][1];
        int w= vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }


    vector<int> dist(vertices,INT_MAX);
    set<pair<int,int>> st;

    

    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());
        
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if(record != st.end()){
                    st.erase(record);
                }

                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }

    return dist;
}


int main()
{

    



    return 0;
}