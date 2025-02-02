// stack - intro and self implimenatation
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

//read classes (imp)

class Stack{
    private:
        int *arr;
        int size;
        int top;

    public:
    //constructor
    Stack(){
        top=-1;
        size=5;
        arr=new int[size];
    }
    Stack(int s){
        size=s;
        top=-1;
        arr=new int[size];
    }

    //functions
    void push(int element){
        if(top==size-1){
            cout<<"~STACK OVERFLOW~"<<endl;
        }
        else{
            top++;
            arr[top]=element;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"~STACK UNDERFLOW~"<<endl;
        }
        else{
            top--;
        }
    }

    int peak(){
        if(top==-1){
            cout<<"~STACK IS EMPTY~"<<endl;
            return -404;
        }
        else{
            return arr[top];
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }


};

class TwoStack{
    private:
        int size;
        int top1;
        int top2;
        int *arr;
    public:
        //constructor
        TwoStack(int s){
            size=s;
            arr= new int[size];
            top1=-1;
            top2=size;
        }
        void push1(int element){
            if(top1==top2-1){  //top1==size-1 || (automatically handled)
                cout<<"~STACK OVERFLOW~"<<endl;
            }
            else{
                top1++;
                arr[top1]=element;
            }
        }

        void push2(int element){
            if(top2==top1+1){  //top2==0 ||(handled) 
                cout<<"~STACK OVERFLOW~"<<endl;
            }
            else{
                top2--;
                arr[top2]=element;
            }
        }

        void pop1(){
            if(top1==-1){
                cout<<"~STACK UNDERFLOW~"<<endl;
            }
            else{
                top1--;
            }
        }

        void pop2(){
            if(top2==size){
                cout<<"~STACK UNDERFLOW~"<<endl;
            }
            else{
                top2++;
            }
        }

        int peak1(){
            if(top1==-1){
                return -404;
            }
            else{
                return arr[top1];
            }
        }

        int peak2(){
            if(top2==size){
                return -404;
            }
            else{
                return arr[top2];
            }
        }

        bool is_empty(){
            if(top1==-1 && top2==size){
                return true;
            }
            else{
                return false;
            }
        }

        int space_left(){
            return top2-top1-1;
        }
};

class linked_Stack{
    private:
        linked_Stack* next;
        linked_Stack* prev;
        int data;
    public:
        //Constructor

        linked_Stack(int element){
            prev=NULL;
            next=NULL;
            data=element;
        }

        friend void push(linked_Stack* &,int);
        friend void print(linked_Stack*);
        friend void pop(linked_Stack*&);
        friend int peak(linked_Stack*);

        ~linked_Stack(){
            prev=NULL;
            next=NULL;
            delete next;
        }
};

void push(linked_Stack* &top,int element){
    linked_Stack* temp=new linked_Stack(element);
    if(top==NULL){
        top=temp;
        return;
    }
    temp->prev=top;
    top->next=temp;
    top=temp;
}

void print(linked_Stack* top){
    while(top!=NULL){
        cout<< top->data<< " ";
        top=top->prev;
    }cout<<endl;
}

void pop(linked_Stack* &top){
    if(top==NULL){
        cout<<"~STACK UNDERFLOW~"<<endl;
        return;
    }
    linked_Stack* waste = top;
    top=top->prev;
    if(top!=NULL){
        top->next=NULL;
    }
    delete waste;
}

int peak(linked_Stack* top){
    if(top==NULL){
        return -404;
    }
    return top->data;
}

bool empty(linked_Stack*top){
    if(top==NULL){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    // //using stl
    // //creation of stack
    // stack<int> s;
    //
    // //push the elements
    // for(int i=0;i<10;i++){
    //     s.push(i);
    // }
    // //pop the elements
    // s.pop();
    // s.pop();  // 9 and 8 will pop
    //
    // //peak the element
    // cout<<"printing top element : "<< s.top() <<endl;
    //
    // //checking if empty
    // cout<<"is it empty? -> "<< s.empty() << endl;
    //
    // //finfing size
    // cout<<"size of stack is : "<<s.size()<<endl;

    // // using self made class....(array implementation)
    // // default size is 5.....O(1),o(n)...time and space complexity
    // Stack st(5);
    // st.push(5);
    // st.push(4);
    // st.push(3);
    // st.push(2);
    // cout<< st.peak() <<endl;
    // st.pop();
    // cout<< st.peak() <<endl;
    // //
    // // st.pop();
    // // st.pop();
    // // st.pop();
    // // st.pop();  // stack underflow
    // // 
    // st.push(2);
    // st.push(1);
    // st.push(0);  //stack overflow
    
    // // (done)HW...implement by linked list
    // linked_Stack* top=NULL;
    // for(int i=0;i<10;i++){
    //     push(top,i);
    // }
    // print(top);
    // cout<<"the top data is -> "<< peak(top)<<endl;
    // //
    // for(int i=0;i<5;i++){
    //     pop(top);
    // }
    // print(top);
    // cout<<"the top data is -> "<< peak(top)<<endl;
    // cout<<"is it empty? -> "<<empty(top)<<endl;
    
    // question....two stack in an array
    TwoStack s2(10);
    //
    for(int i=0;i<5;i++){
        s2.push1(i);
    }
    for(int i=0;i<5;i++){
        s2.push2(2*i);
    }
    //
    cout<<s2.peak1()<<endl;
    cout<<s2.peak2()<<endl;
    
    s2.push1(1); //overflow

    return 0;
}
