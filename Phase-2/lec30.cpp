// chote-mote keywords

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define PI 3.14  //not taking extra storage
//can't alter this value

//TYPES:-

//function like macro
#define AREA(l, b) (l * b)
//chain macro
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138
#define FOLLOWERs 'C' //will change value of before macro and just warn , no error
//object like macro
#define DATE 31
//multi line macr
#define exl 1,\
            2,\
            3,     //uses ,\ to seperate lines


int n=10; //global variable can be read and alter by any function and main too

inline void func(int a, int b){
    cout<<++a<<" "<<++b<<endl;
}

int main()
{
    // // Macro-->#  //(done)HW-->GFG article on macro
    // // ex->#include<iostream>.....preprocessor directive
    // // #define-->can create macro
    // // PI++; //error
    // int r=5;
    // float area=PI * r * r;
    // cout<<area;
    // int c = AREA(5,10);
    // cout<<c<<endl;
    // cout<< INSTAGRAM<<endl; //138
    // int arr[3]={exl};
    // cout<<arr[1]+arr[2]+arr[0]<<endl; //6

    //global variable-->want to share a variable between functions and main
    // // int n=5; local>global
    // cout<<n;
    //scope-->useable inside some block, (block of func,main, user define)

    //inline function-->depends on compiler to accept or not
    //in this both argument copy and function call is changed by replacing that one line with t=where function is called in main
    //thus reduce extra time and also maintain that reusability of function
    // for(int i=0;i<200000;i++){
    //     func(i,i++);
    // }

    //default arrgument,const variable-->skipping, easy

    return 0;
}