/* 
Relative Sorting

Problem Statement

Given two arrays A1[] and A2[] of size N and M respectively.
The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2.
For the elements not present in A2, append them at last in sorted order.
It is also given that the number of elements in A2[] are smaller than or
equal to number of elements in A1[] and A2[] has all distinct elements.

Note: Expected time complexity is O(N log(N)).

Input:
First line of input contains number of testcases.
For each testcase, first line of input contains length of arrays N and M and next two line contains
N and M elements respectively.

Output:
Print the relatively sorted array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N,M  ≤ 106
1 ≤ A1[], A2[] <= 106

Example:
Input:
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

Output:
2 2 1 1 8 8 3 5 6 7 9

Explanation:
Testcase 1: Array elements of A1[] are sorted according to A1[].
 */

#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// utility function to print a unordered_map
void printMap(unordered_map <int, int> m) {
    unordered_map <int, int>:: iterator p;
    for(p = m.begin(); p != m.end(); p++)
        cout << "(" << p->first << ", " << p->second << ")" << endl;
}

/* Approach:
 */
void relativeSorting(int arr1[], int arr2[], int n1, int n2) {
    // take a temp array to store the output
    int temp[n1], l = 0, q;
    
    // unordered map
    unordered_map <int, int> m;
    
    // traverse through first array and store the count of every element in map
    for(int i = 0; i < n1; i++)
        m[arr1[i]]++;
    
    // traverse through second array, check if the element exists in first array
    // if yes store the element in output array as many no of times it is present in original array and remove from map
    for(int j = 0; j < n2; j++) {
        if (m.find(arr2[j]) != m.end()) {
          for(int k = 0; k < m[arr2[j]]; k++) {
              temp[l] = arr2[j];
              l++;
          }
          m.erase(arr2[j]);
        }
    }
    
    q = l;
    // put the rest of the elements in array and sort them
    unordered_map <int, int>:: iterator p;
    for(p = m.begin(); p != m.end(); p++) {
        while(p->second--) {
            temp[l] = p->first;
            l++;
        }
    }
    
    sort(temp + q, temp + n1);
    
    printArray(temp, n1);
        
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n1, n2;
	    cin >> n1 >> n2;
	    int arr1[n1], arr2[n2];
	    for(int i = 0; i < n1; i++)
	        cin >> arr1[i];
	    for(int j = 0; j < n2; j++)
	        cin >> arr2[j];
	    relativeSorting(arr1, arr2, n1, n2);
	    // printArray(arr1, n1);
	}
	return 0;
}

// Company tags: Amamzon, Microsoft

// refer: https://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/