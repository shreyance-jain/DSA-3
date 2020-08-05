/* 
Fibonacci Numbers - Bottom Up DP

Difficulty: Easy

Problem Statement

One of the rudimentary problems to understand DP is finding the nth Fibonacci number.
Here, we will solve the problem using a bottom-up approach.
You are given a number N.
You need to find the Nth Fibonacci number.

Input Format:
The first line of input contains test cases number. 
Each test case contains the number N.

Output Format:
For each test case, in a new line, print the Nth Fibonacci number.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

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
using namespace std;

long long findNthFibonacci(int number);

int main()
{

    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int number;
        cin >> number;
        cout << findNthFibonacci(number) << endl;
    }
    return 0;
}

// Return the n-th Fibonacci
long long findNthFibonacci(int n)
{
    long long fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}

// Note: In Tabulation we simply eliminate recursion
// Time Complexity: Theta(n)
// Aux Space Complexity: Theta(n)
