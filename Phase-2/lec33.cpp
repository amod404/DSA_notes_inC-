//recursion-03-->(binary search by rec.)

#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

bool is_sorted(int arr[],int size){
    if(size==0||size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }

    return is_sorted(arr+1,size-1);
}

int r_sum(int arr[],int size){
    if(size==0){
        return 0;
    }
    return arr[0]+r_sum(arr+1,size-1);
}

bool is_present(int arr[],int size,int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    
    return is_present(arr+1,size-1,key);
}
//self solved..... ^.^
bool is_present_b(int arr[],int s, int e, int &key){
    if(arr[(s+e)/2]==key){
        return true;
    }
    if(s>e){
        return false;
    }
    if(arr[(s+e)/2]>key){
        e=(e+s)/2-1;
    }
    else if(arr[(s+e)/2]<key){
        s=(e+s)/2+1;
    }
    return is_present_b(arr,s,e,key);
}

int main()
{
    //finding if an array is sorted by recursion
    // int arr[]={2};
    // int s= sizeof(arr)/sizeof(int);
    // cout<<is_sorted(arr,s);
    
    //(done)HW-->finding sum of an array
    // int arr[]={0,1,2,3,4,5,6,7,8,9};
    // int s= sizeof(arr)/sizeof(int);
    // cout<<r_sum(arr,s);

    // linear search by recursion
    // int arr[]={0,1,2,3,4,5,6,7,8,9};
    // int s= sizeof(arr)/sizeof(int);
    // cout<<is_present(arr,s,9);

    // binary search by recursion
    // int arr[]={0,1,2,3,4,5,6,7,8,9};
    // int s= sizeof(arr)/sizeof(int);
    // cout<<"Is present: "<<is_present_b(arr,0,s-1,10);

    //(done with process)HW-->do all the previous questions by recursion
    
    return 0;
}
