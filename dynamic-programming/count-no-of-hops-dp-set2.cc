/* 
Count number of hops

Difficulty: Easy

Problem Statement

A frog jumps either 1, 2, or 3 steps to go to the top. 
In how many ways can it reach the top. 
As the answer will be large find the answer modulo 1000000007.

Example 1:

Input:
N = 1
Output: 1

Example 2:

Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
 */

#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
 
long long countWays(int);
 
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		
		//calling function countWays()
		cout << countWays(n) << endl;
	}
    
    return 0;
    
}

/* The idea is very similar: countWays is a recursive function which gives
the no of ways in which we can reach the top.
So at a step we can either take 1, 2 or 3 steps and do this recursively for the reamining 

Now simply converting the above recursion to dp solution
Note: We can optimise Space here as for a n we only need value for n-1, n-2 and n-3*/
long long countWays(int n){
    if (n == 1) return 1;
    long long prev1 = 2; // n-1
    long long prev2 = 1; // n-2
    long long prev3 = 1; // n-3
    long long res = prev1;
    for(int i = 3; i <= n; i++) {
        res = (prev1 + prev2 + prev3) % mod;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = res;
    }
    return res;
}


// Time Complexity: O(n)
// Space Complexity: O(1)

// Tags: Easy
// Company Tags: Amazon
