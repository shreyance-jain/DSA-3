/* 
Egg Dropping Puzzle

Difficulty: Medium

Problem Statement

Suppose you have N eggs and you want to determine from which floor in a K-floor 
building you can drop an egg such that it doesn't break. 
You have to determine the minimum number of attempts you need in order 
find the critical floor in the worst case while using the best strategy.
There are few rules given below. 

- An egg that survives a fall can be used again.
- A broken egg must be discarded.
- The effect of a fall is the same for all eggs.
- If the egg doesn't break at a certain floor, it will not break at any floor below.
- If the eggs breaks at a certain floor, it will break at any floor above.

For more description on this problem see wiki page

Example 1:

Input:
N = 2, K = 10
Output: 4

Example 2:

Input:
N = 3, K = 5
Output: 3

Expected Time Complexity : O(N*K)
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=10
1<=K<=50
 */

#include<bits/stdc++.h>
using namespace std;

int eggDrop(int n, int k) ;

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}

/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
/* For details explanation see Notes,  */
int eggDrop(int e, int f) 
{
    // base case: 1. egg =1 , trials = f
    // 2. f = 1, trial = 1
    // 3. f = 0, trial = 0
    int dp[f+1][e+1];
    
    // f = 0, trial = 0, f = 1, trial = 1
    for(int i = 1; i <= e; i++) {
        dp[0][i] = 0; dp[1][i] = 1;   
    }
    // egg = 1, trials = f
    for(int i = 0; i <= f; i++)
        dp[i][1] = i;
    
    for(int i = 2; i <= f; i++){
        for(int j = 2; j <= e; j++) {
            dp[i][j] = INT_MAX;
            for(int x = 1; x <= i; x++) {
                dp[i][j] = min(dp[i][j], 1 + max(dp[x-1][j-1], dp[i-x][j]));
            }
        }
    }
    return dp[f][e];
}


// Time Complexity : O((f^2)*e)
// Auxiliary Space: O(f*e)

// Tags: Medium
// Company Tags: Amazon, DE-Shaw, Goldman Sachs, Google, Hike, MakeMyTrip,
// MAQ Software, Myntra, nearbuy, Opera, Oracle, Philips, Samsung, Service Now,
// Unisys, VMWare
