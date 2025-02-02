#include <iostream>
using namespace std;

int main()
{
    float x;
    cout << "Enter a number: ";
    cin >> x;
    float rem,root,pre,dev;
    for (float i = 1;; i = i + 1)
    {
        if (i * i > x)
        {
            root = i - 1;
            rem = x - (i - 1) * (i - 1);
            break;
        }
    }

    for (float i = 1; i < 10; i = i + 1)
    {
        if (((20 * (root) + i) * i) > (rem * 100))
        {
            root = root + (i - 1) / 10;
            rem = rem * 100 - ((20 * (root) + (i - 1)) * (i - 1));
            pre = (20 * (root) + (i - 1)) + i - 1;
            break;
        }
    }
    for (float i = 1; i < 10; i++)
    {
        if (((pre * 10 + i) * i) > (rem * 100))
        {
            dev = i - 1;
            break;
        }
    }

    if (dev >= 5)
    {
        root = root + 0.1;
    }
    cout << "Your approx root is: " << (float)root;
    return 0;
}

// #include<iostream>
// using namespace std;

// int pow(int a, int b){
//     int bin=1;
//     for(int i=1;i<=b;i++){
//         bin=bin*a;
//     }
//     return bin;
// }
// int digits(int a){
//     int bin;
//     for(bin=0;a;a/=10){
//         bin++;
//     }
//     return bin;
// }

// int root(int n, int digit){
//     int bin=0,i;
//     for(i=1;i<=digit/2;){
//         int m=n/pow(10,digit-2);
//         int p=n%pow(10,digit-2);
//         int y;
//         for(y=1;;y++){
//             if((y*y)>m){
//                 bin=(bin*10)+y-1;
//                 break;
//             }
//         }
//         int reminder=m-pow(y-1,2);
//         n=100*reminder+p;
//         }
//     return bin;
// }

// int main()
// {
//     int digit,n;
//     cout<<"Enter a num: ";
//     cin>>n;

//     digit=digits(n);
//     if(digit%2){
//         digit++;
//     }

//     cout<<"Your square root is: "<<root(n,digit);

//     return 0;
// }