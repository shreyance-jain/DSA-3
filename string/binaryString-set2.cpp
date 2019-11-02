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


/* A simple algorithm can be obtained if we look at this problem
from mathematics point of view
We count the number of ones in the stirng
now number of such string that start and end with one will be obtained by
 mC2 where m is number of ones, mC2 = m!/((m-2)! * 2!) which is m*(m-1)/2*/
long binarySubstring(int n, string a){
    long m = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] == '1')
            m++;
    }
    return m*(m-1)/2;
}

// Time Complexity: O(n) single traversal
// Aux Space: O(1)
// Company tags: Amazon