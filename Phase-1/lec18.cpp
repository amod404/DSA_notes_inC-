// Insertion sort
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

void I_sort(int arr[], int size){
    for(int i=1;i<size;i++){
        int temp=arr[i];
        int j;
        for(j=i-1;j>=0;j--){

            if(arr[j]>temp){
                //shift
                arr[j+1]=arr[j];
            }
            else{
                //stop
                break;
            }
        }
        arr[j+1]=temp;
    }
}

//using while loop
void i_sort(int arr[],int size){
    int temp,i=1,j;
    while(i<size){
        printArray(arr,size);
        j=i-1;
        temp=arr[i];
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
                j--;
            }
            else break;
        }
        arr[j+1]=temp;
        i++;

    }
}

int main()
{
    //HW...write the algo with while loop
    int x[]={5,3,4,2,1};
    int s=sizeof(x)/sizeof(int);
    printArray(x,s);
    i_sort(x,s);
    printArray(x,s);
    return 0;
}