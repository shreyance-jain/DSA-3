/*

Minimum Number in a sorted rotated array

Problem Statement:

Given an array A  which is sorted and contains N distinct elements. Also, this array 
is rotated at some unknown point. The task is to find the minimum element in it. 

Note: Expected time complexity is O(logN).

Input:
The first line of input contains an integer T denoting the number of test cases. 
Each test case contains the number of elements in the array arr[] as N and next line 
contains space separated n elements in the array arr[].

Output:
Print an integer which denotes the minimum element in the array.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= arr[i] <= 107

Example:
Input:
3
10
2 3 4 5 6 7 8 9 10 1
5
3 4 5 1 2
8
10 20 30 45 50 60 4 6

Output:
1
1
4

Explanation:
Testcase 1: The array is rotated once anti-clockwise. So minium element is at last index (n-1) which is 1.*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum element in sorted and rotated array
// arr: input array
// low and high are 0 and n-1, where n is the size of arr

int getPivot(int arr[], int low, int high) {
    if (low > high) return -1;
    if (low == high) return low;
    int mid = low + (high - low) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid - 1] > arr[mid])
        return mid - 1;
    if (arr[mid] > arr[high])
        return getPivot(arr, mid + 1, high);
    return getPivot(arr, low, mid - 1);
}

int minNumber(int arr[], int low, int high)
{
    // rotation point is pivot in sorted and rotated array
    int pivot = getPivot(arr, low, high);
    // min element is element next to pivot
    if (pivot > 0) {
        int min = arr[pivot+1];
        return min;
    } else {
        return arr[0];
    }
    
}

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];		
		cout << minNumber(a,0,n-1) << endl;
	}
	return 0;
}