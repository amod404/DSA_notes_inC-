// 2D arrays

#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

void get_data(int arr[3][4]){
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col]; //can take entry as coulum wise....just put arr[col][row]
        }
    }

}

void print_2d(int arr[3][4]){

    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";
        }cout<<endl;
    }
}

bool isPresent(int arr[3][4],int target){
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            if(arr[row][col]==target){
                return 1;
            }
        }
    }
    return 0;
}

void in_wave(int arr[3][4]){

    for(int j=0;j<4;j++){
        for(int i=0;i<3;i++){
            cin>>arr[i][j];
        }
        j++;
        for(int i=0;i<3 && j<4;i++){
            cin>>arr[2-i][j];
        }
    }
}

void sprial_print( int arr[5][5]){
    int i=0,j=0;
    int n=5;
    int N=5;
    for(;j<N;j++){
        cout<<arr[i][j]<<endl;
    }
    j--;
    i++;
    n--;
    N--;
    // to break the loop we are taking the or as, there may be n=0, but N nonzero, so
    // have to print that last iteration and vive verse
    while(n>0 || N>0){

        for(int m=n;m;m--,i++){
            cout<<arr[i][j]<<endl;
        }i--; // bringing back the extra iteration
        j--;  // jumping to next iteration
        n--;  // shorting for next to next iteration

        if(n<0 || N<0){
            break;
        }

        for(int m=N;m;m--,j--){
            cout<<arr[i][j]<<endl;
        }j++; // bringing back the extra iteration
        i--;  // jumping to next iteration
        N--;  // shorting for next to next iteration

        if(n<0 || N<0){
            break;
        }

        for(int m=n;m;m--,i--){
            cout<<arr[i][j]<<endl;
        }i++; // bringing back the extra iteration
        j++;  // jumping to next iteration
        n--;  // shorting for next to next iteration

        if(n<0 || N<0){
            break;
        }

        for(int m=N;m;m--,j++){
            cout<<arr[i][j]<<endl;
        }
        j--; // bringing back the extra iteration
        i++;  // jumping to next iteration
        N--;  // shorting for next to next iteration
    }
}

//not best solution :(    but self solve :)
void rotate_90(int matrix[10][10]){

    int n=10;
    int i1=0,j1=1;
    int i2=n-1,j2=0;
    int i3=n,j3=n-1;
    int i4=1,j4=n;
    while(n>0){

        for(int m1=i1,n1=j1,m2=i2,n2=j2,m3=i3,n3=j3,m4=i4,n4=j4,k=0;
        k<n;k++){

            int temp=matrix[m1][n1];
            matrix[m1][n1]=matrix[m2][n2];
            matrix[m2][n2]=matrix[m3][n3];
            matrix[m3][n3]=matrix[m4][n4];
            matrix[m4][n4]=temp;

            n1++;m2--;n3--;m4++;
        }
            
        i1++;j1++;
        i2--;j2++;
        i3--;j3--;
        i4++;j4--;
        n=n-2;
    }
}

bool B_search_matrix(vector<vector<int>> &matrix,int target){
    int row = matrix.size();
    int col = matrix[0].size();

    int s=0;
    int e=row*col-1;
    int mid = (s+e)/2;

    //remember: 
    // row_no=mid/col
    // col_no=mid%col

    while(s<=e){
        int element=matrix[mid/col][mid%col];

        if(element==target){
            return 1;
        }

        if(element<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }

        mid=(s+e)/2;
    }
    return 0;
}   

bool search_matrix(vector<vector<int>> &matrix, int target){

    int row=matrix.size();
    int col=matrix[0].size();

    int r_index = 0;
    int c_index = col-1;

    while(r_index<row && c_index<col){
        int element=matrix[r_index][c_index];
        if(element==target){
            return 1;
        }

        if(element<target){
            r_index++;
        }
        else{
            c_index--;
        }
    }
    return 0;
}

int main()
{
    // int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,0,0,0}};
    // int arr[3][4]={1,2,3,4,5,6,7,8,9,0,0,0};
    // int arr[3][4]={0}; //all zeros
 
    // int arr[3][4];
    // get_data(arr);
    // print_2d(arr);
    // cout<<sizeof(arr)/sizeof(arr[0])<<endl; //rows
    // cout<<sizeof(arr[0])/sizeof(int)<<endl; //coloum
    
    //not coding row wise sum and all
    
    //checking wheather contigous memory!
    // int *p = &arr[0][0];
    // for(int i=0;i<9;i++,p++){
    //     cout<<p<<"\t"<<*p<<endl;
    // }
    
    //to find an element
    // cout<<"is 5 present-->"<<isPresent(arr,5)<<endl;
    
    //getting values as wave
    // O(n*m)-->complexity
    // in_wave(arr);   
    // print_2d(arr);
    
    //sprial print for square matrix...imp
    // int arr[5][5]={1,2,3,4,5,16,17,18,19,6,15,24,25,20,7,14,23,22,21,8,13,12,11,10,9};
    // sprial_print(arr);
    
    //HW....rotate an matrix without temp matrix..leetcode.
    // int arr[10][10]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // rotate_90(arr);
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<endl;
    // }
    
    //binary search...with stl
    // vector <vector<int>> matrix={{1,3,5,7},{10,11,16,20},{22,30,34,60}};
    // cout<<B_search_matrix(matrix,30);
    //we can also return its index

    //level 2 of searching :||
    // vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{22,30,34,60}};
    // cout<<search_matrix(matrix,30);

    return 0;
}