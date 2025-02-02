//question on stacks
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
void print(stack<int> s){
    while(!s.empty()){
        cout<< s.top() <<" ";
        s.pop();
    }
    cout<<endl;

    // for(;!s.empty();s.pop()){
    //     cout<< s.top()<<" ";
    // }cout<<endl;

}

void print(stack<char> s){
    while(!s.empty()){
        cout<< s.top() <<" ";
        s.pop();
    }
    cout<<endl;
}

void reverse(string &str){
    stack<char> s;
    int m=str.length();
    for(int i=0;i<m;i++){
        s.push(str[i]);
    }
    
    for(int i=0;i<m;i++){
        str[i]=s.top();
        s.pop();
    }
}

void del_mid(stack<int> & s){
    int m=s.size()/2;
    stack<int> temp;
    for(int i=0;i<m;i++){
        temp.push(s.top());
        s.pop();
    }
    s.pop();
    for(int i=0;i<m;i++){
        s.push(temp.top());
        temp.pop();
    }
    cout<<"~Removed the middle~"<<endl;
}

void del_helper(stack<int>&s,int m){
    if(m<=0){
    cout<<"HI"<<endl;
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    m--;
    del_helper(s,m);
    s.push(temp);
}

void Del_mid(stack<int> &s){
    int m = s.size()/2;
    del_helper(s,m);
}

void if_balanced(string& s){
    int m=s.length();
    int i=0;
    stack<char> box;
    box.push('a');


    for(int i=0;i<m;i++){
        switch(s[i]){
            case '}':
                if(box.top()=='{'){
                    box.pop();
                }
                else{
                    box.push(s[i]);
                }
                break;
            
            case ']':
                if(box.top()=='['){
                    box.pop();
                }
                else{
                    box.push(s[i]);
                }
                break;
            
            case ')':
                if(box.top()=='('){
                    box.pop();
                }
                else{
                    box.push(s[i]);
                }
                break;
            default :
                box.push(s[i]);
        }
    }
    box.pop();
    if(box.empty()){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
}

void If_balanced(string& s){
    int m=s.length();
    int i=0;
    stack<char> box;
    box.push('a');

    for(int i=0;i<m;i++){
        switch(s[i]){
            case '}':
                if(box.top()=='{'){
                    box.pop();
                }
                else{
                    cout<<"Unbalanced"<<endl;
                    return;
                }
                break;
            
            case ']':
                if(box.top()=='['){
                    box.pop();
                }
                else{
                    cout<<"Unbalanced"<<endl;
                    return;
                }
                break;
            
            case ')':
                if(box.top()=='('){
                    box.pop();
                }
                else{
                    cout<<"Unbalanced"<<endl;
                    return;
                }
                break;
            default :
                box.push(s[i]);
        }
    }
    
    cout<<"Balanced"<<endl;
}

void putAtBottom(stack<int> &s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }

    int temp=s.top();
    s.pop();
    putAtBottom(s,element);
    s.push(temp);

}

void reverse(stack<int>&s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverse(s);
    putAtBottom(s,temp);
}

void Reverse(stack<int> &s){
    queue<int> temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty()){
        s.push(temp.front());
        temp.pop();
    }
}

void sortedInsert(stack<int>&s,int x){
    //base case
    if(s.empty() || s.top()<=x){
        s.push(x);
        return;
    }
    int temp=s.top();
    s.pop();
    sortedInsert(s,x);
    s.push(temp);
}

void sortStack(stack<int>&s){
    //base case
    if(s.empty()){
        return;
    }
    //process
    int num=s.top();
    s.pop();
    //recusrsive call
    sortStack(s);
    //sorted insert while returning
    sortedInsert(s,num);
}

bool R_bracket(string& s){
    int m=s.length();
    stack<char>box;
    
    for(int i=0;i<m;i++){
        
        if(s[i]==')'){   //now check if redundant
            if(box.top()=='('){ //means redundant 
                return true;
            }
            else{
                while(box.top()!='('){  //have to remove the whole bracket associated 
                    box.pop();
                }box.pop();
            }
        }
        //insert operator and open bracket
        else if(s[i]=='+' ||s[i]=='/' ||s[i]=='*' ||s[i]=='-' || s[i]=='('){
            box.push(s[i]);
        }

    }
    //if loop ended, means no redundant pair
    return false;
}

int min_rotate(string& s){
    int m=s.length();
    if(m%2==1){  //removing odd case
        return -1;
    }

    stack<char> box;
    for(int i=0;i<m;i++){
        if(s[i]==')'){
            if(box.empty()){
                box.push(s[i]);
            }
            else if(box.top()==')'){
                box.push(s[i]);

            }
            else{
                box.pop(); //means top if '('
            }
        }
        else{  //means s[i]=='('
            box.push(s[i]);
        }
    }

    int a=0,b=0;
    while(!box.empty()){
        if(box.top()=='('){
            a++;
        }
        else{
            b++;
        }
        box.pop();
    }

    return (a+1)/2 + (b+1)/2;
}

int main()
{
    // //reverse a string using stack
    // string str="AMOD";
    // cout<<str<<endl;
    // reverse(str);
    // cout<<str<<endl;

    // // delete middle element of a stack
    // stack<int> s;
    // for(int i=0;i<6;i++){
    //     s.push(i+1);
    // }
    // print(s);
    // // del_mid(s);  //3 will be gone
    // // print(s);
    // Del_mid(s);  //3 will be gone
    // print(s);

    //valid paranthesis
    // string s="{{}}{[()]{}[][]}(({[]{}})())(())";
    // if_balanced(s);
    // If_balanced(s);
    
    //insert at bottom (using recursion)...O(n)
    // stack<int> s;
    // for(int i=0;i<5;i++){
    //     s.push(i+1);
    // }
    // print(s);
    // putAtBottom(s,0);
    // print(s);

    // //reverse stack using recursion  O(n^2)
    // stack<int> s;
    // for(int i=0;i<10;i++){
    //     s.push(i+1);
    // }
    // print(s);
    // reverse(s);
    // print(s);
    // Reverse(s);
    // print(s);

    //sorting stack by recursion....O(n^2)
    // stack<int> s;
    // for(int i=10;i>0;i--){
    //     s.push(i);
    // }
    // print(s);
    // sortStack(s);
    // print(s);
    
    //redundant brackets...O(n)
    // string s="(a+(a+(a+(a+a+(a+a))))";
    // cout<<"is redundant brackets present? -> "<<R_bracket(s)<<endl;

    //minimum changes to get valid bracket string
    // string s=")()(())(()))(()())))()((((((()))))((";
    // cout<<"Minimum flips required -> "<<min_rotate(s)<<endl;
    
    return 0;
}
