/* 
Minimum Cost of ropes

Difficulty: Medium     
Problem Statement

There are given N ropes of different lengths,we need to connect these ropes into one rope.
The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N where N is the number of ropes.
The second line of each test case contains N input L[i],length of ropes.

Output:
For each testcase, print the minimum cost to connect all the ropes.

Your Task:
You are required to complete the method minCost() which takes 2 arguments and returns the minimum cost.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 100000
1 ≤ L[i] ≤ 106

Example:
Input:
2
4
4 3 2 6
5
4 2 7 6 9

Output:
29
62

Explanation:
For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected.

Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes.
Other ways of connecting ropes would always have same or more cost.
For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10),
then connect 10 and 3 (we get two strings of 13 and 2). Finally we connect 13 and 2.
Total cost in this way is 10 + 13 + 15 = 38.
 */

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}


/* Approach:
If we observe the problem closely,
we can notice that the lengths of the ropes which are picked first
are included more than once in total cost.

Therefore, the idea is to connect smallest two ropes first and recur for remaining ropes.

This approach is similar to Huffman Coding.
We put smallest ropes down the tree so that they can be repeated multiple times rather than the longer ropes.

Following is complete algorithm for finding the minimum cost for connecting n ropes.
Let there be n ropes of lengths stored in an array len[0..n-1]
1) Create a min heap and insert all lengths into the min heap.
2) Do following while number of elements in min heap is not one.
……a) Extract the minimum and second minimum from min heap
……b) Add the above two extracted values and insert the added value to the min-heap.
……c) Maintain a variable for total cost and keep incrementing it by the sum of extracted values.
3) Return the value of this total cost. */
long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);
    
    long long minCost = 0;
    while(pq.size() != 1) {
        long long minRope1 = pq.top();
        pq.pop();
        long long minRope2 = pq.top();
        pq.pop();
        long long newRope = minRope1 + minRope2;
        minCost += newRope;
        pq.push(newRope);
    }
    return minCost;
} // see the pro code below

// Time Complexity: O(n) for building the heap + O(n*logn) for extractMin for n items = O(nlogn)

// Auxiliary Space Complexity: O(1) as we are modifiying the given array and not using any extra space

// Company Tags: Amazon, Goldman Sachs

/* PRO CODE */
long long proCode(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);
    
    long long minCost = 0;
    while(pq.size() != 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        minCost += first + second;
        pq.push(first + second);
    }
    return minCost;
}
