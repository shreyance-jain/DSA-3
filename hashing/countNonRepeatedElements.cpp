/* 
Count Non-Repeated Elements

Problem Statement

You are given an array arr[] of size n. You need to print the count of non-repeated elements in the array.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains an integer n denoting the size of the array. The second line contains n space separated elements of the array.

Output Format:
For each testcase, in a new line, print the count of distinct elements in the array.

Your Task:
This is a function problem. You only need to complete the function countNonRepeated() that takes arr and n as parameters and returns count.

Constraints:
1 <= T <= 100
1 <= n <= 103
0 <= arri <= 107

Examples:
Input:
2
10
1 1 2 2 3 3 4 5 6 7
5
10 20 30 40 10

Output:
4
3

Explanation:
Testcase 1: 4, 5, 6 and 7 are the elements with frequency 1.
 */

#include <bits/stdc++.h>
using namespace std;
int countNonRepeated(int arr[], int n);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    cout<<countNonRepeated(arr,n)<<endl;
	    
	}
	return 0;
}

int countNonRepeated(int arr[], int n)
{
    unordered_map <int, int> m;
    int counter = 0;
    for(int i = 0; i < n; i++) {
        m[arr[i]]++;
    }
    for(int i = 0; i < n; i++) {
        if (m[arr[i]] == 1)
            counter++;
    }
    return counter;
}

// Hashing is very useful to keep track of the frequency of the elements in a list.
// Aux Space Complexity: O(n)
// Time Complexity: O(n)