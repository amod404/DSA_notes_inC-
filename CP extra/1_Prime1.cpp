// //complexity O(n*root(n))
#include<iostream>
using namespace std;

int main()
{
    int t=100000000;
    for(int n=2;n<=t;n++){
        // int m=pow(n,0.5);
        int i=2;
        for(i=2;i*i<=n;i++){
            if(n%i==0){
                break;
            }
        }
        if(i*i>n){
            cout<<n<<"\t";
            if(n%7==0){
                cout<<endl;
            }
        }
    }
    return 0;
}


// complexity O(n^2)
// #include<iostream>
// using namespace std;

// int main()
// {
//     int t=100000000;
//     for(int n=2;n<=t;n++){
//         // int m=pow(n,0.5);
//         int i=2;
//         for(i=2;i<n;i++){
//             if(n%i==0){
//                 break;
//             }
//         }
//         if(i==n){
//             cout<<n<<endl;
//         }
//     }
//     return 0;
// }


