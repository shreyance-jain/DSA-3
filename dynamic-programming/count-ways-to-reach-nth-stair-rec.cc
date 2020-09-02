/* 
Count ways to reach the n'th stair

Difficulty: Medium

Problem Statement

There are N stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top (order does matter).

Example 1:

Input:
N = 4
Output: 5
Explanation: You can reach 4th stair in
5 ways.

Example 2:

Input:
N = 10
Output: 89

Your Task:
Complete the function countWays() which takes the top stair number m as input parameters and returns the answer % 10^9+7.

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
 */

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long countWays(int);

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        
        cout<<countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}


// Recursive function to count ways to reach mth stair
long long countWays(int m){
    // 1st base case, when m = 0, we have 1 way which is do not take any step
    // 2nd base case, when m = 1, we have 1 way which is to take 1 step
    if (m == 0 || m == 1)
        return 1;
    
    // from every floor we have 2 possibilities: either take 1 step
    // or take 2 step
    // Note: m will never become negative, because when m becomes less than 2
    // it will fall in the base case
    long long res = countWays(m-1) + countWays(m-2);
    return res;
}

// Time Complexity: Exponential:O(2^m), where m is no of floors, 
// as for every floor we have two possibilities, which is
// either take one step or take 2 steps
