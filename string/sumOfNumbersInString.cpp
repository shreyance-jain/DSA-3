/* 
Sum of numbers in string

Problem Statement

Given a string str containing alphanumeric characters, calculate sum of all numbers present in the string.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow.
Each test case contains a string containing alphanumeric characters.

Output:
Print the sum of all numbers present in the string.

Constraints:
1<=T<=105
1<=length of the string<=105

Example:
Input:
4
1abc23
geeks4geeks
1abc2x30yz67
123abc

Output:
24
4
100
123

Explanation:
Testcase 1: 1 and 23 are numbers in the string which is added to get the sum as 24.
Testcase 4: 123 is a single number, so sum is 123. 
 */

#include <iostream>
using namespace std;

int getSum(string s);

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    cout << getSum(s) << endl;
	}
	return 0;
}

/* The only trick in this question is multiple consecutive digits and considering as on number 

The idea is very simple, we scan every character of input string and if a number is formed by
consecutive characters of a string, we increment the result by that amount */

int getSum(string s) {

    // a temporary string
    string temp = "";

    // holds sum of all numbers present in string
    int sum = 0;
    
    // read each character of input string
    for(char ch: s) {
        // if current character is a digit
        if (isdigit(ch)) {
            temp += ch;
        // if current character is an alphabet
        } else {
            // increment sum by number found earlier, if any
            sum += atoi(temp.c_str());
            // reset temporary string to empty, for holding a new possible number
            temp = "";
        }
    }
    // take cares of trailing numbers
    return sum + atoi(temp.c_str());
}

// Company Tags: Amazon, LinkedIn, MAQ Software, OYO Rooms, SAP Labs