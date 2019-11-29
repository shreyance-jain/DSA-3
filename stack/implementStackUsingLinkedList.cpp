/* 
Implement Stack using Linked List

Problem Statement

Let's give it a try!
You have a linked list and you have to implement the functionalities
push and pop of stack using this given linked list.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases.
Then T test cases follow. First line of each test case contains an integer Q denoting the number of queries.
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)
The second line of each test case contains Q queries seperated by space.Output:
The output for each test case will  be space separated integers having -1
if the stack is empty else the element poped out from the stack . 

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input:
2
5
1 2 1 3 2 1 4 2
4
2 1 4 1 5 2

Output:
3 4
-1 5

Explanation:
Testcase 1:
In the first test case for query 
1 2    the stack will be {2}
1 3    the stack will be {2 3}
2       poped element will be 3 the stack will be {2}
1 4    the stack will be {2 4}
2       poped element will be 4
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure of Node of stack */
struct StackNode {
    int data;
    struct StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

/* Structure fo MyStack */
class MyStack {
    private:
        StackNode *top;
    public:
        void push(int);
        int pop();
        MyStack() {
            top = NULL;
        }
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
            } else if (QueryType == 2)
                cout << sq->pop() << " ";
        }
        cout << endl;
    }
}

/* All the stack operations push, pop, size, empty are O(1)
When we need to implement stack using singly linked list
We can do it only by inserting and removing from head in O(1) time
because even if we maintain a tail pointer, we cannot delete the node by just using tail pointer
we would need the node prev to last node as we need to update it
(Remember: delete a node by only a pointer given to is
assumption there was the node is not be the last node)*/


/* Method push to push element into the stack */
void MyStack :: push(int x) {
    // create a new node
    StackNode *newNode = new StackNode(x);
    // make newNode as the top
    newNode->next = top;    
    top = newNode;
}

/* Method pop which return popped element from the stack */
int MyStack :: pop() {
    // base case
    if (top == NULL)
        return -1;
    // deleting node from linked list
    StackNode *temp = top;
    top = top->next;
    int x = temp->data;
    delete temp;
    return x;
}

// Company Tags: Codenation, FaceSet, Microsoft, Samsung, SAP Labs