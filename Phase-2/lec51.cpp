//linked list-08 question->add two numbers

#include<iostream>
#include<vector>
#include<string>    
#include"lec44_LL_class.cpp"
using namespace std;

//solved myself ^^
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next=curr->next;
        curr->next= prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node* Addition(Node* first, Node* second){
    //step 1: reverse
    first = reverse(first);
    second = reverse(second);
    //step2-add2
    Node*ans=NULL;
    int carry=0;
    while(first!=NULL && second!=NULL){
        int sum = first->data+second->data+carry;
        insertAtHead(ans,sum%10);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }
    while(second!=NULL){
        int sum= second->data+carry;
        insertAtHead(ans,sum%10);
        carry=sum/10;
        second=second->next;
    }
    while(first!=NULL){
        int sum= first->data+carry;
        insertAtHead(ans,sum%10);
        carry=sum/10;
        first=first->next;
    }
    while(carry>0){
        int sum= carry;
        insertAtHead(ans,sum%10);
        carry=sum/10;
    }
    return ans;
}

int main()
{
    //approach1->reverse then add by iterating, then reverse 
    Node* first =new Node(2);
    Node* second= new Node(9);
    insertAtHead(first,4);
    insertAtHead(first,4);
    insertAtHead(first,6);
    insertAtHead(first,9);
    insertAtHead(first,0);
    insertAtHead(first,9);
    insertAtHead(first,9);
    insertAtHead(second,1);
    insertAtHead(second,5);
    insertAtHead(second,7);
    insertAtHead(second,2);
    insertAtHead(second,3);
    insertAtHead(second,9);
    insertAtHead(second,3);
    
    cout<<"First number is : ";
    print(first);
    cout<<"Second number is : ";
    print(second);

    Node * add = Addition(first,second);
    cout<<endl<<"Addition is : ";
    print(add);
    return 0;
}