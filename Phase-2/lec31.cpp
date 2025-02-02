// The recursion-01 (basic)

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int r_factorial(int n){
    if(n==0 || n==1){  
        return 1;   //this is our base case
    }
    return n*r_factorial(n-1);  //this is our recursive expression
   
    //can be visualized as.......
    //int choti= r_factorial(n-1);
    //int badi= n*choti;
    //return badi
    //so try to break your problem in choti and badi and make a base case
}

int power(int n){
    //base case
    if(n==0) return 1;
    //recursive relation
    int smallerProblem = power(n-1);
    int biggerProblem = 2*smallerProblem;
    //processing
    cout<<biggerProblem<<" ";
    //so this is an example of Head recursion
    return biggerProblem;
}

void print_count(int n){
    //my appproach
    cout<<n<<endl;
    if(n>1) print_count(n-1);
    return;  //optional, as it is by default given by '}'

    //sir's approach
    //
    // // Head recursion 
    //     if(n==0){
    //         return;
    //     }
    //     //recursive relation
    //     print_count(n-1);
    //     //processing
    //     cout<<n<<endl;
    //
    // //tail recusion
    //     if(n==0){
    //         return;
    //     }
    //     //processing
    //     cout<<n<<endl;        
    //     //recursive relation
    //     print_count(n-1);
}

int main()
{
    //factorial by recursion
    // int n;
    // cout<<"Enter your number: ";
    // cin>>n;
    // cout<<"Factorial is: "<<r_factorial(n)<<endl;

    // Finding 2^n by recursion
    // int n;
    // cout<<"Enter your number: ";
    // cin>>n;
    // cout<<endl<<"answer: "<<power(n)<<endl;

    //print counting
    // int n;
    // cout<<"Enter your number: ";
    // cin>>n;
    // print_count(n);
    
    return 0;
}
