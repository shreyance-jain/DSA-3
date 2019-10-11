/* 
Subarray with 0 sum
            
Problem Statement
Given an array a[] of N positive and negative numbers.
Find if there is a subarray (of size at-least one) with 0 sum.

Input Format:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
Each test case contains an integer n denoting the size of the array.
The next line contains N space separated integers forming the array.

Output Format:
Print "Yes" (without quotes) if there exist a subarray of size
at least one with sum equal to 0 or else print "No" ( without quotes).

Your Task:
This is a function problem. You only need to complete the function subArrayExists()
that takes array and n as parameters and returns true or false.

Constraints:
1 <= T <= 100
1 <= N <= 104
-105 <= a[i] <= 105

Example:
Input:
2
5
4 2 -3 1 6
5
4 2 0 1 6

Output:
Yes
Yes

Explanation:
Testcase 1: 2, -3, 1 is the subarray with sum 0.
 */


// A C++ program to find if there is a zero sum subarray

#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n);

// driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
          cout << "Yes";
        else
          cout << "No";
	}
	return 0;
}

/*
Naive or Brute for approach: A simple apporach is to consider all sub arrays one by one and check sum of
each subarray. We can run two loops: the outer loop picks a starting point i and inner loop tries all 
subarrays starting from i. O(n^2)

Better approach: The conept is to use hashing and concept of prefix sum.
Concept of prefix sum can be used with a hack to check if current sum occured previously.
If the previous sum occured previously, this means elements between previous sum and 
current sum makes them 0
 */

bool subArrayExists(int arr[], int n)
{
  // initalise a set to hash the prefix sums
    unordered_set <int> s;
    int prefix_sum = 0;
    // insert 0 to cover, where prefix sum is 0, eg: cases [5, -5, 1]
    s.insert(0);
    // loop over the array
    for(int i = 0; i < n; i++) {
      // calculate perfix sum
        prefix_sum += arr[i];
        // check if this prefix sum in already encountered, if yes this means we have encountered a
        // subarray with zero sum
        if (s.find(prefix_sum) != s.end()) {
            return true;
        }
        s.insert(prefix_sum);
    }
    return false;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// Comapny tags: Paytm
// Popular interview problem, now variations of it is asked in company interviews