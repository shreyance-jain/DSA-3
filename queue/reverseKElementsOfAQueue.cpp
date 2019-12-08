/* 
Reverse First K elements of Queue
Difficulty: Easy

Problem Statement

Given an integer K and a queue of integers, we need to reverse the order of the first K
elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

    enqueue(x) : Add an item x to rear of queue
    dequeue() : Remove an item from front of queue
    size() : Returns number of elements in queue.
    front() : Finds front item.

Input Format:
First line consists of T test cases. First line of every test case consists of 2 integers,
N and K, denoting number of elements and number of elements to be reversed respectively.
Second line of every test case consists of elements of array.

Output Format:
For each testcase, in a new line, print the modified queue.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= K <= N

Example:
Input:
2
5 3
1 2 3 4 5
4 4
4 3 2 1
Output:
3 2 1 4 5
1 2 3 4
 */


#include<bits/stdc++.h>
using namespace std;
#define ll long long

queue<ll> modifyQueue(queue<ll> q, int k);

int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}


queue<ll> modifyQueue(queue<ll> q, int k)
{
    // reverse the queue
    // 1 2 3 4 5
    stack<ll> st;
    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    // queue is reversed
    // 5 4 3 2 1
    // pop the first size-k items and push to stack
    // push to queue
    int z = q.size() - k;
    while(z--) {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    return q;
}

/* There are many more possible methods
One method can be to push k elements to stack
then push them to queue
then, n-k elements from front of queue to back of queue 
Implementation:*/
queue<ll> modifyQueue2(queue<ll> q, int k)
{
    // reverse the queue
    // 1 2 3 4 5
    int m = k;
    if (k > q.size() || k <= 0 || q.empty()) return q;

    stack<ll> st;
    
    while(k--) {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    
    // 4 5 3 2 1
    // pop the first size-k items and push to stack
    // push to queue
    int z = q.size() - m;
    while(z--) {
        q.push(q.front());
        q.pop();
    }
    return q;
}

// Time Complexity: O(n)
// Aux Space: O(n)