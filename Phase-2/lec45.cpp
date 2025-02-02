//Linklist-02 (questions)

#include<iostream>
#include<vector>
#include<string>
#include"lec44_LL_class.cpp"
using namespace std;

//did myself ^^
void reverse(Node* &head, Node* &tail){
    if(head==NULL || head->next==NULL){
        return;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=head;

    //try to dry run this for revising
    while(curr!=NULL){
        forward=forward->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    swap(head,tail);
}

void solve(Node*curr, Node* prev, Node* forward){
    //base case
    if(curr==NULL){
        return;
    }
    // process
    forward=curr->next;
    curr->next=prev; //this particular line can be below recursive call

    //recursive call;
    solve(forward,curr,forward);
    // prev=curr;  backside mai ye hua
    // curr=forward;
}

void r_reverse(Node* &head, Node* &tail){
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=head;
    solve(curr,prev,forward);
    swap(head,tail);
}

Node* R_solve(Node * head){
    // base case to return the tail of th LL
    if(head==NULL ||head->next==NULL){
        return head;
    }
    //calling till end node
    Node* chotahead= R_solve(head->next);    //while returning we have valu of last note in it
    
    //breaking and joining the links
    head->next->next=head;
    head->next=NULL;  //this is to make the first node NULL, or otherwise have to do manually

    //returning it in each iteration
    return chotahead;
}
Node* R_reverse(Node* &head){
    return R_solve(head);
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

Node* middleNode(Node* &head){
    int len = nodeLength(head);
    int mid = len/2+1;
    Node* temp=head;
    for(int i=1;i<mid;i++){
        temp=temp->next;
    }
    return temp;
}

Node* midNode(Node* &head){
    Node* pro = head;
    Node* noob = head;
    while(pro!=NULL){
        pro=pro->next;
        if(pro==NULL){
            break;
        }
        else{
            noob=noob->next;
            pro=pro->next;
        }
    }
    return noob;
}

int C_length(Cnode* &tail){
    if(tail==NULL){
        return 0;
    }

    Cnode* temp=tail->next;
    int count=1;
    while(temp!=tail){
        count++;
        temp=temp->next;
    }
    return count;
}

bool is_circular(Cnode* &tail){
    if(tail==NULL){
        return false;
    }
    Cnode* temp=tail->next;
    int i=0;
    while(temp!=tail){
        temp=temp->next;
        i++;
        if(i==C_length(tail)){
            return false;
        }
    }
    return true;
}

Dnode* D_reverse(Dnode*& head){
    if(head==NULL){
        return head;
    }
    Dnode* curr = head;
    Dnode* forw = head->next;

    while(curr!=NULL){
        head=curr;
        curr->next=curr->prev;
        curr->prev=forw;
        curr=forw;
        if(forw!=NULL){
            forw=forw->next;
        }
    }
    return head;
}

int main()
{
    //making a new node
    // Node* head = new Node(11);
    // Node* tail = head;
    // for(int i=0;i<10;i++){
    //     insertAtHead(head,10-i);       
    // }
    // print(head);    

    //reverse a linked list
    // reverse(head,tail);
    // print(head);  

    //reverse a linked list by recursion
    // reverse(head,tail);
    // print(head);

    //(done)HW->make stack chart of this algo
    //Third approach
    // Node* temp = R_reverse(head);
    // print(temp);
    //but head and tail are not swaping
    // swap(head,tail);
    // cout<<head->data<<endl;

    //(done)HW->reverse doublylinked list 
    // Dnode* head= new Dnode(0);
    // for(int i=1;i<10;i++){
    //     D_insertAtHead(head,i);
    // }print(head);
    // head=D_reverse(head);
    // print(head);


    // middle of a linked list
    //right one is prefered in even case
    // deleteValue(head,tail,11);
    // Node* middleN = middleNode(head);
    // Node* midN = midNode(head);
    // cout<< midN->data<<endl;
    
    //(done))HW->check wheather a linked list is circular or not
    // Cnode* tail=NULL;
    // for(int i=1;i<10;i++){
    //     C_insertAtPosition(tail,1,i);
    // }
    // print(tail);
    // cout<<"IS circular-> "<<is_circular(tail);


    return 0;
}