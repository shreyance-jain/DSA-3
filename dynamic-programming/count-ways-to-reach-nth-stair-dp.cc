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


// Function to count ways to reach mth stair
long long countWays(int m){
    // if (m == 0 || m == 1)
    //     return 1;
    // long long res = countWays(m-1) + countWays(m-2);
    // return res;
    
    // same concept as fibonacci, above is the recursive code
    long long prev_prev = 1; // let say m-2
    long long prev = 1;       // say m-1
    long long res = prev;
    for(int i = 2; i <= m; i++) {
        res = (prev + prev_prev) % mod; // m-1 + m-2
        prev_prev = prev;
        prev = res;
    }
    return res;
}

// Time Complexity: O(N), where N is the number of floors
// Space Complexity: O(1)

// Company Tags: Amazon, OYO Rooms
