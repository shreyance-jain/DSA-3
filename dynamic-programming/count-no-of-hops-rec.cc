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
So at a step we can either take 1, 2 or 3 steps and do this recursively for the reamining */
long long countWays(int n){
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;
    long long res = countWays(n-1) + countWays(n-2) + countWays(n-3);
    return res % mod;
}

// Time Complexity: O(3^n) where n is the top where the frog has to reach
// as at every step we have 3 possiblities, which is
// either take 1, 2 or 3 steps.
