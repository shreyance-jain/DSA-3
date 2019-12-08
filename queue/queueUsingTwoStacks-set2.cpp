/* 
Queue using two Stacks

Difficulty: Easy
Problem Statement

Implement a Queue using 2 stacks s1 and s2 .

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output Format:
The output for each test case will  be space separated integers having -1
if the queue is empty else the element poped out from the queue . 
You are required to complete the two methods push which take one argument an integer 'x'
to be pushed into the quee and pop which returns a integer poped out from other queue.

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
1 2 2 2 1 4
Output
2 3
2 -1

Explanation:
Testcase1:
1 2    the quee will be {2}
1 3    the queue will be {2 3}
2       poped element will be 2 the queue will be {3}
1 4    the queue will be {3 4}
2       poped element will be 3 s
*/

/* Approach: Making dequeue costly
Algorithm:
enQueue(q, x)
1. Push x to stack1 (assuming size of stack is unlimited)
Here complexity will be O(1)

deQueue(q)
1. If both stacks are empty then error
2. If stack2 is empty,
    While stack1 is not empty, push everything from stack1 to stack2
3. Pop the element from stack2 and return it
Here time complexity will be O(n)

Approach: Simply push to stack in enqueue
When dequeue is stack2 is empty push all the items from stack1 to stack2
Now on dequeue pop the stack2 and return the item
Here we don't need to put these items back in stack1
as when we push we simply keep on adding to stack1
and while stack2 is not empty we simple pop from it and return on dequeue
when stack2 becomes empty we repeat the process
This method only moves the elements once and moves elements only if stack2 is empty
So, the amortized complexity of the dequeue operation becomes Theta(1)
*/
#include <bits/stdc++.h>
using namespace std;

class StackQueue {
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        int pop();
        void push(int x);
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        StackQueue *sq = new StackQueue();
        int q;
        cin >> q;
        while(q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            }
            else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

void StackQueue ::  push(int x) {
    s1.push(x);
}

int StackQueue :: pop() {
    if (s1.empty() && s2.empty())
        return -1;
    if (s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int x = s2.top();
    s2.pop();
    return x;
}

// Company Tags: Accolite, Adobe, Amazon, D-E-Shaw, Flipkart, Goldman Sachs, Hike, InfoEdge, InMobi
// MakeMyTrip, MAQ Software, Microsoft, Morgan Stanley, Oracle, Walmart