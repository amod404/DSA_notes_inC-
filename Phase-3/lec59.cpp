// stack  hard hard  question

#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class SpecialStack{
    stack<int>s;
    int mini=INT8_MAX;

    public:

    void push(int data){
        if(s.empty()){
            s.push(data);
            mini=data;
        }
        else{
            if(data<mini){
                s.push(2*data-mini);
                mini=data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop(){
        if(s.empty()){
            return -1;
        }

        int curr=s.top();
        s.top();
        if(curr>mini){
            return curr;
        }
        else{
            int prevmini=mini;
            mini=2*mini-curr; //its like past mini will be given by current mini*2 - top element  2x-(2x-mini)
            return prevmini;
        }
    }

    int top(){
        if(s.empty()){
            return -1;
        }

        int curr = s.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }

    }

    bool isEmpty(){
        return s.empty();
    }

    int getMin(){
        if(s.empty()){
            return -1;
        }
        else{
            return mini;
        }
    }

};

int main()
{
    //get min of a all stack o(1) and O(1) TC and SC *O*
    //see video,,,do dry run,,,its a good structure


    //during pop...return the value
    //can use getmin()...so for all possible stack get mini should take O(1) space...to do so use to store that mini value in given stack only.....
    //during push we are doing the manipulation 
    
    //(pending)HW->write the comments on the functions above

    SpecialStack s1;
    s1.push(5);
    s1.push(3);
    s1.push(8);
    s1.push(1);
    // s1.push(2);

    cout<<"top is -> "<< s1.top()<<endl;
   
    return 0;
}