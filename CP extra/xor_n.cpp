#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int main()
{	CLEAR;

    int t;
    cin>>t;
    for(int p=0; p<t; p++){
        int n;
        cin>>n;
        int ans;
        if(n%4==1){
            ans=1;
        }
        else if(n%4==2){
            ans = n+1;
        }
        else if(n%4==3){
            ans = 0;
        }
        else{
            ans = n;
        }
        cout<<ans<<endl;

    }
    return 0;
}