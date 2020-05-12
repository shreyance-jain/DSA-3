/* 

Kth largest element

Difficulty: Medium

Problem Statement

Given an array arr[] of N positive integers and a number K.
The task is to find the kth largest element in the array.

Input Format:
First line of input contains number of testcases. For each testcase,
there will be a single line of input containing number of elements in the array and K.
Next line contains N elements.

Output Format:
For each testcase, there will be a single line of output containing the kth largest element in the array.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106
1 <= K <= N

Example:
Input:
2
5 3
3 5 4 2 9
5 5
4 3 7 6 5

Output:
4
3

Explanation:
Testcase 1: Third largest element in the array is 4.
Testcase 2: Fifth largest element in the array is 3s
 */

#include <bits/stdc++.h>
using namespace std;

int kthLargest(int arr[], int n, int k);

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << kthLargest(arr, n, k) << endl;
    }
    return 0;
}


/*
Approach:
Idea is same as that of k largest elements, Since we maintain a min heap so the top
element will be the kth largest element.

Algo:
1. create and maintain MinHeap of size k.
2. First insert elements from the array into the min heap of size K
(maintaining the size by popping the weed elements),
keping in mind that only K largest elements should exists in heap (by including some comparisons).
Finally, element at the top will be kth largest element.
 */
int kthLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        if (pq.size() == k) { // SEE THE PRO CODE, if ONLY ONE IF CONDITION IN THE IF STATEMENT, OPTIMIZE THE CONDITION
            if (arr[i] > pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        } else {
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

/* 
Time Complexity: O(k + (n-k)*logk)
O(k) for buildiing the initial heap of first k elements (we can modify the above code
to initialise the heap with first k elements and then run the loop starting from
(k+1)th element)
O(n-k * log k) for remaining (n-k) it will be extract min and insert opertions
both will be log(k) operations
*/


// PRO CODE
int KthLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        if (pq.size() == k && pq.top() < arr[i]) { // if size becomes equal to k
            // and top element is smaller than arr[i]
            pq.pop();
            pq.push(arr[i]);
        } else if (pq.size() < k)
            pq.push(arr[i]);
    }

    return pq.top(); // return Kthlargest element
}
