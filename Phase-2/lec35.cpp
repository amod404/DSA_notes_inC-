//recursion-05 (merge sort by recursion)

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void merge_two_sorted(int arr[],int s, int e){
    //the array we got contains two sorted halfs....so need to seperate them by our variables
    int mid=s-(s-e)/2;     
    int l_len=mid-s+1;   //length of left half
    int r_len=e-mid;     //length of right half

    int *l_arr = new int[l_len];    
    int *r_arr = new int[r_len];
    //getting those data from both half on different temperory dynamic arrays
    //for both loop check the start cases and conditions in the loops
    for(int k=s,i=0;i<l_len;i++,k++){  
        l_arr[i]=arr[k];
    }
    for(int k=mid+1,i=0;i<r_len;i++,k++){
        r_arr[i]=arr[k];
    }
    
    //iterating both the array by two variables and merging them as the are sorted
    //note we are merging two half arrays into the array they are taken from
    int i=0,j=0,k=s; //i-->left iterator, j-->right iterator, k is array pointer
    //this question we have already done, by using three while loops
    while(i<l_len && j<r_len){
        if(l_arr[i]<r_arr[j]){
            arr[k++]=l_arr[i++];
            // or k++;i++;
        }
        else{
            arr[k++]=r_arr[j++];
            // or k++;j++;
        }
    }
    while(i<l_len){
        arr[k++]=l_arr[i++];
        // or k++;i++;
    }
    while(j<r_len){
        arr[k++]=r_arr[j++];
        //or j++;k++;
    }

    //releasing those dynamic memories
    delete []l_arr;
    delete []r_arr;
}
void merge_sort(int arr[],int s, int e){
    //base case
    if(s>=e){  //as an array of length 1 is already sorted
        return;
    }
    //initializing mid (will be initialized for each call)
    int mid=s-(s-e)/2;

    //recursive relation
    //breaking the array by calling the left half
    merge_sort(arr,s,mid);
    //breaking the array by calling the right half
    merge_sort(arr,mid+1,e);

    //processing part-->will happen during returning(as head recursion)
    //will merge the sorted array
    //or merge the sub array by sorting them, without actual merge in a different memory
    merge_two_sorted(arr,s,e);


    //note:- array is breaking into call stacks by recursion 
    //       and merging+sorting during return process by above function
}
//these codes above are monsterous +.+

void s_merge_two_sorted(string &str, int s, int e, int mid){
    //seperate the two sorted half
    string l_arr;
    string r_arr;
    for(int i=0;i<mid-s+1;i++){
        l_arr.push_back(str[i+s]);
    }
    for(int i=0;i<e-mid;i++){
        r_arr.push_back(str[mid+1+i]);
    }
    int i=0,j=0,k=s;
    while(i<mid-s+1 && j<e-mid){
        if(l_arr[i]<r_arr[j]){
            str[k++]=l_arr[i++];
        }
        else{
            str[k++]=r_arr[j++];
        }
    }
    while(i<mid-s+1){
        str[k++]=l_arr[i++];
    }
    while(j<e-mid){
        str[k++]=r_arr[j++];
    }    
}
void helperfunc(string &str,int s, int e){
    //base case
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    //heads recursion call
    helperfunc(str,s,mid);
    helperfunc(str,mid+1,e);

    s_merge_two_sorted(str,s,e,mid);
}
void s_merge_sort(string &str){
    if(str.length()<=1){
        return;
    }
    int s=0;
    int e=str.length()-1;
    helperfunc(str,s,e);
}

//figured it out in seconds and did it without any typo error and working :]
void count_inversions(vector<int>&v,int s, int e, int mid, int &ans){
    for(int i=s;i<=mid;i++){
        for(int j=mid+1;j<=e;j++){
            if(v[i]>v[j]){
                ans++;
            }
        }
    }
}
void helperfunc(vector<int>&v, int s, int e, int &ans){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    helperfunc(v,s,mid,ans);
    helperfunc(v,mid+1,e,ans);

    count_inversions(v,s,e,mid,ans);
}
int inversion_count(vector<int>&v){
    if(v.size()<=1){
        return 1;
    }
    int ans=0;
    int s=0,e=v.size()-1;
    helperfunc(v,s,e,ans);
    return ans;
}
int main()
{
    //merge sort
    //time complexity-->O(nlogn)
    // int arr[]={9,8,7,6,5,4,3,2,1,0};
    // int s= sizeof(arr)/sizeof(int);
    // merge_sort(arr,0,s-1);
    // for(int k=0;k<s;k++){
    //     cout<<arr[k]<<" ";
    // }

    //(done)HW-->inversion count
    //(done)read drawbacks
    //(done)use merge sort for strings

    // merge sort for string...did myself ^^
    // string s="amodyadav";
    // cout<<s<<endl;
    // s_merge_sort(s);
    // cout<<s<<endl;

    //inversion count is the number of pairs of two that are in unsorted way
    // vector<int>v={2,4,1,3,8,9};
    // cout<<inversion_count(v)<<endl;

    return 0;
}
