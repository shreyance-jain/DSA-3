/* 
Removing consecutive duplicates - 2

Problem Statement

You are given a string str. You need to remove the pair of duplicates.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains one line of input containing string str.

Output Format:
For each testcase, in a new line, print the modified string.
If the final string is empty, then print "Empty String".

Constraints:
1 <= T <= 100
1 <= |str| <= 103

Examples:
Input:
2
aaabbaaccd
aaaa
Output:
ad
Empty String

Explanation:
Testcase1: Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad
 */


#include <bits/stdc++.h>
using namespace std;

string removePair(string);

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        
        string ans = removePair (s);
        
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}

/* The problem is very simple as we only need to remove the adjacent duplicates
Push the first character into a stack
pop if the top of the stack is equal to current character else push it into the stack */
string removePair(string str){
    stack<char> st;

    // push the first character to stack
    st.push(str[0]);

    // iterating over remaining characters
    for(int i = 1; i < str.length(); i++) {
        // if top of stack is equal to current character in the string
        // then remove the character from stack
        if (!st.empty() && st.top() == str[i]) {
            st.pop();
        }
        // else push the element into stack
        else {
            st.push(str[i]);
        }
    }
    string answer = "";
    // combining answer string
    while(!st.empty()) {
        answer = st.top() + answer;
        st.pop();
    }
    return answer;
}