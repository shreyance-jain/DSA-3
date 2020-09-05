/* 

Stickler Thief

Difficulty: Easy

Problem Statement

Stickler the thief wants to loot money from a society having n houses in a single line.
He is a weird person and follows a certain rule when looting the houses.
According to the rule, he will never loot two consecutive houses. 
At the same time, he wants to maximize the amount he loots. 
The thief knows which house has what amount of money but is unable 
to come up with an optimal looting strategy. 
He asks for your help to find the maximum money he can get if he strictly follows the rule. 
Each house has a[i] amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110

Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4 

Expected Time Complexity: O(N).
Expected Space Complexity: O(N).

Constraints:
1 <= n <= 104
1 <= a[i] <= 104
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll FindMaxSum(ll arr[], ll n);

int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
			
		//calling function FindMaxSum()
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}

/* Please note: In the dp solution for a value of n we only need results of
n-1 and n-2, we can optimise it to work in O(1) like Fibonacci Numbers */
ll FindMaxSum(ll arr[], ll n)
{
    if (n == 1) return arr[0];
    ll prev_prev = arr[0];
    ll prev = max(arr[0], arr[1]);
    ll res = prev;
    for(int i = 3; i <= n; i++) {
        res = max(arr[i-1] + prev_prev, prev);
        prev_prev = prev;
        prev = res;
    }
    return res;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// Tags: Easy
// Company Tags: Amazon, OYO, Paytm, Walmart
