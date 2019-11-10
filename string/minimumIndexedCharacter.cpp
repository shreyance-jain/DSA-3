/* 
Minimum indexed character
       
Problems

Given a string str and another string patt.
Find the character in patt that is present at the minimum index in str.
If no character of patt is present in str then print ‘No character present’.

Input Format:
The first line of input contains an integer T denoting the number of test cases.
Then the description of T test cases follow.
Each test case contains two strings str and patt respectively.

Output Format:
Print the character in patt that is present at the minimum index in str.
Print "No character present" (without quotes) if no character of patt is present in str.

Constraints:
1 <= T <= 105
1 <= |str|,|patt| <= 105

Example:
Input:
2
geeksforgeeks
set
adcffaet
onkl

Output:
e
No character present

Explanation:
Testcase 1: e is the character which is present in given patt "geeksforgeeks" and is first found in str "set"
 */


#include <bits/stdc++.h>
using namespace std;

void printMinIndexChar(string str, string patt);

// driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    string patt;
	    cin>>str;
	    cin>>patt;
	    printMinIndexChar(str, patt);
	    cout<<endl;
	}return 0;
}

/*Naive Approch: Run two loops (nested) O(n*m)
Better Approach: Use direct addressing 
traverse the second string patt and mark the presence of character
Traverse the first string str and check if marked present, return min indexed
If not found return not found
*/
void printMinIndexChar(string str, string patt)
{
    int count[256] = {0};
    int index = -1;
    
    for(int i = 0; i < patt.length(); i++)
        count[patt[i]]++;
    
    for(int i= 0; i < str.length(); i++) {
        if (count[str[i]] > 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        cout << "No character present";
    } else {
        cout << str[index];
    }
}

// Time Complexity: O(n + m), where n and m is the no of characters in str and patt respectively
// Space Complexity: O(alphabet_size)
// Company tags: Ola Cabs