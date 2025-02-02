//tree--> morris tarversal algorithm

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

vector<int> M_inOrder(node* root) {
    vector<int> result;
    node* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {  //follow LNR
            // If no left child, store this node 
            // and go right
            result.push_back(curr->data);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            node* prev = curr->left;
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its inorder predecessor
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } 

            else {
                // you again got back to loop means all left entries are done  
                // Revert the changes made in the tree structure
                prev->right = NULL;
                result.push_back(curr->data); 
                curr = curr->right;  //traverse right side now
            }
        }
    }

    return result;
}


vector<int> M_inOrder_fun(node* root){
    vector<int>inorder;
    node * curr = root;
    
    while(curr){
        if(!curr->left){
            inorder.push_back(curr->data);
            curr = curr->right;
            continue;
        }

        node* prev = curr->left;
        while(prev->right && prev->right != curr)
            prev = prev->right;

        if(!prev->right){
            prev->right = curr;
            curr = curr->left;
        }
        else{
            prev->right = NULL;
            inorder.push_back(curr->data);
            curr = curr->right;
        }
    }
    return inorder;
}


void flattenTree(node* &root){
    node* curr = root;
    while(curr!=NULL){
        if(curr->left){
            node* prev= curr->left;
            while(prev->right){
                prev=prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr=curr->right;
    }
}

void f_print(node* root){

    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->right;
    }cout<<endl;
}

int main()
{	CLEAR;

    //morris traversal..TC..O(n) and SC....O(1) *o*
    node* root=NULL;
    buildFromLevelOrder(root);
    CLEAR;
    vector<int> ans = M_inOrder(root);
    for(auto i:ans){
        cout<< i<< " ";
    }
    cout<<endl;
    inorder(root);
    cout<<endl;

    //make a binary tree into linked list
    // or flatten a binary tree
    flattenTree(root);
    f_print(root);
    inorder(root);

    return 0;
}