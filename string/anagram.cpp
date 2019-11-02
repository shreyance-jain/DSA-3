/* 
Anagram   
 
Problem Statement

Given two strings a and b consisting of lowercase characters.
The task is to check whether two given strings are anagram of each other or not.
An anagram of a string is another string that contains same characters,
only the order of characters can be different. For example, “act” and “tac” are anagram of each other.

Input:
The first line of input contains an integer T denoting the number of test cases.
Each test case consist of two strings in 'lowercase' only, in a single line.

Output:
Print "YES" without quotes if the two strings are anagram else print "NO".

Constraints:
1 ≤ T ≤ 300
1 ≤ |s| ≤ 1016

Example:
Input:
2
geeksforgeeks forgeeksgeeks
allergy allergic

Output:
YES
NO

Explanation:
Testcase 1: Both the string have same characters with same frequency. So, both are anagrams.
Testcase 2: Characters in both the strings are not same, so they are not anagrams.
 */

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string c, string d);

// driver code
int main() {
    
    int t;
    cin >> t;
    while(t--){
        string c, d;
        cin >> c >> d;
        if(isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

/* 
check if two strings are anagrams or,
in other words check if two strings are permutations of each other
 */
bool isAnagram(string c, string d){
    int n = c.length(), m = d.length();

    // if the lenght is not equal strings cannot be anagrams
    if (n != m) return false;

    // take a count array of size 26 as string contains only lowercase characters
    // otherwise 256 if all characters are allowed
    int count[26] = {0};

    // traverse the first string and store the count of individual characters
    for(int i = 0; i < n; i++)
        count[c[i] - 'a']++;

    // traverse the second string and reduce the count of individual characters
    for(int j = 0; j < m; j++)
        count[d[j] - 'a']--;

    // now if in count array at some index if value is greater than zero it means unequal count of diff characters, return false
    for(int k = 0; k < 26; k++)
        if(count[k] > 0)
            return false;
    
    // if here, strings are anagrams return true
    return true;
}

// Time Complexity: O(n) or, O(n + alphabet_size) to be precise where alphabet_size is a constant
// Aux Space: O(1) or O(alphabet_size), where alphabet_size is a constant

// Company tags: Naggaro
