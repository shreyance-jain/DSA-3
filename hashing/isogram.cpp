/* 
Check if a string is Isogram or not
      
Problem Statement
Given a string S of lowercase aplhabets, check if it is isogram or not.
An Isogram is a string in which no letter occurs more than once.

Input Format:
The first line of input contains an integer T denoting the number of test cases. T testcases follow.
Each test case consist of one string in 'lowercase' only, in a separate line.

Output Format:
For each testcase, in a new line, Print 1 if string is Isogram else print 0.

Constraints:
1 <= T <= 100
1 <= |S| <= 103

Example:
Input:
2
machine
geeks
Output:
1
0

Explanation:
Testcase 2: geeks is not an isogram as 'e' appears twice. Hence we print 0.
 */

//#include<bits/stdc++.h>
#include <iostream>
using namespace std;

bool isIsogram(string s);

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        
        cout<<isIsogram(s)<<endl;
        
    }
	return 0;
}
/* 
Approach: Use a hash array of size 26 to store the count of characters

 */
bool isIsogram(string s)
{
  /* initialise an array of size 26 which will be used a direct addressing
  since the input is in small range, otherwise we prefer hashing over direct addressing
  if the input is not in a small range */
    int hash[26] = {0};

    // increment the count in hash
    for(int i = 0; i < s.length(); i++) {
        hash[s[i] - 'a']++;
        
        if(hash[s[i] - 'a'] > 1)
            return false;
    }

    return true;
}