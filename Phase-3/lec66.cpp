// binary tree question

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<unordered_map>
#include"lec62_classes.cpp"
#define CLEAR system("cls")
using namespace std;


// NOTE : - Here dividing the inorder into start,pos-1 and pos+1,end...... doesnt have any significant
// it is used to just solve the base condition otherwise the main work is of interator preorder index....and unordered_map

//sleepy~~~~~(read again)
void create_mapping(vector<int> &in, unordered_map<int,int> &nodeToIndex){
    int n= in.size();
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
    return;
}
node* solve(unordered_map<int,int> & nodeToIndex,vector<int>& pre, int &index, int inorderStart , int inorderEnd){
    //base case
    if(index >= pre.size() || inorderStart>inorderEnd){
        return NULL;
    }

    int element = pre[index++];
    node* root = new node(element);
    int position = nodeToIndex[element];

    root->left = solve(nodeToIndex,pre,index,inorderStart,position-1);
    root->right = solve(nodeToIndex,pre,index,position+1,inorderEnd);

    return root;
}
node* buildTree(vector<int>& in, vector<int>&pre){
    int n = in.size();
    int preOrderIndex=0;
    // iterating preorder index one by one....as using that the first element of preorder is root node
    unordered_map<int,int>nodeToIndex; 
    create_mapping(in,nodeToIndex);
    return solve(nodeToIndex,pre,preOrderIndex,0,n-1);
}

//too much sleepy~~~~~~~~~~~~~

int Create_mapping(vector<int> &in, unordered_map<int,int> &nodeToIndex){
    int n= in.size();
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
    return -1;
}

node* Solve(unordered_map<int,int> & nodeToIndex,vector<int>& post, int &index, int inorderStart , int inorderEnd){
    //base case
    if(index < 0 || inorderStart>inorderEnd){
        return NULL;
    }

    int element = post[index--];
    node* root = new node(element);
    int position = nodeToIndex[element];

    //note here right is going first as we are iterating back in post
    root->right = Solve(nodeToIndex,post,index,position+1,inorderEnd);
    root->left = Solve(nodeToIndex,post,index,inorderStart,position-1);

    return root;
}

node* BuildTree(vector<int>& in, vector<int>&post){
    int n= in.size();
    int postOrderIndex=n-1;
    unordered_map<int,int> nodeToIndex;
    Create_mapping(in,nodeToIndex);
    node* ans = Solve(nodeToIndex,post,postOrderIndex,0,n-1);
    return ans;
}


int main()
{	CLEAR;

    // TC...O(nlogn)
    node* head=NULL;
    vector<int> in={1,6,8,7};
    vector<int> pre={1,6,7,8};

    head = buildTree(in,pre);


    inorder(head);
    cout<<endl;
    preorder(head);
    cout<<endl;
    postorder(head);
    cout<<endl;

    return 0;
}