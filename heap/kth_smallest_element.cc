/* 

Kth smallest element

Difficulty: Medium
   
Problem Statement

Given an array arr[] of N positive integers and a number K.
The task is to find the kth smallest element in the array.

Input:
First line of input contains number of testcases. For each testcase,
there will be a single line of input containing number of elements in the array and K.
Next line contains N elements.

Output:
For each testcase, there will be a single line of output containing the kth smallest element in the array.

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
7

Explanation:
Testcase 1: Third smallest element in the array is 4.
Testcase 2: Fifth smallest element in the array is 7.
 */

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int [], int, int);

int main(){
	
	int t;
	cin >> t;
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    
	    for(int i = 0; i<n; ++i)
	        cin>>arr[i];
	        
	    cout << kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}

/* 
Approach: Idea is same as k largest element
Here since we want the smallest element, we will maintain a MAX HEAP.
Element element less than top will be pushed top will be popped.
In the end we are left with k smallest element.
And the top one would be kth smallest

Algo:
1. Create and maintain MAX HEAP of size k.
2. While inserting elements in heap kepp check whether size of heap is less than k.
If size of heap becomes k and tompost element of heap is more than kth(index starting from 0)
element of array then remove the tompost element and insert current element of array.
Do this while i < n. Finally print the topmost element of heap.
 */
int kthSmallest(int arr[], int n, int k) {
    priority_queue<int> pq; // MAX HEAP
    for(int i = 0; i < n; i++) {
        if (pq.size() == k && arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        } else if (pq.size() < k){
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

/* 
Time Complexity: O(k + (n-k)*logk)
O(k) for buildiing the initial MAX HEAP of first k elements (we can modify the above code
to initialise the heap with first k elements and then run the loop starting from
(k+1)th element)
O(n-k * log k) for remaining (n-k) it will be extract max and insert opertions
both will be log(k) operations
*/
// Space complexity: O(k)