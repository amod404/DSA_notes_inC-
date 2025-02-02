// graph - minimum spannin tree using kruskal's algorithm

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2]<b[2];
}

int findParent(vector<int> & parent, int node){
    if(parent[node]==node){
        return node;
    }
    int t = findParent(parent,parent[node]);
    
    parent[node]=t;  // use ofr path compression
    return t;

    // can also write as : 
    // return parent[node]=findParent(parent, parent[node]);

    // this will travers ethe whole tree 
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
    //converting the nodes into their parent
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{  //equal case
        parent[v]=u;
        rank[u]++; 
    }
    //we didnt increse the rank as a shorter tree is adding 
    //also we increase the rank by one as the new tree will have the node of height 1 as due to path compression
}

//taking union and path compresion
int minimumSpanningTree(vector<vector<int>>& edges, int n){
    //sorting on bases of the weight...
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    for(int i=0; i<n; i++){
        parent[i]=i;
        rank[i]=0;
    }   
    int minWeight=0;
    
    for(int i=0; i<edges.size(); i++){
        // finding parnets of two adjacent nodes
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int wt = edges[i][2];

        if(u != v){
            //minweigt will store the total weight of Min.Spanning.Tree
            minWeight+=wt;
            unionSet(u,v,parent,rank);
        }
        //else if the parnets are same then ignore
    }
    return minWeight;
}

int main()
{
    
    



    return 0;
}