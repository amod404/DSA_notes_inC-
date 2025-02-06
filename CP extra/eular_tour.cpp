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

void inorder(node* root, vector<int> & ans){
    if(root==NULL){
        return;
    }
    //L
    inorder(root->left,ans);
    //N
    ans.push_back(root->data);
    //R
    inorder(root->right,ans);
}


void Eular_type1(node* root, vector<int>&eular){
    if(!root)return;

    eular.push_back(root->data);

    if(root->left){
        Eular_type1(root->left,eular);
        eular.push_back(root->data);
    }

    if(root->right){
        Eular_type1(root->right,eular);
        eular.push_back(root->data);
    }
}

void Eular_type2(node* root, vector<int>&eular){
    if(!root) return;

    eular.push_back(root->data);

    if(root->left) Eular_type2(root->left,eular);
    if(root->right) Eular_type2(root->right,eular);

    eular.push_back(root->data);
}

//
//
//                      1
//                   2     3
//                4    5 6    7
//              8               
//      
//      eular_type1 : 1 2 4 8 4 2 5 2 1 3 6 3 7 3 1
//      eular_type2 : 1 2 4 8 8 4 5 5 2 3 6 6 7 7 3 1
//
//      you can find wheathe a node is inside the subtree of another node 
//      if its frist occurance and last occurance if side the first and last occurance of other node
//
//
//
//
