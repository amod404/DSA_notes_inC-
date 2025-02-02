//linked list-05 question->remove duplicate
#include<iostream>
#include<vector>
#include<string>
#include"lec44_LL_class.cpp"
using namespace std;

void S_removeDuplicate(Node*&head,Node*&tail){
    if(head==NULL){
        return;
    }
    Node* back=head;
    Node* front=head->next;
    while(front!=NULL) {
        if(back->data==front->data){
            back->next=front->next;
            if(front==tail){
                tail=back;
            }
            delete front;
            front=back->next;
        }
        else{
            front=front->next;
            back=back->next;
        }
    }
}

void U_removeDuplicates(Node*& head, Node*& tail){
    if(head==NULL){
        return;
    }
    Node*curr=head;
    while(curr->next!=NULL){
        Node*temp=curr;
        while(temp->next!=NULL){
            if(temp->next->data==curr->data){
                Node* waste=temp->next;
                temp->next=temp->next->next;
                if(waste==tail){
                    tail=temp;
                }
                delete waste;
            }
            else{
                temp=temp->next;
            }
        }
        if(curr->next!=NULL){
            curr=curr->next;
        }
    }
}

pair<Cnode*,Cnode*> C_split(Cnode* & tail){
    pair<Cnode*,Cnode*>ans={NULL,NULL};
    //base case
    if(tail==NULL || tail->next==tail){
        ans.first=tail;
        return ans;
    }
    //finding the middle
    Cnode* slow =tail;
    Cnode* fast =tail->next;
    if(fast->next!=tail){  //case for only two nodes..imp
        do{
            fast=fast->next;
            slow=slow->next;
            if(fast->next!=tail){
                fast=fast->next;
            }
        }while(fast->next!=tail);
    }
    // breaking the CLL
    Cnode* tail2=slow->next;
    fast->next=tail2;
    slow->next=tail;

    //returnin the answer
    ans.first=tail;
    ans.second=tail2;
    return ans;
}

int main()
{
    //remove duplicate from a :
    // 1. sorted LL  2. unsorted LL

    //1. O(n)
    // Node*head = new Node(0);
    // Node*tail=head;
    // insertAtTail(tail,1);
    // insertAtTail(tail,1);
    // insertAtTail(tail,2);
    // insertAtTail(tail,3);
    // insertAtTail(tail,3);
    // insertAtTail(tail,3);
    // insertAtTail(tail,4);
    // insertAtTail(tail,4);
    // insertAtTail(tail,4);
    // print(head);
    // // removing duplicates from the linked list 
    // removeDuplicate(head,tail);
    // print(head);
    // cout<< tail->data << endl; //checking if tail is shifted back
     
    //2.(done)HW....O(n^2)
    // Node*head = new Node(0);
    // Node*tail=head;
    // insertAtTail(tail,9);
    // insertAtTail(tail,2);
    // insertAtTail(tail,3);
    // insertAtTail(tail,9);
    // insertAtTail(tail,1);
    // insertAtTail(tail,2);
    // insertAtTail(tail,1);
    // insertAtTail(tail,1);
    // insertAtTail(tail,3);
    // insertAtTail(tail,3);
    // insertAtTail(tail,3);
    // insertAtTail(tail,3);
    // print(head);
    // // removing duplicates from the linked list 
    // U_removeDuplicates(head,tail);
    // print(head);
    // cout<< tail->data << endl; //checking if tail is shifted back
     
    //(pending)HW->
    //can do like, sort the linked list and then use the above alogo
    //O(nlogn)
    //use map...TO(n),SO(n)
    //(extra)->split a circular linked list into two halfs
    
    //(done)HW->spliting the circular LL
    // Cnode* tail = new Cnode(2);
    // C_insertAtPosition(tail,2,10);
    // C_insertAtPosition(tail,2,9);
    // C_insertAtPosition(tail,2,8);
    // C_insertAtPosition(tail,2,7);
    // C_insertAtPosition(tail,2,5);
    // C_insertAtPosition(tail,2,4);
    // C_insertAtPosition(tail,2,3);
    // // //    
    // C_print(tail);
    // pair<Cnode*,Cnode*>ans=C_split(tail);
    // cout<<"The first half is :"<<endl;
    // C_print(ans.first);
    // cout<<"The second half is :"<<endl;
    // C_print(ans.second);

    return 0;
}