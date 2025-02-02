//BitWise operator

#include<iostream>
using namespace std;

int main()
{
    // And && 
    // or || 
    // not !   
    // not ~ 
    // xor ^ 0,1-->1 only
    // int a=2;
    // cout<<~a<<endl; //-3
    // cout<<2&&3; //2
    // cout<<endl;
    // cout<<(5^7)<<endl;  //2
    // cout<<(~5^7);  //3


    //left shift(<<) and rigt shift(>>)
    // int c=3<<2;  // 3--> 00...00011
    //              // 3<<2 --> 00...01100 shifted left by two
    // cout<<c<<endl;   //12

    // if we left shift by 2 means we multiply by 4
    // by 1 means mltipleby 2
    // by 3 mean 8
    // by n means 2^n;
    //only for small numbers and small n

    // cout<<(17>>1)<<endl;
    // cout<<(17>>2)<<endl;
    // cout<<(19<<1)<<endl;
    // cout<<(19<<2)<<endl;

    //for loop + easy qustions like fbinocci and prime numb
    int i=5;
     for(i=1;i<=10;i++){
        if(i==5){
            break;
        }
        cout<<i<<endl;
     }

     for(i=1;i<=10;i++){
        if(i==5){
            continue;
        }
        cout<<i<<endl;
     }
    return 0;
}

