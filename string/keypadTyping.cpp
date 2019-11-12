/* 
Keypad typing

Problem Statement

You are given a string S of alphabet characters and the task is to
find its matching decimal representation as on the shown numeric keypad.
Output the decimal representation corresponding to the string.
For ex: if you are given “amazon” then its corresponding decimal representation will be 262966.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of a single line containing a string.

Output:
For each test case, print in a new line, the corresponding decimal representation of the given string.

Constraints:
1 ≤ T ≤ 100
1 ≤ length of String ≤ 100

Example:
Input
2
geeksforgeeks
geeksquiz

Output
4335736743357
433577849
 */

#include <iostream>
using namespace std;

string matchingDecimalKeypadRepresentation(string str) {
    int n = str.length();
    string temp;
    for(int i = 0; i < n; i++) {
        if (str[i] == 'a'|| str[i] == 'b' || str[i] == 'c') temp.insert(i, "2");
        else if (str[i] == 'd'|| str[i] == 'e' || str[i] == 'f') temp.insert(i, "3");
        else if (str[i] == 'g'|| str[i] == 'h' || str[i] == 'i') temp.insert(i, "4");
        else if (str[i] == 'j'|| str[i] == 'k' || str[i] == 'l') temp.insert(i, "5");
        else if (str[i] == 'm'|| str[i] == 'n' || str[i] == 'o') temp.insert(i, "6");
        else if (str[i] == 'p'|| str[i] == 'q' || str[i] == 'r' || str[i] == 's') temp.insert(i, "7");
        else if (str[i] == 't'|| str[i] == 'u' || str[i] == 'v') temp.insert(i, "8");
        else if (str[i] == 'w'|| str[i] == 'x' || str[i] == 'y' || str[i] == 'z') temp.insert(i, "9");
    }
    return temp;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    string n = matchingDecimalKeypadRepresentation(s);
	    cout << n << endl;
	}
	return 0;
}

// Company Tags: Amazon