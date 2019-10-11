/* 
Print Distinct Elements

Problem Statement

You are given an array arr of size n.
You need to print the distinct elements as they appear in the array.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains two lines of input. The first line contains n denoting the size of the array.
The second line contains n elements of the array.

Output:
For each testcase, in a new line, print the distinct elements in the order they appear in the array.

Constraints:
1 <= T <= 100
1 <= n <= 103
0 <= arri <= 107

Examples:
Input:
1
10
1 1 2 2 3 3 4 5 6 7
Output:
4 5 6 7
 */

#include <bits/stdc++.h>
using namespace std;

/* Naive/Brute Force Approach: 
Iterate over all the elements of the array and  keep track of count

Better approach:
Use an unordered map and keep count of all the elements in the array
Traverse the array and check the element count in the map and print the elements which occur only once*/

void printDistinctElements(int arr[], int n) {
  // initialise a map to keep track of count of all the elements of input array
    unordered_map<int, int> m;

    // traverse the input array and store the count in map
    for(int i = 0; i < n; i++)
        m[arr[i]]++;
    
    // traverse again the input array and print the elements whose count is one
    for(int i = 0; i < n; i++) {
        if (m[arr[i]] == 1) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
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
	    printDistinctElements(arr, n);
	}
	return 0;
}

// Hashing is very useful to keep track of the frequency of the elements in a list.