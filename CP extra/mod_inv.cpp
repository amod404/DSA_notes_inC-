#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

// m^n
long long binaryexpo(long long int m, long long int n,long long int M){
   
    if(n==0){
        return 1;
    }
    long long int t = binaryexpo(m,n/2,M) % M;
    
    if(n&1) return (t*t)%M*m%M;
    else return (t*t)%M;

}

int main()
{	CLEAR;

    //modular multiplicative  inverse  only fro co prime a and m

    // fermet little therorum
    // {A^(m-1)} % m => 1
    // concurrency: A^(m-1)= 1 * mod(m)
    //              A^(m-2)= A^-1 * mod(m)
    //              {A^(m-2)}%m= A^-1

    //use fast exponentiation to find A^m-2 
    int a=12;
    int M = 1e9+7;
    long long MMI = binaryexpo(12,M-2,M);
    cout<<MMI<<endl;
    return 0;
}