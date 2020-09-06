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
    long long max_ending_here = 0;
    long long max_so_far = INT_MIN;
    for(int i = 0; i < sizeOfArray; i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        cout << max_ending_here << " ";
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    cout << endl;
    return max_so_far;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)
