//linked list-09 question->clone a linked list with random pointer

#include<iostream>
#include<vector>
#include<string>  
#include<unordered_map>  
using namespace std;

class Node
{

public:
    // creating our node
    int data;   // stores data of urrent object
    Node *next; // store address of next obj
    Node *random;
    // construcutor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random=this;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        this->next = NULL;
        delete next;
        cout << "Memory is free for node with data " << value << endl;
    }

};
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d); // new node to be inserted
    temp->next = head;        // point the next of new node at head of old one
    head = temp;              // now head will go to that new node
}
void print(Node *&head)
{
    // since we are calling by reference, we dont want our head to go anywhere
    // so we will make a temp to iterate the nodal path
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // to go to next node
        // visualize it ~ ~
    }
    cout << endl;
}   

// almost solved mself...learn STL :|
Node* clone(Node* head){
    Node* ans=new Node(0);
    //base case
    if(head==NULL){
        ans=NULL;
        return ans;
    }

    //making clone node
    ans->data=head->data;
    Node* curr1= head->next;
    Node* curr2= ans;
    while(curr1!=NULL){
        Node* temp= new Node(curr1->data);
        curr2->next=temp;

        curr1=curr1->next;
        curr2=curr2->next;
    }

    //linking all nodes
    unordered_map<Node*,Node*> links;
    curr1=head;
    curr2=ans;
    while(curr1!=NULL){
        links[curr1]=curr2;
        curr1=curr1->next;
        curr2=curr2->next; 
    }

    curr1=head;
    curr2=ans;
    //fixing random
    while(curr1!=NULL){
        Node* temp = links[curr1->random];
        curr2->random=temp;
        curr1=curr1->next;
        curr2=curr2->next; 
    }
    return ans;
}
//draw diagram, messed up approach
Node* advance_clone(Node* head){
    Node* ans=new Node(0);
    //base case
    if(head==NULL){
        ans=NULL;
        return ans;
    }
    
    //making clone linked list 
    ans->data=head->data;
    Node* curr1= head->next;
    Node* curr2= ans;
    while(curr1!=NULL){
        Node* temp= new Node(curr1->data);
        curr2->next=temp;
        curr1=curr1->next;
        curr2=curr2->next;
    }

    curr1=head;
    curr2=ans;
    //cross linking the original and clone list
    while(curr1!=NULL){
        Node* save1 = curr1->next; //saving next iteration
        Node* save2 = curr2->next; 
        curr1->next=curr2;
        curr2->next=save1;
        curr1=save1;
        curr2=save2;
    }

    //fixing random pointers of clone list
    Node* temp= head;
    while(temp!=NULL){
        temp->next->random=temp->random->next; //imagine
        temp=temp->next->next;  //temp will iterate to original part
    }

    //undo the crosslinking
    curr1=head;
    curr2=ans;
    while(curr2->next!=NULL){
        curr1->next=curr1->next->next;
        curr2->next=curr2->next->next;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    curr1->next=NULL;  // last case
    return ans;
}

int main(){

    //frist we are cloning the simple linked list
    //then mapping the nodes with respective position
    //then point the random of clone acoordingly
    Node* head=new Node(10);
    Node* tail=head;
    for(int i=9;i>0;i--){
        insertAtHead(head,i);
    }
    //changng the random pointer
    head->random=head->next->next->next;
    print(head);
    cout<<head->random->data<<endl;
    // Node* ans = clone(head);
    // print(ans);
    // cout<<ans->random->data<<endl;

    //this approach is messed up:{
    Node* ans = advance_clone(head);
    print(ans);
    cout<<ans->random->data<<endl;

    return 0;
}