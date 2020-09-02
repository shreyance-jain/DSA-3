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
    // 2 parameters were changing in recursive call: Value & Number of coins
    long long dp[value+1][numberOfCoins+1];
    
    // when Value to be picked is 0, there is always one way
    // do not pick any coin
    for(int j = 0; j <= numberOfCoins; j++)
        dp[0][j] = 1;
    
    // When Number of Coins are 0 and value to be picked is greater than 0
    // then 0 ways possible
    for(int i = 1; i <= value; i++)
        dp[i][0] = 0;
    
    // follow the same recursion
    for(int i = 1; i <= value; i++)
        for(int j = 1; j <= numberOfCoins; j++) {
            // case when don't include to last coin
            dp[i][j] = dp[i][j-1];
            // case when include the last coin
            if (coins[j-1] <= i)
                dp[i][j] += dp[i-coins[j-1]][j];
        }
    
    return dp[value][numberOfCoins];
}

/* Why (sum+1) x (n+1) and not (n+1) x (sum+1)?
It will not work, we will get more value in the result
because for a sum you are not going through all coins but for a
coin you are going through all the sum. So we will add same cases
again and again in the result.
 */

// Time Complexity: O(Number Of Coins * Value)
// Space Complexity: O(Number Of Coins * Value)

// Note: There exists a solution where we can solve it in same time
// but in less space = O(Value)