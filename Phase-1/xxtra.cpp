#include<iostream>
#include<vector>  //These all are containers 
#include<array>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<array>
#include<algorithm> //all algo
using namespace std;

int main()
{
    vector<int>a;
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);

    for(auto i:a){
        cout<<i<<" ";
    }cout<<endl;

    vector<int>::iterator it = a.end();
    cout<<*--it<<endl;
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }cout<<endl;

    

    return 0;
}