/* 
Remove common characters and concatenate

Problem Statement

Given two strings s1 and s2.
Modify string s1 such that all the common characters of s1 and s2 is to be removed and
the uncommon characters of s1 and s2 is to be concatenated.

Note: If no modification is possible print -1.

Input:
The first line consists of an integer T i.e number of test cases.
The first line of each test case consists of a string s1.The next line consists of a string s2. 

Output:
Print the concatenated string.

Constraints: 
1 <= T <= 200
1 <= |Length of Strings| <= 104

Example:
Input:
2
aacdb
gafd
abcs
cxzca

Output:
cbgf
bsxz

Explanation:
Testcase 1:
The common characters of s1 and s2 are: a, d.
The uncommon characters of s1 and s2 are: c, b, g and f. Thus the modified string with uncommon characters concatenated is: cbgf
 */

// C++ program to find concatenated string with uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 

string concatenatedString(string, string);

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	string res = concatenatedString(s1, s2);
    	
    	if(res.length() >= 1) cout << res << endl;
    	else cout << "-1" << endl;
	
	}
	return 0; 
}

// utitity function to print a map in C++
void printMap(unordered_map<char, int> m) {
    unordered_map<char, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
        cout << "(" << it->first << ", " << it->second << ")" << endl;
}

/* 
Approach is very simple:
The idea is to use hashmap where key is character and value is number of strings in which
character is present. 
If character is present in one string, then count is 1, else if character is 
present in both strings, count is 2

Algo:
1. Initialise result as empty string
2. Push all characters of 2nd string in map with count as 1
3. Traverse the first string and append all those characters to result which are not present in map.
Characters that are present in map, make count 2
4. Traverse the second string and append all those characters to result whose count is 1
 */
string concatenatedString(string s1, string s2) 
{ 
    // map to store character and count in how many string this character is present    
    unordered_map<char, int> m;
    
    // output string
    string output = "";
    
    // store all characters of s2 in map
    for(long i = 0; i < s2.length(); i++)
        m[s2[i]] = 1;
        
    // find characters of s1 that are not present in s2 and append to result
    for(long i = 0; i < s1.length(); i++) {
        if(m.find(s1[i]) == m.end())
            output += s1[i];
        else
            m[s1[i]] = 2;
    }

    // find characters of s2 that are not present in s2
    for(long i = 0; i < s2.length(); i++) {
        if (m[s2[i]] == 1)
            output += s2[i];
    }
    return output;
}

// Time Complexity: O(n + m), where n and m are no of characters in s1 and s2 resp.
// Company tags: Microsoft