/// here we are doing Mo's algorithm with sqrt decomposition

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

const int N = 1e5+2, MOD = 1e9+7;

typedef struct{
    int l;
    int r;
    int idx;
}Q;

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

    rootN = sqrt(n);

    int queries;
    cin>>queries;

    for(int i=0; i<queries; i++){
        cin>>q[i].l>>q[i].r;
        q[i].idx = i;
    }

    sort(q, q+queries, cmp);

    vector<int>ans(queries);
    vector<int>freq(10*N, 0);

    int curr_l = 0;
    int curr_r = -1;
    int l,r;
    int curr_ans = 0;

    for(int i=0; i<queries; i++){
        l = q[i].l;
        r = q[i].r;
        l--;r--;

        while(curr_r<r){
            curr_r++;
            freq[a[curr_r]]++;
            if(freq[a[curr_r]] == 1){
                curr_ans++;
            }
        }
        while(curr_l>l){
            curr_l--;
            freq[a[curr_l]]++;
            if(freq[a[curr_l]] == 1){
                curr_ans++;
            }
        }
        while(curr_l<l){
            freq[a[curr_l]]--;
            if(freq[a[curr_l]] == 1){
                curr_ans++;
            }
            curr_l++;
        }
        while(curr_r<r){
            freq[a[curr_r]]--;
            if(freq[a[curr_r]] == 1){
                curr_ans++;
            }
            curr_r--;
        }

        ans[q[i].idx] = curr_ans;
    }

    for(int i=0; i<queries;i++){
        cout<<ans[i]<<endl;
    }


    


    return 0;
}