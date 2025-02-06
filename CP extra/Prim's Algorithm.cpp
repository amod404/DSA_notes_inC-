// axiom 1 : ek tree ke andr n-1 edges hoti hai.... agar jyada ho to cycle present hogi
// axiom 2 : lekin agar n-1 hai aur cycle present hai to vo graph disconnected hai 

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

class Solution{

    public : 
    int spanningTree(int V, vector<vector<int>>adj[]){
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<bool>vis(V,false);
        // {wt,node}

        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            // get the minimum edges
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            // decide if the edge form cycle or not .... using compliment of axiom 1
            // means n-1 edges hi lega extra ni lega... garbage of pq will get empty
            if(vis[node]) continue;
            //this is when I add it to mst
            vis[node] = true;
            sum+=wt;

            // now add the adjacent also
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edW = it[1];

                //again using axiom 1 and 2
                if(!vis[adjNode]){
                    //dont mark visited true now
                    pq.push({edW,adjNode});
                }
            }


        }
        return sum;
    }


};

