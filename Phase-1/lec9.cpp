// // array : some basics are skips

// #include <iostream>
// using namespace std;

// int Max(int arr[], int size)
// {
//     int max = INT8_MIN;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//         // use max function.....int y= max(max,arr[i])
//     }
//     return max;
// }

// int Min(int arr[], int size)
// {
//     int min = INT8_MAX;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] < min)
//         {
//             min = arr[i];
//         }
//     }
//     return min;
// }
// void printArray(int arr[], int size)
// {
//     cout << "printing the array " << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void getData(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         cin >> arr[i];
//     }
// }

// void update(int arr[], int size, int a, int b)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == a)
//         {
//             arr[i] = b;
//         }
//     }
// }

// int sum(int arr[], int size)
// {
//     int sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum += arr[i];
//     }
//     return sum;
// }

// int main()
// {
//     // int size;
//     // int x[size];......Ghatiya practice
//     // int x[10];
//     int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//     int s = sizeof(x) / sizeof(int);
//     // getData(x,s);
//     // printArray(x,s);
//     // cout<< Max(x,s)<<endl;
//     // cout<< Min(x,s)<<endl;
//     printArray(x, s);
//     cout << sum(x, s) << endl;
//     update(x, s, 3, 33); // scope of array is all over the functions and main f.
//     printArray(x, s);
//     return 0;
// }


// #include<iostream>
// using namespace std;

// //Linear search
// bool search(int arr[], int size, int key){
//     for(int i=0;i<size;i++){
//         if(arr[i]==key){
//             return 1;
//         }
//     }
//     return 0;
// }


// int main()
// {
//     int arr[10]={5,7,-2,10,22,-2,0,5,22,1};
//     int s = 10;  //size
//     //wheather 1 is present or not
//     bool found = search(arr,s,1);
//     if(found){
//         cout<<"Present";
//     }
//     else{
//         cout<<"Not present";
//     }
//     return 0;
// }

//reverse of an array
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

void reverse (int x[],int size){
    int y[size];
    for(int i=0;i<size;i++){
        y[size-i-1]=x[i];
    }
    for(int i=0;i<size;i++){
        x[i]=y[i];
    }
}

//better and faster
void Reverse (int x[],int size){
    int temp;
    for(int i=0;i<size/2;i++){
        temp=x[i];
        x[i]=x[size-1-i];
        x[size-1-i]=temp;    
        // swap(x[i],x[size-i-1]);
    }
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    int s=10;
    printArray(arr,s);
    Reverse(arr,s);
    // reverse(arr,s);
    printArray(arr,s);
    return 0;
}