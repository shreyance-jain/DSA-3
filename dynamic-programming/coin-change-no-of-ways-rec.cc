/* 

Coin Change - Number of ways

Difficulty: Easy

Problem Statement

You have an infinite supply of coins, each having some value. 
Find out the number of ways to use the coins to sum-up to a certain required value.

Example 1:

Input:
value = 4
numberOfCoins = 3
coins[] = {1,2,3}
Output: 4
Explanation: We need to make the change
for value = 4. The denominations are
{1,2,3} Change for 4 can be made:
1+1+1+1
1+1+2
1+3
2+2
So, as it is evident, we can do this in
4 ways.

Example 2:

Input:
value = 10
numberOfCoins = 4
coins[] = {2,5,3,6}
Output: 5

Expected Time Complexity: O(Number of Coins * Value).
Expected Auxiliary Space: O(Value).

Constraints:
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000
 */

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

long long numberOfWays(int coins[],int numberOfCoins,int value);


int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int value;
	    cin>>value;
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    cout<<numberOfWays(coins,numberOfCoins,value)<<endl;
	    
	}
	return 0;
}

long long numberOfWays(int coins[],int numberOfCoins,int value)
{
    if (value == 0) return 1;
    if (numberOfCoins == 0) return 0;
    // For every coin we have 2 choices: either we ignore it or pick it

    // Case when we ignore the last coin
    long long res = numberOfWays(coins, numberOfCoins - 1, value);

    // Case when we pick the last coin,
    // first we check if we can pick the last coin or not
    if (coins[numberOfCoins -1 ] <= value)
    // here we reduce the value by the coin's value which is picked and the numberOfCoins remain
    // same as we can again pick this coin since we have infinite supply
        res += numberOfWays(coins, numberOfCoins, value - coins[numberOfCoins - 1]);
    
    return res;
}

// Time Complexity: Exponential: if there are n coins, it will be O(2^n)
