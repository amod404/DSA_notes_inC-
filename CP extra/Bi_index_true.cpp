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

// first set bit from right is given by x&(-x) eg 100100100 -> 000000100

//this will give you sum from 0 to index
int sum(vector<int>&BItree, int n, int index){

    int sum = 0;
    index = index+1;

    //make loop for all the entries that will comine to form your sum
    while(index>0){
        //store the sum
        sum+=BItree[index];
        //net bit the will containe the previous below index-1
        index -= index&(-index);
    }

    return sum;
}

void updateValue(vector<int>&BItree,int n, int index, int val){

    //BIT indexing is 1 basedindexing
    index = index+1;

    //update the value of all the parents who can contain iindex in their range
    while(index<=n){
        BItree[index]+=val;
        //next element
        index+=index&(-index);
    }

}

void makeBIT(vector<int>&arr,vector<int>&BItree, int n){
    
    //update the original value to make a binary index tree
    for(int i=0; i<n; i++){
        updateValue(BItree,n,i,arr[i]);
    }

}

int main()
{

    vector<int> arr = {3,4,2,4,8,5,2,8,9};
    int n = arr.size();
    vector<int>BItree(n+1,0);

    // in binary index tree entries are stored as : BItree[i] = sum of arr[j+1] to arr[i]
    // where j is defines as [i - (i&(-i))]
    makeBIT(arr,BItree,n);
    



    return 0;
}