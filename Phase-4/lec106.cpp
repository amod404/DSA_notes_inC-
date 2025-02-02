//dp-05

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
using namespace std;

int solveTab_optimized(vector<int>&nums){
    int n = nums.size();

    int prev2=0;
    int prev1=nums[0];

    for(int i=1;i<n; i++){
        int incl=prev2+nums[i];
        int excl=prev1+0;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}

int main()
{
    //House robbery problem
    //same as last question,,,just the first and last should not be included at same time
    vector<int> valueInHouse={1,2,3,4,5};
    int n=valueInHouse.size();
    if(n==1){
    cout<<valueInHouse[0]<<endl;
    }
    else{
        vector<int> first(n-1);
        vector<int> second(n-1);
        for(int i=0; i<n-1; i++){
            first[i]=valueInHouse[i];
            second[i]=valueInHouse[i+1];
        }

        cout<<max(solveTab_optimized(first),solveTab_optimized(second))<<endl;
    }


    return 0;
}