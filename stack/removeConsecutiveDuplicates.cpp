/* 
Removing consecutive duplicates

Problem Statement

Stacks can be used to remove duplicate characters from a string that
are stacked next to each other.
For example, we take the string aabbccccc and convert it into abc.
We can push the first character into a stack and skip if the top of the stack is equal to current character.

You are given a string str. You need to remove the consecutive duplicates.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains one line of input containing string str.

Output Format:
For each testcase, in a new line, print the modified string.
s
Constraints:
1 <= T <= 100
1 <= |str| <= 103

Examples:
Input:
2
aaaaaabaabccccccc
abbccbcd

Output:
ababc
abcbcd

Explanation:
Testcase 1: Removing all consecutive duplicates, we have no duplicates consecutively.
 */

#include <bits/stdc++.h>
using namespace std;

string removeConsecutiveDuplicates(string);

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << removeConsecutiveDuplicates(s) << endl;
    }
}

string removeConsecutiveDuplicates(string s) {
    stack<char> st;
    string answer = "";

    st.push(s[0]);

    // iterate through string
    for(int i = 1; i < s.length(); i++) {
        // if current character is equal to the character at the top of stack
        if (st.top() == s[i])
            continue;
        // else add this character to the answer string, and push it to the stack
        else {
            answer += st.top();
            st.pop();
            st.push(s[i]);
        }
    }
    // add character at the top to answer
    answer += st.top();
    return answer;
}