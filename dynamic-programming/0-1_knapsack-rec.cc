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
Approach: The idea is to consider 2 possiblities for every item
either inlcude it or not include it in the result
We also need to take care of the case when the weight of the item
is more than the capacity of the knapsack
And handle the base cases as well,
So the approach is to consider all the subsets of the given items
and pick the max value of the subsets whose weights are less than W
 */
int knapSack(int W, int wt[], int val[], int n) 
{ 
    if (n == 0 || W == 0) return 0;
    if (wt[n-1] > W)
        return knapSack(W, wt, val, n-1);
    else {
        return max (knapSack(W, wt, val, n-1),
        val[n-1] + knapSack(W - wt[n-1], wt, val, n-1));
    }
}

// Time Complexity: O(2^n) T(n) = 2T(n-1) + Theta(1)
