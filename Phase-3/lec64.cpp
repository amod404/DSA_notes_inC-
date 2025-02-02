// binary tree questions :-

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
#include"lec62_classes.cpp"
#define CLEAR system("cls")
using namespace std;

void ZigZagtraversal(node* root){
    if(root==NULL){
        return;
    }

    queue<node*> q;
    q.push(root);

    bool leftToRight=true;

    while(!q.empty()){
        //store each level
        int size = q.size();
        vector<int> ans(size);

        for(int i=0;i<size;i++){
            node* front = q.front();
            q.pop();

            //normal insert or reverse insert...(if i or size-i-1)
            int j=leftToRight ? i : size-i-1;
            ans[j]=front->data;

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }

        //direction for next iteration
        leftToRight=!leftToRight;

        //print the level and give nextline
        for(auto i:ans){
            cout<<i<<" ";
        }cout<<endl;
    }
}

//Optimized myself ^^
void zigzagtraversal(node* root){
    if(root==NULL){
        return;
    }
    deque<node*> q;
    q.push_back(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        
        if(leftToRight){
            for(int i=0;i<size;i++){
                node*front=q.front();
                q.pop_front();
                
                cout<<front->data<<" ";

                if(front->left){
                    q.push_back(front->left);
                }
                if(front->right){
                    q.push_back(front->right);
                }
            }
        }
        else{
            for(int i=0;i<size;i++){
                node*back=q.back();
                q.pop_back();
                
                cout<<back->data<<" ";

                if(back->right){
                    q.push_front(back->right);
                }
                if(back->left){
                    q.push_front(back->left);
                }
            }
        }
        cout<<endl;
        leftToRight=!leftToRight;
    }
}

void zigZagTraversal_fun(node* root){
    if(!root) return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    bool leftToRight = true;

    while(!q.empty()){
        deque<int>temp;
        while(!q.empty()){
            node* curr = q.front();
            q.pop();
            if(curr==NULL){
                if(!q.empty()) q.push(NULL);
                break;
            }

            temp.push_back(curr->data);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }

        if(leftToRight){
            while(!temp.empty()){
                cout<<temp.front()<<" ";
                temp.pop_front();
            }
        }
        else{
            while(!temp.empty()){
                cout<<temp.back()<<" ";
                temp.pop_back();
            }
        }
        cout<<endl;
        leftToRight = !leftToRight;
    }
}


void traverseleft(node* root,vector<int> & ans){
    //base case
    if((root==NULL) || (root->left== NULL && root->right==NULL)){
        return;
    }
    //now this non-NULL node must have either left or right 
    
    //value store
    ans.push_back(root->data);
    //note it is not printing the leaf

    if(root->left){
        traverseleft(root->left,ans);
    }
    else{
        traverseleft(root->right,ans);
    }

    //can make else if for right and than the else case
    //will handle the case of both null 
    //and we dont have to add it in base case
}
void traverseleaf(node* root,vector<int> & ans){
    //base case
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right == NULL){
        //store the leaf node
        ans.push_back(root->data);
    }

    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
}

void traverseright(node* root,vector<int> & ans){
    if((root==NULL) || (root->left==NULL && root->right == NULL)){
        return;
    }

    //traversal
    if(root->right){
        traverseright(root->right,ans);
    }
    else{
        traverseright(root->left,ans);
    }

    //return time mai value store krva do
    ans.push_back(root->data);
}
void BoundaryTraversal(node* root){
    vector<int> ans;
    if(root==NULL){
        return;
    }

    //left part store
    traverseleft(root,ans);
    //traverse seprately to diffrent subtree as 
    //it shouldn't add root as a leaf if it is a single node
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
    //don't include root in right subtree
    traverseright(root->right,ans);

    for(auto i:ans){
        cout<< i << " ";
    }cout<<endl;

}

void verticalTraversal(node* root){
    map<int,vector<int>> nodes;
    //horizontal distance->vector<int>
    queue<pair<node*,int>> q;
    //current node,horizontal distance

    if(root==NULL){
        return;
    }

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp =q.front();
        q.pop();
        
        node* frontNode = temp.first;
        int hd = temp.second;
        // int lvl = temp.second.second;

        nodes[hd].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    for(auto i : nodes){
        for(auto j: i.second){
            cout<< j<<" ";
        }
        cout<<endl;
    }
}


void vT_helper(node*root, map<int,vector<int>>&nodes, int&hd){

    if(root == NULL)return;

    nodes[hd].push_back(root->data);

    hd--;
    if(root->left) vT_helper(root,nodes,hd);
    hd+=2;
    if(root->right) vT_helper(root->right,nodes,hd);
    hd--;
}

void VerticalTraversal_fun(node* root){
    map<int,vector<int>>nodes;
    int hd = 0;
    vT_helper(root,nodes,hd);

    for(auto i:nodes){
        for(auto j: i.second){
            cout<<j<<" ";
        }cout<<endl;
    }
}

//made myself ^^
void VerticalTraversal_helper(node* root, map<int,vector<int>> & nodes, int hd){
    if(root==NULL){
        return;
    }

    nodes[hd].push_back(root->data);

    VerticalTraversal_helper(root->left,nodes, hd-1);
    VerticalTraversal_helper(root->right,nodes, hd+1);

}
void VerticalTraversal(node* root){
    map<int,vector<int>> nodes;
    VerticalTraversal_helper(root,nodes,0);

    for(auto i : nodes){
        for(auto j: i.second){
            cout<< j<< " ";
        }
    }cout<<endl;
}

void topView(node* root){
    map<int,vector<int>> nodes;
    //hd->vector<int>
    queue<pair<node*,int>> q;
    //current node,horizontal distance

    if(root==NULL){
        return;
    }

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp =q.front();
        q.pop();
        
        node* frontNode = temp.first;
        int hd = temp.second;
        // int lvl = temp.second.second;

        nodes[hd].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    for(auto i : nodes){
        cout<<i.second[0]<<" ";
    }
    cout<<endl;
    //copy paste -_-
}

void TopView(node* root){
    vector<int> ans;
    if(root==NULL){
        return;
    }
    map<int,int> topNode;
    queue<pair<node*,int>>q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd]=frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }

    }
    for(auto i : topNode){
        cout<<i.second<<" ";
    }cout<<endl;
}

//made myself ^^
void top_view_helper(node* root, map<int,int> &topview, int hd){
    if(root==NULL)
        return;
    
    if(topview.find(hd)==topview.end()){
        topview[hd]=root->data;
    }

    if(root->left){
        top_view_helper(root->left,topview,hd-1);
    }
    if(root->right){
        top_view_helper(root->right,topview,hd+1);
    }
}
void top_view(node*root){
    if(root==NULL)
        return;
    map<int,int> topview;
    top_view_helper(root, topview, 0);

    for(auto i: topview){
        cout<< i.second<<" ";
    }
    cout<<endl;
}

void BottomView(node* root){
    if(root==NULL){
        return;
    }
    map<int,int> bottomNode;
    queue<pair<node*,int>>q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        bottomNode[hd]=frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }

    }

    for(auto i : bottomNode){
        cout<<i.second<<" ";
    }cout<<endl;
}

void bottom_view_helper(node* root, map<int,int> & bottomview, int hd){
    if(root==NULL){
        return;
    }

    bottomview[hd]=root->data;

    if(root->left){
        bottom_view_helper(root->left, bottomview, hd-1);
    }
    if(root->right){
        bottom_view_helper(root->right, bottomview, hd+1);
    }
}
void bottom_view(node* root){
    if(root==NULL){
        return;
    }
    map<int,int> bottomview;
    bottom_view_helper(root,bottomview,0);

    for(auto i: bottomview){
        cout<<i.second<<" ";
    }
    cout<<endl;
}

void LeftView(node* root){
    vector<int> ans;
    if(root==NULL){
        return;
    }
    map<int,int> leftNode;
    queue<pair<node*,int>>q;
    //simple here instead of hd we define level as second attribute in map and queue

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        if(leftNode.find(hd) == leftNode.end()){
            leftNode[hd]=frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd+1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }

    }
    for(auto i : leftNode){
        cout<<i.second<<" ";
    }cout<<endl;
}

void RightView(node* root){
    vector<int> ans;
    if(root==NULL){
        return;
    }
    map<int,int> rightNode;
    queue<pair<node*,int>>q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        rightNode[hd]=frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd+1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }

    }
    for(auto i : rightNode){
        cout<<i.second<<" ";
    }cout<<endl;
}

//solved myself^^
void left_View_helper(node* root,int lvl, map<int,int> & leftView){
    if(root==NULL){
        return;
    }

    if(leftView.find(lvl) == leftView.end()){
        leftView[lvl]=root->data;
    }

    left_View_helper(root->left,lvl+1,leftView);
    left_View_helper(root->right,lvl+1,leftView);
}
void left_View(node* root){
    if(root==NULL){
        return;
    }
    map<int,int> leftView;
    left_View_helper(root,0,leftView);
    for(auto i:leftView){
        cout<<i.second<<" ";
    }cout<<endl;
}

void right_View_helper(node* root,int lvl, map<int,int> & rightView){
    if(root==NULL){
        return;
    }

    rightView[lvl]=root->data;

    right_View_helper(root->left,lvl+1,rightView);
    right_View_helper(root->right,lvl+1,rightView);
}
void right_View(node* root){
    if(root==NULL){
        return;
    }
    map<int,int> rightView;
    right_View_helper(root,0,rightView);
    for(auto i:rightView){
        cout<<i.second<<" ";
    }cout<<endl;
}

//solved myself ^^ 
void diagnol_view_helper(node* root,map<int,int> &view, int dd){
    if(root==NULL){
        return;
    }

    if(view.find(dd)== view.end()){
        view[dd]=root->data;
    }

        diagnol_view_helper(root->left,view,dd-1);
        diagnol_view_helper(root->right,view,dd);
}
void diagnol_view(node* root){
    if(root==NULL){
        return;
    }
    map<int,int> view;
    diagnol_view_helper(root,view,0);
    for(auto i: view){
        cout<< i.second<<" ";
    }cout<<endl;
}


void diagnol_view_helper_fun(node*root, map<int,vector<int>>&nodes, int&dd){
    if(root->right) diagnol_view_helper_fun(root->right,nodes,dd);
    if(root->left) diagnol_view_helper_fun(root->right,nodes,--dd);
}

void diagnol_view_fun(node* root){
    if(!root) return;
    map<int,vector<int>>nodes;
    int dd = 0;
    diagnol_view_helper_fun(root,nodes,dd);

    for(auto i:nodes){
        for(auto j:i.second){
            cout<<j<<" ";
        }cout<<endl;
    }
}


int main()
{	CLEAR;
    
    node* root=NULL;
    buildFromLevelOrder(root);

    // //zig-zag tarversal
    // //approach 1-> use of boolian flag to store the direction
    // //TC or SC.....O(n)
    // CLEAR;
    // levelOrderTraversal(root);
    // cout<<endl;
    // ZigZagtraversal(root);
    // cout<<endl;
    zigZagTraversal_fun(root);
    cout<<endl;

    // //boundary traversal
    // //approach--> 1.left part without leaf node
    // //            2.all leaf node
    // //            3.right part without leaf and root node in reverse order
    // BoundaryTraversal(root);

    // //vertical traversal of binary tree
    // verticalTraversal(root);
    // VerticalTraversal(root);

    // //top view of binary tree
    // topView(root);
    // TopView(root);
    // top_view(root);

    // //bottom view of binary tree
    // BottomView(root);
    // bottom_view(root);

    // //Left view of binary tree
    // LeftView(root);
    // left_View(root);

    // //Right view of binary tree
    // RightView(root);
    // right_View(root);

    //(done)HW-->make recursive function of top and bottom view also

    //(done)HW-->diagnol traversal of binary tree
    // diagnol_view(root);

    return 0;
}
