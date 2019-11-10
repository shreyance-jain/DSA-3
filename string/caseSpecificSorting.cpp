/* 
Case-specific Sorting of Strings

Problem Statement

Given a string S consisting of uppercase and lowercase characters.
The task is to sort uppercase and lowercase letters separately such that
if the ith place in the original string had an Uppercase character
then it should not have a lowercase character after being sorted and vice versa.

Input Format:
The first line of input contains an integer T denoting the number of test cases.
The description of T test cases follows.
The first line of each test case contains a single integer N denoting the length of string.
The second line contains a string S of length N, consisting of uppercase and lowercase characters.

Output Format:
For each testcase, in a new line, print the answer.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 103

Example:
Input:
1
12
defRTSersUXI

Output:
deeIRSfrsTUX

Explanation:
Testcase 1: Sorted form of given string with the same case of character as that in original string.
 */


#include<bits/stdc++.h>
using namespace std;

string caseSort(string str, int n);

// driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		
		cout<<caseSort (str, n)<<endl;
	}
}

/*
The idea is simple to store lower case characters and upper case characters in
two different vectors and sort both the vectors.
Then use the sorted vectors to get the stored string
*/
string caseSort(string str, int n){
    // vetcors to strore lower case and upper case characters
    vector<char> v1, v2;
    // traverse the stirng and push characters in correct vectors based on their case
    for(int i = 0; i < n; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            v1.push_back(str[i]);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            v2.push_back(str[i]);
    }
    
    // sort both the vectors
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    // traverse the input string again
    int i = 0, j = 0; // pointer for the above two vectors
    for(int k = 0; k < n; k++) {
        // if the current character is lowercase then pick lowercase character from the stored list(i.e. vector v1)
        if (str[k] >= 'a' && str[k] <= 'z') {
            str[k] = v1[i++];
        // else pick the uppercase character
        } else if (str[k] >= 'A' && str[k] <= 'Z') {
            str[k] = v2[j++];
        }
    }
    // return the sorted string
    return str;
}

// Time Complexity: O(nlogn), worst case
// Space Complexity: O(n)