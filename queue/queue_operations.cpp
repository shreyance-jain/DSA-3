/* 
Operations on Queue

Difficulty: Basic
Problem Statement

Given a queue of integers and Q queries. The task is to perform operations on queue according to the query.

Input Format:
First line of input contains nubmer of testcases T. For each testcase,
first line of input contains Q, number of queries.
Next line contains Q queries seperated by space. Queries are as:

    i x : (adds element x in the queue from rear).

    r : (returns and removes the front element of queue).

    h : Prints the topmost element.

    f y : (check if the element y is present or not in the queue). Print "Yes" if present, else "No".

Output Format:
For each testcase, perform Q queries and print the output wherever required.

Constraints:
1 <= T <= 100
1 <= Q <= 103

Example:
Input:
2
6
i 2 i 4 i 3 i 5 h f 8
4
i 3 i 4 r f 3

Output:
2
No
No

Explanation:
Testcase 1: Inserting 2, 4, 3, and 5 onto the queue: 2 4 3 5. h means front. So front is 2. f is find. 8 is not in queue so No.
 */

#include <bits/stdc++.h>
using namespace std;

void enqueue(queue<int> &, int);
void dequeue(queue<int> &);
void front(queue<int> &);
void find(queue<int>, int);

int main() {
    int t;
    cin >> t;
    while(t--) {
        queue<int> s;
        int q;
        cin >> q;
        while(q--) {
            char ch;
            cin >> ch;

            if (ch == 'i') {
                int x;
                cin >> x;
                enqueue(s, x);
            }
            else if (ch == 'r') {
                dequeue(s);
            }
            else if (ch == 'h') {
                front(s);
            }
            else if (ch == 'f') {
                int x;
                cin >> x;
                find(s, x);
            }
        }
    }
}

void enqueue(queue<int> &s, int x) {
    s.push(x);
}

void dequeue(queue<int> &s) {
    s.pop();
}

void front(queue<int> &s) {
    int x = s.front();
    cout << x << endl;
}

void find(queue<int> s, int val) {
    bool exists = false;
    while(!s.empty()) {
        int x = s.front();
        if (x == val) {
            exists = true;
            break;
        }
        s.pop();
    }
    if (exists)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
}