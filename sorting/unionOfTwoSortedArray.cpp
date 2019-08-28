/*
Union of Two Sorted Arrays

Problem Statement
Given two sorted arrays arr[] and brr[] of size N and M respectively.
The task is to find the union of these two arrays.

Union of two arrays can be defined as the common and distinct elements in the two arrays.

Input Format: 
First line of input contains number of testcases T.
For each testcase, first line of input contains number of testcases T.
For each testcase, first line of input contains size of two arrays N and M.
Next two line contains N and M elements.

Output Format:
For each testcase, print the union (common and distinct) of two arrays in a single line.
You need to print the union in sorted order.

Constraints:
1 <= T <= 100
1 <= N, M <= 105
1 <= arr[i], brr[i] <= 106

Example:
Input:
3
5 3
1 2 3 4 5
1 2 3
5 5
2 2 3 4 5
1 1 2 3 4
5 5
1 1 1 1 1
2 2 2 2 2

 

Output:
1 2 3 4 5
1 2 3 4 5
1 2

Explanation:
Testcase 1: Distinct elements including both the arrays are: 1 2 3 4 5.
Testcase 2: Distinct elements including both the arrays are: 1 2 3 4 5.
 

** For More Input/Output Examples Use 'Expected Output' option **
*/

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void findUnion(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        // handle duplicates
        while(arr1[i] == arr1[i+1])
            i++;
        // handle dulpicates
        while(arr2[j] == arr2[j+1])
            j++;
        if (arr1[i] < arr2[j]) {
            cout << arr1[i] << " ";
            i++;
        } else if (arr1[i] > arr2[j]) {
            cout << arr2[j] << " ";
            j++;
        } else {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    while (i < n) {
        // handle duplicates
        while(arr1[i] == arr1[i+1])
            i++;
        cout << arr1[i] << " ";
        i++;
    }
    while (j < m) {
        // handle duplicates
        while(arr2[j] == arr2[j+1])
            j++;
        cout << arr2[j] << " ";
        j++;
    }
}

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    findUnion(arr1,arr2, N, M);
	    
	    cout << endl;
	    
	}
	
	return 0;
}
