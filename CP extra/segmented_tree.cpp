#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;

void build(vector<int>&arr,vector<int>&seg, int index, int low, int high){
    //base case pe answer store karvao
    if(low==high){
        seg[index] = arr[low];
        return;
    }
    //split the array into two equal parts
    int mid = (low+high)/2;
    //recursive call for both parts
    build(arr,seg,2*index+1,low,mid);
    build(arr,seg,2*index+2,mid+1,high);

    //during return 2*index+1 and 2*index+2 are already solved
    // sore answer for curr index
    seg[index] = max(seg[2*index+1],seg[2*index+2]);
}

int query(vector<int>&seg, int index, int low, int high, int&l, int&r){
    // if completely inside range return the answer
    if(low>=l && high<=r){
        return seg[index];
    }
    
    // if does not lie in the range
    if(high<l || low>r){
        return INT_MIN;
    }

    //if it partial overlap
    int mid = (low+high)/2;
    int left = query(seg,2*index+1,low,mid,l,r);
    int right = query(seg,2*index+2,mid+1,high,l,r);

    return max(left,right);
}

void pointUpdate(vector<int>&seg,int index,int low, int high, int& node, int& val){
    //if we reached the node
    if(low==high){
        seg[index]=val;
        return;
    }

    int mid = (low+high)/2;
    // if node sis in left half
    if(node <=mid && node>=low)
    pointUpdate(seg,2*index+1,low,mid,node,val);

    //if node is in right half
    else
    pointUpdate(seg,2*index+2,mid+1,high,node,val);

    //in return time apdate the whole array ~ backtracking
    seg[index] = max(seg[2*index+1],seg[2*index+2]);
}

void rangeUpdate(vector<int>&seg,vector<int>&lazy,int index, int high, int low, int&l, int& r, int& val){
    //updating the lazy part
    if(lazy[index]!=0){
        //add the lazy
        seg[index]+=(high-low+1)*lazy[index];
        //if it is not leaft node...pass the lazy work on its child
        if(low!=high){
            lazy[2*index+1] += lazy[index];
            lazy[2*index+2] += lazy[index];
        }
        //remove the lazy from index
        lazy[index]=0;
    }

    //if it comppletely remain outside the range
    if(r<low || l>high || low>high) return;

    //if it completely remain inside the range
    if(low>=l && high<=r){
        //update that node with value 
        seg[index] += (high-low+1)*val;
        //store the lazy work
        if(low!=high){
            lazy[2*index+1] += val;
            lazy[2*index+2] += val;
        }
        return;
    }

    //if it partial overlaps pass the value
    int mid = (low+high)/2;
    rangeUpdate(seg,lazy,2*index+1,low,mid,l,r,val);
    rangeUpdate(seg,lazy,2*index+2,mid+1,high,l,r,val);

    ///duriing return time updat the values of parents
    seg[index] = max(seg[2*index+1],seg[2*index+2]);
    //order of steps matter
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }    
    vector<int>seg(4*n+5);
    vector<int>lazy(4*n+5,0);


    build(arr,seg,0,0,n-1);



    return 0;
}