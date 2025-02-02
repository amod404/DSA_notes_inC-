//here we do oflline processsing of the query

// time complexity O(q*root(n))

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;
typedef struct{
    int l;
    int r;
    int idx;
}Q;

const int N = 1e5+2, MOD = 1e9+7;
int rootN;
Q q[N];


bool cmp(Q&q1,Q&q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r>q2.r;
    }
    return q1.l<q2.l;
}

int main()
{	
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    rootN = sqrtl(n)+1;
    int queries;
    cin>>queries;
    for(int i=0; i<queries; i++){
        cin>>q[i].l>>q[i].r;
        q[i].idx = i;
    } 

    sort(q,q+queries,cmp);
    vector<int>ans(queries);
    int curr_l = 0;
    int curr_r = -1;
    int curr_ans = 0;
    
    for(int i=0; i<queries; i++){
        int l = q[i].l;
        int r = q[i].r;
        l--;r--;

        while(curr_r<r){
            curr_r++;
            curr_ans +=a[curr_r];
        }

        while(curr_l > l){
            curr_l--;
            curr_ans += a[curr_l];
        }
        
        while(curr_l < l){
            curr_ans -= a[curr_l];
            curr_l++;
        }

        while(curr_r > r){
            curr_ans -= a[curr_r];
            curr_r--;
        }
        ans[q[i].idx] = curr_ans;
    }
    for(int i=0; i<queries; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

