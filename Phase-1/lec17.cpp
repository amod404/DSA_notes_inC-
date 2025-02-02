//Bubble sort
#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "printing the array " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void B_sort(int arr[],int size){
    bool swapped=false;
    for(int i=1;i<size;i++){
        // cout<<"Round: "<<i<<endl;
        for(int j=0;j<size-i;j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                swapped=true;
                // printArray(arr,size);
            }
        }
        if(swapped==false){
            break;
        }
        else{
            swapped=false;
        }
   }
}
int main()
{
    //HW stable or unstable
    // in place sort?
    // quiz in description of lec17
    // solve for i=0 to i<n-1
    int x[]={0,3,4,5,3,2,1,4,5,6,5,3,2,4,6,8,3};
    int s=sizeof(x)/sizeof(int);
    printArray(x,s);
    B_sort(x,s);
    printArray(x,s);

    return 0;
}