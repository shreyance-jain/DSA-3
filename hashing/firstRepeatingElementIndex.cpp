/* 
First Repeating Element

Problem Statement:

Given an array arr[] of size N. The task is to find the first repeating element in an array of integers,
i.e., an element that occurs more than once and whose index of first occurrence is smallest.

Input :
The first line contains an integer T denoting the total number of test cases. In each test cases,
First line is number of elements in array N and second its values.

Output:
In each separate line print the index of first repeating element,
if there is not any repeating element then print “-1” (without quotes). Use 1 Based Indexing.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 106

Example:
Input:
1
7
1 5 3 4 3 5 6

Output:
2

Explanation: 
Testcase 1: 5 is appearing twice and its first appearence is at index 2 which is
less than 3 whose first occuring index is 3.
 */

#include <iostream>
#include <unordered_set>
using namespace std;

/* 1. A simple naive solution is to use two loops O(n^2)
2. Another approach is to use sorting, O(nlogn) copy elements in a temp array, sort the temp array
   scan the input array from left to right and search it in temp array
3. Use hashing to solve in O(n) in average, the idea is to traverse the given array from right to left and update the
 min index whenever we find an element that has been visited on the right side*/

int getFirstRepeatingElementIndex(int arr[], int n) {
    // take a unordered set to implement hashing
    unordered_set <int> s;
    // initialise min index
    int min_index = -1;
    // traverse from right to left so it will keep track of first from left
    for(int i = n - 1; i >= 0; i--) {
        // update min index if the element has already been visited on right side
        if (s.find(arr[i]) != s.end()) {
            min_index = i;
        }
        s.insert(arr[i]);
    }
    if (min_index == -1)
        return min_index;
    // add 1 to index as output is expected on 1 Based Indexing
    return min_index + 1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    cout << getFirstRepeatingElementIndex(arr, n) << endl;
	}
	return 0;
}

// Time Complexity: O(n) single traversal
// Company tags: Amazon, Oracle