/* 
Reverse words in a given string

Problem Statement

Given a String of length S, reverse the whole string without reversing the individual words in it.
Words are separated by dots.

Input:
The first line contains T denoting the number of testcases.
T testcases follow.
Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr

Explanation:
Testcase 1: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i.
 */

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void reverseWords(char*);

/* Driver function to test above functions */
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        reverseWords(s);
        cout<<endl;
    }
}

/* Function to reverse any sequence starting from pointer begin
and ending in pointer end */
void reverse(char *begin, char *end) {
    char temp;
    while(begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

/* 
This is a very interesting/impressive style of code

Coming to approach:
eg1: i like this program very much
eg2: shrey jain
 first reverse the individual words, we get the sting below
eg1: i ekil siht margorp yrev hcum
eg2: yerhs niaj
 next reverse the whole string from start to end and we get the desired output
eg1: much vert program this like i
eg2: jain shrey
 */
void reverseWords(char *s) {
    
    // shrey.jain
    // yerhs.naij
    // jain.shrey

    // storing the given string s in word_begin and temp to use it further for different uses
    char *temp = s;
    char *word_begin = s;

    // loop iterating through string
    while(*temp) {
        temp++;

        // if, current character is not null,
        // then call reverse till this
        if (*temp == '\0') {
            reverse(word_begin, temp-1);
        }

        // if character is dot, then also reverse the word, but jump the 
        // word_begin pointer to current
        else if (*temp == '.') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }

    // reverse complete resulting string
    reverse(s, temp-1);
    
    cout << s;
}

// Company tags: Accolite, Adobe, Amazon, Cisco, Goldman Sachs, MakeMyTrip, Microsoft, Paytm, Samsung, SAPLabs