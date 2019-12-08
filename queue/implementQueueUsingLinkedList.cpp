/* 
Implement Queue using Linked List

Difficulty: Basic
Problem Statement

Implement a Queue using Linked List.

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop element from queue and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output Format:
The output for each test case will  be space separated integers having -1
if the queue is empty else the element poped out from the queue . 
You are required to complete the two methods push which takes one argument an integer 'x'
to be pushed into the quee  and pop which returns a integer poped out from othe queue.

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
1 2 2 2 1 3  
Output:
2 3
2 -1

Explanation:
Testcase1:
1 2    the quee will be {2}
1 3    the queue will be {2 3}
2       poped element will be 2 the queue will be {3}
1 4    the queue will be {3 4}
2       poped element will be 3 
 */

#include <bits/stdc++.h>
using namespace std;

struct QueueNode {
    int data;
    QueueNode *next;
    QueueNode(int a) {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode * rear;
    void push(int x);
    int pop();
    MyQueue() {
        front = NULL;
        rear = NULL;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        MyQueue *sq = new MyQueue();
        int q;
        cin >> q;
        while(q--) {
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

/* Concept here is which is very important concept of linked list :-
we can delete a node with only a pointer given to it 
But is should not be the last node of linked list
To delete the last node we need to get hold of the previous node and
this operation beomes O(n)
 */
/* So we maintain front at head of linked list to remove from queue in O(1)
and rear at tail of linked list to add in queue  in O(1),
since we can remove a node from head in O(1)
and add a node at tail in O(1)*/
void MyQueue :: push(int x) {
    QueueNode *temp = new QueueNode(x);
    if (front == NULL)
        front = temp;
    else {
        rear->next = temp;
    }
    rear = temp;
}

int MyQueue :: pop() {
    if (!front) return -1;
    QueueNode *temp = front;
    int x = temp->data;
    front = front->next;
    delete temp;
    return x;
}

// Company Tags: Adobe, Amazon, Oracle, Qualcomm, Samsung