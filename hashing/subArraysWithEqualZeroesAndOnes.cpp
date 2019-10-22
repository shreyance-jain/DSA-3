/* 
Subarrays with equal 1s and 0s
     
Problem Statement

Given an array arr[] of size N containing 0s and 1s only.
The task is to count the subarrays having equal number of 0s and 1s.

Input Format:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines.
First line of each test case contains an Integer N denoting size of array and
the second line contains N space separated 0 and 1.

Output Format:
For each test case, in a new line, print the count of required sub arrays in new line

Constraints:
1 <= T <= 100
1 <= N <= 106
0 <= A[i] <= 1

Example:
Input:
2
7
1 0 0 1 0 1 1
5
1 1 1 1 0

Output:
8
1

Explanation:
Testcase 1: The index range for the 8 sub-arrays are:
(0, 1), (2, 3), (0, 3), (3, 4), (4, 5)
(2, 5), (0, 5), (1, 6) 
 */

#include <bits/stdc++.h>
using namespace std;
long long int countSubarrWithEqualZeroAndOne(int arr[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	cout << countSubarrWithEqualZeroAndOne(arr, n) << endl;
	}
	return 0;
}

/* The concept is same as counting subArray with 0 sum
Just consider 0 as -1 and the problem reduces to problem: subarray with 0 sum */

long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    long long int counter = 0;
    unordered_map<int, int> m;
    
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        // consider 0 as -1
        if (arr[i] == 0) {
            sum += -1;
        } else {
            sum += arr[i];
        }
        
        if (sum == 0)
            counter++;
            
        if (m.count(sum) != 0)
            counter += m[sum];
            
        m[sum]++;
    }
    
    m.clear();
    
    return counter;
}