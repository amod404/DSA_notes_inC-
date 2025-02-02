//linked list-10....merge sort in linked list

#include<iostream>
#include<vector>
#include<string>
#include"lec44_LL_class.cpp"
using namespace std;

Node* get_Mid(Node* head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* mergeTwo(Node* left, Node*right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    Node* ans= new Node(-1);
    Node* temp=ans;
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    return ans->next;
}

Node* merge_sort(Node* head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    //getting the mid of the Linked list
    Node* midNode= get_Mid(head);
    //breaking our list into two halfs
    Node* right = midNode->next;
    Node* left = head;
    midNode->next=NULL;
    
    //breaking while calling and merging while return
    left= merge_sort(left);
    right=merge_sort(right);

    //merging two sorted 
    Node* ans=mergeTwo(left,right);

    return ans;
}

int main()
{
    Node* head= new Node(0);
    for(int i=1;i<10;i++){
        insertAtHead(head,i);
    }print(head);

    head=merge_sort(head);
    print(head);

    //(pending)HW->wy merge sort is prefer nott quick sort in linkedlist

    //(HW) Check flatten linked list;

    //(pending)HW->done all the questions of spread sheet till linked list
    return 0;
}