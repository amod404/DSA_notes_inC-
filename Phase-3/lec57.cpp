// stack (hard) questions

#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include"lec56.cpp"
using namespace std;

bool knows(int a, int b, vector<vector<int>> & M){
    if(M[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}

int celebrity(vector<vector<int>> & M){
    int n = M[0].size();
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }

    while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(knows(a,b,M)){
            s.push(b);
        }
        else if(knows(b,a,M)){
            s.push(a);
        }

    }
    
    int candidate;
    if(s.empty()){
        return -1;
    }
    else{
        candidate=s.top();
    }
    //single element has to verify
    bool rowCheck=false;

    for(int i=0;i<n;i++){
        if(M[candidate][i]==1){
            return -1;
        }
    }

    for(int i=0;i<n;i++){
        if(M[i][candidate]==0 && i!=candidate){
            return -1;
        }
    }

    return candidate+1;
}

int Celebrity(vector<vector<int>> & M){
    int n = M[0].size();
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }

    while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        // agar a b ko janta hai to a ko nhi krna push
        if(knows(a,b,M)){
            // agar b a ko janta hai to b ko bhi nhi krna push
            if(!knows(b,a,M)){
                s.push(b);
            }
        }
        //agar a b ko nhi janta
        else if(knows(b,a,M)){
            //agar b bhi a kon nhi janta to koi push ni hoga
            if(knows(b,a,M)){
                s.push(a);
            }
        }

    }
    
    int candidate;
    if(s.empty()){
        return -1;
    }
    else{
        candidate=s.top();
    }
    //single element has to verify
    bool rowCheck=false;

    for(int i=0;i<n;i++){
        if(M[candidate][i]==1){
            return -1;
        }
    }

    for(int i=0;i<n;i++){
        if(M[i][candidate]==0 && i!=candidate){
            return -1;
        }
    }

    return candidate+1;
}

//independent hard wuestion hai, lekin inke ander ke sub questions kr rakhe hai na isliye aasan lg rhe *+*
int largestArea(vector<vector<int>>&R){
    int r=R.size();
    int c=R[0].size();
    int ans=-1;
    vector<int> M(c,0);
    for(int i=0;i<r;i++){  // loop to run for all histogram
        //updating below the new histogram
        for(int j=0;j<c;j++){
            if(R[i][j]==1){
                M[j]++; //add
            }
            else{ //rectangle broke
                M[j]=0;
            }
        }
        //getting max
        ans=max(ans,largestRectangleArea(M));  //from histogram
    }
    return ans;
}

int main()
{
    // //celebrity problem
    // vector<vector<int>> M={ {0,0,0,1,0},
    //                         {1,0,1,1,1},
    //                         {1,0,0,1,1},
    //                         {0,0,0,0,0},
    //                         {1,1,0,1,0} };
    // cout<<"Our celebrity is -> "<<celebrity(M)<<endl;
    // cout<<"Our celebrity is -> "<<Celebrity(M)<<endl;
    
    //largest area of a binary matrix.....using histogram approah and smallest nearest
    // vector<vector<int>> R={ {0,1,1,1,1},
    //                         {1,1,0,1,1},
    //                         {1,1,0,1,1},
    //                         {1,0,0,0,1},
    //                         {1,1,1,1,1} };
    //
    // cout<<"The largest area is -> "<< largestArea(R)<<endl;
    
    return 0;
}
