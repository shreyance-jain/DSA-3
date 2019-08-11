/*
Count only Repeated

Problems

Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element 
which is repeating X (any variable) number of times. Now, the task is to find the element which is repeated and number 
of times it is repeated.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements 
in the array N. Next line contains the array elements.

Output:
For each testcase, there will be a single line containing the element which is repeated and the number of times 
it is repeated, seperated by space.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= arr[i] <= 1015

Input:
2
5
1 2 3 3 4
5
2 3 4 5 5

Output:
3 2
5 2

Example:
Testcase 1: In the given array, 3 is occuring two times.
*/

#include <iostream>
using namespace std;


void getRepeatingElementAndCount(int arr[], int s, int e, int n) {
    while(s < e) {
        int mid = (s + e) / 2;
        if (arr[mid] >= arr[0] + mid) {
            s = mid + 1;
        }
        else 
            e = mid -1;
    }
    cout << arr[s] << " " << n - (arr[n-1] - arr[0]) << endl;
}

void countRepeating(int arr[], int n) {
    int s = 0;
    int e = n-1;
    getRepeatingElementAndCount(arr, s, e, n);
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    countRepeating(arr, n);
	}
	return 0;
}