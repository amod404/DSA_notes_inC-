//QUEUE - introduction(fist in first out)

#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<deque> //doubly ended queue
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size=1000001;

    public:

    Queue(){
        arr=new int[size];
        front=0;
        rear=0;
    }

    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is Full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue(){
        if(front==rear){
            return -1;
        }
        else{
            int ans= arr[front];
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
            return ans;
        }
    }

    bool isEmpty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }

    int qsize(){
        return front-rear;
    }

};

class Cqueue{
    int front;
    int rear;
    int* arr;
    int size;

    public:

    Cqueue(int s){
        size=s;
        rear=-1;
        front=-1;
        arr=new int[size];
    }

    void Cpush(int data){
        if(rear=-1){
            rear=0;
            front=0;
            arr[rear]=data;
            rear++;
        }
        else if(rear==front || size==1){
            cout<<"~QUEUE OVERFLOW~"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
            if(rear==size){
                rear=0;
            }
        }
    }

    int Cpop(){
        if(rear==-1){
            cout<<"~EMPTY QUEUE~"<<endl;
            return -1;
        }
        //deleting data
        int ans = arr[front];
        arr[front]=-1;
        front++;
        //right most reach case
        if(front==size){
            front=0;
        }
        //empty after pop case
        if(rear==front){
            rear=-1;
            front=-1;
        }
        return ans;
    }

    bool isCempty(){
        if(rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int Csize(){
        if(rear==-1){
            return 0;
        }

        if(rear>front){
            return rear-front;
        }
        
        if(rear<front){
            return size-(front-rear);
        }
    }

};

class linked_queue{
    int data;
    linked_queue* prev;
    static linked_queue* front;
    static linked_queue* back;

    public:
        linked_queue(){}
        linked_queue(int element){
            data = element;
            prev=NULL;
        }

        void push(int value){
            linked_queue* temp = new linked_queue(value);
            if(front==NULL){
                front=temp;
                back=temp;
            }

            back->prev = temp;
            back=temp;
        }

        void pop(){
            if(front==NULL){
                cout<<"~QUEUE IS EMPTY~"<<endl;
                return;
            }
            if(front==back){
                front=NULL;
                back=NULL;
            }
            
            linked_queue* waste=front;
            front= front->prev;
            waste->prev=NULL;

            cout<<"Memory is removed at position : "<< waste->data<<endl;



        }

        int Front(){
            if(front==NULL){
                return -404;
            }
            return front->data;
        }

        int Back(){
            if(back==NULL){
                return -404;
            }
            return back->data;
        }

        bool isEmpty(){
            if(front == NULL){
                return true;
            }
            return false;
        }

        int length(){
            int count =1;
            linked_queue* temp=front;
            while(temp!=back){
                count++;
                temp=temp->prev;
            }
            return count;
        }

        void print(){
            linked_queue* temp = front;

            while(temp!= NULL){
                cout<<temp->data<<" ";
                temp=temp->prev;
            }
            cout<<endl;
        }
};
linked_queue* linked_queue :: front;
linked_queue* linked_queue :: back;

class Dqueue{
    int size;
    int* arr;
    int front;
    int back;

    public:
        Dqueue(int s){
            size = s;
            arr = new int[size];
            front = -1;
            back =-1;
        }

        int Front(){
            if(front == -1){
                return -404;
            }
            return arr[front];
        }

        int Back(){
            if(front == -1){
                return -404;
            }
            return arr[back];
        }

        void push_front(int data){
            if(front == -1){
                back = 0;
                front = 0;
                arr[0] = data;
            }
            else if(front == back-1){
                cout<<"~OVERFLOW~"<<endl;
            }
            else if(front = size-1){
                if(back == 0){
                    cout<<"~OVERFLOW~"<<endl;
                    return;
                }
                front =0;
                arr[front]=data;
            }
            else{
                front++;
                arr[front]=data;
            }
        }

        void push_back(int data){
            if(back == -1){
                back = 0;
                front = 0;
                arr[0] = data;
                return;
            }

            else if(back==front+1){
                cout<<"~OVERFLOW~"<<endl;
            }

            else if(back == 0){
                if(front == size-1){
                    cout<<"~OVERFLOW~"<<endl;
                    return;
                }
                back = size-1;
                arr[back]=data;
            }
            else{
                back--;
                arr[back = data];
            }
        }

        void pop_front(){
            if(front == -1 ){
                cout<<"~UNDERFLOW~"<<endl;
            }
            else if(front == back){
                cout<<"Clearing memory at : "<< arr[front]<<endl;
                front=-1;
                back=-1;
            }
            else if(front == 0){
                cout<<"Clearing memory at : "<< arr[front]<<endl;
                front = size-1;
            }
            else{
                cout<<"Clearing memory at : "<< arr[front]<<endl;
                front--;
            }
        }

        void pop_back(){
            if(back == -1 ){
                cout<<"~UNDERFLOW~"<<endl;
            }
            else if(front == back){
                cout<<"Clearing memory at : "<< arr[back]<<endl;
                front=-1;
                back=-1;
            }
            else if(back == size-1){
                cout<<"Clearing memory at : "<< arr[back]<<endl;
                back=0;
            }
            else{
                cout<<"Clearing memory at : "<< arr[front]<<endl;
                back++;
            }
        }

        bool isEmpty(){
            if(front == -1){
                return true;
            }
            else{
                return false;
            }
        }

        int length(){
            if(front>=back){
                return front - back +1;
            }
            else{
                return size - ( back - front ) + 1;
            }
        }
};

int main()
{
    // //create a queue
    // queue<int> q;
    // q.push(11);
    // cout<<"Front: "<<q.front()<<endl;
    // cout<<"Back: "<<q.back()<<endl;
    // q.push(12);
    // cout<<"Front: "<<q.front()<<endl;
    // cout<<"Back: "<<q.back()<<endl;
    // q.push(13);
    // cout<<"Front: "<<q.front()<<endl;
    // cout<<"Back: "<<q.back()<<endl;
    //
    // cout<<"SIZE: "<< q.size()<<endl;
    // q.pop();
    // cout<<"SIZE: "<< q.size()<<endl;
    //
    // if(q.empty()){
    //     cout<<"Empty"<<endl;
    // }
    // else{
    //     cout<<"Not Empty"<<endl;
    // }

    //(done)HW->implement using linked list
    //making our own queue using array
    //
    // linked_queue q1;
    // for(int i=0;i<10;i++){
    //     q1.push(i);
    // }
    // q1.print();
    //
    // for(int i=0;i<5;i++){
    //     q1.pop();
    // }
    //
    // cout<<"Is it empty? "<< q1.isEmpty()<<endl;
    // cout<<"What is its length? "<< q1.length()<<endl;
    // cout<<"front is : "<< q1.Front()<<endl;
    // cout<<"back is : "<< q1.Back()<<endl;
    // q1.print();
    
    //circular queue
    //DONE

    //input restricted queue----> pop both side, push only fron back
    //output restricted queue-----> push both side, pop only front
    //douly endy queue -----> both side pop and push
    //(pending)HW-->learn practical usage of queue

    // //(done)HW-->perforn STL for deque
    // deque<int> q;
    // q.push_front(11);
    // cout<<"Front: "<<q.front()<<endl;
    // q.push_back(12);
    // cout<<"Back: "<<q.back()<<endl;
    // cout<<"Front: "<<q.front()<<endl;
    // cout<<"Back: "<<q.back()<<endl;
    // q.push_front(13);
    // cout<<"Back: "<<q.back()<<endl;
    // cout<<"Front: "<<q.front()<<endl;
    //
    // cout<<"SIZE: "<< q.size()<<endl;
    // q.pop_back();
    // cout<<"SIZE: "<< q.size()<<endl;
    //
    // if(q.empty()){
    //     cout<<"Empty"<<endl;
    // }
    // else{
    //     cout<<"Not Empty"<<endl;
    // }

    //(done)HW-->try to implement deque



    return 0;
}