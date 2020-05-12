/* 

K Most occurring elements

Difficulty: Medium
   
Problem Statement

Given an array arr[] of N integers in which elements may be repeating several times.
Also, a positive number K is given and the task is to
find sum of total frequencies of K most occurring elements

Note: The value of K is guaranteed to be less than or equal to the number of distinct elements in arr.

Input:
First line of input contains number of testcases T. For each testcase,
first line of input contains the size of array N, and next line contains N positive integers.
The last line contains K.

Output:
For each testcase, print the sum of total frequencies of K most occurring elements in the given array.

Constraints:
1 <= T <= 100
1 <= K <= N
1 <= N <= 107
1 <= arr[i] <= 106

Example:
Input:
2
8
3 1 4 4 5 2 6 1
2
8
3 3 3 4 1 1 6 1
2

Output:
4
6

Explanation:
Testcase 1: Since, 4 and 1 are 2 most occurring elements in the array with their frequencies as 2, 2. So total frequency is 2 + 2 = 4.

Testcase 2: Since, 3 and 1 are most occurring elements in the array with frequencies 3, 3 respectively. So, total frequency is 6.
 */

#include <bits/stdc++.h>
using namespace std;

int print_N_mostFrequentNumber(int arr[], int n, int k);

int main() {
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        cin >> k;
        cout << print_N_mostFrequentNumber(arr, n, k) << endl; 
    }

	return 0; 
}


/* 
Naive Approach:
Traverse the array, store frequency of every element in a map
Now the question reduces to k largest element from these frequency of diff elements
 */
int print_N_mostFrequentNumber(int arr[], int n, int k) 
{ 
	unordered_map<int, int> m; // to store frequencies
	priority_queue<int, vector<int>, greater<int>> pq; // heap of frequency of elements

    // traverse the array and store the frequencies using map
	for(int i = 0; i < n; i++) {
	    m[arr[i]]++;
	}

    // traverse the map, and build a MIN HEAP of size k of frequencies of elements
	unordered_map<int, int>::iterator it;
	for(it = m.begin(); it != m.end(); it++) {
	    if (pq.size() < k) {
	        pq.push(it->second);
	    } else {
	        if (pq.top() < it->second) {
	            pq.pop();
	            pq.push(it->second);
	        }
	    }
	}
    // return the sum of frequencies of top k most occuring element
    // this MIN HEAP will have the k largest frequencies, so return sum
	int sum = 0;
	while(pq.empty() == false) {
	    sum += pq.top();
	    pq.pop();
	}
	return sum;
}

// Time Complexity: O(n + nlogk) // RECHECK, if we do deep analysis, it can be tight bounded further
// Space Complexity: O(n) for map + O(k) for MIN HEAP of size k = O(n+k) = O(n)
 
