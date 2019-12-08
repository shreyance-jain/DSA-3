/* 
Implement Queue using array

Problems

Implement a Queue using Array. Your task is only to complete the functions push and pop.

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types:
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop element from queue and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output Format:
The output for each test case will  be space separated integers having -1
if the queue is empty else the element poped out from the queue .

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input
2
5
1 2 1 3 2 1 4 2
4
1 3 2 2 1 4  

Output
2 3
3 -1

Explanation:
In the first test case for query 
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
};

class MyQueue {
    private:
        int arr[10001];
        int front;
        int rear;
    public:
        MyQueue() {
            front = 0;
            rear = 0;
        }
        void push(int);
        int pop();
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        MyQueue *sq = new MyQueue();
        int Q;
        cin >> Q;
        while(Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2){
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

/* 10001 is the size of array
we are using modulus technique to avoid wastage of space in array */
/* The method push to push element into the queue */
void MyQueue :: push(int x)
{
    arr[rear] = x;
    rear = (rear + 1) % 10001;
}
/*The method pop which return the element 
  poped out of the queue*/
int MyQueue :: pop()
{
    if (front == rear)
        return -1;
    int x = arr[front];
    front = (front + 1) % 10001;
    return x;
}

// Company Tags: Goldman Sachs