/* 
Evaluation of Postfix Expression

Problem Statement

Given a postfix expression, the task is to evaluate the expression and print the final value.
Operators will only include the basic arithmetic operators like *,/,+ and -.

Input Format:
The first line of input will contains an integer T denoting the no of test cases .
Then T test cases follow.
Each test case contains an postfix expression.

Output Format:
For each test case, in a new line, evaluate the postfix expression and print the value.

Constraints:
1 <= T <= 100
1 <= length of expression <= 100

Example:
Input:
2
231*+9-
123+*8-

Output:
-4
-3

Explanation:
Testcase 1: After solving the given expression, we have -4 as result.
 */

// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string &s);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        cout << evaluatePostfix(str) << endl;
    }
    return 0;
}

/* 
Algorithm: For evaluation of postfix expression
1. Create a stack to store operands (or values)
2. Scan the given expression and do the following for every scanned element
..a) If the element is a number, push it to stack
..b) If the element is an operator, pop operands for the operator from the stack
Evaluate the operator and push the result back to stack
3. When expression is ended, the number in stack is the final answer
 */
int evaluatePostfix(string &str)
{
    stack<char> st;
    int n = str.length();
    
    // scan characters one by one
    for(int i = 0; i < n; i++) {
        // if the scanned character is an operand(digit here) push it to the stack
        if (isdigit(str[i])) {
            st.push(str[i] - '0');
        }
        // if the scanned character is an operator, pop two elements from stack
        // apply the operator and push the result back in stack
        else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (str[i]) {
                case '+':
                    st.push(b + a);
                    break;
                case '-':
                    st.push(b - a);
                    break;
                case '*':
                    st.push(a * b);
                    break;
                case '/':
                    st.push(b/a);
                    break;
            }
        }
    }
    return st.top();
}


// Time Complexity: O(n) where n is the number of characters in input expressions
// There are following limitations of the above implementation:
// 1. It supports only 4 binary operators '+' '-' '/' and '*'. It can be exteneded for more operators
// by adding more switch cases
// 2. The allowed operands are only single digit operands. The program can be extened for multiple
// digits by adding a seperator like space between all elements(operands and operators) of given expression