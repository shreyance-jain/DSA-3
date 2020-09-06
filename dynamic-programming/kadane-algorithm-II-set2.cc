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

/* 
My Approach: Implemented in Set 1
extra thing is to compare it with the current element also
as it is not mentioned that all the elements are positive
so it is possible the previous values i.e. dp[i-1] and dp[i-2] are -ve
or more less and the current element is +ve or greater

For eg: arr[n] = {-9, -8, 8, 3, 4}
        dp[n+1] = {0, 0, 0, 0, 0, 0}
        dp[0] = arr[0] = -9
        dp[1] = max(arr[0], arr[1]) = -8
    so, dp[n+1] = {-9, -8, 0, 0, 0, 0}
    next element index 2 = 8
    we do dp[i] = max({arr[i-1] + dp[i-2], dp[i-1], (long long)arr[i-1]});
        dp[n+1] = {-9, -8, 8, 0, 0, 0} 

Geeks Approach: initialise dp elements with 0, so any -ve will be overridden with 0
in beginning itself

For eg: arr[n] = {-9, -8, 8, 3, 4}
        dp[n+1] = {0, 0, 0, 0, 0, 0}
        dp[0] = max(arr[0], dp[0]) = 0
        dp[1] = max(arr[1], dp[0]) = 0
    so, dp[n+1] = {0, 0, 0, 0, 0, 0}
    next element index 2 = 8
        dp[n+1] = {0, 0, 8, 0, 0, 0}

Here in this approach, we have to explicitly check if all the elements are negative
because in that case we cannot give result with this approach since all the elements
in the dp array will remain/ will be 0 after the complete traversal
*/
long long maximumSum(int arr[], int sizeOfArray)
{
   long long dp[sizeOfArray]={0};       // Initializing all the dp elements as 0
   dp[0]=max((long long)arr[0],dp[0]);  // Take max of first element or 0.
   dp[1]=max(dp[0],(long long)arr[1]);  // Take max of second element, first element or 0.
   for(int i=2;i<sizeOfArray;i++)
   {
       dp[i]=max(dp[i-2]+arr[i],dp[i-1]);   // dp to calculate max answer till ith position

   }

   int maxx=INT_MIN;
   bool isAllNegative=true;                 // If all numbers are negative, max number need to be searched

   for(int i=0;i<sizeOfArray;i++)
   {
       maxx=max(maxx,arr[i]);
       if(arr[i]>0)
       {
           isAllNegative=false;
           break;
       }

   }

   if(isAllNegative==true)
   {
       return maxx;                     // Return the max negative if all numbers are negative
   }
   else
   return (dp[sizeOfArray-1]); 
}

// Note: Geeks Solution, CONCEPT: ELIMINATE NEGATIVE IN DP ARRAY takes 2 traversals of the input array
// My solution: 1 traversal of the input array

// Time Complexity: O(N)
// Space Complexity: O(N), we can optimise space as for value n, we only need values of n-1 and n-2
