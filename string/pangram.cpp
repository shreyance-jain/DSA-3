/* 
Pangram Checking

Problem Statement

Given a string check if it is Pangram or not.
A pangram is a sentence containing every letter in the English Alphabet.

Input Format:
First line of input contains of an integer 'T' denoting number od test cases then T test cases follow .
Each testcase contains a String 'S'.

Output Format:
For each test case print in a new line 1 if its a pangram else print 0 .

Constraints:
1 <= T <= 25
1 <= |S| <= 50

Example:
Input:
2
Bawds jog, flick quartz, vex nymph
sdfs

Output:
1
0
 */

#include<bits/stdc++.h>
using namespace std;

bool checkPangram (string &str);

int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, ' ');
    while(t--){
        string str;
        getline(cin, str);
        
        if (checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

/* 
Create a mark array of boolean type
Iterate through the charcaters of input string and whenever we see a character we mark it
Lowercase and uppercase character are considered same so we mark 'A' and 'a' at index 0
After iterating we would check entries of mark array
*/
bool checkPangram (string &str)
{
    // create a hash table to mark the characters present in the string
    vector<bool> mark(26, false);
    
    // traverse all characters
    for(int i = 0; i < str.length(); i++) {

        // if uppercase subtract 'A' to find index
        if (str[i] >= 'A' && str[i] <= 'Z')
            mark[str[i] - 'A'] = true;
        
        // if lowercase subtract 'a' to find index
        // else used here is imp to avoid un-necssary checking of invalid condition
        else if (str[i] >= 'a' && str[i] <= 'z')
            mark[str[i] - 'a'] = true;
    }
    
    // retunr false if any character is unmarked
    for(int i = 0; i < 26; i++) {
        if (mark[i] == false)
            return false;
    }

    // if all characters were present
    return true;
}

// Time Complexity: O(n + alpahbet_size), where n is the number of characters in input string
// Space Complexity: O(alphabet_size)