//  binary trees question 

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

//lets go, solved myself ^^
void sum_helper(node* root,pair<int,int> currentNode, pair<int,int> & ans){
    
    currentNode.first+=root->data;
    if(root->left==NULL && root->right==NULL){
        if(currentNode.second>ans.second){
            ans=currentNode;
        }
        else if(currentNode.second==ans.second){
            if(currentNode.first>ans.first){
                ans=currentNode;
            }
        }
        return;
        //basically we checked if sum is same then the level is given priority
    }
    //non-null node

    currentNode.second++;

    if(root->left){
        sum_helper(root->left,currentNode,ans);
    }
    if(root->right){
        sum_helper(root->right,currentNode,ans);
    }

    return;
}
int sumOfLongest(node* root){
    if(root==NULL){
        return 0;
    }
    pair<int,int> ans=make_pair(0,0);
    pair<int,int> currentNode=make_pair(0,0);
    //sum,lvl

    sum_helper(root,currentNode,ans);

    return ans.first;
}

node* lca(node* root,int n1,int n2){
    //base case
    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    node*leftAns = lca(root->left,n1,n2);
    node*rightAns = lca(root->right,n1,n2);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    else if(leftAns != NULL){
        return leftAns;
    }
    else if(rightAns!=NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}

node* lca_fun(node*root, int n1, int n2){
    if(!root) return NULL;

    if(root->data == n1 || root->data==n2 ) return root;
    auto leftAns = lca_fun(root->left,n1,n2);
    auto rightAns = lca_fun(root->right,n1,n2);

    if(leftAns && rightAns) return root;
    return leftAns ? leftAns : rightAns;
}


void solve(node* root, int k, int & count, vector<int> &path){
    //base case
    if(root==NULL){
        return;
    }

    path.push_back(root->data);
    
    //left call
    solve(root->left,k,count,path);
    //right call
    solve(root->right,k,count,path);

    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }

    path.pop_back();
}
int sumK(node *root,int k){
    vector<int> path;
    int count=0;
    solve(root,k,count,path);
    return count;
}

//this is the optimized version using prefixSum and hashmap
void sumK_helper_fun(node* root, int&k , int& currSum, unordered_map<int,int>&frequency, int &ans){
    currSum+=root->data;
    ans+=frequency[currSum-k];   // check all the cases in O(1)
    frequency[currSum]++;   //storing the frequency prefix sum

    if(root->left) sumK_helper_fun(root->left,k,currSum,frequency,ans);
    if(root->right) sumK_helper_fun(root->right,k,currSum,frequency,ans);

    frequency[currSum]--;
    currSum-=root->data;
}

int sumK_fun(node* root, int k){
    if(!root) return 0;
    int currSum = 0;
    unordered_map<int,int>frequency;
    frequency[0]++;
    int ans = 0;
    sumK_helper_fun(root,k,currSum,frequency,ans);
    return ans;
}

node* solve(node* root, int&k, int Node){
    //base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == Node){
        return root;
    }

    node* leftAns = solve(root->left,k, Node);
    node* rightAns = solve(root->right,k, Node);

    if(leftAns!= NULL && rightAns == NULL){
        k--;
        if(k==0){
            k--;
            return root;
        }
        return leftAns;
    }

    else if(leftAns== NULL && rightAns != NULL){
        k--;
        if(k==0){
            k--;
            return root;
        }
        return rightAns;
    }
    
else{
    return NULL;
}

}
int kthAncestor(node* root , int k , int Node){
    
    node* ans=solve(root,k,Node);
    if(ans==NULL || ans->data == Node){
        return -1;
    }
    else{
        return ans->data;
    }

}

int KHelper(node* root, vector<int>& ans, int k, int Node) {
    if (root == NULL) return -1; // base case
    
    ans.push_back(root->data);
    if (root->data == Node) {
        if (ans.size() > k) {
            return ans[ans.size() - k - 1]; // Return the Kth ancestor
        }
        return -1; // Not enough ancestors
    }
    
    int left = KHelper(root->left, ans, k, Node);
    if (left != -1) return left;
    int right = KHelper(root->right, ans, k, Node);
    if (right != -1) return right;
    
    ans.pop_back();
    return -1;
}

int KthAncestor(node* root, int k, int Node) {
    if(!root)return -1;
    vector<int> ans;
    return KHelper(root, ans, k, Node); // Call the helper function
}


pair<int,int> helper(node * root){
    //base case
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = helper(root->left);
    pair<int,int> right = helper(root->right);
    pair<int,int> res;
    //during inclusion of current node data
    //has to exclude its left and right
    res.first = root->data + left.second + right.second;
    //during exclusion of current node data
    //may include left or right or exclude either or both
    res.second = max(left.first,left.second) + max(right.first,right.second);
    return res;
}

pair<int,int>helper_fun(node* root){
    if(!root) return {0,0};

    auto left = helper(root->left);
    auto right = helper(root->right);

    return {root->data+left.second+right.second,
    max(left.first,left.second)+max(right.first,right.second)};
}

int getMaxSum(node* root){
    pair<int,int> ans = helper(root);
    // here this int,int means a,b
    //a->maximum sum including this for current node
    //b->maximum sum excluding this for current node
    //traversal LRN (post)
    return max(ans.first,ans.second);
    
    ans = helper_fun(root);
    return max(ans.first,ans.second);
}

int main()
{	CLEAR;

    node* root=NULL;
    buildFromLevelOrder(root);
    CLEAR;

    // //sum of longest path
    // // we have to find the sum of the longest chain and if two chains are
    // // same then the one with larger sum is considered as answer
    // cout<<"sum of longest path is : "<< sumOfLongest(root)<<endl;    
    
    // Lowest common ancenstor 
    // cout<< "least common ancestor is : "<< lca(root,4,5)->data << endl; 

    //sum k
    //approach 1-> can be solved by two recursion,,,like calculate all path....brute force
    // cout<<"answer is : "<<sumK(root,2);
    // (done)HW--> find complexity and find a mistake in the question
    // O(n^2)

    //find K-th ancestor
    //approach 1-> find that path by recursion, and store that path in ans,
    //  then find k element from back side of that ans vector
    //aproach 2->without much space
    // int k=2;
    // int t=4;
    // cout<< k<<"-th ancestor of "<< t<< " is : "<< kthAncestor(root,k,t)<<endl;
    // cout<< k<<"-th ancestor of "<< t<< " is : "<< KthAncestor(root,k,t)<<endl;

    //(done)HW-->approach 1 of above probelem

    //maximum sum of non adjacent node
    // cout<<"maximum for non-adjacent nodes are : "<<getMaxSum(root)<<endl;

    
    return 0;
}