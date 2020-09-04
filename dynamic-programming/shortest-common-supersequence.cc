/* 
Shortest Common Supersequence

Difficulty: Easy

Problem Statement

Given two strings X and Y of lengths m and n respectively, 
find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.

Example 2

Input:
X = efgh, Y = jghi
Output: 6
Explanation: Shortest Common Supersequence
would be ejfghi which is of length 6 and
has both the strings as its subsequences.

Expected Time Complexity: O(Length(X) * Length(Y)).
Expected Auxiliary Space: O(Length(X) * Length(Y)).

Constraints:
1<= |X|, |Y| <= 100s
 */

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* , char*, int, int );

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

/*
Approach: Find the Longest Common Subsequence of the both the strings
Say the length of LCS of s1 and s2 is x
So the required lenght of the Shortest Common Subsequence will be =
Lenght of LCS + extra characters of s1 + extra characters of s2
*/
int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    // DP code of LCS
    int dp[m+1][n+1];
    
    for(int i = 0; i <= m; i++)
        dp[i][0] = 0;
    
    for(int j = 0; j <= n; j++)
        dp[0][j] = 0;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // Required ans: Length of LCS + remaining characters of s1 and remaining characters of s2
    return dp[m][n] + abs(dp[m][n] - m) + abs(dp[m][n] - n);
}

// Time Complexity: O(Length(s1) * Length(s2))
// Auxiliary Space: O(Length(s2) * Length(s1))

// Tags: Easy
// Company Tags: Microsoft
