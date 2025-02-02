// //decimal compliment
// //compliment of base 10 integer

// #include <iostream>
// #include <math.h>
// using namespace std;

// long long int binary(long long int a)
// {  
//     long long int bin, m, n;
//     for (bin = 0, m = 0; a; a = a / 2, m++)
//     {
//         n = a % 2;
//         bin = bin + n * pow(10, m);
//     }
//     return bin;
// }
// long long int compliment(long long int b)
// {
//    long  long int bin, n, m;
//     for (bin = 0, n = 0; b; b = b / 10, n++)
//     {
//         m = b % 10;
//         if (m == 0)
//         {
//             bin = bin + pow(10, n);
//         }
//     }
//     return bin;
// }
// long long int decimal(long long int c)
// {
//     long long int bin, n, m;
//     for (bin = 0, n = 0; c; c = c / 10)
//     {
//         m = c % 10;
//         bin = bin + m * pow(2, n);
//     }
//     return bin;
// }

// long long int D_compliment(long long int x)
// {
//     return decimal(compliment(binary(x)));
// }
// int main()
// {
//     long long int x;
//     cin>>x;
//     cout << D_compliment(x);
//     return 0;
// }


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==0){      //edge case
        cout<<1;
        return 0;
    }
    int mask=0;
    int m=n;
    while(m!=0){
        mask=(mask<<1)|1;
        m=m>>1;
    }
    int ans=(~n)&mask;
    cout<<ans;    

    return 0;
}