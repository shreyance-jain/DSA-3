/* 
Intersection of two arrays
     
Problem Statement

Given two arrays A and B respectively of size N and M.
The task is to print the count of elements in the intersection (or common elements) of the two arrays.

For this question, intersection of two arrays can be defined as the set
containing distinct common elements between the two arrays.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N and M, N is the size of array A and M is size of array B.
The second line of each test case contains N input A[i].
The third line of each test case contains M input B[i].

Output:
Print the count of intersecting elements.

Constraints:
1 ≤ T ≤ 100
1 ≤ N, M ≤ 105
1 ≤ A[i], B[i] ≤ 105

Example:
Input:
4
5 3
89 24 75 11 23
89 2 4
6 5
1 2 3 4 5 6
3 4 5 6 7
4 4
10 10 10 10
20 20 20 20
3 3
10 10 10
10 10 10

Output:
1
4
0
1
 

Explanation:
Testcase 1: 89 is the only element in the intersection of two arrays.
Testcase 2: 3 4 5 and 6 are the elements in the intersection of two arrays.

Refer: https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
 */

#include <bits/stdc++.h>
using namespace std;

int intersectionElementsCount(int arr1[], int arr2[], int n1, int n2) {
    // initialize count
    int count = 0;

    // unordered_set for implementig hashing
    unordered_set <int> s;

    // insert all the elements of the first array in unordered_set
    for(int i = 0; i < n1; i++)
        s.insert(arr1[i]);

    // iterate over second array, check if the element is already present, if yes then it is part of intersection set
    // and remove the element from the unordered_set to handle duplicates
    for(int j = 0; j < n2; j++)
        if (s.find(arr2[j]) != s.end()) {
            count++;
            s.erase(arr2[j]);
        }
    return count;
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
	    cout << intersectionElementsCount(arr1, arr2, n1, n2) << endl;
	}
	return 0;
}

// Time Complexity: O(n + m) under the assumption that search and insert operation takes O(1) time

// Company tags: Accolite, Amazon, PayPal, Rockstand