#include<iostream>
using namespace std;

int P(int a){
    int bin;
    for(bin=1;a;a/=10){
        int m=a%10;
        bin=bin*m;
    }
    return bin;
}
int A(int a){
    int bin;
    for(bin=0;a;a/=10){
        int m=a%10;
        bin=bin+m;
    }
    return bin;
}
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    cout<<P(n)-A(n);
    return 0;
}