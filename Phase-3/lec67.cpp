// queestion -> burn a tree

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include"lec62_classes.cpp"
#define CLEAR system("cls")
using namespace std;


node* createParentNode(node* root, int target, map<node*,node*>&nodeToParent){
    
    //1. create mapping 
    //2. also find pointer to target node

    node* res=NULL;
    //level order traversal

    queue<node*> q;
    q.push(root);
    nodeToParent[root]=NULL;

    while(!q.empty()){

        node* front = q.front();
        q.pop();

        if(front->data == target){
            res=front;
        }

        if(front->left){
            nodeToParent[front->left]=front;
            q.push(front->left);
        }

        if(front->right){
            nodeToParent[front->right]=front;
            q.push(front->right);
        }
        
    }

    return res;
}

int burnTree(node* root,map<node*,node*>&nodeToParent){
    map<node*,bool> visited;
    queue<node*> q;
    q.push(root);
    visited[root]=true;

    int ans=0; //time

    while(!q.empty()){

        int size = q.size();
        bool flag = false;

        for(int i=0;i<size;i++){
            //process the neighbouring node
            node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag=true;
                q.push(front->left);
                visited[front->left]=true;
            }

            if(front->right && !visited[front->right]){
                flag=true;
                q.push(front->right);
                visited[front->right]=true;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag=true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]]=true;
            }
        }

        if(flag){
            ans++;
        }
    }
    return ans;
}

int minTime(node* root, int target){
    //algo:
    //1. create nodeToParent mapping
    //2. find target node
    //3. burn the tree in the min time also pass visited node
    int ans=0;
    map<node*, node*> nodeToParent;
    node* targetNode = createParentNode(root,target,nodeToParent);

    ans=burnTree(targetNode,nodeToParent);
    return ans;
}

int main()
{	CLEAR;

    // minimum time to burn a binary tree
    // approach 1-> mapping to parent node
    node* root=NULL;
    buildFromLevelOrder(root);
    CLEAR;
    int k;
    cout<<"Enter the node to be burn first : ";
    cin>>k;
    cout<<endl;
    cout<< "Minimum time to burn the tree is : "<< minTime(root,k)<<endl;

    // approach 2....make a adjacency list with undirected edges.....
    // starting from target node call for bfs with a counter ......

    return 0;
}