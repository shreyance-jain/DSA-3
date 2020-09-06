/* 

Kadane's Algorithm - II

Difficulty: Easy

Problem Statement

You are given an array arr of size sizeOfArr. 
You need to find the maximum sum in the array provided that you 
cannot sum neighboring elements or adjacent elements.

Example 1:

Input:
sizeOfArr = 4
arr[] = {4,5,6,7,8}
Output: 18
Explanation:The given elements are 4 5 6 7 8
For 4, the maximum sum will be 4 as no
element other than 4 from index 0 to 0
For 5, the maximum sum will be 5 as we cannot
add 4 and 5(neighboring elements).
For 6, the maximum sum will be 10 as we can
add 6 and 4.
For 7, the maximum sum will be 12 as we can
add 7 and 5.
For 8, the maximum sum will be 18 as we can
add 4 and 6 and 8.

Example 2:

Input:
sizeOfArr = 5
arr[] = {-9,-8,8,3,-4}
Output: 8

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= sizeOfArr <= 103
-103 <= arri <= 103

 */

#include <bits/stdc++.h>
using namespace std;

long long maximumSum(int arr[], int sizeOfArray);

int main() {
    
    //taking total testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking size of array
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    //inserting elements in the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    //calling function maximumSum()
	    cout<<maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}

// extra thing is to compare it with the current element also
// as it is not mentioned that all the elements are positive
// so it is possible the previous values i.e. dp[i-1] and dp[i-2] are -ve
// or more less and the current element is +ve or greater
long long maximumSum(int arr[], int sizeOfArray)
{
    long long dp[sizeOfArray+1];
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);
    for(int i = 3; i <= sizeOfArray; i++) {
        dp[i] = max({arr[i-1] + dp[i-2], dp[i-1], (long long)arr[i-1]});
    }
    return dp[sizeOfArray];
}

// Note: My Solution

// Time Complexity: O(N)
// Space Complexity: O(N), we can optimise space as for value n, we only need values of n-1 and n-2
