/* 
Nearly sorted

Difficulty: Medium     
Problem Statement

Given an array of n elements, where each element is at most k away from its target position,
you need to sort the array optimally.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains two lines of input.
The first line contains two elements n and k separated by a space. 
The second line contains n elements of array.

Output:
For each testcase, in a new line, print the sorted array.

Note: DO NOT use STL sort() function for this question.

Constraints:
1 <= T <= 50
1 <= n <= 106
1 <= k <= n
1 <= arri <= 107

Examples:
Input:
2
7 3
6 5 3 2 8 10 9
5 2
4 3 1 2 5
Output:
2 3 5 6 8 9 10
1 2 3 4 5
 */

#include<bits/stdc++.h>
using namespace std;

// utility function to print an array
void print(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

/* Idea is to use heap.
Algo:
1) Create a Min Heap of size k+1 with first k+1 elements.
as at index 0, min item should be present
and that item will be in range 0 to 0 + k
This will take O(k) time (See this GFact)

2) One by one remove min element from heap, put it in result array,
and add a new element to heap from remaining elements.
Removing an element and adding a new element to min heap will take Logk time.
This step will take O((n-k)*logK)

3) Add all the remaining elements from the pq to the arr
This step will take O(klogK)

So the overall time complexity would be O(k) + O((n-k)*logK) + O(klogK) = O((n+k)logK)
*/
void nearlySorted(int arr[], int n, int k){
    // for increasing order we will use min heap here
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // handle out of bound case when k = n
    if (k == n)
         k--;
    
    for(int i = 0; i <= k; i++)
        pq.push(arr[i]);
        
    int index = 0;
    
    for(int i = k+1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    
    while(pq.empty() == false) {
        arr[index++] = pq.top();
        pq.pop();
    }
    print(arr, n);
}

// driver code
int main()
 {
	int T;
	cin>> T;
	// { Driver Code Starts.

	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    
	    nearlySorted(arr, num, K);
	    cout<<endl;
	}
	
	return 0;
}
