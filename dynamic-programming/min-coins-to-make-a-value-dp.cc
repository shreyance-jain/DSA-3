/* 

Coin Change - Minimum number of coins

Difficulty: Easy
Problem Statement

You are given an amount denoted by value. 
You are also given an array of coins. 
The array contains the denominations of the give coins. 
You need to find the minimum number of coins to 
make the change for value using the coins of given denominations. 
Also, keep in mind that you have infinite supply of the coins.
If making the change is not possible then print "Not Possible"

Input Format:
The first line of input contains number of testcases. 
Number of testcases follow. 
Each testcase contains three line of input. 
The first line contains value for which you need to make the change. 
The second line contains size of the array. 
The third line contains the denominations of the coins.

Output Format:
For each testcase, in a new line, print the minimum number of coins required.

Expected Time Complexity: O(N*V).
Expected Auxiliary Space: O(V)

Constraints:
1 <= T <= 100
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000

Example:
Input:
2
5
3
3 6 3
10
4
2 5 3 6
Output:
Not Possible
2

Explanation:
Testcase1: We need to make the change for value = 5
The denominations are {3,6,3}
It is certain that we cannot make 5 using any of these coins.
Testcase2: We need to make the change for value = 10
The denominations are {2,5,3,6}
We can use two 5 coins to make 10. So minimum coins are 2.
 */

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value);

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
	    
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}

long long minimumNumberOfCoins(int coins[],int numberOfCoins, int value)
{
    // we will make 1D array as only one parameter value changes
    // dp[i] will indicate the min no of coins required to get value i
    long long dp[value+1];
    dp[0] = 0;
    // i is denoting value
    for(int i = 1; i <= value; i++) {
        dp[i] = INT_MAX;
        // consider every coin, to get min coins to get value i
        for(int j = 0; j < numberOfCoins; j++) {
            if (coins[j] <= i) {
                long long sub_res = dp[i-coins[j]];
                if (sub_res != INT_MAX)
                    dp[i] = min(dp[i], sub_res+1);
            }
        }
    }
    if (dp[value] == INT_MAX)
     return -1;
    return dp[value];
}

// Time Complexity: O(N*V)
// Auxiliary Space: O(V)
// Here N-> Number of Coins, V-> Value to make

// Company Tags: Amazon
