/*

Sort by Absolute Difference

Problem Statement

Given an array of N elements and a number K. 
The task is to arrange array elements according to the absolute difference with K, i. e.,
element having minimum difference comes first and so on.
Note : If two or more elements are at equal distance arrange them in same sequence as in the given array.

Input Format:
First line of input contains a single integer T which denotes the number of test cases. 
Then T test cases follows. First line of test case contains two space separated integers N and K.
Second line of each test case contains N space separated integers.

Output Format:
For each test case print the given array in the order as described above.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= K <= 105

Example:
Input:
3
5 7
10 5 3 9 2
5 6
1 2 3 4 5
4 5
2 6 8 3

Output:
5 9 10 3 2
5 4 3 2 1
6 3 2 8

Explanation:
Testcase 1: Sorting the numbers accoding to the absolute difference with 7, we have array elements as 5, 9, 10, 3, 2.
*/

#include <bits/stdc++.h>
using namespace std;

void sortABS(int A[],int N, int k);

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin>>N>>diff;
	    int A[N];
	    
	    for(int i = 0; i<N; i++)
	        cin>>A[i];
	   
	    sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout<<val<<" ";
	    cout<<endl;
	    
	}
	
	return 0;
}

/* The solution is based on insertion sort.
For every i in range 1<= i < n
we compare the absolute difference of arr[i] with the given number k (Let this be diff)
We then compare this difference with the abs(arr[j] -k) where 0 <= j < i (let this be abdiff)
if abdiff is greater than diff than we shift the values in the array to accommodate arr[i] at its correct position*/

void sortABS(int A[],int N, int k)
{
   for(int i = 0; i < N; i++) {
       int key = A[i];
       int j = i - 1;
       int diff = abs(A[i] - k);
       while (j >= 0 && abs(A[j] - k) > diff) {
           A[j+1] = A[j];
           j--;
       }
       A[j+1] = key;
   }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)