/* 
Non Repeating Character

Problem Statement

Given a string S consisting of lowercase Latin Letters. Find the first non-repeating character in S.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each testcase contains the string S.

Output:
For each testcase, print the first non repeating character present in string.
Print -1 if there is no non repeating character.

Your Task:
This is a function problem. You only need to complete the function nonrepeatingCharacter()
that takes string S as parameter and returns the character.
If there is no non repeating character then return '$' .
The driver code automatically appends a new line after function call.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input :
3
hello
zxvczbtxyzvy
xxyyzz

Output :
h
c
-1

Explanation:
Testcase 1: In the given string, first character which is non-repeating is h, as it appars first and there is no other 'h' in the string. 
 */
#include <bits/stdc++.h>
using namespace std;

char nonrepeatingCharacter(string S);

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    
        char ans = nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

/*
Naive Solution will be traverse the input string and store the count of each character
and then again traverse the input string and check if count is 1 return that character

A good logical/trickier O(n) single traversal solution of input string is:
Traverse the input string mark the presence of character by storing its index in an array
If a character is occured twice mark its presence by another negative numbers
Now all the negatives numbers represent either more than one presence or no presence
Traverse through the count array and among all non-negative values which represent the index
of character in input string
track the least index
and return its corresponding charcater from input string
 */

char nonrepeatingCharacter(string S)
{
    int res = INT_MAX;
    int n = S.length();
    
    int count[256];
    memset(count, -1, sizeof(count));
    
    for(int i = 0; i < n; i++) {
        // if character occurs first time store its index
        if(count[S[i]] == -1)
            count[S[i]] = i;
        else
        // if character occurs again don't unset it -1 because if it appears third time it would become a candidate and
        // we want to avoid that so we mark the second occurence with some other negative value here -2
            count[S[i]] = -2;
    }
    
    // traverse the count array, all the characters that occured once will be identified by non negative count array
    // value equal to thier index in input string, get the min index among these index to identify first such element
    for(int i = 0; i < 256; i++)
        if (count[i] > -1)
            res = min(res, count[i]);
            
    if (res == INT_MAX)
        return '$';
    return S[res];
}

// Time Complexity: O(n) Single Traversal where n is the number of characters in input string
// Aux Space: O(alphabet_size)
// Company tags: Amazon, D-E Shaw, Goldman Sachs, InfoEdge, MakeMyTrip, MAQ Software, OATS Systems,
// Ola cabs, Payu, Tejas Networks, Teradata