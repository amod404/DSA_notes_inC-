//linked list-07 question->palindrome

#include<iostream>
#include<vector>
#include<string>
#include"lec44_LL_class.cpp"
using namespace std;
Node* getmid(Node*head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
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
bool isPalindrome(Node*head){
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return true;
    }

    //step 1. find middle
    Node* middle = getmid(head);
    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node* a= head;
    Node* b= middle->next;
    while(b!=NULL){
        if(a->data!=b->data){
            return false;
        }
        a=a->next;
        b=b->next;
    }
    return true;
    
}
int main()
{
    //palindrome
    //aproach 1.-> save values in a array, then check palindrome SO(n), TO(n)
    //approach2.-> MIddle (find), then reverse LL after
    // compare head and middle    
    Node*head = new Node(1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    cout<<"Our LL is:"<<endl;
    print(head);
    if(isPalindrome(head)){
        cout<<"It is an palindrome"<<endl;
    }
    else{
        cout<<"It is not an palindrome!!!"<<endl;
    }
    return 0;
}