// Binary search tree -> questions

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


bool isBST(node* root, int min, int max){
    if(root==NULL){
        return true;
    }

    if(root->data >= min && root-> data <= max){
        bool left = isBST(root, min, root->data);
        bool right = isBST(root, root->data, max);
        return left && right;
    }
    else{
        return false;
    }

    // optimize by breaking when get one false
}

bool isBST_fun(node* root, int min, int max){
    if(!root)return true;

    if(root->data < min || root->data > max) return false;

    if(!isBST_fun(root,min,root->data)) return false;

    if(!isBST_fun(root,root->data,max)) return false;

    return true;
}

bool validBST(node* root){
    if(root==NULL){
        return true;
    }
    int min=INT_MIN;
    int max=INT_MAX;
    return isBST(root,min,max);
}

int solve(node* root, int& i, int& k){
    //base case
    if(root==NULL){
        return -1;
    }
    // L
    int left = solve(root->left, i,k);

    if(left!=-1){
        return left; // when traversal break...return the values during return 
    }

    //N
    i++;
    if(i==k){
        return root->data; // inorder traversal will break here 
    }

    //R
    return solve(root->right, i,k);
}

int kThsmallest(node* root, int k){
    int i=0;
    return solve(root,i,k);
}

void solve_fun(node* root, int& k, int& i,int&ans){
    if(!root) return;

    solve_fun(root->left,k,i,ans);
    if(ans != -1) return;
    
    i++;
    if( i == k ) {
        ans=root->data;
        return;
    }

    solve_fun(root->right,k,i,ans);
}

int kTsmallest_fun(node*root,int k){
    int i = 0;
    int ans = -1;
    solve_fun(root,k,i,ans);
    return ans;
}



int solve_(node* root, int & i, int k){
    if(root==NULL){
        return -1;  //  base case
    }
    //this time the order will be R N L (reverse of inorder) reverse sorted array

    int right = solve_(root->right,i,k);

    if(right!=-1){
        return right;  // use to break the traversal
    }

    //N
    i++;
    if(i==k){
        return root->data;  // traversal is breaking here
    }

    //L
    return solve_(root->left,i,k);
}

int kThlargest(node* root, int k){
    int i=0;
    int ans = solve_(root, i, k);
    return ans;
}


void Solve_fun(node* root, int& k, int&i, int& ans){
    if(root == NULL) return;

    Solve_fun(root->right,k,i,ans);
    if(ans!=-1) return;

    if(++i == k){
        ans = root->data;
        return ;
    }
    Solve_fun(root->left, k, i, ans);
}

int kThLargest_fun(node*root, int k){
    int i = 0;
    int ans = -1;
    Solve_fun(root, k, i, ans);
    return ans;
}



int minvalue(node* root){
    node* temp=root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}
int maxvalue(node* root){
    node* temp=root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}


pair<int,int> cessors(node* root, int key){
    // find key--using Binary search
    node* temp= root;
    int pre=-1;
    int suc=-1;

    while(temp && temp->data != key){
        //also storing previous posible answers
        if(temp->data > key){
            suc = temp->data;
            temp = temp -> left;
        }
        else{
            pre = temp->data;
            temp= temp->right;
        }
    }
    if(!temp) return {-1,-1};

    // find pre and sec
    node* leftTree = temp->left;
    while(leftTree!=NULL){
        //calculating for max in left
        pre = leftTree->data;
        leftTree = leftTree->right;
    }

    node* rightTree = temp->right;
    while(rightTree!= NULL){
        // calculating for min in right
        suc = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pre,suc};
}

pair<int,int> cessors_gpt(node* root, int key){
    node* temp = root;
    int pre = -1;
    int suc = -1;

    while (temp && temp->data != key) {
        if (temp->data > key) {
            suc = temp->data;  // candidate for successor
            temp = temp->left;
        } else {
            pre = temp->data;  // candidate for predecessor
            temp = temp->right;
        }
    }

    if (!temp) return {-1, -1};  // key not found

    // Find predecessor (max in the left subtree)
    if (temp->left) {
        node* leftTree = temp->left;
        while (leftTree->right) {
            leftTree = leftTree->right;
        }
        pre = leftTree->data;
    }

    // Find successor (min in the right subtree)
    if (temp->right) {
        node* rightTree = temp->right;
        while (rightTree->left) {
            rightTree = rightTree->left;
        }
        suc = rightTree->data;
    }

    return {pre, suc};
}

node* LCAinBST(node* root, int &value1, int &value2){
    if(root==NULL){
        return NULL;
    }
    if(root->data < value1 && root->data < value2){
        return LCAinBST(root->right,value1,value2);
    }
    else if(root->data > value1 && root->data > value2){
        return LCAinBST(root->left,value1,value2);
    }
    else{
        // this is the answer
        return root;
    }
    // can use iterative way to optimizes space
}

node* LCAinBST_iter(node* root, int value1, int value2){
    while(root){
        if(root->data < value1 && root->data <value2)
            root = root->right;
        else if(root->data > value1 && root->data > value2)
            root = root->left;
        else break;
    }
    return root;
}

int main()
{	CLEAR;

    //valid BST
    // approach !-> inorder traversal and then see if it is sorted or not
    // O(n) time complexity and O(n) space complexity
    // approach 2-> find the range

    // find Kth smallestand Kth lasrgest
    // approach 1-> use inorder traversal and find kth element from required end
    // use and counter so that you dont ahve to travel whole tree with inorder traversal
    // approach 2-> use moris traversal to reduce space complexity
    // (done)HW--> do the 2nd approach
    // (done)HW--> write the code for kth largest 

    // inorder predecessor and successor in BST
    // approach 1-> use a vector and find that key and return the prev and next index value
    // appraoch 2-> find the key and the maximum in left BST and min value in right BST is the answer
    // node*root=NULL;
    // takeInput(root);
    // pair<int,int> ans = cessors(root,5);
    // cout << ans.first << endl;
    // cout << ans.second << endl;

    // LCA of a binary tree
    // exploiting the property of BST
    //(done)HW--> use iterative way to solve same
    
    return 0;
}