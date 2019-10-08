/* 
Union of two arrays
 
Problem Statement:

Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays.
If there are repetitions, then only one occurrence of element should be printed in union.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consist of three lines.
The first line of each test case contains two space separated integers N and M,
where N is the size of array A and M is the size of array B.
The second line of each test case contains N space separated integers denoting elements of array A.
The third line of each test case contains M space separated integers denoting elements of array B.

Output:
Correspoding to each test case, print the count of union elements of the two arrays.

Constraints:
1 ≤ T ≤ 100
1 ≤ N, M ≤ 105
1 ≤ A[i], B[i] < 105

Example:
Input:
2
5 3
1 2 3 4 5
1 2 3
6 2
85 25 1 32 54 6
85 2

Output:
5
7

Explanation:
Testcase 1: 1, 2, 3, 4 and 5 are the elements which comes in the union set of both arrays. 
 */

#include <iostream>
#include <unordered_set>
using namespace std;

int unionElementsCount(int arr1[], int arr2[], int n1, int n2) {
    // unordered set to implement hashing
    unordered_set <int> s;
    // insert all the elements of both the array in set and return its size, as unordered_set does not keep duplicates
    for(int i = 0; i < n1; i++)
        s.insert(arr1[i]);
    for(int j = 0; j < n2; j++)
        s.insert(arr2[j]);
    return s.size();
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n1, n2;
	    cin >> n1 >> n2;
	    int arr1[n1], arr2[n2];
	    for(int i = 0; i < n1; i++)
	        cin >> arr1[i];
	    for(int j = 0; j < n2; j++)
	        cin >> arr2[j];
	    cout << unionElementsCount(arr1, arr2, n1, n2) << endl;
	}
	return 0;
}

// Time Complexity: O(n + m) under the assumption that insert operation takes O(1)
// Company Tags: Rockstand, Zoho