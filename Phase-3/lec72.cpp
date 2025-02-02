// Binary search tree -> imp question(independent quetsions in this one)

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

//approach 1
void inorder(node* root, vector<int> & in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int> mergeSorted(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();
    vector<int>ans(n+m);

    int i=0,j=0,k=0;

    while(i<n && j<m) {
        if(a[i]<b[j]){
            ans[k++]=a[i++];
        }
        else{
            ans[k++]=b[j++];
        }
    }

    while(i<n){
        ans[k++]=a[i++];
    }

    while(j<n){
        ans[k++]=a[j++];
    }

    return ans;
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
node * mergeBST(node* root1, node* root2){
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int> mergedArray = mergeSorted(bst1,bst2);

    return inorderToBST(0,mergedArray.size()-1,mergedArray);
}

//approach 2
void convertIntoSortedDLL(node* root, node* &head){
    //base case
    if(root==NULL){
        return;
    }

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if(head!= NULL){
        head->left = root;
    }
    head = root;

    convertIntoSortedDLL(root->left,head);
}
node* mergeLL(node*head1, node*head2){
    node* head=NULL;
    node* tail=NULL;
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1= head1->right;
            }
        }
        else{
            if(head == NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right = head2;
                head1->left = tail;
                tail = head2;
                head2= head2->right;
            }
        }
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1= head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2= head2->right;
    }
    
    return head;
}
int countnode(node* head){
    int cnt=0;
    node* temp =head;
    while(temp!= NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
node* sortedLLtoBST(node* head, int n){
    //base case
    if(n<=0 || head==NULL){
        return NULL;
    }

    node* left = sortedLLtoBST(head,n/2);

    node* root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLLtoBST(head, n-n/2-1);
}
node* MergeBST(node* root1, node* root2){
    // step1: convert BST into sorted DLL in-place
    node* head1=NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left ==NULL;
    node* head2=NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left= NULL;

    // step2: merge two sorted linked list
    node* head = mergeLL(head1,head2);

    // step3: convert SLL in BST
    return sortedLLtoBST(head,countnode(head));
}

int main()
{	CLEAR;

    // merge two BST

    //approach 1-> find inorder of both BST
    //             than merge two sorted array
    //             than simple make BST from inorder
    //             TC and Sc...both O(m+n) 

    // if we are asked to optimize the space

    //aproach 2-> convert both the bst into sorted Doubly linked list
    //            merge two sorted linked list
    //            sorted linked list into bst .( make sure to optimize space)
    //            TC..O(m+n), SC...O(h1+h2)

    //(pending)HW-> dry the code for examples and find its TC and SC

    return 0;
}