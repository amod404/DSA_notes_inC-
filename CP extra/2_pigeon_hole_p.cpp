//pegionhole problem
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector <int> v){

    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
}

void p_sort(vector<int> &v){
    //finding range-->O(n);
    int min=*min_element(v.begin(),v.end());
    int max=*max_element(v.begin(),v.end());
    int range = max-min;
    
    //initiazlize empty holes
    vector<int> holes(range+1,0);
    //storing number of counts
    for(int i=0;i<v.size();i++){
        int index=v[i]-min;
        holes[index]++;
    }

    //entering the pigeon back in order
    //time complexity-->O(n)
    int k=0;
    int O=0;
    for(int j:holes){
        for(int i=0;i<j;i++){
            v[k++]=O+min;
        }
        O++;
    }
}

int main()
{
    vector<int> v={9,3,4,6,2,9,6,4,2,1,4,6,3,3};
    print(v);
    p_sort(v);
    print(v);

    //PH_sort reduces space complexity from O(max) to O(max-min-1);
    //thus used where elements are large enough but the difference b/w max and min is constraint to be small
    //also its time complexity for sorting is O(n)...good one

    return 0;
}