/* 
Unique BST's

Difficulty: Medium

Problem Statement

Given an integer. Find how many structurally unique binary search trees are there 
that stores the values from 1 to that integer (inclusive). 

Example 1:

Input:
N = 2
Output: 2
Explanation:for N = 2, there are 2 unique
BSTs
     1               2  
      \            /
       2         1

Example 2:

Input:
N = 3
Output: 5
Explanation: for N = 3, there are 5
possible BSTs
  1           3     3       2     1
    \        /     /      /  \     \
     3      2     1      1    3     2
    /      /       \                 \
   2      1         2                 3

 
Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N).

Constraints:
1<=N<=1000
 */

#include<bits/stdc++.h>
using namespace std;
#define modulo 1000000007

int numTrees(int N);

int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        
        //calling function numTrees()
        cout<<numTrees(n)<<"\n";
    }
}

int numTrees(int N) {
    int dp[N+1];
    dp[0] = dp [1] = 1;
    for(int i = 2; i <= N; i++) {
        dp[i] = 0;
        for(int j = 0; j < i; j++) {
            dp[i] = (dp[i] + (1LL*dp[j]*dp[i-j-1])%modulo)%modulo;
        }
    }
    return dp[N];
}

// Time Complexity: O(N^2)
// Auxiliary Space: O(N)

// Company Tags: Amazon, Samsung, Twitter
