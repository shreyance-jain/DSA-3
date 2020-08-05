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

/* Main recursive function
return INT_MAX if not possible to make the value from given denominations

Approach: Try every coin(coin value should be less than or equal to required
value) and recur for remaining value and take min of all the coins required
Here we are considering sub_res after choosing a coin therefore considering
sub_res + 1 since we choosed a coin

Please note: we only take min when a solution is possible in the code 
we are checking it by if sub_res in not INT_MAX
because taking a solution into consideration which could not get the
required value from the given denominations may result in false results
 */
long long sol(int coins[],int numberOfCoins,int value)
{
    if (value == 0) return 0;
    long long res = INT_MAX;
    for(int i = 0; i < numberOfCoins; i++) {
        if (coins[i] <= value) {
            long long sub_res = sol(coins, numberOfCoins, value-coins[i]);
            if (sub_res != INT_MAX) {
                res = min(res, sub_res+1);
            }
        }
    }
    return res;
}

// wrapper over plain recursion
long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    long long res = sol(coins, numberOfCoins, value);
    if (res == INT_MAX)
        return -1;
    return res;
}
