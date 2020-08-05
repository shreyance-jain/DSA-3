/* 

Longest Common Subsequence

Difficulty: Medium
Problem Statement

Given two sequences, find the length of longest subsequence 
present in both of them. 
Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B 
denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of the longest 
common subsequence of the two strings.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC
Output:
3
2
Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2.
 */

// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// DP Tabluation(Bottom Up) based solution
int lcs(int x, int y, string s1, string s2){
    int dp[x+1][y+1];
    // base cases of recursion, when m == 0 || n == 0 return 0
    // as lenght of lcs of an empty string with any string is 0
    for(int i = 0; i <= x; i++)
        dp[i][0] = 0;
    for(int j = 0; j <= y; j++)
        dp[0][j] = 0;
    
    // fill the table left to right and top to down
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            // if last characters match add 1 and go the diagnol
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else // if last characters do not match take max of left and upper value
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[x][y];
}

// Time Complexity : O(|str1|*|str2|)
// Auxiliary Space: O(|str1|*|str2|)

// Company Tags: Amazon, Citrix, MakeMyTrip, Paytm, VMWare 
