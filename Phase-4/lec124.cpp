//dp-23

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){

    if(index == nums1.size()){
        return 0;
    }

    int ans = INT_MAX;

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    if(swapped){
        swap(prev1,prev2);
    }

    //noswap
    if(nums1[index] > prev1 && nums2[index] > prev2){
        ans = solve(nums1,nums2,index+1,false);
    }

    //swap
    if(nums1[index] > prev2 && nums2[index] > prev1){
        ans = min(ans, 1 + solve(nums1,nums2,index+1,true));
    }

    return ans;
}

int minSwap(vector<int>& nums1, vector<int>& nums2){
    // bool swapped=0;
    // nums1.insert(nums1.begin(),-1);
    // nums1.insert(nums2.begin(),-1);
    // return solve(nums1,nums2,1,swapped);

    int n=nums1.size();
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    bool swapped=0;
    nums1.insert(nums1.begin(),-1);
    nums1.insert(nums2.begin(),-1);

}

int main()
{	CLEAR;

    



    return 0;
}