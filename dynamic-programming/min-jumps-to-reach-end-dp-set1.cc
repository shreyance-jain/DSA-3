/* 

Minimum number of jumps

Difficulty: Medium

Problem Statement

Given an array of integers where each element represents the max 
number of steps that can be made forward from that element. 
The task is to find the minimum number of jumps to reach the end of the array
(starting from the first element). 
If an element is 0, then cannot move through that element.

Example 1:

Input:
N = 11
a[] = {1,3,5,8,9,2,6,7,6,8,9}
Output: 3
Explanation: First jump from 1st element,
and we jump to 2nd element with value 3.
Now, from here we jump to 5h element with
value 9. and from here we will jump to
last.

Example 2:

Input:
N = 6
a[] = {1,4,3,2,6,7}
Output: 2

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 107
0 <= ai <= 107
 */

#include<bits/stdc++.h>

using namespace std;

int minimumJumps(int[], int);

int main()
{
    //taking count of testcases
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}

// Refer Notes for detailed explanation
/* 
Approach: We begin from last cell, consider all the cells from which we can reach the last cell
We recursively check if these cells are reachable from start.
We recursively find min jumps for these cells from which we can reach the last cell adn take min of these
and add 1 to it.

We have one parameter which is changing in the recursive call and the value
of it ranges from 1 to given value, so we need an array of size n.

We also have base case, if n = 1 and if we want to reach end, ways = 0
as no jump will be required
All other value will be initialised as INT_MAX
 */
int minimumJumps(int arr[], int n){
    int dp[n];
    dp[0] = 0;
    for(int i = 1; i < n; i++) 
        dp[i] = INT_MAX;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if (arr[j] + j >= i) {
                // check if j is reachable from start
                if (dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    int res = dp[n-1] == INT_MAX ? -1 : dp[n-1];
    return res;
}

// Time Complexity : O(N ^ 2)
// Auxiliary Space: O(N)

// Company Tags: Adobe, Amazon, Housing.com, Moonfrog Labs, OYO Rooms, Walmart
