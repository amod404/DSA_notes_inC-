// binary searc tree -> imp question

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

class node{

    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data =d;
            left = NULL;
            right = NULL;
        }      
};

node* insertIntoBST(node* & root,int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }

    if(data > root->data){
        //insert in right
        root->right = insertIntoBST(root->right, data);
    }
    else{
        //insert in left
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void takeInput(node* &root){
    int data;
    cin>> data;

    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
    CLEAR;
}
void levelOrderTraversal(node*root){
    queue<node*> q;
    q.push(root);
    // seperator
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp==NULL){
            //purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){
                //queue still has some child node
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

//solution

class info{
    public:
    bool isBST;
    int maxi;
    int mini;
    int size;
};

info solve(node*root,int &ans){
    if(root==NULL){
        return {true,INT_MIN,INT_MAX,0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.size = left.size+right.size+1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.maxi = min(root->data,left.mini);

    if(left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini){
        currNode.isBST=true;
    }
    else{
        currNode.isBST=false;
    }

    //answer update;
    if(currNode.isBST){
        ans = max(ans,currNode.size);
    }
    return currNode;
}

int largestBst(node* root){
    int maxSize=0;
    solve(root,maxSize);
    return maxSize;
}

int main()
{	CLEAR;

    // largest BSt in a binary tree 
    // approach 1-> check each node if it is valid BST 
    //              if true than store that size and maximize it
    //              TC..O(n^2)

    // approach 2-> if left part and right part are valid BSt then 
    //              it is also valid bst if it follows the conditiions.
    //              also during backtracking store the size and boolian value,
    //              extra condition-> max and min of subtrees 

    // (pending)HW--> do the dry run 
    
    return 0;
}