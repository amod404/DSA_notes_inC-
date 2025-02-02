// heap -> introduction

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include"lec62_classes.cpp"
#include<map>
#define CLEAR system("cls")
using namespace std;

class heap {
        int arr[100];
        int size;
    public:

    heap(){
        size=0;
    }

    void insert(int val){
        int index = size;
        arr[index] = val;

        while(index>0){
            int parent = (index-1)/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                break;
            }
        }
        size =size+1;
    }   
    
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deleteHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
        }
        //swap first and last node
        arr[0]=arr[size-1];
        //reduce arr now
        size--;
        //now give correct position to first node
        int index = 0;
        while(index<size){
            int maxIndex;
            if(2*index+2<size){
                maxIndex = arr[2*index+1] > arr[2*index+2] ? 2*index+1 :2*index+2;
            }
            else if(2*index+1<size){
                maxIndex=2*index+1;
            }
            else{
                return;
            }

            if(arr[index]<arr[maxIndex]){
                swap(arr[index],arr[maxIndex]);
                index=maxIndex;
            }
            else{
                return;
            }
        }
    }
    
};

void heapify_helper(vector<int>& arr,int n, int i){
    int curr = i;
    int largest;
    if(2*i+2<n){
        // largest child 
        largest = arr[2*i+1]>=arr[2*i+2] ? 2*i+1 : 2*i+2; 
    }
    else if(2*i+1<n){
        // only left child exist then check it 
        largest=2*i+1;
    }
    else{
        //both left and right don't exist
        return;
    }

    if(arr[curr]<arr[largest]){
        // if child is larger than swap and do recursive call
        swap(arr[largest],arr[curr]);
        curr= largest;
        heapify_helper(arr,n,curr);
    }
}
void heapify(vector<int> & arr,int n){
    //no need to process leaf node n/2 to n
    for(int i=n/2-1;i>=0;i--){
        heapify_helper(arr,n,i);
    }

    //tc....O(logn)
}

void heap_sort(vector<int> &arr){
    int size=arr.size();

    while(size>0){
        // step 1. heapify the partial array
        heapify(arr,size);
        // step 2. swap 
        swap(arr[size-1],arr[0]);
        size--;
    }
}

int main()
{	CLEAR;

    // heap h;
    // h.insert(55);
    // h.insert(54);
    // h.insert(53);
    // h.insert(50);
    // h.insert(52);
    // h.print();
    // h.deleteHeap();
    // h.print();

    // //heapify-->
    // //(pending)HW-->find its complexities
    // vector<int> arr ={54,53,55,52,50};
    // heapify(arr,arr.size());
    // for(auto i: arr){
    //     if(i!=-1)
    //     cout<< i<< " ";
    // }cout<<endl;

    vector<int> arr1 ={1,21,321,342,123,423,543,3,13,342,543,54,32,33,34,435,23,54,46,867,987,455,3,4354,6,02,56,5,7,1};
    heap_sort(arr1);
    cout<<"Heap sort is: ";
    for(auto i: arr1){
        cout<< i<< " ";
    }cout<<endl;

    return 0;
}