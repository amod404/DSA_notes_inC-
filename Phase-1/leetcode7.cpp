#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i,j;

    for(int i=1;;i++){
        if(i*i>n){
            j=i-1;
            break;
        }
    }
    
    if(j*j==n){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}