// questions on binary tree

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
#include"lec62_classes.cpp"
#define CLEAR system("cls")
using namespace std;

//self solved ~.~
void helper(node* root,int cnt,int & ans){
    //base case
    if(root==NULL){
        return;
    }

    //follow LRN

    helper(root->left,cnt+1,ans);      //L
    helper(root->right,cnt+1,ans);     //R
    if(cnt>ans){                //N
        ans = cnt;
    }    
}
int Height(node* root){
    int cnt=1;
    int ans=0;
    helper(root,cnt,ans);
    return ans;
}

//sir's solution
int height(node* root){
    if(root==NULL)
        return 0;

    //height of left and right
    int left = height(root->left);
    int right = height(root->right);

    //ans is maximum branch + that root node
    int ans = max(left,right)+1;
    return ans;

    //just solve one case, baki recursion sabhal lega
}
//+.+
int diameter(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    // there can be three option, 
    // either whole in right or whole in left
    // or combination of bot including root node

    int op1=diameter(root->left);
    int op2=diameter(root->right);

    int op3= height(root->left)+height(root->right)+1;

    return max(op1,max(op2,op3));
    //TC....O(n^2), as heigt and diameter both are calling
}

pair<int,int> diameter_fast(node*root){
    //base case
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        // first one is diameter and second one is height
        return p;
    }

    pair<int,int> left = diameter_fast(root->left);
    pair<int,int> right = diameter_fast(root->right);

    // here we are minimizing the iteration
    int op1=left.first;  // left ka diameter
    int op2=right.first;   // right ka diameter

    int op3= left.second+right.second+1;  // also including root node

    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));   // for max diameter
    ans.second=max(left.second,right.second)+1;   // for max height
    return ans;

    //NOTE:- this method of passing some structures like pairs make 
    // iterations less as now you can do two job in one go
}

//just for practice
pair<int,int>fun_diameter_fast(node*root){
    if(root == NULL){
        return {0,0};
    }

    auto left = fun_diameter_fast(root->left);
    auto right = fun_diameter_fast(root->right);

    int a = max({left.first,right.first,left.second+right.second+1});
    int b = max({left.second,right.second})+1;
    return {a,b};
}

int Diameter(node* root){
    return diameter_fast(root).first;
    return fun_diameter_fast(root).first;
}

bool isBalanced(node*root){
    //base case 
    if(root==NULL)
        return true;
    

    bool left= isBalanced(root->left);

    bool right= isBalanced(root->right);

    bool diff = abs(Height(root->left)-Height(root->right)) <=1;

    
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }

    // // this will make the iterations less and if left is false, it wont go for next checking....so average TC gets minimize
    // if(isBalanced(root->left) && isBalanced(root->right) && (abs(Height(root->left)-Height(root->right)) <=1)){
    //     return true;
    // }
    // else{
    //     return false;
    // }

    //TC....O(n^2)
}

pair<bool,int> isBalanced_fast(node* root){
    //base case 
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<bool,int> left=isBalanced_fast(root->left);
    pair<bool,int> right=isBalanced_fast(root->right);
    
    bool diff = abs(left.second-right.second) <=1;

    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;  // maximum height plus that node

    if(left.first && right.first && diff){ // can save iterations here also
        ans.first=true;
    }
    else{
        ans.first=false;
    }

    // :) dont forget to return =3
    return ans;
}


//more optimized code
pair<int,bool> fun_is_Balanced_fast(node*root){
    if(root==NULL) return {0,true};

    auto left = fun_is_Balanced_fast(root->left);
    if(!left.second) return {0,false};

    auto right = fun_is_Balanced_fast(root->right);
    if(!right.second) return {0,false};

    if(abs(left.first-right.first)>1) return {0,false};

    return {max(left.first,right.first)+1,true};
}

bool IsBalanced(node* root){
    return isBalanced_fast(root).first;
    return fun_is_Balanced_fast(root).first;
}

bool isIdentical(node *r1, node *r2){
    //base case
    if(r1== NULL && r2 == NULL){
        return true;
    }
    if(r1==NULL || r2 != NULL){
        return false;
    }
    if(r1!= NULL && r2==NULL){
        return false;
    }

    //both are non-NULL
    bool left= isIdentical(r1->left,r2->left);
    bool right= isIdentical(r1->right,r2->right);

    bool value = (r1->data == r2->data);

    if(left && right && value){  // again save iteration by writing this boolian values directly in if condition
        return true;
    }
    else{
        return false;
    }
}

bool is_identical_fun(node*r1, node*r2){
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 == NULL || r2 == NULL) return false;

    if(!is_identical_fun(r1->left,r2->left)) return false;
    if(!is_identical_fun(r1->right,r2->right)) return false;

    return (r1->data == r2->data);
}


//solved myself ^^
pair<bool,int> isSum_helper(node*root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        // is sum? and sum
        return p;
    }
    
    pair<bool,int> left = isSum_helper(root->left);
    pair<bool,int> right = isSum_helper(root->right);

    int sum = left.second+right.second; // can be zero and also non zero

    pair<bool,int>ans;
    ans.second=sum+root->data;

    if((sum==0 || sum==root->data)&& left.first && right.first){  // again save iteration, because if once false then no need to check the rest conditions
        ans.first=true;
    }
    else{
        ans.first=false;
    }

    return ans;
}

pair<bool,int> isSum_fun(node* root){
    if(root==NULL) return {true,0};

    auto left = isSum_fun(root->left);
    if(!left.first) return {false,0};
    auto right = isSum_fun(root->right);
    if(!right.first) return {false,0};

    if(left.second + right.second == root->data)
        return {true,2*root->data};
    else return {false,0};

}


bool isSum(node*root){
    return isSum_helper(root).first;
}

int main()
{	CLEAR;

    // Height of binary tree
    node* root=NULL;
    buildFromLevelOrder(root);
    CLEAR;
    levelOrderTraversal(root);
    cout<<"Height of tree is : "<< Height(root) <<endl;
    cout<<"Height of tree is : "<< height(root) <<endl;

    //diameter of a tree
    cout<<"Diameter of tree is : "<<diameter(root)<<endl;
    cout<<"Diameter of tree is : "<<Diameter(root)<<endl;

    //check for balanced tree...height of left and right subtree for all nodes must be <=1
    cout<<"Is it balance? -> "<< isBalanced(root)<<endl;
    cout<<"Is it balance? -> "<< IsBalanced(root)<<endl;

    // //identical or not?
    // node *r1=NULL;
    // node *r2=NULL;
    // buildFromLevelOrder(r1);
    // CLEAR;
    // buildFromLevelOrder(r2);
    // CLEAR;
    // cout<<"is Identical? -> "<< isIdentical(r1,r2)<<endl;

    //(pending)HW-->make recursibve tree and write both complexity

    //check sum tree or not
    cout<<"Is it a Sum tree -> "<< isSum(root)<<endl;
    

    return 0;
}
