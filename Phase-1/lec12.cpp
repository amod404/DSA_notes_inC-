// Binary search--->wheneversee sorted arrays...(or some related patterns)
#include<iostream>
#include<vector>
using namespace std;

int B_search(vector<int> &arr, int key){
    int i=0,j=arr.size()-1;
        // int mid=(i+j)/2; //error for end cases
        int mid=i + (j-i)/2;

    while(i<=j){
        if(arr[mid]==key){
            return mid;
        }
        else if(key>arr[mid]){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
        mid=i + (j-i)/2;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    //will work on both even and odd array
    vector <int> y={1,2,3,4,5,6,7,8,9,10};
    vector <int> x={1,2,3,4,5,6,7,8,9};
    cout<<"Your key is on index number: "<<B_search(y,n)<<endl; //for even
    cout<<"Your key is on index number: "<<B_search(x,n)<<endl;  //for odd
    return 0; 
}




// // Binary search--->wheneversee sorted arrays...(or some related patterns)
// #include<iostream>
// using namespace std;

// int B_search(int arr[],int size, int key){
//     int i=0,j=size-1;
//         // int mid=(i+j)/2; //error for end cases
//         int mid=i + (j-i)/2;

//     while(i<=j){
//         if(arr[mid]==key){
//             return mid;
//         }
//         else if(key>arr[mid]){
//             i=mid+1;
//         }
//         else{
//             j=mid-1;
//         }
//         mid=i + (j-i)/2;
//     }
//     return -1;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     //will work on both even and odd array
//     int y[10]={1,2,3,4,5,6,7,8,9,10};
//     int x[9]={1,2,3,4,5,6,7,8,9};
//     int S=sizeof(x)/sizeof(int);
//     int s=sizeof(y)/sizeof(int);
//     cout<<"Your key is on index number: "<<B_search(y,s,n)<<endl; //for even
//     cout<<"Your key is on index number: "<<B_search(x,S,n)<<endl;  //for odd
//     return 0; 
// }