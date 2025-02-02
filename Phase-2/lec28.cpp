// Reference variable || Static vs Dynamic Memory
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//before this we are doing pass by value
void update(int& n){  //pass by value reference...
    n++; // n is refernce variable to same memory as i
    //as function end r.v. will be deleted and used again for another call
}

//can for reference of pointer also...means a pointer have two names, and 1 memory
void update(int* &p){
    p+=1;
    *p+=1;
}

void getData(int* ptr,int n){
    for(int i=0;i<n;i++){
        cin>>ptr[i];
    }
    //arr[i] is same as ptr[i]...where ptr is pointer of arr
}

void printData(int* ptr, int n){
    cout<<"printing the array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<ptr[i]<<" ";
    }cout<<endl;
}

int sum(int* ptr, int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=ptr[i];
    }
    return ans;
}

int main()
{
    // int i=5; 
    // int &j=i;//way to initialize an reference variable 
    // //int &j=i+1; //error
    // cout<<j<<" "<<i<<endl; //5 5
    // i++;
    // cout<<j<<" "<<i<<endl; //6 6
    // j=j+2;
    // cout<<j<<" "<<i<<endl; //8 8
    //thus both name will map to same memory, 
    //so use anyone to alter the value at that specific memory address

    //call by reference function
    // update(i); // i will become 6
    // cout<<i; 
    // // //
    // // for pointers
    // int arr[5]={1,2,3,4,5};
    // int *ptr=&arr[0];
    // update(ptr); //ptr will move to arr[1] and then increase arr[1] from 2 to 3
    // cout<<*ptr;

    //return by reference and return by pointers is a bad practice
    // as that memory is the scope of function so we can refernce it after function ends after returning
    // thus it will throw a warning

    
    // //now we will create a dynamic array with the help of heap memory
    // //plz refer notes for theory
    // //static memory-->stack
    // //dynamic memory-->heap
    // int n;
    // cout<<"Enter the length of array:";
    // cin>>n;
    // //to initialize array in heap
    // int *ptr = new int[n];
    // getData(ptr,n);
    // printData(ptr,n);   
    // cout<<"The sum is : "<<sum(ptr,n)<<endl;

    //(done)HW-->Read documentation on memory allocation

    //(done)HW-->void pointer and address typecasting
    //address typecasting
    // int a=10;
    // char ch='a';
    // int *p=&a;
    // cout<<*p<<endl;
    // char *c=(char *)p;
    // cout<<*c;
    //void pointer can also be typecasted in same way....read notes
    
    return 0;
}