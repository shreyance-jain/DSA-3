/* 
Check if two arrays are equal or not

Problem Statement

Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not.
Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation)
of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow.  Each test case contains 3 lines of input.
The first line contains an integer N denoting the size of the array.
The second line contains element of array A[].
The third line contains elements of the array B[].

Output:
For each test case, print 1 if the arrays are equal else print 0.

Constraints:
1<=T<=100
1<=N<=107
1<=A[],B[]<=1018

Example:
Input:
2
5
1 2 5 4 0
2 4 5 0 1
3
1 2 5
2 4 15

Output:
1
0

Explanation:
Testcase1:
Input : A[] = {1, 2, 5, 4, 0}; B[] = {2, 4, 5, 0, 1};
Output : 1

Testcase2:
Input : A[] = {1, 2, 5}; B[] = {2, 4, 15};
Output : 0 
 */

#include <bits/stdc++.h>
using namespace std;

/* A naive solution can be to sort both the arrays and linearly compare each element */

/* Efficient Approach: Store all the elements and their counts in a hash table.
 Then traverse the second array and check if count of every element matches the count of
 elements in first array */
bool checkEqualArrays(long arr1[], long arr2[], long n1, long n2) {
    
    // if length of arrays are not equal
    if (n1 != n2) return false;

    // unordered_map to store elements and their counts
    unordered_map <long, long> m;
    
    // store the counts of elements of first array in unordered_map
    for(long i = 0; i < n1; i++)
        m[arr1[i]]++;
    

    for(long j = 0; j < n2; j++) {
        // if present in arr2 and not in arr1
        if (m.find(arr2[j]) == m.end())
            return false;

        // if element appears more times in arr2 than in arr1
        if(m[arr2[j]] == 0)
            return false;
            
        m[arr2[j]]--;
    }
    return true;
}

int main() {
	long t;
	cin >> t;
	while(t--) {
	    long n;
	    cin >> n;
	    long arr1[n], arr2[n];
	    for(long i = 0; i < n; i++)
	        cin >> arr1[i];
	    for(long j = 0; j < n; j++)
	        cin >> arr2[j];
	    cout << checkEqualArrays(arr1, arr2, n, n) << endl;
	}
	return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

// Company tags: Goldman Sachs