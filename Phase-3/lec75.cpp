//question on heap

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int kthSmallest(vector<int>& arr, int k){
    int n = arr.size();
    if(k>n || k<=0){
        return -404;
    }
    priority_queue<int> pq;  //how to declare MAX-heap

    //push first k elements
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    //for remaining elements
    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //now the topmost element is kth smallest element
    return pq.top();
}

struct node{
    node*left;
    node* right;
    int data;
};

int countNode( struct node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    return (1 + countNode(root->left) + countNode(root->right));
}
bool isCBT(struct node* root,int index, int cnt){
    if(root==NULL){
        return true;
    }
    if(index>=cnt){
        return false;
    }

    // bool left = isCBT(root->left, 2*index+1,cnt);
    // bool right = isCBT(root->right, 2*index+2,cnt);
    // return (left && right);

    //optimized these && case of recursion
    if(!isCBT(root->left, 2*index+1,cnt)){
        return false;
    }
    else{
        if(isCBT(root->right,2*index+2,cnt)){
            return true;
        }
        else{
            return false;
        }
    }
}
bool isMaxOrder(struct node* root){
    //leaf node
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    else if( root->right == NULL){
        return (root->data > root->left->data);
    }
    else{
        //means both child nodes are present
        return(
                ( root-> data > root->left->data     // left check
                && root->data > root->right->data )  // right check
                && isMaxOrder(root->left)            // if true than futher recursive tree
                && isMaxOrder(root->right)
            );   
    }
}
bool isHeap(struct node* root){
    int index = 0;
    //frist counting the numbers of nodes
    int totalCount=countNode(root);
    // we will check if it have all the nodes is correct order(other than last level all are completly filled)
    // ans is itmax order or not
    if( isCBT(root,index,totalCount) && isMaxOrder(root)){
        return true;
    }
    return false;
}

int minCost( vector<int> &arr){
    //create a min heap
    priority_queue<int,vector<int>,greater<int>>pq;
    
    //adding all elements
    int n=arr.size();
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    int cost =0;
        while(pq.size()>1){
            int a =pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            int sum = a+b;
            cost+=sum;

            pq.push(sum);
        }

    return cost;
}

int main()
{	CLEAR;

    //K-th smallest element
    //approach 1->do heap sort and find kth element from start
    //approach 2->make max heap from first k elements
    //            for remaining elements if curr is smaller that heap.top(),
    //            heap.pop(), heap.push(curr)....at end the top most elemet is kth smallest element
    // vector<int> arr={12,11,10,9,8,7,6,5,4};
    // int k;
    // cout<<"enter the value of K : ";
    // cin>>k;
    // cout<<"your array is :"<<endl;
    // for(auto i:arr){
    //     cout<<i<<" ";
    // }cout<<endl;
    // cout<<"the "<<k<<"th smallest element is : "<<kthSmallest(arr,k);

    // Is binary tree heap?
    // node* root = new node;
    // root->data= 55;
    // root->left = new node;
    // root->left->data = 54;
    // root->right = new node;
    // root->right->data = 51;
    // root->left->left=NULL;
    // root->left->right=NULL;
    // root->right->left=NULL;
    // root->right->right=NULL;
    // cout << "is it heap? -> " << isHeap(root) << endl;

    //merge two binry max-heap
    //approach-> join both array in any order and then heapify...simple
    
    //minimum cost to join N ropes, cos of each join is equal to sum of their length
    // vector<int> v={6,2,3,4};
    // cout<< "min cost is: "<< minCost(v) <<endl;
    
    //(pending)CW,HW-> convert BST in MIN heap
    // constraints--> all left aliments are less than all right elements
    return 0;
}