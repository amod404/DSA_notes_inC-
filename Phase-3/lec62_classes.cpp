#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#define CLEAR system("cls")
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    //constructor
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data [or -1] : "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        free(root);
        return NULL;
    }

    cout<<"enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data for inserting in right "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(node*root){
    queue<node*>q;
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

void inorder(node* root){
    //base case
    if(root==NULL){
        return;
    }

    //follow LNR

    inorder(root->left);      //L
    cout<<root->data<<" ";    //N
    inorder(root->right);     //R
}

void preorder(node* root){
    //base case
    if(root==NULL){
        return;
    }

    //follow NLR

    cout<<root->data<<" ";    //N
    preorder(root->left);      //L
    preorder(root->right);     //R
}

void postorder(node* root){
    //base case
    if(root==NULL){
        return;
    }

    //follow LRN

    postorder(root->left);      //L
    postorder(root->right);     //R
    cout<<root->data<<" ";    //N
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    int data;
    cout<<"Enter data for root : ";
    cin>>data;
    if(data == -1) return;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        cout<<"Enter left node for : "<<temp->data <<endl;
        int leftdata; 
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for : "<<temp->data <<endl;
        int rightdata; 
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }

    }
}

int numberOfLeaf(node* root){
    //base case
    if(root==NULL)
        return 1;

    return numberOfLeaf(root->left) + numberOfLeaf(root->right);
}
