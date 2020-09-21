/* 
Ways to write n as sum

Given a positive integer N, the task is to find the number of different ways 
in which N can be written as a sum of two or more positive integers.

Example 1:

Input:
N = 5
Output: 6
Explanation: 
1+1+1+1+1
1+1+1+2
1+1+3
1+4
2+1+2
2+3
So, a total of 6 ways.

Example 2:

Input:
N = 3
Output: 2

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)
 */

// { Driver Code Starts
#include<bits/stdc++.h>


using namespace std;

int countWays(int);

// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        cout<<countWays(n)<<endl;
    }
    return 0;
}// } Driver Code Ends


int mod = 1000000007;


// Same dp function as Coin Change Problem
int count(int coins[], int numberOfCoins, int value) {
    int dp[value+1][numberOfCoins+1];
    
    for(int j = 0; j <= numberOfCoins; j++)
        dp[0][j] = 1;
    
    for(int i = 1; i <= value; i++)
        dp[i][0] = 0;
        
    for(int i = 1; i <= value; i++) {
        for(int j = 1; j <= numberOfCoins; j++) {
            dp[i][j] = dp[i][j-1] % mod;
            if (coins[j-1] <= i)
                dp[i][j] += (dp[i-coins[j-1]][j]) % mod;
        }
    }
    return dp[value][numberOfCoins];
}

/* 
Approach: Convert the problem into Coin Change Problem
Coin Change Problem: Find the number of ways to use the coins to sum up to a give value

So here, we construct the coins array by inserting values from 1 to n-1 (as we need 2 values, so
not inserting 1)
Now, problem reduces to find number of ways to make value n, with this array of items from 1 to n-1
 */
int countWays(int n)
{
    // normal way to consider it as a coin change problem
    // create a coins array and pass it in to same function
    int coins[n-1];
    for(int i = 1; i < n; i++)
        coins[i-1] = i;
    return count(coins, n-1, n);
}

// Tags: Easy
// Time Complexity: O(n^2)
// Space Complexity: O(n), requries two arrays of size n, one dp[] and one coins[]

// Note: see optimised solution in set-2
