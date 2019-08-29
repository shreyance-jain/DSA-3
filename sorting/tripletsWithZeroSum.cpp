/*
Find triplets with zero sum

Problem Statement

Given an array A[] of N elements. The task is to complete the function which returns
true if triplets exists in array A whose sum is zero else returns false.

Input Format:
The first line of input contains an integer T, denoting the number of test cases.
Then T test cases follow. The first line of each test case contains an integer N,
denoting the number of elements in array. The second line of each test case contains
N space separated values of the array.

Output:
For each test case, output will be 1 if triplet exists else 0.

Constrains:
1 <= T <= 100
1 <= N <= 106
-106 <= A <= 106

Example:
Input:
2
5
0 -1 2 -3 1
3
1 2 3

Output:
1
0

Explanation:
Testcase 1: 0, -1 and 1 forms a triplet with sum equal to 0.
Testcase 2: No triplet exists which sum to 0.
*/

#include<bits/stdc++.h>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else 
        cout<<"0"<<endl;
	}
    return 0;
}

bool findTriplets(int arr[], int n)
{ 
    bool found = 0;
    // sort the array
    sort(arr, arr+n);
    // loop over the array 
    for(int i = 0; i <= n-1; i++) {
        // use 2 pointer approach on the remaining array
        int x = arr[i];
        int l = i+1;
        int r = n-1;
        while(r > l) {
            if (x + arr[l] + arr[r] == 0) {
                found = 1;
                l++;
                r--;
            } else if (arr[l] + arr[r] + x < 0) {
                l++;
            } else
                r--;
        }
    }
    return found;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)