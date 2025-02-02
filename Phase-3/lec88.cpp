// graph--> cyclic detection 

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

//using BFS
bool isCyclicBFS(int src, unordered_map<int,bool> &visited, unordered_map<int,list<int>>& adj, unordered_map<int,int>& parent){

    parent[src]=-1;
    visited[src]=true;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(!visited[neighbour]){
                //store that not visited node for further traverse
                q.push(neighbour);
                //store parent and mark visited
                visited[neighbour] = true;
                parent[neighbour]= front;
            }
            //check if parent or not
            else if(neighbour!=parent[front]){
                // means neighbour is neither front's parent but still visited
                return true;
            }
            // else it is parent fo nothing 
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> & edges, int n, int m){

    //create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    //to handle disconnected component
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adj, parent);
            //if cycle is present in any component then return yes
            if(ans){
                return"Yes";
            }
        }
    }

    return "No";
}

//using DFS
bool isCyclicDFS(int node, int parent, unordered_map<int,bool> &visited, unordered_map<int,list<int>>& adj){
    visited[node]=true;

    for(auto neighbour : adj[node]){
        //so that we dont come backward we only go for those which are not visited
        if(!visited[neighbour]){
            //new node is that neighbour, and its parent is curr node
            bool cycleDetected = isCyclicDFS(neighbour,node,visited,adj);
            // if cycle is fount in next dfs call then return true;
            if(cycleDetected){
                return true;
            }
        }
        //for those node which are visited we will check if it is our parent or not
        else if(neighbour != parent){
            //cycle present
            return true;
        }
        // else do nothing as this is previous node 
    }

    return false;
}
string CycleDetection(vector<vector<int>> & edges, int n, int m){

    //create adjacency list
    // n is vertices and m is edges
    unordered_map<int,list<int>> adj;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    //we will mark the first parent of each component in the function call stack instead of a map
    //to handle disconnected component
    for(int i=0; i<n; i++){
        if(!visited[i]){
            //for starting node parent is -1
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans){
                return"Yes";
            }
        }
    }

    return "No";
}

int main()
{

    //(done)HW-> run these on test case and do dry run on example
    vector<vector<int>> edges={{0,1},
                                {1,2},
                                {2,3},
                                {3,4},
                                {4,5},
                                {5,1},
                            };

    cout<<cycleDetection(edges,6,6)<<endl;        
    cout<<CycleDetection(edges,6,6)<<endl;        

    return 0;
}




//     Cycle detection in a graph using DFS and BFS, when applied to an adjacency list representation, has the following time and space complexities:

// ---

// ### **Using Depth-First Search (DFS)**
// 1. **Time Complexity**:
//    - In the worst case, DFS visits every vertex and explores every edge of the graph once.
//    - For a graph with \( V \) vertices and \( E \) edges:
//      \[
//      O(V + E)
//      \]
//    - The \( V \) term accounts for visiting all vertices, and the \( E \) term accounts for traversing all edges.

// 2. **Space Complexity**:
//    - The space complexity is dominated by the following:
//      - The adjacency list storage: \( O(V + E) \).
//      - The recursion stack for DFS:
//        - In the worst case (e.g., for a graph like a single long path), the recursion stack can go as deep as \( O(V) \).
//    - Total:
//      \[
//      O(V + E)
//      \]
//      (Adjacency list and recursion stack combined).

// ---

// ### **Using Breadth-First Search (BFS)**
// 1. **Time Complexity**:
//    - Similar to DFS, BFS also visits every vertex and explores every edge once in the worst case:
//      \[
//      O(V + E)
//      \]

// 2. **Space Complexity**:
//    - The space complexity for BFS is determined by:
//      - The adjacency list storage: \( O(V + E) \).
//      - The queue used in BFS:
//        - In the worst case, the queue can store all vertices of the largest level in the graph, which is \( O(V) \).
//    - Total:
//      \[
//      O(V + E)
//      \]
//      (Adjacency list and queue combined).

// ---

// ### **Key Observations**:
// - Both DFS and BFS have the same time complexity of \( O(V + E) \).
// - Space complexity is also similar for both methods when considering the adjacency list. However:
//   - DFS may use additional memory for the recursion stack.
//   - BFS uses additional memory for the queue.
// - In practice, DFS may be slightly more memory-efficient for shallow graphs since its stack usage depends on the depth of recursion, while BFS queue size depends on the breadth of the graph.

// ---

// ### Summary Table:

// | **Method** | **Time Complexity** | **Space Complexity**              |
// |------------|---------------------|------------------------------------|
// | DFS        | \( O(V + E) \)      | \( O(V + E) \) (Adjacency list + Stack) |
// | BFS        | \( O(V + E) \)      | \( O(V + E) \) (Adjacency list + Queue) |

