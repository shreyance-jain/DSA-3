/* 

Longest Increasing Subsequence

Difficulty: Medium
Problem Statement

Given an array of integers, find the length of the longest (strictly) 
increasing subsequence from the given array.

Input:
The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of the array 
and next line followed by the value of array.

Output:
For each testcase, in a new line, print the Max 
length of the subsequence in a separate line.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 10000

Example:
Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1
Output:
6
3
Explanation:
Testcase 1: Longest increasing subsequence : 0 2 6 9 13 15, which has length 6
Testcase 2: Longest increasing subsequence : 5 7 9, with length 3s
 */

#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        cout << longestSubsequence(n, a) << endl;
    }
}

// return length of longest strictly increasing subsequence
int longestSubsequence(int n, int a[])
{
    int dp[n];
    dp[0] = 1;
    // dp[i] represents the max lenght of LIS ending with element at index i
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    // return the max of the lis values
    int res = dp[0];
    for (int i = 1; i < n; i++)
        res = max(res, dp[i]);
    return res;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
