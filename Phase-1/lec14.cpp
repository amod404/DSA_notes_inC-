//Binary search questions

#include<iostream>
#include<math.h>
using namespace std;

int PIVOT(int arr[], int size){
    int s=0,e=size-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>arr[0]){
            s=mid+1;
        }
        mid=s+(e-s)/2;
        if(arr[mid]<arr[size-1]){
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int B_search(int arr[],int s, int e, int key){
    int mid=(e+s)/2;
    while(s<=e){
        if(key==arr[mid]){
            return mid;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
            e=mid-1;
        }
        mid=(e+s)/2;
    }
}
int Find_in_rotated(int arr[],int size,int key){
    int s=0,e=size-1;
    int mid=(e+s)/2;
    while(e<s){
        if(arr[mid]>arr[0]){
            s=mid+1;
        }
        mid=(e+s)/2;
        if(arr[mid]<arr[size-1]){
            e=mid;
        }
        mid=(e+s)/2;
    }

    if(key>arr[0]){
        return B_search(arr,0,s-1,key);
    }
    else{
        return B_search(arr,s,size-1,key);
    }

}

int Sq_root_int(int n){
    int s=0,e=n;
    int mid=(s+e)/2;
    int ans=0;

    while(s<=e){  //dry run for different cases..as here equal to sign was important
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid>n){
            e=mid-1;
        }
        else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }
        mid=(e+s)/2;
    }
    return ans;

    //to avoid end cases--> mid=s+(e-s)/2
    //and take a variable long long int named square to put--> square=mid*mid
}

//upto variable decimal places
float Sq_root(int n,int p){
    int s=0,e=n;
    int mid=(s+e)/2;
    int ans=0;

    while(s<=e){ 
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid>n){
            e=mid-1;
        }
        else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }
        mid=(e+s)/2;
    }

    float N=(float)n;
    float ans2=(float)ans;
    int n_=1;
    double factor=1;

    for(int i=0;i<p;i++){
        factor=factor/10;

        for(float j=ans2;j*j<N;j=j+factor){
            ans2=j;
        }
    }
    return ans2;
}

int main()
{
    //pivot in an array--->real problem
    //int x[]={1,2,3,7,9};
    //roating that array
    // int x[]={7,9,1,2,3};
    // int s=sizeof(x)/sizeof(int);
    // cout<<"answer: "<<PIVOT(x,s)<<endl;
    // cout<<"answer: "<<x[PIVOT(x,s)]<<endl;
    
    // int x[]={7,9,1,2,3};
    // int s=sizeof(x)/sizeof(int);
    // cout<<"answer: "<<Find_in_rotated(x,s,2)<<endl;
    // cout<<"answer: "<<x[Find_in_rotated(x,s,2)]<<endl;
    // cout<<B_search(x,2,4,2);
    
    //square root and square root qith precision
    // int n,m;
    // cout<<"Enter the value: ";
    // cin>>n;
    // cout<<"Enter the precision: ";
    // cin>>m;
    // cout<<"Your square root is:"<<Sq_root(n,m);
    
    return 0;
}