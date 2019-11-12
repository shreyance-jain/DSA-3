/* 
Isomorphic Strings (all occureneces of every character of 'str1' map to same character is 'str2')

Problem Statement

Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic,
if there is a one to one mapping possible for every character of str1 to every character of str2
while preserving the order.

Input:
The first line contains an integer T, depicting total number of test cases.
Each test case contains two strings each in new line.

Output:
Print "1" if strings are isomorphic and "0" if not.

Constraints:
1 <= T <= 100
1 <= Length of Strings <= 103

Example:
Input:
2
aab
xxy
aab
xyz

Output:
1
0

Explanation:
Input:  str1 = "aab", str2 = "xxy"
Output: True
'a' is mapped to 'x' and 'b' is mapped to 'y'.

Input:  str1 = "aab", str2 = "xyz"
Output: False
One occurrence of 'a' in str1 has 'x' in str2 and 
other occurrence of 'a' has 'y'.
 */


// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>
using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}

/* 
A simple solution is to consider every character of 'str1' and check if all occurences of it 
map to same character in 'str2', time complexity: O(n^2)

An Efficient solution O(n),
the idea is to create an array to store mappings of processed characters
1. if lengths of str1 and str2 are not same, return false
2. Do following for every character in str1 and str2
  a) If this character is seen first time in str1, then the current character of str2 must not have been appeared before
        (i) If current character of s2 is seen return false
        Mark current character of s2 as visisted
        (ii) Store mapping of current characters
  b) Else check if previous occurence of str[i] is mapped to same characters
 */
bool areIsomorphic(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    // lenght of both strings must be same for one to one correspondence
    if (m != n) 
        return false;
    // to mark visited characters in str2
    bool marked[256] = {false};
    // To store mapping of every character of str1 to that of str2. Initialise all entries of map as -1
    int map[256];
    memset(map, -1, sizeof(map));
    int i = 0;
    // process all characters one by one
    for(int i = 0; i <  n; i++) {
        // if current character is seen first time in str1
        if (map[str1[i]] == -1) {
            // if current character of str2 is already seen then one to one mapping is not possible
            if (marked[str2[i]]) return false;
            // mark character of str2 as visited
            marked[str2[i]] = true;
            // store mapping of current characters
            map[str1[i]] = str2[i];
        }
        // if it is not first appearence of current character in str1, then check if previous occurence
        // mapped to same character of str2
        else if (map[str1[i]] != str2[i]) return false;
    }
    return true;
}

// Time Complexity: O(n)
// Aux Space : O(2 * alphabetSize)
// Company tags: Hike