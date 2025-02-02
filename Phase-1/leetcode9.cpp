#include<iostream>
using namespace std;

bool isUnique(int x[],int size){

}

int duplicate(int x[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(x[i]==x[j] && j!=i){
                return x[i];//or x[j]
            }
        }
    }
}
//sir's sol
int Duplicate(int x[],int size){
    int ans=0;
    for(int i=1;i<size;i++){
        ans=ans^i;    
    }
    for(int j=0;j<size;j++){
        ans=ans^x[j];
    }
    return ans;
}

int main()
{
    //unique numberof occurance
    //pending
    //find duplicate
    int arr[10]={1,2,3,4,5,6,7,8,9,3};
    int s=sizeof(arr)/sizeof(int);
    int y=duplicate(arr,s);
    int z=Duplicate(arr,s);
    cout<<y<<endl<<z;
    return 0;
}