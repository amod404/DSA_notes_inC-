// Greedy Algorithm

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b){
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n){

    vector<pair<int,int>>v;

    for(int i=0; i<n; i++){
        v.push_back(make_pair(start[i],end[i]));
    }

    sort(v.begin(),v.end(),cmp);

    int count =1;
    int ansEnd = v[0].second;

    for(int i=1; i<n; i++){
        if(v[i].first > ansEnd){
            count++;
            ansEnd = v[i].second;
        }
    }
    return count;
}

int main()
{	CLEAR;

    //maximum number of meetings...start and end time are given..1 meeting at a time
    int start[]={10,12,20};
    int end[]={20,25,30};

    cout<<maxMeetings(start,end,3)<<endl;
    
    //

    return 0;
}