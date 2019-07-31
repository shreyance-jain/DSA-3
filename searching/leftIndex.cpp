/*

Left Index

Problem Statement:

Given a sorted array arr of N positive integers (elements may be repeated) and a number x. 
The task is to find the leftmost index of x in the array arr.

Input:
First line of input contains number of testcases T. For each testcase, 
first line contains number of elements N, and next line contains N elements. 
Last line contains x.

Output:
For each testcase, print the leftmost index at which x is present in the array. 
If the element is not present in the array, then output "-1" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106
1 <= x <= 106

Example:
Input:
2
10
1 1 2 2 3 4 5 5 6 7
1
7
10 20 20 20 20 20 20
20

Output:
0
1

Explanation:
Testcase 1: 1 is present two times in the array and its leftmost index is 0.
*/


#include <iostream>
using namespace std;


// Function to find element in sorted array

int getLeftMostIndex(int arr[], int lo, int hi, int x) {
    if (lo > hi) return -1;
    int mid = lo + (hi - lo) / 2;
    if(arr[mid] == x && (arr[mid - 1] != x || mid == lo))
        return mid;
    if (arr[mid] < x)
        return getLeftMostIndex(arr, mid + 1, hi, x);
    else
        return getLeftMostIndex(arr, lo, mid -1 , x);
}


int leftIndex(int sizeOfArray, int arr[], int elementToSearch){
    
    // Your code here
    int leftMostIndex = getLeftMostIndex(arr, 0, sizeOfArray-1, elementToSearch);
    return leftMostIndex;
}


// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    int elemntToSearch;
	    cin >> elemntToSearch;
	    
	    cout << leftIndex(sizeOfArray, arr, elemntToSearch) << endl;
	}
	
	return 0;
}
