// stack....(hard)  question

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class stack{
    int *arr;
    int *top;
    int *next;
    int n,s;
    int freespot;

    public: 
    //initialize your data structure
    stack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        next = new int[s];
        top = new int[n];

        fill(top,top+n,-1);

        int i;
        for(i=0; i<s-1; i++){
            next[i]=i+1;
        }
        next[i]=-1;
        freespot=0;
    }

    bool push(int x, int m){
        if(freespot == -1){
            return false;
        }
        
        //step1-> Find index where element has to entered
        int index = freespot;

        //step2-> update freespot by using next array
        freespot = next[index]; // can use next[freespot]

        //step3-> enter the value of data in index
        arr[index]=x;

        //step4-> link next of array from previous top 
        next[index]=top[m-1];

        //step5-> update top 
        top[m-1]=index;
        
        return true;
    }

    bool pop(int m){
        if(top[m-1]==-1){
            return false;
        }
        //reverse the step of push

        //find the index from where element has to be pop
        int index = top[m-1];

        //update top by backtracking frm next
        top[m-1]=next[index];

        //fill some garbage value, not mandatory
        arr[index]=0;

        //link that next[index] with current freespot
        next[index]=freespot;

        //also update freespot 
        freespot = index; 
    }

    //NOTE:- the next array is having two uses, to store and link the remaining freespots
    //       and also storing the prvious indexes of top.

    bool isEmpty(int m){
        if(top[m-1]==-1){
            return true;
        }
        else{
            false;
        }
    }

    int spaceleft(){
        int count =0;
        int temp =freespot;
        while(next[temp]!=-1){
            count++;
            temp=next[temp];
        }
        return count;
    }
    
};

int main()
{
    //N stacks in a array
    //TC...O(1)
    //SC...O(1)

    return 0;
}