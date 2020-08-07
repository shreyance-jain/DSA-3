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
// } Driver Code Ends


// TOP DOWN APPROACH

int sol(int x, int y, string s1, string s2, vector<vector<int>> &memo) {
    if (memo[x][y] != -1) return memo[x][y];
    if (x == 0 || y == 0) memo[x][y] = 0;
    else {
        if (s1[x-1] == s2[y-1])
            memo[x][y] = 1+sol(x-1, y-1, s1, s2, memo);
        else 
            memo[x][y] = max(sol(x-1, y, s1, s2, memo), sol(x, y-1, s1, s2, memo));
    }
    return memo[x][y];
}

int lcs(int x, int y, string s1, string s2){
    vector<vector<int>> memo(x+1);
    for(int i = 0; i <= x; i++)
        memo[i] = vector<int>(y+1);
    
    for(int i = 0; i <= x; i++)
        for(int j = 0; j <= y; j++)
            memo[i][j] = -1;
    
    return sol(x, y, s1, s2, memo);
}

/* 
Time Complexity: We have a 2D array of size m+1 and n+1 
(where m and are the length of the first and the second string)
and every entry is going to be filled exactly once and time taken
to fill an entry is constant as we do a comparison and a addition
so, Time Complexity: Theta(m*n)
and, Aux Space Complexity: Theta(m*n)
 */