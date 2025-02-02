//linked list-06 (question)->sort 0,1,2 and merge 2 sorted LL
//Important notes

#include<iostream>
#include<vector>
#include<string>
#include"lec44_LL_class.cpp"
using namespace std;

void insertInTail(Node*&our_tail,Node*curr){
    our_tail->next=curr;
    our_tail=curr;
}
void sorttwo(Node* &head){
    Node*zeroHead=new Node(-1);
    Node*zeroTail= zeroHead;
    Node*oneHead=new Node(-1);
    Node*oneTail= oneHead;
    Node*twoHead=new Node(-1);
    Node*twoTail= twoHead;

    Node*curr=head;
    //create separate list for 0,1,2
    while(curr!=NULL){
        int value=curr->data;
        switch(value){
            case 0: insertInTail(zeroTail,curr);
                break;
            case 1: insertInTail(oneTail,curr);
                break;
            case 2: insertInTail(twoTail,curr);
                break;
        }
        curr=curr->next; //current will remain ahead of all the tails
    }
    //merge
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
        oneTail->next=twoHead->next;
    }
    else{
        zeroTail->next=twoHead->next;

    }
    twoTail->next=NULL;

    head=zeroHead->next;
    
    //delete
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

// solved my self
void traverse(Node*&curr1,Node*&curr2){
    while(curr1->next!=NULL && curr1->next->data <= curr2->data){
                curr1=curr1->next;
            }
            Node* temp=curr1->next;
            curr1->next=curr2;
            curr1=temp;
}
Node* merge_sorted(Node*head1,Node*head2){
    //base cases:
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1==NULL && head2==NULL){
        return head1;
    }
    
    Node* curr1=head1;
    Node* curr2=head2;
    Node* main=NULL;
    if(head1->data <= head2->data){
        main=head1;
    }
    else{
        main=head2;
    }

    while(curr1!=NULL && curr2!=NULL){
        if(curr1->data <= curr2->data){
            traverse(curr1,curr2);
        }
        else{
            traverse(curr2,curr1);
        }
    }
    return main;
}

//sir's approach...same complexity
void solve(Node*&first,Node*&second){

    Node* curr1=first;
    Node* next1=curr1->next;
    Node* curr2=second;
    if(next1==NULL){
        curr1->next = curr2; //dangerous
        return;
    }

    while(next1!=NULL && curr2!=NULL){
        if(curr2->data >= curr1->data && curr2->data <=next1->data){
            //to track the second list
            Node* next2=curr2->next;
            //added in betwenn
            curr1->next=curr2;
            curr2->next=next1;
            //iincrement
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=curr1->next;
            next1=next1->next;
            if(next1==NULL){
                curr1->next = curr2;
                return;
            }
        }
    }
}
Node* Merge_Sorted(Node* first, Node*second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }

    if(first->data <= second->data){
        solve(first,second);
        return first;
    }
    else{
        solve(second,first);
        return second;
    }
}

int main(){
    // //for sort 0,1,2
    // //Approac 1-> count 0 1 and 2 and change the data
    // Node*head=new Node(1);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    // insertAtHead(head,0);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    // insertAtHead(head,2);
    // insertAtHead(head,0);
    // insertAtHead(head,2);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    // insertAtHead(head,0);
    // insertAtHead(head,1);
    // print(head);
    // //sorting
    // sorttwo(head);
    // print(head);
    // //TO(n),SO(1)

    //merge 2 sorted linkedlist
    Node* head1 = new Node(35);
    Node* head2 = new Node(21);

    for(int i=10;i>0;i--){
        insertAtHead(head1,3*i);
    }
    for(int i=15;i>7;i--){
        insertAtHead(head2,i+4);
    }
    cout<<"List 1: "<<endl;
    print(head1);
    cout<<"List 2: "<<endl;
    print(head2);

    //TO(n),SO(1)
    Node* merged_head = Merge_Sorted(head2,head1);
    // Node* merged_head = merge_sorted(head2,head1);
    cout<<"printing the merged LL: "<<endl;
    print(merged_head);

    return 0;
}
