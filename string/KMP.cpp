/* 
Pattern Search KMP

Problem Statement

Given a string S and a pattern P of all lowercase characters.
The task is to check if the pattern exists in the string or not.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains string S and next line contains pattern P.

Output:
For each testcase, print "Yes" if pattern is found in the string, and "No" if pattern is not found in the string.

Constrsaints:
1 <= T <= 100
1 <= |S|, |P| <= 103

Example:
Input:
2
aabaacaadaabaaba
aaaab
aabaacaadaabaaba
caada

Output:
No
Yes

Explanation:
Testcase 1: Given pattern is found in the given string S.
Testcase 2: Given pattern is found in the given string S.
 */


// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 
using namespace std;

bool KMPSearch(string pat, string txt);

// Driver program to test above function 
int main() 
{ 
    int t;
    std::cin >> t;
    
    while(t--){
        string s, pat;
        cin >> s >> pat;
        if(KMPSearch(pat, s)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    
	return 0;
}

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(string pat, int M, int* lps) 
{ 
    // lenght of previous longest proper prefix which is also suffix
	int len = 0;
	lps[0] = 0; // lps[0] is always 0

    // loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while(i < M) {
	    if (pat[i] == pat[len]) {
	        len++;
	        lps[i] = len;
	        i++;
	    } else { // else if pat[i] != pat[len]
	        if (len != 0) {
	            len = lps[len-1];
                // note we do not incerment i here
	        } else {
	            lps[i] = 0;
	            i++;
	        }
	    }
	}
} 
// Returns true if pat found in txt
bool KMPSearch(string pat, string txt) {
    int N = txt.length();
    int M = pat.length();

    // create lps[] that will hold the longest prefix suffix values of pattern
    int lps[M];
    
    // pre-process the pattern compute the lps array
    computeLPSArray(pat, M, lps);
    
    int i = 0; // index for text[]
    int j = 0; // index for pat[]
    while(i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == M) {
            // cout << "Pattern found at index %d", i-j);
            // j = lps[j-1];
            return true;
        }
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // do not match lps[0...lps[j-1]] characters they will match anyway
            if (j != 0) {
                j = lps[j-1];
            } else {
                i = i+1;
            }
        }
    }
    return false;
}

// Time Complexity: KMP algo uses degenrating property of pattern and imporves worst case complexity to O(n)
/* 
 txt[] = "AAAAAAAAAAAAAAAAAB"
   pat[] = "AAAAB"

   txt[] = "ABABABCABABABCABABABC"
   pat[] =  "ABABAC" (not a worst case, but a bad case for Naive)
 */
// Company Tags: Amazon, Facebook, Microsoft, Qualcomm