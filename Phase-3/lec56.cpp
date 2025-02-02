// stack -> (hard)largest rectangle
// when I say hard means hard...!

#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

//messed up approach...dry run
vector<int> nextSmaller(vector<int> &arr){
    int i= arr.size()-1;
    vector<int> ans;
    stack<int>bin;
    bin.push(-1);

    for(;i>=0;i--){
        
        while(bin.top()>=arr[i]){
            bin.pop();  //what is poping is no longer needed for next checking as it is greater than curr element, so it cant be next smaller for next number
        }
        //ans is stack ka top
        ans.push_back(bin.top());
        bin.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

//if your life is going well...read this :)
vector<int> nextSmallerElement(vector<int>&arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int>bin;
    bin.push(-1);

    for(int i=n-1;i>=0;i--){
        
        while(bin.top()!=-1 && arr[i]<=arr[bin.top()]){
            bin.pop();  //what is poping is no longer needed for next checking as it is greater than curr element, so it cant be next smaller for next number
        }
        //ans is stack ka top
        ans[i]=bin.top();
        bin.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int>&arr){
    int n= arr.size();
    vector<int> ans(n);
    stack<int>bin;
    bin.push(-1);

    for(int i=0;i<n;i++){
        
        while(bin.top()!=-1 && arr[i]<=arr[bin.top()]){
            bin.pop();  //what is poping is no longer needed for next checking as it is greater than curr element, so it cant be next smaller for next number
        }
        //ans is stack ka top
        ans[i]=bin.top();
        bin.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>&heights){
    int n= heights.size();

    vector<int>next(n);
    next = nextSmallerElement(heights);

    vector<int>prev(n);
    prev = prevSmallerElement(heights);

    int ans=-1;
    for(int i=0;i<n;i++){
        if(next[i]==-1){
            next[i]=n;
        }
        ans=max(ans,heights[i]*(next[i]-prev[i]-1));
        // int l=heights[i];
        // int b = next[i]-prev[i]-1;
        // ans=max(ans,l*b);
    }
    return ans;
}

// // //function is used in next lecture
// int main()
// {
//     // // next smaller element...return -1 for end case and if no element is present
//     // vector<int> arr={2,1,4,3,1,3};
//     // vector<int>ans=nextSmaller(arr);
//     // for(auto i:arr){
//     //     cout<<i<<" ";
//     // }cout<<endl;
//     // for(auto i:ans){
//     //     cout<<i<<" ";
//     // }cout<<endl;

//     //largest area for histogram rectangles
//     // vector<int> arr={1,2,3,4,5,5,4,3,2,1};
//     // cout<<"Largest area is -> "<<largestRectangleArea(arr)<<endl;
    
//     return 0;
// }
