//This gives us number of coprime till n

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;
const int N = 1e4+2,MOD=1e9+7;

int totient[N];



int main()
{	CLEAR;

    for(int i=0; i<N; i++){
        totient[i]=i;
    }

    for(int i=2; i<N; i++){
        if(totient[i]==i){
            for(int j=2*i; j<N; j+=i){
                totient[j] *= i-1;
                totient[j] /= i;
            }
            totient[i] = i-1;
        }
    }

    for(int i = 2; i<11; i++){
        cout<<totient[i]<<" ";
    }cout<<endl;


    return 0;
}