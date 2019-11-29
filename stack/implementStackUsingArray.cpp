/* 
Implement stack using array

Problem Statement

Implement a Stack using Array.

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases.
Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types:
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output Format:
The output for each test case will  be space separated integers having
-1 if the stack is empty else the element poped out from the stack .

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input:
1
5
1 2 1 3 2 1 4 2
4
2 1 4 1 5 2  

Output:
3 4
-1 5

Explanation:
In the first test case for query 
1 2    the stack will be {2}
1 3    the stack will be {2 3}
2       poped element will be 3 the stack will be {2}
1 4    the stack will be {2 4}
2       poped element will be 4
 */

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    private:
     int arr[1000];
     int top;
    public:
     MyStack() {
        top = -1;
     }
     int pop();
     void push(int);
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        MyStack *sq = new MyStack();
        int Q;
        cin >> Q;
        while(Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

/* Function push to insert element into the stack 
For push we simply increment top and assign arr[top] = element*/
void MyStack :: push(int x) {
    // element will be inserted just above the previous element
    top++;
    arr[top] = x;
}

/* Function pop() to delete element from stack
For pop simply return top element and decrement top. If top is -1
then no pop can happen */
int MyStack :: pop() {
    // if top is -1, then there is no element in the stack
    if (top == -1)
        return -1;
    // if there is element in the stack, then return the element
    int x = arr[top];
    // and decrease the top index
    top--;
    return x;
}

// Company Tags: FaceSet, Goldman Sachs, Kritikal Solutions, Qualcomm, Visa