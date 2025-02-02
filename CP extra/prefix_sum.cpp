// its like if the quieres to find the sum between 
// two intervals then we can generate an prefix array while
// taking input from user and then its a peice of cake


#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

vector<int> make(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n+1);
    ans[0]=0;
    ans[1]=arr[0];
    for(int i=1; i<n; i++){
        ans[i+1]=ans[i]+arr[i];
    }
    return ans;
}

int prefixSum(vector<int> &ans, int s, int e){
    if(s==0){
        return ans[e];
    }
    return ans[e]-ans[s-1];
}
int main()
{	CLEAR;

    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    vector<int> prefix = make(v);

    cout<<" The Sum of arr from to  is : "<< prefixSum(prefix,1,4)<<endl;
    cout<<" The Sum of arr from to  is : "<< prefixSum(prefix,0,4)<<endl;    
    cout<<" The Sum of arr from to  is : "<< prefixSum(prefix,1,5)<<endl;
    cout<<" The Sum of arr from to  is : "<< prefixSum(prefix,0,10)<<endl;
    cout<<" The Sum of arr from to  is : "<< prefixSum(prefix,2,3)<<endl;
    return 0;
}