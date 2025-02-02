//Linked list-04...question->detect and remove loop in linked list
#include<iostream>
#include<vector>
#include<string>
#include"lec44_LL_class.cpp"
#include<map>
using namespace std;

bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }
    map<Node*, bool> visited;
    Node*temp=head;
    while(temp!=NULL){
        if(visited[temp] == true){
            cout<<"loop is present at:"<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

Node* floydDetectLoop(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* slow= head;
    Node* fast= head;
    while(slow!=NULL && fast != NULL){
        fast=fast->next;
        if(fast==NULL){
            break;
        }
        else{
            fast=fast->next;
        }
        slow= slow->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            cout<<"Cycle is present at: "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

void removeLoop(Node*&head){
    if(head==NULL){
        return;
    }
    
    Node* slow= head;
    Node* fast= head;
    while(slow!=NULL && fast != NULL){
        fast=fast->next;
        if(fast==NULL){
            break;
        }
        else{
            fast=fast->next;
        }
        slow= slow->next;
        if(slow==fast){
            slow=head;
            Node* back = fast;
            while(slow!=fast){
                back = fast;
                slow=slow->next;
                fast=fast->next;
            }
            cout<<"Removing cycle at: "<<slow->data<<endl;
            back->next=NULL;
        }
    }
}

void brentDetectandremove(Node* head){
    if(head==NULL || head->next==NULL){
        return;
    }
    Node* slow=head;
    Node* fast=head;
    int steps=0;
    int power=1;
    //brent's alogorthm-->read it 
    while(fast!=NULL && fast->next!=NULL){
        if(steps==power){
            slow=fast;
            power*=2;
            steps=0;
        }
        fast=fast->next;
        steps++;
        if(slow==fast){
            cout<<"LOOP detected"<<endl;
            break;
        }
    }

    // counting length of the loop 
    int count=1;
    Node* temp=fast;
    while(temp->next!=fast){
        temp=temp->next;
        count++;
    }

    slow=head;
    fast=head;
    //moving fast ahed of slow by the length of the loop
    for(int i=0;i<count;i++){
        fast=fast->next;
    }
    //moving both fast and slow and a prev pointer
    Node*prev=fast;
    while(fast!=slow){
        prev=fast;
        fast=fast->next;
        slow=slow->next;
    }
    //breaking the loop and pointing to NULL
    prev->next=NULL;
}


int main()
{
    //Detech cycle in linked list
    //remove cycle from linked list
    //beginning/start node of a loop in linked list

    Node*head= new Node(0);
    Node* tail= head;

    int n=10;
    for(int i=1;i<=n;i++){
        insertAtTail(tail,i);
    }print(head);
    
    //forming a loop ourself  \*U*/
    tail->next = head->next;


    // SO(n),TO(n)
    // if(detectLoop(head)){
    //     cout<<"It has a loop"<<endl;
    // }
    // else{
    //     cout<<"No loop present"<<endl;
    // }

    // floyd algo do not give head noed of loop, just detect with SO(1)
    // if(floydDetectLoop(head)!=NULL){
    //     cout<<"It has a loop"<<endl;
    // }
    // else{
    //     cout<<"No loop present"<<endl;
    // }

    //removing loop using flyod algo
    // removeLoop(head);
    // print(head);
    
    //(done)HW->5 ways to remove a loop
    // -> floyd + count
    // -> floyd advance version
    // -> using hashmap or hashing
    // -> using flagging
    // -> using brentz algorithm
    // 3 ways to detect loop:
    // -> flyod algo
    // -> Map of hashedset to store either visited or not
    // -> adding "bool visited" attribute in the class

    //BY brentz alogo removing the loop
    // brentDetectandremove(head);
    // print(head);

    return 0;
}