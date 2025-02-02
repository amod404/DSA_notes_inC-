// linklist-03 (question)

#include<iostream>
#include<vector>
#include<string>
#include"lec44_LL_class.cpp"
using namespace std;

//did myself ^^
void K_reverseNode(Node* & head, Node* &tail, int k){
    Node* t1=head;
    Node* t2=head;
    Node*temp=NULL;
    int j=1;
    int t= (nodeLength(head))/k;
    while(j<=t){
    // cout<<"Hi";
        int i=1;
        while(i<k){
            t2=t2->next;
            i++;
        }
        if(j==1){
            head=t2;
        }
        if(j==t){
            tail=t1;
        }
        if(j!=1){
            temp->next=t2;
        }
        seg_reverse(t1,t2);
        temp=t1;
        t2=t1->next;
        t1=t2;
        j++;
    }
}


int nodeLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void seg_reverse(Node* start, Node* end){
    Node* temp = end->next;
    Node* prev=temp;
    Node* curr=start;
    Node* forward=start;

    //try to dry run this for revising
    do{
        forward=forward->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }while(curr!=temp);
}

Node* kReverse(Node* head,int k){
    //base case
    if(head==NULL){
        return NULL;
    }

    Node* next = NULL;
    Node*curr = head;
    Node* prev = NULL;
    int count=0;

    while(curr!= NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!= NULL){
        head->next = kReverse(next,k);
    }

    return prev;

}

int main()
{
    //reverse a linked-list in K-groups
    //making a new node
    Node* head = new Node(0);
    Node* tail = head;
    for(int i=1;i<15;i++){
        insertAtTail(tail,i);       
    }print(head);

    // K_reverseNode(head,tail,5);
    //or
    // print(kReverse(head,3));
    print(head);
    cout<< head->data <<endl;    
    cout<< tail->data <<endl;    

    return 0;
}


