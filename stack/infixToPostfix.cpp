/* 
Infix to Postfix

Problem Statement

Given an infix expression in the form of a string str. Conver this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

Input:
The first line of input contains an integer T denoting the number of test cases.
The next T lines contains an infix expression.The expression contains all characters and ^,*,/,+,-.

Output:
For each testcase, in a new line, output the infix expression to postfix expression.

Constraints:
1 <= T <= 100
1 <= length of str <= 103

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D

Output:
abcd^e-fgh*+^*+i-
ABC+*D/
 */

#include <bits/stdc++.h>
using namespace std;

string infixToPostfix(string);

int main() {
	//code
	int T;
	cin >> T;
	while(T--) {
	    string s;
	    cin >> s;
	    string res = infixToPostfix(s);
	    cout << res << endl;
	}
	return 0;
}

// function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

/*  
Algorithm:
1. Scan the infix expression from left to right
2. If the scanned character is operand, output it
3. Else
    3.1. If precedence of the scanned operator is greater than the precedence of the operator
    in stack(or the stack is empty, or stack contains a '('), push it
    3.2. Else, Pop all the operators, from the stack which are greater or equal to in precedence
    than that of the scanned operator. After doing that Push the scanned operator to the stack.
    (if you encounter parenthesis while popping then stop there are push the scanned operator)
4. If the scanned operator is an '(', push it to the stack
5. If the scanned operator is ')', pop the stack and ouput it until a '(' is encountered,
    and discard both the parenthesis
6. Repeat steps 2-6 until infix expression is scanned
7. Print the output
8. Pop and output the stack until it is not empty
*/
string infixToPostfix(string s) {
    int l = s.length();
    stack<char> st;
    st.push('N');
    string ns;
    
    for(int i = 0; i < l; i++) {
        // if the scanned character is operand, add it to output string
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            ns += s[i];
        
        // if the scanned character is '(', push it to the stack
        else if (s[i] == '(')
            st.push(s[i]);

        // if the scanned character is ')', pop and add to ouput string
        // unitl an '(' is encountered    
        else if (s[i] == ')') {
            while(st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                ns += c;
            }
            if (st.top() == '(')
                st.pop();
        }
        // if the operator is scanned
        else {
            while(st.top() != 'N' && (prec(s[i]) <= prec(st.top()))) {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }
    }
    
    // pop all the remaining elements from the stack
    while(st.top() != 'N') {
        char c = st.top();
        st.pop();
        ns += c;
    }
    
    return ns;
}


// Company Tags: Amazon, Paytm, Samsung, VMWare