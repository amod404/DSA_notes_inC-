// recursion-08 (phone keypad problem)
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//solved myself and 100% correct..^^

void solve(string digit,string output,int index,vector<string> &ans,vector<string> &phone){
    //base case when whole "digit" is iterated
    if(index==digit.size()){
        ans.push_back(output);//saving all the answers in our vector
        return;
    }
    int k=digit[index]-'0';   //converting string to integer
    for(int i=0;i<phone[k].size();i++){   //iterating for all alphabets for that number present in "phone"
        output.push_back(phone[k][i]);   //giving one alpabet
        solve(digit,output,index+1,ans,phone);  //calling recursion for that output
        if(i<phone[k].size()-1){                //deleting that alphabet to add another
            output.pop_back();
            //this is called backtracking ~.~
        }
    }  
}

vector<string> keypad(string digit){
    if(digit.size()==0){
        vector<string> ans2;
        return ans2;
    }
    int index=0;
    string output;     
    vector<string> phone={"xxx","xxx","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    solve(digit,output,index,ans,phone);
    return ans;
}

int main()
{   
    //have to print all possible permutation of a key pressed
    //example-->23 will print ad,ae,af,bd,be,bf,cd,ce,cf   (check keypad)
    string digit="789";
    vector<string> ans;
    ans=keypad(digit);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}