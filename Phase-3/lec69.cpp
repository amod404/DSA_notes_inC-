// Binary search tree

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;


// defination : if a node is root then all of its left values are smaller then it and right are greater ... which is true for every node
// it may be balanced or not that changes it time complexity of insertion, deletion, searching

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

// just practice 
void lot(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *front = q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}


node* insertIntoBST(node* & root,int data){
    if(!root)
        return new node(data);

    if(data > root->data)
        //insert in right
        root->right = insertIntoBST(root->right, data);
    else
        //insert in left
        root->left = insertIntoBST(root->left, data);
    
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

node* B_S_T(node* root, int target){
    if(root==NULL){ 
        return NULL;
    }
    if(root->data==target){
        return root;
    }
    if(root->data > target){
        return B_S_T(root->left,target);
    }
    else{
        return B_S_T(root->right,target);
    }
}

node* getMin(node* root){
    node* temp=root;
    while(temp->left != NULL){
        temp= temp->left;
    }
    return temp;
}
node* getMax(node* root){
    node* temp=root;
    while(temp->right != NULL){
        temp= temp->right;
    }
    return temp;
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

node* deleteFromBST(node* root, int val){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        if(root-> left != NULL && root->right ==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root-> right != NULL && root->left ==NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        
        if(root-> left !=NULL && root->right!= NULL){
            int mini = minvalue(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;

            // or u can do
            int maxi = maxvalue(root->left);
            root->data = maxi;
            root->left = deleteFromBST(root->left,maxi);
            return root;
        }

    }

    else if( val< root->data){
        root->left = deleteFromBST(root->left,val);
    }
    else{
        root->right = deleteFromBST(root->right,val);
    }
    return root;
}
node* findpre(node* root, int val) {
    node* temp = root;
    node* ans = NULL;  // Initialize to NULL

    // Search for the node containing `val`
    while (temp) {
        if (temp->data < val) {
            ans = temp;  // Update predecessor
            temp = temp->right;
        } 
        else if (temp->data > val) {
            temp = temp->left;
        } 
        else {
            break;  // Found `val`
        }
    }

    // If the node has a left subtree, find the maximum in the left subtree
    if (temp && temp->left) {
        ans = getMax(temp->left);
    }

    return ans;  // Return the predecessor node or NULL if none
}

node* findsucc(node* root, int val) {
    node* temp = root;
    node* ans = nullptr; // Initialize as NULL to handle edge cases

    while (temp) {  // Prevent null dereferencing
        if (temp->data > val) {
            ans = temp;  // Possible successor
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    // If `val` exists in the tree and has a right subtree, find min in right subtree
    node* target = root;
    while (target && target->data != val) {
        if (target->data < val) {
            target = target->right;
        } else {
            target = target->left;
        }
    }

    if (target && target->right) {
        ans = getMin(target->right);
    }

    return ans;  // Return the correct successor or nullptr if not found
}

int main()
{	CLEAR;

    node* root = NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    node* ans = B_S_T(root,10);  // ... O(logn)
    if(ans)  cout<<"finding 10 : "<< ans ->data <<endl;
    else     cout<<"10 not found "<<endl;

    //(done)HW -> inorder precedesor and inorder successor

    return 0;
}