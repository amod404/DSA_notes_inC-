//some question on STL

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> reverse(vector<int> v){

    int s=0;
    int m= v.size()-1;

    while(s<m/2){
        swap(v[s], v[m-s]);
        s++;
    }
    return v;
} 

vector<int> merge(vector<int>v, vector<int> u){

    vector<int> w(u);

    for(int i=0; i<v.size();i++){
        int count=0,j=0;
        for(;j<u.size();j++){
            if(u[j]==v[i]){
                count++;
            }
        }
        if(!count){
            w.push_back(v[i]);
        }
    }

    return w;
}

void print(vector <int> v){

    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
}

void moveZero(vector<int> &v){
    int i=0;
    for(int j=0; j<v.size();j++){
        if(v[j] !=0){
            swap(v[j],v[i]);
            i++;
        }
    }
}

int main()
{
    vector<int> v,u;

    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(0);
    v.push_back(0);
    v.push_back(7);

    //reverse of an array
    // vector<int> ans1 = reverse(v);
    // print(v);
    // print(ans1);

    // merge different array 
    // use two pointer aproach is the arrays are sorted
    // vector<int> ans2 = merge(v,u);
    // print(v);
    // print(u);
    // print(ans2);

    //move zeros
    // print(v);
    // moveZero(v);
    // print(v);

    


    return 0;
}