//binary search questions
#include<iostream>
using namespace std;

int B_first(int arr[],int size, int key){
    int i=0,j=size-1,ans=-1;
    int mid= i+(j-i)/2;

    while(i<=j){
       
        if(arr[mid]==key){
            ans=mid;
            j=mid-1;
        }
        else if(key>arr[mid]){
            i=mid+1;
        }
        else if(key<arr[mid]){
            j=mid-1;
        } 
        mid= i+(j-i)/2;
    }
    return ans;
}

int B_last(int arr[],int size, int key){
    int i=0,j=size-1,ans=-1;
    int mid= i+(j-i)/2;

    while(i<=j){
       
        if(arr[mid]==key){
            ans=mid;
            i=mid+1;
        }
        else if(key>arr[mid]){
            i=mid+1;
        }
        else if(key<arr[mid]){
            j=mid-1;
        } 
        mid= i+(j-i)/2;
    }
    return ans;
}

int B_mount(int arr[],int size){
    int i=0,j=size-1;
    int mid=i+(j-i)/2;
    while(i<j){
        if(arr[mid]<arr[mid+1]){
            i=mid+1;
        }
        else{
            j=mid;
        }
        mid=i+(j-i)/2;
    }
    return i;
}
//cracked same alternate :>
int B_Mount(int arr[],int size){
    int i=0,j=size-1;
    int mid=i+(j-i)/2;
    while(i<j){
        if(arr[mid-1]>arr[mid]){
            j=mid-1;
        }
        else{
            i=mid;
        }
        mid=i+(j-i)/2;
    }
    return j;
}

//HW
int sum(int arr[],int a, int b){
    int sum=0;
    for(int i=a;i<=b;i++){
        sum=sum+arr[i];
    }
    return sum;
}

int B_pivot(int arr[], int size){
    int i=0,j=size-1;
    int mid=(i+j)/2;  //won't work for limiting cases
    while(mid!=i || mid!=j){
        if(sum(arr,i,mid-1)==sum(arr,mid+1,j)){
            return mid;
        }
        else if(sum(arr,i,mid-1)<sum(arr,mid+1,j)){
            mid=(mid+j)/2;
        }
        else{
            mid=(mid+i)/2;
        }
    }
}
int main()
{
    //first and last position of an element in a sorted array
    // int n;
    // cout<<"Enter n: ";
    // cin>>n;
    // int x[11]={1,2,3,3,3,3,3,3,3,3,5};
    // int s=sizeof(x)/sizeof(int);
    // cout<<"first occurence is at index: "<<B_first(x,s,n)<<endl;
    // cout<<"last occurence is at index: "<<B_last(x,s,n)<<endl;
    
    // //total number of occurence
    // cout<<"It occured "<<B_last(x,s,n)-B_first(x,s,n)+1<<" times"<<endl;
    
    //peak element in a mountain
    // int y[10]={1,2,4,5,8,10,11,14,2,1};
    // int s= sizeof(y)/sizeof(int);
    // cout<<"The peak element is index:"<<B_mount(y,s)<<endl;
    // cout<<"The peak element is index:"<<B_Mount(y,s)<<endl;
    // cout<<"The element is: "<<y[B_mount(y,s)]<<endl;
    // cout<<"The element is: "<<y[B_Mount(y,s)]<<endl;
    
    //HW: find pivot index in an array
    //first lets make a function to find sum of a range of index;
    // int y[10]={1,1,3,2,3,6,1,5,10,7};
    // int s=sizeof(y)/sizeof(int);
    // cout<<"Pivot is at index: "<<B_pivot(y,s)<<endl;
    return 0;
}