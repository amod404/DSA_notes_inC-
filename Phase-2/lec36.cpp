//recursion-06 (quick sort by recursion)

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//solved myself by usin pivot as last element
int Last_partition(int arr[],int s,int e){
    int count=0;
    int len=e-s+1;
    for(int i=1,k=s;i<len;k++,i++){
        if(arr[e]<arr[k]){
            count++;
        }
    }
    int p=e-count;
    swap(arr[e],arr[p]);

    int i=s,j=e;
    while(i<j){
        if(arr[i]>arr[p] && arr[j]<=arr[p]){
            swap(arr[i++],arr[j--]);
        }
        else if(arr[i]>arr[p]){
            j--;
        }
        else if(arr[j]<=arr[p]){
            i++;
        }
        else{
            i++;j--;
        }
    }
    return p;
}

void Last_quicksort(int arr[],int s, int e){
    if(s>=e){
        return;
    }

    int p=Last_partition(arr,s,e);
    Last_quicksort(arr,s,p-1);
    Last_quicksort(arr,p+1,e);

}

int partition(int arr[],int s, int e){
    int count=0;
    int len=e-s+1;
    int k=s+1;
    for(int i=1;i<len;k++,i++){
        if(arr[s]>arr[k]){
            count++;
        }
    }
    int p=s+count;
    swap(arr[s],arr[p]);

    int i=s,j=e;
    while(i<j){
        if(arr[i]>=arr[p] && arr[j]<arr[p]){
            swap(arr[i++],arr[j--]);
        }
        else if(arr[i]>=arr[p]){
            j--;
        }
        else if(arr[j]<arr[p]){
            i++;
        }
        else{
            i++;j--;
        }
    }
    return p;
}

void quicksort(int arr[],int s, int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);

    quicksort(arr, s , p-1);
    quicksort(arr, p+1, e);

}

int main()
{
    int arr[]={2,2,2,3,4,4,4,2,2,2,3,3,3,1,1,1,6,6,7,7,7};
    int s=sizeof(arr)/sizeof(int);
    Last_quicksort(arr,0,s-1);
    // quicksort(arr,0,s-1);
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }

    //(done)HW-->is it a stable algo?
    //              is it a in place sort.
    //              read why is it prefer over merge sort for sorting array
    //              do dry run and play with it
    //
    //HW--> No it is not a stable algorithm
    //      Yes it is an in-placesort
    //      average TC is same, but SC of merge>quick (n>logn)
    
    return 0;
}










//.....................................................................................
//waste

// #include <iostream>
// #include <vector>
// using namespace std;
//
// // Internal recursive QuickSort function (not exposed to the user)
// void quickSortHelper(vector<int>& arr, int low, int high) {
//     if (low < high) {
//         // Choose pivot and partition the array
//         int pivot = arr[high];  // Choose last element as pivot
//         int i = low - 1;
//
//         for (int j = low; j < high; j++) {
//             if (arr[j] < pivot) {
//                 i++;
//                 swap(arr[i], arr[j]);
//             }
//         }
//         swap(arr[i + 1], arr[high]);  // Place pivot in correct position
//         int pi = i + 1;
//
//         // Recursively apply to the partitions
//         quickSortHelper(arr, low, pi - 1);
//         quickSortHelper(arr, pi + 1, high);
//     }
// }
//
// // Wrapper function for QuickSort (only vector as argument)
// void quickSort(vector<int>& arr) {
//     // Call the internal helper with initial low and high values
//     quickSortHelper(arr, 0, arr.size() - 1);
// }
//
// // Utility function to print the array
// void printArray(const vector<int>& arr) {
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;
// }
//
// // Main function
// int main() {
//     vector<int> arr = {10, 80, 30, 90, 40, 50, 70};
//
//     cout << "Original array: ";
//     printArray(arr);
//
//     // Call the wrapper quickSort function
//     quickSort(arr);
//
//     cout << "Sorted array: ";
//     printArray(arr);
//
//     return 0;
// }
