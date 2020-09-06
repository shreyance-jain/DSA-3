/* 

Reach a given score

Difficulty: Easy

Problem Statement

Consider a game where a player can score 3 or 5 or 10 points in a move. 
Given a total score n, find the number of distinct combinations to reach the given score.

Example 1:

Input:
n = 8
Output: 1
Explanation:when n = 8,{3,5} and {5,3}
are the two possible permutations but
these represent the same cobmination.
Hence output is 1.

Example 2:

Input:
n = 20
Output: 4
Explanation:When n = 20, {10,10},
{5,5,5,5},{10,5,5} and {3,3,3,3,3,5}
are different possible permutations.
Hence output will be 4.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ n ≤ 1000
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll count(ll n);

int main()
{
    //taking total testcases
	int t;
	cin>>t;
	
	while(t--)
	{
	    //taking the score
		ll n;
		cin>>n;
		
		//calling function count()
		cout << count(n) << "\n";
	}
	return 0;
}// } Driver Code Ends


/* 
Naive approach: Simple from the notes lecture count coin combinations to make a certain value
here we make a coin type array of [3, 5, 10] and use the same algorithm
*/
/* Better Approach: The number of ways to reach i will be sum of ways to reach (i-3) + (i-5) + (i-10)
So create an array and fill it with 0, arr[0] = 1 (no sum to make => 1 way do not pick any value)
Now, simply itreate the array and do arr[i] = arr[i-3] + arr[i-5] + arr[i-10]
print the required arr[i] value */
ll count(ll n) {
    ll dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 3; i <= n; i++)
        dp[i] += dp[i-3];
    for(int i = 5; i <= n; i++)
        dp[i] += dp[i-5];
    for(int i = 10; i <= n; i++)
        dp[i] += dp[i-10];
    return dp[n];
}

// Time Complexity: O(n)
// Aux Space Complexity: O(n)

// Tags: Easy
// Company Tags: Amazon

/* NOTE: Same as:
- Count Ways to Reach nth Stair, the person can climb either 1 stair or 2 stairs at a time.
- Count no of frog hops, frog can take 1, 2 or 3 steps at a time */
