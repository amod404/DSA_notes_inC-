// heap->question

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int getKthLargest_1(vector<int> & arr, int k){
    vector<int> sumStore;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for( int j=i;j<n;j++){
            sum+=arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(),sumStore.end());
    return sumStore[sumStore.size()-k];
}

int getKthLargest_2(vector<int> & arr, int k){
    priority_queue<int,vector<int>,greater<int>> mini;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for( int j=i;j<n;j++){
            sum+=arr[j];

            if(mini.size() <= k){
                mini.push(sum);
            }
            else{
                if(mini.top()<sum){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }

    return mini.top();
}

class node{
    public :
    int data;
    int i,j;

    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeSortedArrays(vector<vector<int>> & kArrays , int k){
    //min heap
    priority_queue<node*,vector<node*>,compare>minHeap;
    //step 1. sare elements store krva lo
    for(int i=0;i<k;i++){
        node* tmp = new node(kArrays[i][0],i,0);
        minHeap.push(tmp);
    }
    vector<int>ans;
    //step 2. 
    while(!minHeap.empty()){
        node* tmp = minHeap.top();
        minHeap.pop();
        ans.push_back(tmp->data);

        int i= tmp->i;
        int j= tmp->j;

        if(j+1 < kArrays[i].size()){
            //means next data is present
            node* next = new node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
}

class Node
{

public:
    // creating our node
    int data;   // stores data of urrent object
    Node *next; // store address of next obj

    // construcutor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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
void insertAtTail(Node *&tail, int d)
{

    Node *temp = new Node(d); // new node to be inserted
    tail->next = temp;        // point the next of tail to new mode
    tail = temp;              // now tail will go to that new node
}
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    Node *to_insert = new Node(d);

    // starting case
    if (position == 1)
    {
        to_insert->next = head;
        head = to_insert;
        // can use insertAthead(head,d);
        return;
    }

    // in between case
    Node *temp = head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
        // ending case
    }
    if (temp == tail)
    {
        tail = to_insert;
        // can use insertAttail(tail,d);
    }
    to_insert->next = temp->next;
    temp->next = to_insert;
}
void deletePosition(Node *&head, Node *&tail, int position)
{
    // starting case
    if (position == 1)
    {
        Node *waste = head;
        head = head->next;
        // memory free
        delete waste;
    }
    // other case
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
            if (curr == tail)
            {
                tail = prev;
            }
        }

        prev->next = curr->next;
        delete curr;
    }

    // // in between case
    // Node* temp= head;
    // int i=2;
    // while(i<position){
    //     temp=temp->next;
    //     i++;
    //     //ending case
    //     if(temp->next==tail){
    //         tail=temp;
    //     }
    // }
    // Node* waste=temp->next;
    // temp->next = temp->next->next;
    // delete waste;
}
void deleteValue(Node *&head, Node *&tail, int d)
{
    // starting case
    if (head->data == d)
    {
        Node *waste = head;
        head = head->next;
        // memory free
        delete waste;
    }
    // other case
    else
    {
        Node *curr = head;
        Node *prev = head;
        while (curr->data != d && prev->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev->next == NULL)
        {
            cout << "Data not found" << endl;
            return;
        }
        if (curr == tail)
        {
            tail = prev;
        }
        prev->next = curr->next;
        delete curr;
    }
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

struct Compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};
Node* mergeSortedLL(vector<Node*> kLL){
    //min heap
    priority_queue<Node*,vector<Node*>,Compare> minHeap;
    int k=kLL.size();
    //step 1. put the first k elements in the list
    for(int i=0;i<k;i++){
        if(kLL[i]) minHeap.push(kLL[i]);
    }
    Node* head=minHeap.top();
    minHeap.pop();
    minHeap.push(head->next);
    Node* curr=head;
    //step 2. 
    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        minHeap.pop();
        curr->next = temp;
        curr=curr->next;
        if(temp->next){
            minHeap.push(temp->next);
        }
    }
    return head;
    //code is corrrect but comparator is not working :(
}

int main()
{	CLEAR;

    // Kth largest sum of subarray
    // vector<int> arr ={ 2,3,6,7,8,1,2,3,4,5,7 };
    // int k;
    // cout<<"Enter the value of K: ";
    // cin>>k;
    // //approach 1-> TC...O(n^2 logn) and SC...O(n^2)
    // cout<< k <<"th largest sum is : "<< getKthLargest_1(arr,k)<<endl;
    // //approach 2 -> TC...(HW) and SC...O(k)
    // cout<< k <<"th largest sum is : "<< getKthLargest_2(arr,k)<<endl;
    
    //merge K sorted array

    //merge k sorted linked list(without extra space)
    // Node* head1 = new Node(15);
    // insertAtHead(head1,7);
    // insertAtHead(head1,6);
    // insertAtHead(head1,5);
    // //
    // Node* head2 = new Node(14);
    // insertAtHead(head2,11);
    // insertAtHead(head2,2);
    // insertAtHead(head2,1);
    // //
    // Node* head3 = new Node(20);
    // insertAtHead(head3,13);
    // insertAtHead(head1,9);
    // insertAtHead(head3,8);
    // //
    // vector<Node*> kLL={head1,head2,head3};
    // Node* ans=mergeSortedLL(kLL);
    // print(ans);

    return 0;
}