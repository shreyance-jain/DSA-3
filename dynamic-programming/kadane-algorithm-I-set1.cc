/* 

Kadane's Algorithm - I

Difficulty: Easy

Problem Statement

Kadane's algorithm comes into picture when we want to find the maximum 
possible sum in an array when summing the contiguous elements of the array.

You are given an array. Find the maximum possible sum of contiguous 
elements of the array ending at each position in the array. 
Also, return the overall maximum that we can achieve.

Example 1:

Input:
N = 6
arr[] = {5,2,-3,32,-5,65}
Output: 5 3 0 32 27 92
        92
Explanation: Maximum sum at each index is
5, 3, 0, 32, 27, 92. And, maximum sum for
contiguous array is 92.


Example 2:

Input:
N = 5
arr[] = {-9,-8,8,3,-4}
Output: -9 -8 8 11 7
         11

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= sizeOfArray <= 103
-103 <= Ai <= 103
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
	    
	    //inserting elements to the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    //calling function maximumSum()
	    cout<<maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}

// space optimised solution, but the value at every point will not be stored
long long maximumSum(int arr[], int sizeOfArray)
{
    long long dp[sizeOfArray + 1];
    long long max_so_far = arr[0];
    dp[1] = arr[0];
    for(int i = 2; i <= sizeOfArray; i++) {
        dp[i] = max(dp[i-1] + arr[i-1], (long long)arr[i-1]);
        max_so_far = max(max_so_far, dp[i]);
    }
    for(int i = 1; i <= sizeOfArray; i++)
        cout << dp[i] << " ";
    cout << endl;
    return max_so_far;
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)
