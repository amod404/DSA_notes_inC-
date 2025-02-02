//no of one bit

#include<iostream>
using namespace std;

int one_bit(int a){
    int m,count;
    for(count=0;a;a/=2){
        m=a%2;
        if(m==1){
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    cout<<one_bit(n);
    return 0;
}