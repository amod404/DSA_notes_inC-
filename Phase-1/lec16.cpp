//Selection sort
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

void S_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        
        swap(arr[minIndex],arr[i]);
        // int t=arr[minIndex];
        // arr[minIndex]=arr[i];
        // arr[i]=t;
    }
}
int main()
{
    //HW--> what is stable and unstable algo.....
    // also make flowchart for selectio sort
    
    int x[]={4,3,2,1};
    int s=sizeof(x)/sizeof(int);
    printArray(x,s);
    S_sort(x,s);
    printArray(x,s);

    return 0;
}