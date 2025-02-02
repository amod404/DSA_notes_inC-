//recursion-04   (with strings)

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void r_reverse(string &s,int i, int j){
    if(i>j){
        return;
    }
    swap(s[i],s[j]);
    r_reverse(s,i+1,j-1);
}

bool r_palin(string &s, int j, int i=0){ //used default argument :>
    if(i>j-i-1){
        return true;
    }
    if(s[i]!=s[j-i-1]){
        return false;
    }
    r_palin(s,++i,j);
}

//check notes too
int r_f_exp(int a, int b){ 
    
    //extra case
    if(b==0){
        return 1;
    }

    //base case
    if(b==1){
        return a;
    }    

    //recursive call
    int ans=r_f_exp(a,b>>1);

    // processing-->to direct recursive return values
    if(b&1){
        return a*ans*ans;
    }
    else{
        return ans*ans;
    }
}

void r_bubblesort(int* arr, int n){
    //base case
    if(n==0||n==1){
        return;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]); //largest element at end
        }
    }
    r_bubblesort(arr,n-1);
}

void r_selectionSort(int arr[],int s,int e){
    if(s==e){
        return;
    }
    int min=s;
    for(int k=s+1;k<e;k++){
        if(arr[min]>arr[k]){
            min=k;
        }
    }
    swap(arr[s],arr[min]);

    r_selectionSort(arr,s+1,e);
}

void r_insertionSort(int arr[],int s, int e){
    //base case
    if(s>e){
        return;
    }

    //processing
    int temp=arr[s+1];
    int j;
    for(j=s-1;j>=0;j--){    
        if(arr[j]>temp){
            arr[j+1]=arr[j];
        }
        else{
            break;
        }
    }
    arr[j+1]=temp;

    //recursive call
    r_insertionSort(arr,s+1,e);
}


int main()
{
    //reversing the string by recursion
    // string name="Babba";
    // cout<<name<<endl;
    // r_reverse(name,0,name.size()-1);
    // cout<<name<<endl;

    //check palindrome
    // string s;
    // cin>>s;
    // cout<<"Answer-->"<<r_palin(s,s.size())<<endl;
    
    //(imp)fast exponential by recursion
    // int a,b;
    // cin>>a>>b;
    // cout<<r_f_exp(a,b);

    //bubble sort by recursion
    // int arr[10]={1,4,3,2,1,4,5,2,1,5};
    // int s=sizeof(arr)/sizeof(int);
    // r_bubblesort(arr,s);
    // for(int i=0;i<s;i++){
    //     cout<<arr[i]<<" ";
    // }

    //(done)HW-->selection and insertion sort by recursion
    // int arr[10]={1,4,3,2,1,4,5,2,1,5};
    // int s=sizeof(arr)/sizeof(int);
    // // r_selectionSort(arr,0,s-1);
    // // r_selectionSort(arr,0,s-1);
    // r_insertionSort(arr,0,s-1);
    // for(int i=0;i<s;i++){
    //     cout<<arr[i]<<" ";
    // }
    
    return 0;
}



