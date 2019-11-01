/* 
Naive Pattern Search

Problem Statement

Given a string S and a pattern P both of lowercase characters.
The task is to check if the given pattern exists in the given string or not.

Input:
First line of input contains number of testcases T.
For each testcase, first line will the string and second line will be the pattern to be searched.

Output:
For each testcase, print "Yes" if pattern exists or "No" if doesn't.

Constraints:
1 <= T <= 100
1 <= |S|, |P| <= 103

Example:
Input:
2
aabaacaadaabaaabaa
aaba
aabaacaadaabaaabaa
ccda

Output:
Yes
No

Explanation:
Testcase 1: Given pattern aaba is found in the string at index 0.
Testcase 2: Given pattern ccda doesn't exists in the string at all.
 */

// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 

bool search(string pat, string txt) ;

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
Simply apply brute force to search for a pattern
Start from a window of size equal to size of pattern
If we are getting characters matched with the window in the string then we continue for next character
else break and start checking for window sliced one to right
In this way we will iterate till the whole string is exhausted
*/

/*  Function to serach pattern in the given string
*   pat: pattern given in input
*   txt: string given in the input
*/
bool search(string pat, string txt) 
{ 
	int n = txt.length(), m = pat.length();

    // loop to slide pattern one by one
	for(int i = 0; i <= n - m; i++) {
        int j;

        // for current index i, check for pattern match
	    for(j = 0; j < m; j++)
	        if(txt[i+j] != pat[j])
	           break;

	    if(j == m) // if pat[0...M] = txt[i, i+1, .... i + M-1]
	        return true;
	}
	return false;
}

// Time Complexity: If n is length of text and m is lenght of pattern, then complexity of naive algorithm wiil be
// O((n - m + 1) * m)
// the outer loop will run n-(m + 1) times and inner loop complexity is O(m)