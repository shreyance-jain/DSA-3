/* 
Rabin Karp - Pattern Searching

Problem Statement

Given a string S and a pattern P of lowercase characters.
The task is to check if pattern is present in string or not.

Input Format:
First line of input contains number of testcases T.
For each testcase, first line of input contains string S and next line contains pattern P.

Output Format:
For each testcase, print "Yes" if pattern is found in the string else print "No".

Constraints:
1 <= T <= 100
1 <= |S|, |P| <= 103

Example:
Input:
2
aabaacaadaabaaba
aaba
aabaacaadaabaaba
asdfa

Output:
Yes
No

Explanation:
Testcase 1: You can find the patter at starting at index 12.
Testcase 2: Pattern doesn't exists in the given string S.
 */

/* Following program is a C implementation of 
Rabin Karp. Algorithm given in the CLRS book */

#include<bits/stdc++.h>
using namespace std;
bool search(string, string, int);


/* Driver program to test above function */
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
	    string s, p;
	    cin >> s >> p;
	    int q = 101; // A prime number 
	    if(search(p, s, q)) cout << "Yes" << endl;
	    else cout << "No" << endl;
    }
	return 0; 
} 

/* 
The naive pattern matching algorihtm slides the pattern one by one.
After each slide, it one by one checks characters at current shift and if all characters match the prints the match
Like the Naive Algorithm, Rabin-Karp algorithm also slides the pattern one by one. But unlike Naive Algorithm
Rabin karp algorihtm matches the hash value of the pattern with the hash value of current substring of text,
and if the hash value matches then only is start matching individual characters
So Rabin Karp needs to calculate hash values for following string:
1. Pattern itself
2. All substring of text of lenght m

This is simple mathematics, we compute decimal value of current window from previous window.
For example pattern length is 3 and string is “23456”
You compute the value of first window (which is “234”) as 234.
How how will you compute value of next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.

 */
// d is the number of characters in the input alphabet 
#define d 256 // like base
/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
bool search(string pat, string txt, int q) 
{ 
	int M = pat.length();
	int N = txt.length();
	int p = 0; // hash of pattern
	int t = 0; // hash of current window of text
	int h = 1;
	
	// The value of h would be pow(d, M-1)%q
	for(int i = 0; i < M -1; i++)
	    h = (h * d)%q;
	    
	// calculate hash of pattern and first window of text
	for(int i = 0; i < M; i++) {
	    t = (t*d + txt[i]) % q;
	    p = (p*d + pat[i]) % q;
	}
	
	// slide pattern over text one by one
	for(int i = 0; i <= N-M; i++) {
	    // check the hash value of current window of text and pattern. If the hash value match
        // then only check for characters one by one
	    if (p == t) {
	        int j;
            // check for characters one by one
	        for(j = 0; j < M; j++) {
	            if (txt[i+j] != pat[j])
	                break;
	        }
            // if p == t and pat[0...M-1] = txt[i...i+M-1]
	        if (j == M)
	                return true;
	    }
	    // calculate hash value for next window of text: Remove leading digit, add trailing digit
	    if (i < N-M) {
	        t = (d*(t - txt[i]*h) + txt[i+M]) % q;
            // we might negative value of t because of modulo operation, converting it to positive
	        if (t < 0)
	           t = t + q;
	    }
	}
	return false;
} 
// Time Complexity: O(n + m) in average and best case, but
// O((n - m + 1) * m) in worst case , worst case occurs when all substring of text matches with pattern
// for example, consider case: txt: "AAAAAAA", pat: "AAA"
// it performs ever worse than Naive because it calculates hash for every substring which is overhead cost
// and the character matching one by one