//find unique in array

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

int unique(int x[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(x[i]==x[j] && j!=i){
                break;
            }
            if(j==size-1){
                return x[i];
            }
        }
    }
}
//sir'ssolution
int Unique(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    return ans;
}

int main()
{
    int arr[7]={1,2,5,3,5,2,1};
    int s=sizeof(arr)/sizeof(int);
    int y=unique(arr,s);
    cout<<y;
    return 0;
}