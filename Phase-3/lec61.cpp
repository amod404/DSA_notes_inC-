// a lot of lot of questions on queue *O*

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void queue_reverse1(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    // tC--> O(n)....SC-->O(n)
}

void queue_reverse2(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int temp = q.front();
    q.pop();
    queue_reverse2(q);
    q.push(temp);

    // tC--> O(n)....SC-->O(n)
}

vector<int> First_negative(vector<int> &A, int K)
{
    //here K is window size
    int N = A.size();

    deque<int> dq;
    vector<int> ans;

    // storing the first window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // storing answer for first window
    if (dq.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(A[dq.front()]);
    }

    // process for remaining windows

    for (int i = K; i < N; i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }

        // addition
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        // ans store
        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(A[dq.front()]);
        }
    }
    return ans;
}

vector<int> first_negative(vector<int> arr, int k){
    int negative=0;;
    int count=0;
    int N = arr.size();
    vector<int> ans;
    for(int i=N-k;i<N;i++){
        if(arr[i]<0){
            negative = arr[i];
            break;
        }
        count++;
    }
    if(count==k){
        ans.push_back(0);
        count=0;
    }
    else{
        ans.push_back(negative);
        count++;
    }
    
    for(int i=N-k-1 ; i >= 0 ; i--){
        if(count==k){
            count=0;
            negative=0;
        }
        if(arr[i]<0){
            negative=arr[i];
            count=0;
        }
        ans.push_back(negative);
        count++;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void queue_reverse_k(queue<int> &q, int k)
{
    int t = q.size();
    stack<int> temp_s;
    // storing first k elements in stack
    for (int i = 0; i < k; i++)
    {
        temp_s.push(q.front());
        q.pop();
    }
    // entering those k elements in reverse order
    while (!temp_s.empty())
    {
        q.push(temp_s.top());
        temp_s.pop();
    }
    // moving those remaining elements at back
    for (int i = 0; i < t - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    int n = A.length();

    for (int i = 0; i < n; i++)
    {
        char ch = A[i];
        // increment
        count[ch]++;
        // push in queue
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }

    return ans;
}

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(vector<petrolPump> &p)
{
    int n = p.size();
    int balance = 0;
    int deficit = 0;
    int start = 0;
    int rear = 0;

    for (int i = 0; i < n; i++)
    {
        // checking balance
        balance = balance + p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            balance = 0;
            start = i + 1; // making start next to rear
        } //'i' is playing role of rear
    }

    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }

    // algo is easy to understand but hard to think
}

void interleave(queue<int> &q)
{
    int n = q.size();
    stack<int> s1;
    stack<int> s2;

    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            s1.push(q.front());
            q.pop();
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        for (int i = 0; i < n / 2; i++)
        {
            if (!s2.empty())
            {
                q.push(s2.top());
                s2.pop();
            }
            q.push(q.front());
            q.pop();
        }
        return;
    }

    for (int i = 0; i < (n + 1) / 2; i++)
    {
        s1.push(q.front());
        q.pop();
    }
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    for (int i = 0; i < (n + 1) / 2; i++)
    {
        if (!s2.empty())
        {
            q.push(s2.top());
            s2.pop();
        }
        if (!s2.empty())
        {
            q.push(q.front());
            q.pop();
        }
    }
}

class kQueue
{
public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;

public:
    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        // for (int i = 0; i < k; i++)
        // {
        //     front[i] = -1;
        //     rear[i] = -1;
        // }
        fill(front,front+k,-1);
        fill(rear,rear+k,-1);

        next = new int[n];
        for (int i = 0; i < n-1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        arr = new int[n];
        freeSpot = 0;
    }

    void enqueue(int data, int qn)
    {
        // overflow
        if (freeSpot == -1)
        {
            cout << "~OVERFLOW~" << endl;
            return;
        }

        // find first free index
        int index = freeSpot;

        // update freespot
        freeSpot = next[freeSpot];

        // check whether first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // link new element to the prev element
            next[rear[qn - 1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        // underflow
        if (front[qn - 1] == -1)
        {
            cout << "~UNDERFLOW~" << endl;
            return -404;
        }

        // find index to pop
        int index = front[qn - 1];

        // front ko aage badhao
        front[qn - 1] = next[index];

        // freeslots ko manage kro
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int solvesum(vector<int> &arr, int k)
{
    int n = arr.size();

    deque<int> maxi(k);
    deque<int> mini(k);

    // Addiction of first k size window

    for (int i = 0; i < k; i++)
    {

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    // first window ka answer
    ans += arr[maxi.front()] + arr[mini.front()];

    for (int i = k; i < n; i++)
    {

        // next window

        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

class q_stack{

    queue<int> q;
    public:

    void push(int data){
        q.push(data);
    }

    int top(){
        return q.back();
    }

    void pop(){
        int n=q.size()-1;
        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
};

class s_queue{
    
    stack<int> s;
    public:
    void push(int data){
        s.push(data);
    }
    int back(){
        return s.top();
    }
    int front(){
        if(s.size()==1){
            return s.top();
        }

        int temp = s.top();
        s.pop();
        int ans = front();
        s.push(temp);
        return ans;
    }

    void pop(){
        if(s.size()==1){
            s.pop();
            return;
        }

        int temp = s.top();
        s.pop();
        pop();
        s.push(temp);
    }



};

int main()
{
    // // queue reversal
    // // approach1->stack(LIFO)
    // // approach2->recursion
    // queue<int> q;
    // for (int i = 0; i < 10; i++)
    // {
    //     q.push(i + 1);
    // }
    // print(q);
    // queue_reverse1(q);
    // print(q);
    // queue_reverse2(q);
    // print(q);

    // first negative element in window of size k
    // approach->will use douby ended queue for window as adding and removing is easy
    //(can use variable to point)
    // vector<int> A = {1, -1, 3, 5, -5, 4, 6, 5, 5, 5, -1, -8, -7, 1};
    // vector<int> ans = First_negative(A, 2);
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // vector<int> ans1 = first_negative(A, 2);
    // for (auto i : ans1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    //(done)HW-->find optimal solution of above question

    // reverse first k element of queue
    // queue<int> q;
    // for (int i = 0; i < 10; i++)
    // {
    //     q.push(i + 1);
    // }
    // print(q);
    // queue_reverse_k(q, 4);
    // print(q);

    // first non repeating character in a stream
    // string s = "aabbbbcccddd";
    // cout << FirstNonRepeating(s) << endl;

    // circular tour..petrol and distance
    // approach 1--> brute force..O(n^2)
    // appraoch 2--> traverse by thre variables: balance, petrol and distance...and if start==rear u r done
    // approach 3--> save the negative balance in deficit and if deficit+balance at end is >=0 then u r done
    // vector<petrolPump> p = {{6, 5}, {7, 6}, {4, 7}, {10, 8}, {6, 6}, {5, 4}};
    // cout << " valid start from -> " << tour(p) << endl;


    // interleave the first half of the queue
    // approach 1 -->(best) use and second queue of length n/2
    // it is given to use stack only as an auxillary space
    // queue<int> q;
    // for (int i = 0; i < 7; i++)
    // {
    //     q.push(i + 1);
    // }
    // print(q);
    // interleave(q);
    // print(q);

    //(done) K queues in a single array
    ////plz dry run throwly

    // sum of minimum and maximum elements of all subarrays of size k
    //  aproach 1--> simplewindow iteration with time complexity O(n^2)(approx)
    //  approach 2-> use of deque
    //  vector<int> arr={2,5,-1,7,-3,-1,-2};
    //  cout<<"sum of sum of max and min in K windows is -> "<<solvesum(arr,4)<<endl;
    //  (done)HW--> what is space complexity  :   O(k) or O(2K+C)
    //  TC O(n)!

    //(done)HW--> implement stack using queue and implement queue using stack
    //
    // q_stack q;
    // for(int i=0;i<5;i++){
    //     q.push(i);
    // }
    // cout<<"Top is : "<< q.top()<<endl;
    // q.pop();
    // cout<<"Top is : "<< q.top()<<endl;
    // q.pop();
    // cout<<"Top is : "<< q.top()<<endl;
    // q.pop();
    // cout<<"Top is : "<< q.top()<<endl;
    // q_stack q;
    //
    // s_queue s;
    // for(int i=0;i<5;i++){
    //     s.push(i);
    // }
    // cout<<"front is "<<s.front()<<" and back is "<<s.back()<<endl;
    // s.pop();
    // cout<<"front is "<<s.front()<<" and back is "<<s.back()<<endl;
    // s.pop();
    // cout<<"front is "<<s.front()<<" and back is "<<s.back()<<endl;
    // s.pop();
    // cout<<"front is "<<s.front()<<" and back is "<<s.back()<<endl;

    
    return 0;
}
