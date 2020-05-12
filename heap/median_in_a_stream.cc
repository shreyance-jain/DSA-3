/* 

Find median in a stream

Difficulty: Hard
   
Problem Statement

Given an input stream of N integers. The task is to insert these numbers
into a new stream and find the median of the stream formed by each insertion
of X to the new stream.

Input:
The first line of input contains an integer N denoting the number of elements in the stream.
Then the next N lines contains integer x denoting the number to be inserted into the stream.

Output:
For each element added to the stream print the floor of the new median in a new line.
 
Constraints:
1 <= N <= 106
1 <= x <= 106
 
Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4
 
Explanation:
Testcase 1:
Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3) 
 */

#include <bits/stdc++.h>
using namespace std;

class FindMedian {
    public:
        void insertHeap(int &);
        double getMedian();
    private:
        double median;
        priority_queue<int> max;
        priority_queue<int, vector<int>, greater<int>> min;
        void balanceHeaps();
};

int main() {
    int n, x;
    FindMedian Ans;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        Ans.insertHeap(x);
        cout << floor(Ans.getMedian()) << endl;
    }
    return 0;
}

/* Approach:
We can use a max heap on left side to represent elements that are less than effective median,
and a min heap on right side to represent elements that are greater than effective median.

After processing an incoming element, the number of elements in heaps differ utmost by 1 element.
When both heaps contain same number of elements, we pick average of heaps root data as effective median.
When the heaps are not balanced, we select effective median from the root of heap containing more elements.
 */

void FindMedian::insertHeap(int &x) {
    if (max.empty() && min.empty()) {
        max.push(x);
        return;
    }
    if (max.size() > min.size()) {
        if (x > max.top())
            min.push(x);
        else {
            // balance heap
            // here the order will not matter as the element is less than max.top()
            // so it will not go at root of max heap, so it will not get popped in
            // balancing step
            max.push(x);
            balanceHeaps();
        }
    } else {
        if (x < max.top())
            max.push(x);
        else {
            // !important first push then balance
            // assume a case when x is greater than max.top()
            // but less than min.top()
            // so this is the item which should go in max heap after balancing
            // for eg take: 12, 15, 10, 5, 8, 7, 9
            min.push(x);
            balanceHeaps();
        }
    }
} // for rule we can say first push and the balance heaps

void FindMedian::balanceHeaps() {
    if (max.size() > min.size()) {
        min.push(max.top());
        max.pop();
    } else {
        max.push(min.top());
        min.pop();
    }
}

double FindMedian::getMedian() {
    int size = max.size() + min.size();
    if (size % 2) {
        median = max.top();
    } else {
        median = (max.top() + min.top()) / 2;
    }
    return median;
}

// Time Complexity: O(nlogn) extract min or extract max and insert are log(n) operations
// Aux Space Complexity: O(n)
// Company Tags: Adobe, Amazon, Apple, Belzabar, D-E-Shaw, Facebook, Flipkart, Google, Intuit
// Microsoft, Morgan Stanley, Ola Cabs, Oracle, Samsung, SAP Labs, Yahoo
