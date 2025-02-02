//Binary search-->advance questions :|
#include<iostream>
using namespace std;

bool isPossible(int arr[],int n, int m, int mid){

    int studentCount=1;
    int pageSum=0;

    for(int i=0; i<n ; i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m ||arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;
}
int allocateBooks(int arr[], int n, int m){
    //we have to minimize the maximum
    //Here m is number of students
    int s=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e=sum, mid=s+(e-s)/2,ans=-1;

    while(s<e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}


bool IsPosiible(int arr[],int n, int m, int mid){
    int count=1,pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            count++;
            if(count>m ||arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;
}
int P_P_M(int arr[], int size,int m){
    int sum=0;
    for(int k=0;k<size;k++){
        sum=sum+arr[k];
    }
    
    int s=0,e=sum,mid=(s+e)/2,ans=-1;
    while(s<e){
        if(IsPosiible(arr,size,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(e+s)/2;
    }
    return ans;

}


bool ifpossible(int arr[],int size,int m, int mid){
    int count=1,lastcow=arr[0];
    for(int i=0;i<size;i++){
        if((arr[i]-lastcow)>=mid){
            count++;
            if(count==m){
                return true;
            }
            lastcow=arr[i];
        }
    }
    return false;
}
int A_C(int arr[],int size,int m){
    // here m is the number of cows 
    // here we are maximizing the minimum distance
    //learn to initialize final answer as -1 not zero unlss needed
    int s=0,e=arr[size-1],mid=(s+e)/2,ans=-1; 
    while(s<=e){
        if(ifpossible(arr,size,m,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=(e+s)/2;
    }    
    return ans;
}
int main()
{
    //Note:- all teh questions we did today is on sorted array only

    // 1.Book allocation problem
    // int x[7]={1,3,4,7,8,10,13};
    // int s= sizeof(x)/sizeof(int);
    // int y=allocateBooks(x,s,4);
    // cout<<y<<endl;
        
    //2.Painter's Partition problem
    // int x[]={5,5,5,5};
    // int s=sizeof(x)/sizeof(int);
    // cout<<P_P_M(x,s,2)<<endl;
    // cout<<allocateBooks(x,s,2);
    
    //3.Aggresive cow
    // int x[]={1,2,3,4,6};
    // int s=sizeof(x)/sizeof(int);
    // cout<<A_C(x,s,2);

    return 0;
}