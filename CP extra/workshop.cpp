#include<iostream>
using namespace std;

int main()
{
   int t;
   cin>>t;
   for(int k=0;k<t;k++){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<arr[0]+1<<endl;
        continue;
    }

    int ans1=0,ans2=0;
    int max1=-1,max2=-1;
    for(int i=0;i+1<n;i=i+2,ans1++,ans2++){
        if(arr[i]>max1){
            max1=arr[i];
        }
        if(arr[i+1]>max2){
            max2=arr[i+1];
        }
    }
    if(n%2==1){
        if(arr[n-1]>max2)
        max2=arr[n-1];
        ans2++;
    }
    ans1+=max1;
    ans2+=max2;
    if(ans1>ans2){
        cout<<ans1<<endl;
    }
    else{
        cout<<ans2<<endl;
    }
   }
   return 0;
}