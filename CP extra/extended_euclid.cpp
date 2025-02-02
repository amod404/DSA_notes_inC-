#include<iostream>
using namespace std;

int extended_euclid(int a, int b, int &x, int &y){
    if(b==0){
        //initializing the vales for backtracking
        x=1;
        y=0;
        // returning the gcd 
        return a;
    }
    int x1,y1;
    int g = extended_euclid(b,a%b,x1,y1);
    //backtracking
    x = y1;
    y = x1-(a/b)*y1;
    //conserving the return value of gcd
    return g;
}

int main(){
    int a =5, b=3, x,y;
    int g = extended_euclid(a,b,x,y);
    cout<<a<<"x+"<<b<<"y="<<g<<endl;
    cout<<"x:"<<x<<" y:"<<y<<endl;
    return 0;
}