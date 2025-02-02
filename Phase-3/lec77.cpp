// heap hard questions

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;
    node(int d, int r, int c){
        data= d;
        row=r;
        col=c;
    }
};

class compare{
    public:
    bool opertor(node* a, node*b){
        return a->data > b->data;
    }
};

//dry run kro...smjh ni aaya
int range(vector<vector<int>> &a,int k,int n){
    int mini = INT_MAX,maxi=INT_MIN;
    //making heap of nodes of first k elements
    priority_queue<node*,vector<node*>,compare> minHeap;

    for(int i=0; i<k; i++){
        int element = a[i][0];
        mini = min(mini,element);  // also finding mini and maxi in same loop
        maxi = max(maxi,element);
        node* temp = new node(element, i,0);
        minHeap.push(temp);
    }
    //starting and ending value of ans
    int start= mini , end = maxi;

    while(!minHeap.empty()){
        node* temp=minHeap.top();
        minHeap.pop();

        // find minimum value
        mini= minHeap.top()->data;
     
        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }

        if(temp->col +1< n){
            maxi = max (maxi,a[temp->row][temp->col +1]);
            minHeap.push(new node(a[temp->row][temp->col +1], temp->row,temp->col+1));
        }
        else{
            break;
        }
    }
    return end-start+1;
}

//ye bhini chl rha :(
void helper(int element, priority_queue<int>&maxHeap, priority_queue<int,vector<int>,greater<int>>&minHeap, int&median){
    
    if(maxHeap.size() == minHeap.size()){
        if(element<median){
            maxHeap.push(element);
            median = maxHeap.top();
        }
        else{
            minHeap.push(element);
            median = maxHeap.top();
        }
        return;
    }
    else if( maxHeap.size() > minHeap.size()){
        if(element > median){
            minHeap.push(element);
        }
        else{
            int temp = maxHeap.top();
            minHeap.push(temp);
            maxHeap.pop();
            maxHeap.push(element);
        }
        median = (minHeap.top()+maxHeap.top())/2;
        return;
    }
    else{
        if(element < median){
            maxHeap.push(element);
        }
        else{
            int temp = minHeap.top();
            maxHeap.push(temp);
            minHeap.pop();
            minHeap.push(element);
        }
        median = (minHeap.top()+maxHeap.top())/2;
        return;
    }
    cout<<"HI"<<endl;
}
vector<int> callMedian(vector<int> &arr){
    int n= arr.size();
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int median = 0;

    for(int i=0; i<n;i++){
    helper(arr[i],maxHeap,minHeap,median);
    ans.push_back(median);
    }
    return ans;
}

int main()
{
    // smallest range in k-list
    // its like take atleast one element fron each list, such that the range is minimum
    // approach -> 1.... take the first k elemets and find max and min....then keep on increaseing min..use pointers or node
    // approach -> 2.... to optimize the min and max use heap

    // find median of a data stream
    // vector<int> arr={1,4,2,3};
    // vector<int> ans; 
    // ans = callMedian(arr);
    // for(auto i: ans){
    //     cout<<i<<" ";
    // }cout<<endl;

    return 0;
}