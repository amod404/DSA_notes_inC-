// bbinary search tree questions

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
bool twoSum(node*root,int target){
    vector<int> inorderVal;
    //save the inorder traversal which is sorted
    inorder(root, inorderVal);

    // using two pointer approach to find if the sum exist?
    // kadane's algorithm
    int i=0;
    int j=inorderVal.size()-1;
    while(i<j){
        int sum = inorderVal[i] + inorderVal[j];

        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

void Inorder(node* root, vector<node*> & ans){
    if(root==NULL){
        return;
    }
    //L
    Inorder(root->left,ans);
    //N
    ans.push_back(root);
    //R
    Inorder(root->right,ans);
}

node* flatten(node* root){
    // store the inorder 
    vector<node*> arr;
    Inorder(root,arr);

    // link the pointers 
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        arr[i]->left =NULL;
        arr[i]->right = arr[i+1];
    }
    arr[n-1]->left =NULL;
    arr[n-1]->right =NULL;
    return arr[0];
}

void In(node* root, vector<int> & ans){
    if(root==NULL){
        return;
    }
    //L
    In(root->left,ans);
    //N
    ans.push_back(root->data);
    //R
    In(root->right,ans);
}

node* inorderToBST(int s, int e, vector<int> &inorderVal){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(inorderVal[mid]);
    root->left = inorderToBST(s,mid-1,inorderVal);
    root->right = inorderToBST(mid+1,e,inorderVal);
    return root;
}
node* flatten(node* root){
    // store the inorder 
    vector<int> inorderVal;
    In(root,inorderVal);

    return inorderToBST(0,inorderVal.size()-1,inorderVal);
}

node* solve(vector<int> & preorder, int mini, int maxi, int &i){
    if(i>=preorder.size()){
        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi){
        return NULL;
    }

    node* root = new node(preorder[i++]);
    root->left = solve(preorder,mini,root->data,i);
    root->right = solve(preorder,root->data,maxi,i);
    return root;

}
node* preorderToBST(vector<int> &preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}

int main()
{	CLEAR;

    //two sum in a BST
    // is there any pair that can sum upto that target
    // approach 1-> find inorder and find the pairs and use two pointer appoach
    // (pending)HW--> search for approach 2

    // Flatten BST to sorted linked list
    // approach 1-> save inorder in an array and then make linked list for same
    // SC....O(n) and TC....O(n)
    // approach 2 -> use the array of pointers to save the inorder traersal
    // then make left null and right joined

    // normal BST to balanced BST
    // balanced means, -1 <= left height - right height <= 1, for each node
    // approach-> make inorder and then balanced BST by mid element

    // BST from preorder
    // approach 1-> just use the method to make BST from 1st lecture..TC..O(n^2)
    // but we didnt use that property of array that it is preorder
    // approach 2-> sort the preorde, and it will give u inorder of the BST
    // approach3 -> use range
    // (pending)HW--> no need of mini, find how?

    return 0;
}