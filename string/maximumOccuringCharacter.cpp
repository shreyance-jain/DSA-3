/* 
Maximum Occuring Character

Problem Statement

Given a string str. The task is to find the maximum occurring character in the string str.
If more than one character occurs maximum number of time then print the lexicographically smaller character.

Input:
The first line of input contains an integer T denoting the number of test cases.
Each test case consist of a string in 'lowercase' only in a separate line.

Output:
For each testcase, in a new line, print the lexicographically smaller character
which occurred the maximum number of time.

Constraints:
1 ≤ T ≤ 30
1 ≤ |s| ≤ 100

Example:
Input:
2
testsample
output

Output:
e
t

Explanation:
Testcase 1: e is the character which is having highest frequency.
Testcase 2: t and u are the characters with the same frequency, but t is lexicographically smaller.
 */

#include<bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(char*);

int main()
{
   
    char str[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%s",str);
        cout<< getMaxOccuringChar(str)<<endl;
    }
}

char getMaxOccuringChar(char* str)
{
    // only lowercase characters so alphabet size reduces to 26
    int hash[26] = {0};

    // traverse the string and store count of every character in hash
    for(int i = 0; str[i] != '\0'; i++)
        hash[str[i] - 'a']++;

    // get the index of max occuring character
    int max_index = 0;
    for(int i = 0; i < 26; i++) {
        // if max count of two characters is same lexicograhically smaller will be picked
        if(hash[i] > hash[max_index])
            max_index = i;
    }
    // add the index to small a character and return
    return 'a' + max_index;
}

// Time Complexity: O(n + alphabet_size)
// Aux Space: O(alphabet_size)