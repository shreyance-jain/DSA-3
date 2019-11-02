/* 
Binary String

Problem Statement

Given a binary string S. The task is to count the number of substrings that start and end with 1.
For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

Input:
The first line of input contains an integer T denoting the number of test cases.
Each test case consist of an integer 'N' denoting the string length and next line is followed by a binary string.

Output:
For each testcase, in a new line, print the number of substring starting and ending with 1 in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |S| ≤ 104

Example:
Input:
2
4
1111
5
01101

Output:
6
3

Example:
Testcase 1: There are 6 substrings from the given string. They are 11, 11, 11, 111, 111, 1111.
Testcase 2: There 3 substrings from the given string. They are 11, 101, 1101.
 */

#include<bits/stdc++.h>
using namespace std;

long binarySubstring(int n, string a);

// driver code
int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        
        cout << binarySubstring(n, a) << endl;
    }
}


/* A brute force naive solution can be to run two loops
if we encounter 1 in outer loop run a inner loop from i+1 to n-1 to check how many such strings are possible
Time complexity of this solution will be O(n^2)

A O(n) single traversal solution can be:
traverse the string from the right end
after the 1st one which is encountered if one more 1 is encounterd than 1 such string is possible
if another 1 is encountered than 2 more such strings are possible 1 more than 3 more and so on, we keep on adding
them to res and start the counter variable by -1 so to ignore the 1st one as no such strings are possible from
single one */
long binarySubstring(int n, string a){
    long count = -1;
    long res = 0;
    for(int i = n-1; i >= 0; i--) {
        if (a[i] == '1') {
            count++;
            res = res + count;
        }
    }
    return res;
}

// Time Complexity: O(n) single traversal
// Aux Space: O(1)
// Company tags: Amazon