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

/* Approach: Making enqueue costly
Algorithm:
enQueue(q, x)
- While stack1 is not empty, push everything from stack1 to stack2
- Push x to stack1
- Push everything back to stack1
Here complexity is O(n)

deQueue(q)
- If stack1 is empty then error
- Pop an item from stack1 and return it
Here time complexity will be O(1)
*/
void StackQueue ::push(int x) {
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

int StackQueue :: pop() {
    if (s1.empty())
        return -1;
    int x = s1.top();
    s1.pop();
    return x;
}

// Company Tags: Accolite, Adobe, Amazon, D-E-Shaw, Flipkart, Goldman Sachs, Hike, InfoEdge, InMobi
// MakeMyTrip, MAQ Software, Microsoft, Morgan Stanley, Oracle, Walmart