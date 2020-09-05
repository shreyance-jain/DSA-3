/* 
0 - 1 Knapsack Problem

Difficulty: Easy

Problem Statement

You are given weights and values of N items,put these items in a knapsack of
capacity W to get the maximum total value in the knapsack. 
Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] 
which represent values and weights associated with N items respectively. 
Also given an integer W which represents knapsack capacity, 
find out the maximum value subset of val[] such that sum of the weights of 
this subset is smaller than or equal to W. You cannot break an item, 
either pick the complete item, or don’t pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000
 */

#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n);


int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
} 


// Returns the maximum value that  
// can be put in a knapsack of capacity W
/* 
Approach: Two parameters n and W are changing in the recursive solution
so we create a 2D array, range of n -> 0-n
range of W -> 0-W
fill base cases and follow recursion
 */
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int dp[n+1][W+1]; // represents max value that we can collect with first i items and
    // knapsack capacity j
    
    // first column
    for(int i = 0; i <= W; i++) dp[0][i] = 0;
    
    // first row
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    
    // follow recursion
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if (wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
        }
    }
    return dp[n][W];
}

// Time Complexity: O(W*n) Psuedo Polynomial NP Hard Problem

// Tags: Easy
// Company Tags: Amazon, Directi, Flipkart, GreyOrange, Microsoft,
// Mobicip, Morgan Stanley, PayU, Snapdeal, Visa
