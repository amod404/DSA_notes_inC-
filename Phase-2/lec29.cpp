//Dynamic memory allocation of 2D array

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void create(int**&arr, int r, int c){
    arr = new int*[r];
    for(int i=0;i<r;i++){
        arr[i] = new int[c];
    }
}

void takeInput(int **arr,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j]; //remember arr is pointer
        }
    }
}

void printOutput(int **arr, int r, int c){
    cout<<"Printing the array:"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" "; //remember arr is pointer
        }
        cout<<endl;
    }
}

void release(int **arr, int r, int c){
    for(int i=0;i<r;i++){
        delete []arr[i];  //will remove all the rows
    }
    delete []arr;    // will remove the array containing pointers of each row
}

int main()
{
    int r,c;
    cout<<"enter the rows:";
    cin>>r;
    cout<<"enter the coloumns:";
    cin>>c;

    // //initiazlization of 2-D array of (r x c)
    // int **arr = new int*[r];
    // for(int i=0;i<r;i++){
    //     arr[i] = new int[c];
    // }

    // int **arr;
    // create(arr,r,c);
    // takeInput(arr,r,c);
    // printOutput(arr,r,c);
    // //remember to free the memory in heap...reverse order
    // // cout<<arr[1][1]<<endl;  //will give the value inputed by us
    // release(arr,r,c);
    // // cout<<arr[1][1]<<endl;   // will give a garbage value
        
    //(done)HW-->jaggered Array and dynamic 2-D array article
    

    return 0;
}


