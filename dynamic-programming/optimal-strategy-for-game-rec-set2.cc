/* 

Optimal Strategy For A Game

Difficulty: Medium 

Problem Statement

You are given an array A of size N. 
The array contains integers and is of even length. 
The elements of the array represent N coin of values V1, V2, ....Vn. 
You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, 
removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.

Example 1:

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)

Example 2:

Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum
value as 22(7 + 15)

Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
2 <= N <= 100
1 <= Ai <= 106s
 */

#include <bits/stdc++.h>
using namespace std;

long long maximumAmount(int arr[], int n);

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}

// For details see recursive solution - 2 in notes
long long maxAmt(int arr[], int i, int j) {
    if (i+1 == j)
        return max(arr[i], arr[j]);
    return max(arr[i] + min(maxAmt(arr, i+2, j), maxAmt(arr, i+1, j-1)),
                arr[j] + min(maxAmt(arr, i+1, j -1), maxAmt(arr, i, j-2)));
}


long long maximumAmount(int arr[], int n) 
{
    return maxAmt(arr, 0, n-1);
}

// Tags: Medium
// Company Tags: Amazon, Google, Microsoft, Salesforce
