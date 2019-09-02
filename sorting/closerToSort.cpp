/* 
Closer to sort

Problem Statement

Given an array arr[] of N integers which is closer sorted (defined below) and an element x.
The task is to find index of the element x if it is present. If not present, then print -1.

Closer Sorted: First array is sorted, but after sorting some elements are moved to either of the adjacent positions,
i.e, may be to the arr[i+1] or arr[i-1].

Expected Time Complexity: O(Log N)

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array. Next line contains the array elements. Last line contains the element to be searched.

Output Format:
Output the index at which the element is present (0-based), if present, else print "-1".

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i],x <= 106

Example:
Input:
1
5
3 2 10 4 40
2

Output:
1

Explanation:
Testcase 1: 2 is present at index 1 (0-based indexing) in the given array.
 */


#include <iostream>
using namespace std;

int binarySearch(int arr[], int lo, int hi, int x);
int closer(int arr[],int n, int x);

int main() {
    
    cin.tie(NULL);
    
	int t;
	cin >> t;
	
	while(t--){
	  
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    int x;
	    cin >> x;
	    
	    int res = closer(arr,n,x);
	    
	    cout << res << endl;
	}
	
	return 0;
}

int binarySearch(int arr[], int lo, int hi, int x) {
    if (lo <= hi) {
        
        int mid = lo + (hi - lo) / 2;
        
        if (arr[mid] == x)
            return mid;
        
        /* apart from checking the element at mid, we also check for
        element at mid - 1 and mid + 1 */

        // check if mid element is present at mid - 1
        if (mid > lo && arr[mid - 1] == x)
            return mid - 1;
        
        // check if mid is present ar mid + 1
        if (mid < hi  && arr[mid + 1] == x)
            return mid + 1;
        
        // comapre element at mid
        // if greater than x, then recursive for left half
        if (arr[mid] > x)
            return binarySearch(arr, lo, mid - 2, x);
        
        // else recursive for right half
        return binarySearch(arr, mid + 2, hi, x);
    }

    // if element is not present in the array
    return -1;
}

int closer(int arr[],int n, int x)
{
    return binarySearch(arr, 0, n-1, x);
}

// Time Complexity: O(log N)