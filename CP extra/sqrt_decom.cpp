// find the minimum in a range for q qeury 

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;
#define MOD 1e9

int main()
{	CLEAR;

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    int len = sqrtl(n)+1;
    vector<int>b(len,MOD);

    for(int i=0; i<n; i++){
        b[i/len] = min(b[i/len],a[i]);
    }



    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int ans = MOD;
        for(int i=l; i<=r;){
            if(i%len == 0 && i+len-1<=r){
                ans = min(ans,b[i/len]);
                i+=len;
            }
            else{
                ans = min(ans,a[i]);
                i++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {	
//     int n;
//     cin>>n;
//     vector<int>a(n);
//     for(int i=0; i<n ;i++){
//         cin>>a[i];
//     }
//     int len = sqrtl(n)+1;
//     vector<int>b(len,0);
    
//     for(int i=0; i<n; i++){
//         b[i/len] += a[i];
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         int l,r;
//         cin>>l>>r;
//         l--;r--;

//         int sum = 0;
//         for(int i=l; i<=r; ){
//             if(i%len == 0 && i+len-1<=r){
//                 sum+=b[i/len];
//                 i+=len;
//             }
//             else{
//                 sum+=a[i];
//                 i++;
//             }
//         }

//         cout<<sum<<endl;
//     }

//     return 0;
// }