/*
Operations on Stack

Problem Statement

Given a stack of integers and Q queries.
The task is to perform operation on stack according to the query.

Input Format:
First line of input contains nubmer of testcases T. For each testcase,
first line of input contains Q, number of queries.
Next line contains Q queries seperated by space. Queries are as:

    i x: (adds element x in the stack).

    r: (removes the topmost element from the stack).

    h: Prints the topmost element.

    f y: (check if the element y is present or not in the stack). Print "Yes" if present, else "No".

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
5
No
Yes

Explanation:
Testcase 1: Inserting 2, 4, 3, and 5 onto the stack. Returning top element which is 5. Finding 8 will give No, as 8 is not in the stack.
*/

#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int x);
void remove(stack<int> &s);
void headOf_Stack(stack<int> &s);
bool find(stack<int> s, int val);

int main() {
    int T;
    cin >> T;
    while(T--) {
        stack <int> s;
        int q;
        cin >> q;
        while(q--) {
            char ch;
            cin >> ch;
            
            if (ch == 'i') {
                int x;
                cin >> x;
                insert(s, x);
            }
            else if (ch == 'r') {
                remove(s);
            }
            else if (ch == 'h') {
                headOf_Stack(s);
            }
            else if (ch == 'f') {
                int x;
                cin >> x;
                if (find(s, x))
                    cout << "Yes";
                else
                    cout << "No";
                cout << endl;
            }
        }
    }
}

// Stack stl (conatiner adaptor: by default implemeted using dequeue)

/* insert : to insert element to stack */
void insert(stack<int> &s, int x) {
    s.push(x);
}

// remove : to pop element from stack
void remove(stack <int> &s) {
    s.pop();
}

// headOf_Stack : to return top of stack
void headOf_Stack(stack <int> &s) {
    int x = s.top();
    cout << x << " " << endl;
}

// find : to find the element in stack
bool find(stack <int> s, int val) {
    bool exists = false;
    while(!s.empty()) { // traverse while stack is not empty
        if (s.top() == val) { // compare the val with stack top element
            exists = true;
            break;
        }
        s.pop();
    }
    if (exists)
        return true;
    return false;
}