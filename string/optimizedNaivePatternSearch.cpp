/* 
Distinct Pattern Search

Problem Statement

Given a string S and a pattern P (of distinct characters) consisting of lowercase characters.
The task is to check if pattern P exists in the given string S or not.

Note : Pattern has distinct characters. There might be repetitions in text.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains string S and next line contains pattern P.

Output:
For each testcase, print "Yes" if pattern is found in the given string, else print "No".

Constraints:
1 <= T <= 100
1 <= |S|, |P| <= 103

Example:
Input:
2
abceabcdabceabcd
abcd
abceabcdabceabcd
gfhij

Output:
Yes
No

Explanation:
Testcase 1: Given pattern abcd is present at index 4.
Testcase 2: Given pattern gfhij is not found in the string.
 */


// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 

bool search(string pat, string txt);

// Driver Code 
int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    string s, p;
	    cin >> s >> p;
	    if(search(p, s)) cout << "Yes"; else cout << "No"; cout << endl;
	}
	
	return 0; 
}

/* 
In the original Naive String Matching algortihm, we always slide the pattern by 1
When all characters in pattern are different we can slide the pattern more than 1
When a mismatch occurs after j matches,
we know the first character of the pattern will not match the j matched characters
beacuse all characters of pattern are different.
So we can always slide the pattern by j without missing any valid shifts

We skips the matching j times giving linear time complexity
 */

/*  function to search for a pattern with distinct characters
*   pat: pattern(to be searched in txt) given in the input
*   txt: string given in the input
*/
bool search(string pat, string txt) 
{ 
	int n = txt.length(), m = pat.length();
	
	for(int i = 0; i <= n-m; i++) {
	    int j;
	    
	    for(j = 0; j < m; j++)
	        if(txt[i+j] != pat[j])
	            break;
	   
	    if (j == m)
	        return true;
	    if (j == 0)
	        i++;
	    else
	        i = i + j;
	}
	return false;
} 

// Time Complexity: O(n), we skip the matching by j matched characters giving linear time complexity