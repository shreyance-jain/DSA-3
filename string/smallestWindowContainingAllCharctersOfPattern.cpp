/* 
Smallest window in a string containing all the characters of another string

Problem Statement:

Given a string S and text T.
Output the smallest window in the string S having all characters of the text T.
Both the string S and text T contains lowercase english alphabets.

Input:
First line of the input contains an integer T, denoting the number of test cases.
Then T test case follows.
Each test contains 2 lines having a string S and next line contains text T.

Output:
Output the smallest window of the string containing all the characters of the text.
If such window doesn`t exist or this task can not be done then print -1.

Constraints:
1 <= T <= 100
1 <= |N|, |X| <= 1000

Example:
Input:
2
timetopractice
toc
zoomlazapzo
oza

Output:
toprac
apzo

Explanation:
Testcase 1: "toprac" is the smallest substring in the given string S which contains every characters of T.
 */

#include <bits/stdc++.h>
using namespace std;

void smallestWindow(string str, string patt);

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string str, patt;
	    cin >> str >> patt;
	    smallestWindow(str, patt);
	    cout << endl;
	}
	return 0;
}


/* 
Method 1: Brute Force
1- generate all sub string of string1 ("this is a test string")
2- for each substring check whether the substring contains all characters of string2("t stri")
3- finally, print the smallest substring containing all characters of second string

Method 2: (Efficient Solution)
1 - first check if lenght of string is less than less length of given pattern, if yes "no such window exist"
2 - Store the occurence of charcters of give pattern in a hash_pat[]
3 - Start matching the characters of pattern with the characters of string, i.e increment count if a character matches
4 - Check if (count == length of pattern) this means a window is found
5- if such window is found, try to minimise it by removing extra characters from the beginning of current window
6 - update min lenght
7 - print the minimum length window
 */

void smallestWindow(string str, string pat) {
    int len1 = str.length(), len2 = pat.length();
    int hash_pat[256] = {0};
    int hash_str[256] = {0};
    
    // check if string's length is smaller than length of pattern, if yes then no such window exist
    if (len1 < len2) {
        cout << "-1";
        return;
    }
    
    // store occurence of characters of pattern
    for(int i = 0; i < len2; i++)
        hash_pat[pat[i]]++;
        
    int start = 0, start_index = -1, min_len = INT_MAX;

    // start traversing the string
    int count = 0; // count of characters
    for(int j = 0; j < len1; j++) {
        // count occurence of characters of string
        hash_str[str[j]]++;
        
        // if string's character matches with pattern's character then increment count
        if (hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]])
            count++;
        
        // if all characters are matched
        if (count == len2) {
            // try to minimise the window i.e. check if any character is occuring more no of times
            // than its occurence in pattern, if yes then remove it from starting and also remove
            // the useless characters
            while(hash_str[str[start]] > hash_pat[str[start]]
                || hash_pat[str[start]] == 0)
            {
                if (hash_str[str[start]] > hash_pat[str[start]]) 
                    hash_str[str[start]]--;
                start++;
            }
            // update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    // if no window found
    if (start_index == -1) {
        cout << "-1";
    } else {
        string s = str.substr(start_index, min_len);
        cout << s;
    }
}

// Company Tags: Amazon, Google, MakeMyTrip, Streamoid Technologies