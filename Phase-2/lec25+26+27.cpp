//Pointers-->(skipping the basics)
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    //plz plz plz read out the notes
    //as this is a theoratical topic

    // // some precedency and associativity with pointers
    // int *p;
    // int arr[10]={1,1,1,1,1,1,1,1,1,1};
    // p=arr;
    // cout<<"value of *p = "<<*p<<endl;
    // cout<<"value of arr[0] = "<<arr[0]<<endl;
    // cout<<"value of *arr = "<<*arr<<endl;
    // cout<<"value of arr = "<<arr<<endl;
    // cout<<"value of p = "<<p<<endl;
    // cout<<"value of *p+1 = "<<*p+1<<endl;              //readed as  (*p)+1
    // cout<<"value of *(p+1) = "<<*(p+1)<<endl;          //readed as  *(p+1)
    // cout<<"value of &arr[0] = "<<&arr[0]<<endl;
    // cout<<"value of &arr[0]+1 = "<<&arr[0]+1<<endl;       //readed as(&arr[0])+1(*datatype)
    // cout<<"value of ++*p = "<<++*p<<endl;      //++(*p)                      
    // cout<<"value of *++p = "<<*++p<<endl;      //*(++p) means next address
    // // above case precedency is same, right to left associativity came into action
    // cout<<"value of *p++ = "<<*p++<<endl;         //*(p++)  address increase
    // cout<<"value of *(p++) = "<<(*p)++<<endl;     //(*p)++  value increase
    // // above case prcedency of post incriment is more than derefrence operator
    // // note can use ++/-- operators on derefrenced values means
    // // defrence doesnt return value but return memory location(/or variable) so that ++/--operator can do chnages
    
    // // formula:- arr[i]=*(arr+i)....logical
    // // also, i[arr]=*(i+arr).......somewhat logical
    // // conclusion:-  arr[i]=i[arr].........  :0
    // int arr[5]={100,101,102,103,104};
    // int i=0;
    // cout<<arr[i]<<endl;
    // cout<<i[arr]<<endl;
    // cout<<&++i[arr]<<"\t"<<i[arr]<<endl;
    // cout<<&++i[arr]<<"\t"<<i[arr]<<endl;
    // cout<<&++i[arr]<<"\t"<<i[arr]<<endl;
    // cout<<&++i[arr]<<"\t"<<i[arr]<<endl;
    // // .
    // cout<<&++i[arr]<<endl;
    // cout<<i<<endl;
    // cout<<i[arr]<<endl;

    // // pointers for char and char array
    // char ch[6]="abcde";
    // char *c=&ch[0]; //or int *c=ch;
    // cout<<ch<<endl;    //abcde
    // cout<<c<<endl;     //abcde
    // cout<<*ch<<endl;    //a
    // cout<<*c<<endl;     //a
    // cout<<&ch<<endl;    //address
    // char chr='t';
    // char *p=&chr;
    // cout<<&chr<<endl;  //t..garbage value
    // cout<<p<<endl;     //t...garbage value
    // cout<<*p<<endl;     // t
    
    // (pending)HW-->study pointers from code studio and do all the questions on pointer 
    
    // double pointer(again refer notes)
    // int i=5;
    // int *ptr=&i;
    // int **ptr2=&ptr;
    // // cout<<&&i<<" "<<&(&i)<<end;   //this wont
    // cout<<**ptr2<<endl;  //this will work
    
    //(pending)HW--> MCQ of pointer from lec27 description
    
    // //good way of initialize
    // int* p=0;
    // cout<<*p<<endl;

    // &arr case
    // int arr[9]={0};
    // int *p=arr;
    // // p=&arr; //error
    // cout<<p<<endl;
    // cout<<arr<<endl;
    // cout<<&arr<<endl;


    return 0;
}