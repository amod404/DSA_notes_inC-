//maths for dsa
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//messed up approach...seive of eratosthenes
int countPrime(int n){
    int count=0;
    //if n is not included..otherwise n+1 elements
    vector<bool> prime(n,true);
    prime[0]=false;
    prime[1]=false;

    for(int i=2;i<n;i++){

        if(prime[i]){
            count++;

            for(int j=i*i;j<n;j=j+i){
                //loop is starting from i*i..
                // as previous multiples are already removed
                prime[j]=false;
            }
        }
    }
    return count;
}

// vector one 
vector<int> CountPrime(int n){
    vector<int> ans;
    vector<bool> prime(n+1,true);
    prime[0]=false;
    prime[1]=false;

    for(int i=2;i<n+1;i++){

        if(prime[i]){
            ans.push_back(i);
            for(int j=i*i;j<n+1;j=j+i){
                //loop is starting from i*i..
                // as previous multiples are already removed
                prime[j]=false;
            }
        }
    }
    return ans;
}
//Segmented seive...:0
void seg_prime(int low, int high){
    //make and vector for segmented part
    //remember i-th place is for i+low number
    vector<bool> isprime(high-low+1,true);
    if(low==1){
        isprime[0]=false;
    }
    //save all prime below sqrt of h
    vector<int> primes = CountPrime(floor(sqrt(high)));

    // iterating primes
    for(auto p:primes){

        //finding next min multiple of prime in our segment
        //since all p's are prime less than root(high), means p*p<=high
        //learn this formula to find the smallest multiple after a number
        int start=max(p*p,((p+low-1)/p)*p);
        
        for(int j=start;j<=high;j+=p){
            isprime[j-low]=false;
        }
    }
    // one way to do
    // int i=0; // to iterate primes
    // while(i<primes.size()){
    //     int p=primes[i];
    //     int start=max(p*p,((p+low-1)/p)*p);     
    //     for(int j=start;j<=high;j+=p){
    //         isprime[j-low]=false;
    //     }
    //     i++;
    // }

    //printing all primes
    for(int i=0; i<high-low+1;i++){
        if(isprime[i]){
            cout<<i+low<<" ";
        }
    }
}
// note:- complexities
// simple seive-->O[root{high}*log(log(root{high}))]
// seqmented seive-->O[{high-low+1}*log(log(high))  +  simple seive vali]
// simpel seive-->O(root{high})
// segmented seive-->O(high-low+1)

//solved myself 
int HCF(int b, int a){
    if(b>a){
        swap(b,a);
    }
    int ans=b; //the smaller one 
    
    while(b>0){
        int m=a%b;
        a=b;
        b=m;
        if(m>0){
            ans=b;
        }
    }
    return ans;
}

int LCM(int B, int A){
    int a=max(A,B);
    int b=min(A,B);
    
    int ans=b; //the smaller one 
    while(b>0){
        int m=a%b;
        a=b;
        b=m;
        if(m>0){
            ans=b;
        }
    }
    //using that LCM*HCF=A*B;
    return (A*B/ans);
}

int f_power(int x, int n, int m){
    int res=1;

    while(n>0){
        if(n&1){
            //odd
            res=(1LL*(res)*(x)%m)%m;
        }
            x=(1LL*(x)%m*(x)%m);
            n=n>>1;
    }
    return res;
}
//this one is without module
int f_power(int x, int n){
    int res=1;

    while(n>0){
        if(n&1){
            //odd
            res=res*x;
        }
            x=x*x;
            n=n>>1;
    }
    return res;
}

int r_f_power(int x, int n){
    if(n==0){
        return 1;
    }
    int t = r_f_power(x,(n/2));

    if(n&1){
        return (t*t*x);
    }
    else{
        return (t*t);
    }
}

int r_f_power(int x, int n, int m){
    if(n==0){
        return 1;
    }
    int t = (r_f_power(x,(n/2)))%m;

    if(n&1){
        return ((t%m)*(t%m)*(x%m))%m;
    }
    else{
        return ((t%m)*(t%m))%m;
    }
}

int n_m_factorial(int n){
    if(n==0){
        return 1;
    }
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
    }
    return ans;
}

int m_factorial(int n,int m){
    if(n==0){
        return 1;
    }
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
        ans%=m;
    }
    return ans%m;
}

int main()
{
    //no of prime numbers by sieve of eratosthenes
    // int n;
    // cout<<"enter the number: ";
    // cin>>n;
    // cout<<countPrime(n)<<endl;
    
    //HW(proudly done)-->segmented sieve
    // int l,h;
    // cout<<"Enter the larger number: ";
    // cin>>h;
    // cout<<"Enter the smaller number: ";
    // cin>>l;
    // if(h>l){
    //     seg_prime(l,h);
    // }
    // else{
    //     cout<<"Invalid input";
    // }

    //HCF OR GCD.....
    //self HW...easy with recursion but solving now with iteration
    // int a,b;
    // cout<<HCF(72,24)<<endl;
    
    //LCM-->A*B/HCF
    // int A=12,B=42;
    // cout<<HCF(A,B)<<endl;
    // cout<<LCM(A,B)<<endl;

    //HW(done)-->read article on module
    
    //Fast exponentiation
    // int a=2,b=10,m=10000;  //have to find a^b%m
    // cout<<f_power(a,b,m)<<endl;
    // cout<<r_f_power(a,b,m)<<endl;
    
    //HW-->(done)
    //pigeon hole principle      //will be adding in C.P. folder :>
    //catalan number
    //inclusion exclusion principle
    //factotial-->212!...with modulus arithmatic
    
    //modulus of large factorial;
    // int n=121;
    // cout<<m_factorial(n,127)<<endl;

    return 0;
}