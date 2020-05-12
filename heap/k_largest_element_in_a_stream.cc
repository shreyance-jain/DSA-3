/* 

Kth largest element in a stream

Difficulty: Medium

Problem Statement

Given an input stream of n integers, find the kth largest element for each element in the stream.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case contains two lines.
The first line of each test case contains two space separated integers k and n .
Then in the next line are n space separated values of the array.

Output:
For each test case, in a new line, print the space separated values denoting
the kth largest element at each insertion, if the kth largest element at a particular
insertion in the stream doesn't exist print -1.

Constraints:
1 <= T <= 100
1 <= K <= n
1 <= n <= 106
1 <= stream[] <= 105

Example:
Input:
2
4 6
1 2 3 4 5 6
1 2
3 4

Output:
-1 -1 -1 1 2 3
3 4 

Explanation:
Testcase1:
k = 4
For 1, the 4th largest element doesn't exist so we print -1.
For 2, the 4th largest element doesn't exist so we print -1.
For 3, the 4th largest element doesn't exist so we print -1.
For 4, the 4th largest element is 1 {1, 2, 3, 4}
For 5, the 4th largest element is 2 {2, 3, 4 ,5}
for 6, the 4th largest element is 3 {3, 4, 5}
 
 */

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void kthLargest(int arr[], int n, int k);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
    
	    kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}

void kthLargest(int arr[], int n, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++) {
	    if (pq.size() == k) {
	        if (arr[i] > pq.top()) {
	            pq.pop();
	            pq.push(arr[i]);
	        }
	        cout << pq.top() << " ";
	    } else if (pq.size() < k) { // PRO CODE will be to do insertions at one place and printing at another
	        pq.push(arr[i]);
	        if (pq.size() < k)
	            cout << -1 << " ";
	         else
	           cout << pq.top() << " "; // hint is checking this extra condition
	    }
	}
}

void PROCODE(int arr[], int n, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++) {
	    if (pq.size() < k) {
	        pq.push(arr[i]);
	    } else {
	        if (arr[i] > pq.top()) {
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    if (pq.size() < k)
	        cout << -1 << " ";
	    else
           cout << pq.top() << " ";
	}
}

// Time Complexity:
// Space Complexity:

// Company Tags: Cisco
