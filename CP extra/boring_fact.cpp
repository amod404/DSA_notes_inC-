// Bob gives you a prime number P 
// and an integer N close to P,
// and asks you to find N! modulo P
// p~N~1e9, abs[N-P]<=1000
// (p-1)! = (p-1)(mod p)

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

long long power(long long x, long long y, long long p){

    if(y==0){
        return 1;
    }

    long long t = power(x,y/2,p);
    if(y&1){
        return ((t*t)%p*x)%p;
    }
    else{
        return (t*t)%p;
    }
}

long long modInverse(long long n, long long p){
    return power(n,p-2,p);
}


long long modfact(long long n, long long p){
    if(p<=n){
        return 0;
    }
    long long res = p-1;
    for(long long i=n+1; i<p; i++){  // this loop is from n+1 to p-1
        res = (res * modInverse(i,p))%p;
    }
}


int main()
{
    long long n,p;
    cin>>n>>p;
    cout<<modfact(n,p)<<endl;

    return 0;
}


