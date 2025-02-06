// below is a very good question .... can access 
// ******************************************************************************************


// this helps you detect negative cycles as well
// advanced version of dijikstra's algo

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;
#define INF 1e9

class Solution3{
    public:
    vector<vector<int>> shortest_distance(vector<vector<int>>&matrix){
        int n = matrix.size();
        vector<vector<int>>ans(n,vector<int>(n,INF));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    ans[i][j] = 0;
                }
                else if(matrix[i][j] == -1){
                    ans[i][j] = INF;
                }
                else{
                    ans[i][j] = matrix[i][j];
                }
            }
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    int t;
                    if(ans[i][k] == INF || ans[k][j] == INF)
                        t = INF;
                    else
                        t = ans[i][k] + ans[k][j];

                    ans[i][j] = min(ans[i][j],t);
                }
            }
        }

        return ans;
    }

};




//********************************************************************************************* 
// #include<bits/stdc++.h>
// using namespace std;


// class Solution2{
// public:
//     void dfs(int node, unordered_map<int, list<int>>& adjlist, stack<int>& st, vector<int>& visited) {
//         visited[node] = 1;
//         for (auto neighbor : adjlist[node]) {
//             if (!visited[neighbor]) {
//                 dfs(neighbor, adjlist, st, visited);
//             }
//         }
//         st.push(node);
//     }

//     void special_dfs(int node, unordered_map<int, list<int>>& transpose, vector<int>& visited, int scc_id, vector<vector<int>>& scc_nodes) {
//         visited[node] = scc_id; // Mark the node with the current SCC ID
//         scc_nodes[scc_id].push_back(node);
//         for (auto neighbor : transpose[node]) {
//             if (visited[neighbor] == -1) { // Not visited in SCC detection
//                 special_dfs(neighbor, transpose, visited, scc_id, scc_nodes);
//             }
//         }
//     }

//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         // Step 1: Build the adjacency list and transpose graph
//         unordered_map<int, list<int>> adjlist, transpose;
//         for (auto& edge : prerequisites) {
//             int u = edge[0];
//             int v = edge[1];
//             adjlist[u].push_back(v);
//             transpose[v].push_back(u); // Build the transpose graph simultaneously
//         }

//         // Step 2: Perform Topological Sort using DFS
//         stack<int> st;
//         vector<int> visited(numCourses, 0);
//         for (int i = 0; i < numCourses; i++) {
//             if (!visited[i]) {
//                 dfs(i, adjlist, st, visited);
//             }
//         }

//         // Step 3: Identify SCCs using DFS on Transpose Graph
//         vector<vector<int>> scc_nodes(numCourses); // To store nodes in each SCC
//         fill(visited.begin(), visited.end(), -1);  // Reset visited array for SCC detection
//         int scc_count = 0;

//         while (!st.empty()) {
//             int top = st.top();
//             st.pop();
//             if (visited[top] == -1) {
//                 special_dfs(top, transpose, visited, scc_count, scc_nodes);
//                 scc_count++;
//             }
//         }

//         // Step 4: Build the SCC Dependency Graph
//         vector<vector<int>> scc_adj(scc_count, vector<int>(scc_count, 0)); // Adjacency matrix for SCCs
//         for (int i = 0; i < numCourses; i++) {
//             for (auto neighbor : adjlist[i]) {
//                 int u_scc = visited[i];
//                 int v_scc = visited[neighbor];
//                 if (u_scc != v_scc) {
//                     scc_adj[u_scc][v_scc] = 1; // Add edge between SCCs
//                 }
//             }
//         }

//         // Step 5: Compute Transitive Closure (Floyd-Warshall on SCC graph)
//         vector<vector<bool>> reach(scc_count, vector<bool>(scc_count, false));
//         for (int i = 0; i < scc_count; i++) {
//             reach[i][i] = true; // Every SCC can reach itself
//         }
//         for (int i = 0; i < scc_count; i++) {
//             for (int j = 0; j < scc_count; j++) {
//                 if (scc_adj[i][j]) {
//                     reach[i][j] = true;
//                 }
//             }
//         }
//         for (int k = 0; k < scc_count; k++) {
//             for (int i = 0; i < scc_count; i++) {
//                 for (int j = 0; j < scc_count; j++) {
//                     if (reach[i][k] && reach[k][j]) {
//                         reach[i][j] = true;
//                     }
//                 }
//             }
//         }

//         // Step 6: Process Queries
//         vector<bool> ans;
//         for (auto& query : queries) {
//             int u = query[0];
//             int v = query[1];
//             int u_scc = visited[u];
//             int v_scc = visited[v];
//             ans.push_back(reach[u_scc][v_scc]); // Check if there's a path between SCCs
//         }

//         return ans;
//     }
// };





// class Solution {
// public:

//     void dfs(int node, unordered_map<int,list<int>>&adjlist, stack<int>&st, vector<int>&visited){
        
//         visited[node] = -1;
//         for(auto j : adjlist[node]){
//             if(!visited[j])
//             dfs(j,adjlist,st,visited);
//         }
//         st.push(node);
//     }

//     void special_dfs(int node, unordered_map<int,list<int>>&adjlist, vector<int>&visited, int &k, unordered_map<int,set<int>>&scc_marking){


//         if(visited[node]==-2 || visited[node]==k){
//             return;
//         }

//         if(visited[node]!=-1){
//             auto it = scc_marking[visited[node]].find(k);
//             if(it == scc_marking[visited[node]].end()){
//                 scc_marking[visited[node]].insert(k);
//             }
//             return;
//         }

//         visited[node] = -2;

//         for(auto j : adjlist[node]){
//             special_dfs(j,adjlist,visited,k,scc_marking);
//         }

//         visited[node] = k;
//     }


//     bool solve(int node, unordered_map<int,set<int>>scc_marking,int target){
//         if(node == target){
//             return true;
//         }
//         for(auto j:scc_marking[node]){
//             if(solve(j,scc_marking,target)){
//                 return true;
//             }
//         }
//         return false;
//     }


//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
//     unordered_map<int,list<int>>adjlist;
//     unordered_map<int,list<int>>transpose;
//     unordered_map<int,set<int>>ssc_marking;
//     stack<int>st;

//     int e = prerequisites.size();
//     for(int i=0; i<e; i++){
//         int u = prerequisites[i][0];
//         int v = prerequisites[i][1];

//         adjlist[u].push_back(v);
//     }

//     vector<int>visited(numCourses,0);
//     for(int i=0; i<numCourses; i++){
//         if(visited[i]==0){
//             dfs(i,adjlist,st,visited);
//         }
//     }

//     for(int i=0; i<numCourses; i++){
//         for(auto j: adjlist[i]){
//             transpose[j].push_back(i);
//         }
//     }

//     int k = 1;
//     while(!st.empty()){
//         int top = st.top();
//         st.pop();
//         if(visited[top]==-1){
//             special_dfs(top,transpose, visited,k,ssc_marking);
//             k++;
//         }
//     }

//     int q = queries.size();
//     vector<bool>ans(q);
//     for(int i=0; i<q; i++){
//         int u = queries[i][0];
//         int v = queries[i][1];

//         if(visited[u] == visited[v]){
//             ans[i] = true;
//         }
//         else{
//             ans[i] = solve(visited[u],ssc_marking,visited[v]);
//         }
//     }

//     return ans;
//     }
// };




// #include<bits/stdc++.h>
// #define CLEAR system("cls")
// using namespace std;



// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
//         int n = numCourses;
//         vector<vector<bool>>matrix(n,vector<bool>(n,false));

//         for(int i=0; i<n; i++)
//             matrix[i][i] = true;

//         int e = prerequisites.size();
//         for(int i=0; i<e; i++){
//             int u = prerequisites[i][0];
//             int v = prerequisites[i][1];
//             matrix[u][v] = true;
//         }

//         for(int k=0; k<n; k++){
//             for(int i=0; i<n; i++){
//                 if(i==k)continue;
//                 for(int j=0; j<n; j++){
//                     if(!matrix[i][j] && j!=k){
//                         matrix[i][j] = matrix[i][k] && matrix[k][j];
//                     }
//                 }
//             }
//         }

//         int q = queries.size();
//         vector<bool>ans(q);
//         for(int i=0; i<n; i++){
//             ans[i] = matrix[queries[i][0]][queries[i][1]];
//         }
        
//         return ans;
//     }
// };
