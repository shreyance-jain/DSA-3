/* 

Fibonacci Numbers - Top Down DP

Difficulty: Easy
Problem Statement

One of the rudimentary problems to understand DP is finding the nth Fibonacci number. 
Here, we will solve the problem using the top-down approach.

You are given a number N. 
You need to find Nth Fibonacci number.

Input Format:
The first line of input contains test cases number. 
Each testcase contains the number N.

Output Format:
For each testcase, in a new line, print the Nth Fibonacci number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Note: This space is used by dp array.

Constraints:
1 <= testcases <= 100
1 <= number <= 92

Examples:
Input:
2
5
7
Output:
5
13
Explanation:
Some of the numbers of the Fibonacci numbers are 1, 1, 2, 3, 5, 8, 13 ..... (N stars from 1).
*/

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

long long findNthFibonacci(int number, long long int dp[]);

int main()
 {
    long long dp[100]={0};
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        int number;
        cin>>number;
        cout<<findNthFibonacci(number, dp)<<endl;
    }
    
	return 0;
}

long long findNthFibonacci(int n, long long int dp[])
{
    /* Simple recursive solution
    if (n == 0 || n == 1)
         return n;
    return findNthFibonacci(n-1) + findNthFibonacci(n-2);
    (Simple recursive solution to memoisation, it is
    very simple to convert recursive to memoisation,
    instead of returning immediately, 
    store the solution in memo array or table)
     */
    if (dp[n] == 0  && n != 0) {
        dp[n] = findNthFibonacci(n-1, dp) + findNthFibonacci(n-2, dp);
    }
    return dp[n];
}

// Time Complexity: O(N).
// Auxiliary Space: O(N). Note: This space is used by dp array
