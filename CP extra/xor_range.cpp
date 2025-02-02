#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int n_xor(int n){
    if(n==0){
        return 0;
    }

    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
    return n;
}

int xor_range(int l, int r){
    return n_xor(l-1)^n_xor(r); 
}

int main()
{	CLEAR;

    int t;
    cin>>t;
    for(int p=0; p<t; p++){
        int l,r;
        cin>>l>>r;

        //inclusive l and r
        cout<<xor_range(l,r);




    }
    return 0;
}