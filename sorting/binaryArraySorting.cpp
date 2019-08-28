/*
Binary Array Sorting 

Problem Statement
Given a binary array A[] of size N. The task is to arrange array in increasing order.

Note: The binary array contains only 0  and 1.

Input Format:
The first line of input contains an integer T, denoting the testcases.
Every test case contains two lines, first line is N(size of array) and
second line is space separated elements of array.

Output Format: 
Space separated elements of sorted arrays. There should be a new line between output of every test case.

Constraints:
1 < = T <= 100
1 <= N <= 106
0 <= A[i] <= 1

Example:
Input:
2
5
1 0 1 1 0
10
1 0 1 1 1 1 1 0 0 0

Output:
0 0 1 1 1
0 0 0 0 1 1 1 1 1 1

Explanation:
Testcase 1: After arranging the elements in increasing order, elements will be as 0 0 1 1 1.
*/

#include <iostream>
using namespace std;
void binSort(int A[], int N);
int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}

// Logic is based on partition function of quick sort
void binSort(int A[], int N)
{
   int i = -1;
   for(int j = 0; j < N; j++) {
       if (A[j] < 1) {
           i++;
           swap(A[j], A[i]);
       }
   }
}

// Time Complexity: O(n) and only one travresal of input array
// Company Tags: Accolite, InfoEdge, Intuit, Paytm