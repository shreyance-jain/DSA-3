/* 
Queue Reversal

Difficulty: Basic
Problem Statement

Given a Queue Q containing N elements. The task is to reverse the Queue.
Your task is to complete the function rev(), that reverses the N elements of the queue.

Input Format: 
The first line of input contains an integer T denoting the Test cases.
Then T test cases follow. The first line contains N which is the number of elements which will be reversed.
Second line contains N space seperated elements.

Output Format:
For each testcase, in a new line, print the reversed queue.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ elements of Queue ≤ 105

Example:
Input : 
2
6
4 3 1 10 2 6
4
4 3 2 1 

Output : 
6 2 10 1 3 4
1 2 3 4
 */

#include <bits/stdc++.h>
using namespace std;

queue<long long int>rev(queue<long long int>);

int main() {
    int t;
    cin >> t;
    while(t--) {
        queue<long long int> q;
        long long int n, var;
        cin >> n;
        while(n--) {
            cin >> var;
            q.push(var);
        }
        queue<long long int> a = rev(q);
        while(!a.empty()) {
            cout << a.front() << " ";
            a.pop();
        }
    }
    cout << endl;
}

/* The idea is to use a stack to reverse the queue
If we use recursion then also it would internally use recursion call stack */
queue<long long int> rev(queue<long long int> q)
{
    stack<long long int> st;
    long long int x;
    // copy the items in a stack
    while(!q.empty()) {
        x = q.front();
        q.pop();
        st.push(x);
    }
    // pop the items from stack and push them in queue again
    // queue will now have items in reverse order
    while(!st.empty()) {
        x = st.top();
        st.pop();
        q.push(x);
    }
    return q;
}