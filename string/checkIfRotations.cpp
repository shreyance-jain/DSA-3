/* 
Check if strings are rotations of each other or not

Problems

Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1.
The characters in the strings are in lowercase.

Input:
The first line of the input contains a single integer T, denoting the number of test cases.
Then T test case follows. Each testcase contains two lines for s1 and s2.

Output:
For each testcase, in a new line, print "1" if s2 is a rotated version of s1 else print "0".

Constraints:
1 <= T <= 103
1 <= |s1|, |s2| <= 107

Example:
Input:
4
geeksforgeeks
forgeeksgeeks
mightandmagic
andmagicmigth
mushroomkingdom
itsamemario
geekofgeeks
geeksgeekof

Output:
1
0
0
1

Explanation:
Testcase 1: s1 is geeksforgeeks, s2 is forgeeksgeeks. Clearly, s2 is a rotated version of s1 as s2 can be obtained by left-rotating s1 by 5 units.
 */
#include <bits/stdc++.h>
using namespace std;

bool areRotations(string, string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        cout<<areRotations(s1,s2)<<endl;
    }
    return 0;
}

/* 
Here is a very intersting logic to solve this problem in linear time
To check if two strings are rotations we concate one string with itself
and find the other string in the concatenated string
If yes they are rotations else not
 */
bool areRotations(string s1,string s2)
{
    // if lengths are not equal return false
    if (s1.length() != s2.length())
        return false;
    s1 = s1 + s1;
    int index = s1.find(s2);
    if (index != string::npos)
        return 1;
    return 0;
}

// Time complexity: O(n) assusming string matching algorithm is KMP
// Company tags: Adobe