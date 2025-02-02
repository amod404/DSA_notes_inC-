// Hashmap - introduction and implimentation

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

// why this?
int mode(vector<int> & arr){
    int n=arr.size();
    unordered_map<int,int> count;

    int maxFrequency=0;
    int maxAns=0;

    for(int i=0;i<n;i++){
        count[arr[i]]++;
        maxFrequency = max(maxFrequency,count[arr[i]]);
    }

    for(int i=0; i<n; i++){
        if(maxFrequency == count[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }
    return maxAns;
}



int main()
{	CLEAR;

    // // to store data in key value pair
    // // insertion, deletion, searching..... O(1).....F***
    // // map ->O(logn)
    // // unordered map -> O(1)
    // // work on hashtable
    //
    // //creation
    // unordered_map<string,int> m;
    // //
    // //insertion
    // pair<string,int> p1= make_pair("Babbar",3);
    // m.insert(p1);
    // //
    // pair<string,int> p2("Babbar",3);
    // m.insert(p2);
    // //
    // m["mera"]=1;  // key->mera, value->1
    // m["mera"]=2;  // for same key the value is changed
    // // means keys are unique
    // //
    // cout<<m["mera"]<<endl;
    // cout<<m.at("Babbar")<<endl;
    // // cout<<m.at("unknow")<<endl;  // this will throw error
    // cout<<m["unknow"]<<endl; // this will make new entry
    // //
    // cout<<m.size()<<endl;
    //  //
    // cout<< m.count("bro")<<endl; // 0->no
    // cout<< m.count("mera")<<endl;  // 1->yes
    //  //
    // m.erase("love");   // if not present then no problem
    // m.erase("mera");   // if present will erase
    // cout<<m.size()<<endl;
    //  //
    // for(auto i:m){
    //     cout<<i.first<<" -> "<<i.second<<endl;
    // }
    //  //
    // // use iterator
    // unordered_map<string,int> :: iterator it=m.begin();
    // while(it!=m.end()){
    //     cout<<it->first <<" -> "<<it->second<<endl;
    //     it++;
    // }
    // // if your traverse an ordered map then thing will be printedin order they are inserted

    // find the maximum frequency number
    // vector<int> arr ={1,2,3,4,4,5,3,2,3,2,3,2,21,21,1};
    // int ans = mode(arr);
    // cout<<ans<<endl;

    // bucket array and hash-function
    // and a lot of theory

    return 0;
}