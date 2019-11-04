/* 
Check if string is rotated by two places

Problem Statement

Given two strings a and b. The task is to find if the string 'b' can be obtained by
rotating another string 'a' by 2 places.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. In the next two line are two string a and b respectively.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by
rotating string 'b' by two places else print 0.

Constraints:
1 <= T <= 50
1 <= length of a, b < 100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0

Explanation:
Testcase 1: amazon can be rotated anti-clockwise by two places, which will make it as azonam.
Testcase 2: geeksgeeksfor can't be formed by any rotation from the given word geeksforgeeks.
 */
#include <bits/stdc++.h>
using namespace std;

bool isRotated(string str1, string str2);

// driver code
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		cout<<isRotated(s,b)<<endl;
	}
	return 0;
}

/* 
Approach: we can use modulo arithmatic to solve this problem, or,
There are only two cases
If clockwise shifted it means elements are shifted in right. So checking if substring[2...len-1] of string 2
when concatenated with substring[0,1] of substring 2 is equal to string 1. Then return true.
Else, check if it is anti-clockwise rotated that means if elements are shifted to left. So checking if
substring[len-2...len-1] of string2 when concatenated with substring[0...len-3] makes it equal to string 1. Then return true
 */

/* Function to check if str1 can be formed from
*  str2 after rotation by 2 places
*/
bool isRotated(string str1, string str2)
{
    
    if (str1.length() != str2.length())
        return false;
    
    if (str1.length() <= 2 || str2.length() <=2)
        return (str1 == str2);
    
    int len = str2.length();
        
    string clockwise = "";
    string anticlockwise = "";
    
    // initialise substring clockwise by concatenating substring of size two from start
    clockwise = clockwise + str2.substr(2) + str2.substr(0, 2);
    
    // initialise substring anticlockwise by concatenating substring of size two from end
    anticlockwise = anticlockwise + str2.substr(len-2, 2) + str2.substr(0, len- 2);
    
    // check if any one of them is equal to str1
    return (str1.compare(clockwise) == 0||
            str1.compare(anticlockwise) == 0);

}

// Company tags: Accolite, Amazon