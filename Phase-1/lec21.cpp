#include<iostream>
#include<vector>
using namespace std;

void scan_v(vector<int> &v){
    int total=0;
    cout<<"Enter the number of values: ";
    cin>>total;
    int m=0; 
    while(m<total){
        int n;
        cin>>n;
        v.push_back(n);
        m++;
    }
}
//will rotate the next sub vector by shifting by 1
void Rotate(vector<int> &v, int key){
    
    int temp=v[key+1]; 
    for(int i=key+1;i<v.size();i++){
        v[i]=v[i+1];
    }
    v[v.size()-1]=temp;
}

//shift and rotate the whole subvector
void rotate(vector <int> &v, int key){
    for(int i=0;i<=key;i++){
        v.push_back(v[0]);
        v.erase(v.begin());
    }
    
}

void mod(vector<int> &v){

    for(int i=0;i<v.size();i++){
        if(v[i]<0){
            v[i]=-v[i];
        }
    }
}

void print(vector<int> v){
    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
}

//to check if rotated and sorted
bool if_(vector<int> v){
    int count=0;
    int n=v.size();
    for(int i=0;i<n-1;i++){
        if(v[i+1]<v[i]){
            count++;
        }
    }
    if(v[n-1]>v[0]) count++;

    return count<=1;
}

vector<int> reverse(vector<int> &v){

    int s=0;
    int m= v.size()-1;

    while(s<=m/2){
        swap(v[s], v[m-s]);
        s++;
    }
    return v;
} 

vector<int> sum(vector<int>v,vector<int>u){
    vector<int> ans;
    int i=v.size()-1;
    int j=u.size()-1;
    int carry=0;

    while(i>=0 && j>=0){
        int sum=v[i]+u[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while(i>=0){
        int sum=v[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }

    while(j>=0){
        int sum=u[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;
    }

    while(carry){
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    reverse(ans);
    return ans;
}    

int main()
{
    //HW...find time complexity of each of the question done is last 2-3 videos

    // vector<int> v,u;
    // v.push_back(9);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    // v.push_back(8);
    // v.push_back(9);
    // v.push_back(3);
    // u.push_back(9);
    // u.push_back(0);
    // u.push_back(1);
    // u.push_back(2);
    // u.push_back(2);
    // u.push_back(1);
    // u.push_back(2);


    //mod and rotate
    // print(v);
    // mod(v);
    // print(v);
    // Rotate(v,2);
    // print(v);
    // vector <int> v={0,1,2,3,4,5,6,7,8,9};
    // print(v);
    // rotate(v,2);
    // print(v);

    //if rotated an sorted for an sorted array
    // cout<<"If sorted and rotated-->"<<if_(v)<<endl;
    

    //taking input
    // vector<int> v,u;
    // scan_v(v);
    // scan_v(u);
    // print(v);
    // print(u);

    //sum
    // vector<int>z;
    // z=sum(v,u);
    // print(v);
    // print(u);
    // cout<<"Your sum is: \n";
    // print(z);
    
    return 0;
}