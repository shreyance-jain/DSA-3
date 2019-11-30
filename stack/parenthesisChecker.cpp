/* 
Parenthesis Checker

Problem Statement

Given an expression string x.
Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and
'not balanced' for exp = “[(])”.

Input Format:
The first line of input contains an integer T denoting the number of test cases.
Each test case consists of a string of expression, in a separate line.

Output Format:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |x| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced

Explanation:
Testcase 1: { ( [ ] ) }. Same colored brackets can form balaced pairs, with 0 number of unbalanced bracket.
 */


#include<bits/stdc++.h>
using namespace std;

bool ispar(string x);

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}

/* Function to check pair for two characters */
bool isPair(char a, char b) {
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
        return true;
    return false;
}

/* Approach:
Traverse through the string
when an opening bracket is encounterd we push to stack
When a closing bracket is encountered it should make pair with the last opening bracket
i.e. the bracket at the top of the stack 
so when a closing bracket is encounterd we check if it makes correct pair with character at top of stack
if yes, we proceed, else reject
at last stack should be empty*/
bool ispar(string x)
{
    stack<char> st;

    // traverse the input string
    for(int i = 0; i < x.length(); i++) {
        // if opening bracket push to stack
        if (x[i] == '(' || x[i] == '{' || x[i] == '[')
            st.push(x[i]);
        else {
            // if no element and closing bracket is encountered
            if (st.empty())
                return false;
            // check if it make pair with bracket at top of stack
            else if (!isPair(st.top(), x[i]))
                return false;
            // if it made correct pair, pop that opening bracket from stack
            else
                st.pop();
        }
    }
    // after traversing the whole string
    // if parenthesis are balanced
    // stack should be empty
    if (st.empty())
        return true;
    // otherwise not balanced
    return false;
}

// Company Tags: Adobe, Amazon, Flipkart, Oracle, OYO Rooms, Snapdeal, Walmart, Yatra.com    