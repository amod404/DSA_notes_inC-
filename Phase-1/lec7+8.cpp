// // //lec7 is just question practice
// // //switch and functions
// // #include<iostream>
// // using namespace std;

// // int main()
// // {
// //     char ch='a';
// //     int num=10;
// // for(int i=1;i<=10;i++){
// //     switch(i){
// //         case 1: cout<<"first"<<endl;
// //                 cout<<"first again"<<endl;
// //                 break;
// //         case 2: cout<<"second"<<endl;
// //                 break;
// //         case 3: cout<<"third"<<endl;
// //                 break;
// //         case 4: cout<<"fourth"<<endl;
// //                 break;
// //         default:cout<<"end"<<endl;
// //     };
// //     if(i==3){
// //         break;
// //     }
// // }
// //     return 0;
// // }


// // #include<iostream>
// // using namespace std;

// // int main()
// // {
// //     float a,b;
// //     cout<<"Enter the value of a: ";
// //     cin>>a;
// //     cout<<"Enter the value of b: ";
// //     cin>>b;
// //     char op;
// //     cout<<"Enter the operation: ";
// //     cin>>op;

// //     switch(op){
// //         case '+':cout<<a+b<<endl;
// //                  break;
// //         case '-':cout<<a-b<<endl;
// //                  break;
// //         case '*':cout<<a*b<<endl;
// //                  break;
// //         case '/':cout<<a/b<<endl;
// //                  break;
// //         default: cout<<"invalid operation";
// //     }
// //     return 0;
// // }


// //HW

// #include<iostream>
// using namespace std;

// int main()
// {
//     int n,m=1;
//     cout<<"Enter the amount: ";
//     cin>>n;
//     int c_500=0,c_100=0,c_50=0,c_20=0,c_10=0,c_5=0,c_1=0;
//     for(;m;){
//         if(n>=500){
//             m=500;
//         }
//         else if(n>=100){
//             m=100;
//         }
//         else if(n>=50){
//             m=50;
//         }
//         else if(n>=20){
//             m=20;
//         }
//         else if(n>=10){
//             m=10;
//         }
//         else if(n>=5){
//             m=5;
//         }
//         else if(n>=1){
//             m=1;
//         }
//         else{
//             m=0;
//         }
        
//         switch(m){
//             case 500 : for(;;){
//                 if(n>=500){
//                     c_500++;
//                     n=n-500;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             break;
//             case 100 : for(;;){
//                 if(n>=100){
//                     c_100++;
//                     n=n-100;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             break;
//             case 50 : for(;;){
//                 if(n>=50){
//                     c_50++;
//                     n=n-50;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             break;
//             case 20 : for(;;){
//                 if(n>=20){
//                     c_20++;
//                     n=n-20;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             break;
//             case 10 : for(;;){
//                 if(n>=10){
//                     c_10++;
//                     n=n-10;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             break;
//             case 5: for(;;){
//                 if(n>=5){
//                     c_5++;
//                     n=n-5;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             break;
//             case 1 : for(;;){
//                 if(n>=1){
//                     c_1++;
//                     n=n-1;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             break;
//         };

//     }

//     if(c_500){
//         cout<<"500 Rs notes needed: "<<c_500<<endl;
//     }
//     if(c_100){
//         cout<<"100 Rs notes needed: "<<c_100<<endl;
//     }
//     if(c_50){
//         cout<<"50 Rs notes needed: "<<c_50<<endl;
//     }
//     if(c_20){
//         cout<<"20 Rs notes needed: "<<c_20<<endl;
//     }
//     if(c_10){
//         cout<<"10 Rs notes needed: "<<c_10<<endl;
//     }
//     if(c_5){
//         cout<<"5 Rs coins needed: "<<c_5<<endl;
//     }
//     if(c_1){
//         cout<<"1 Rs notes needed: "<<c_1<<endl;
//     }
//     return 0;
// }

//functions padhaya....basic level

//total no of set bits:

#include<iostream>
using namespace std;

int setBit(int x){
    int count=0;
    while(x){
        if(x&1){
            count++;
        }
        x=x>>1;
    }
    return count;
}

int main()
{
    int a,b;
    cin>>a>>b;

    cout<<"No of bits are : "<<setBit(a)+setBit(b);
    return 0;
}