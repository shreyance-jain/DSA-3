/* 
Merge Without Extra Space

Problem Statements
Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m.
The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).

Note: Expected time complexity is O((n+m) log(n+m)). DO NOT use extra space. 
We need to modify existing arrays as following.

Input: arr1[] = {10};
       arr2[] = {2, 3};
Output: arr1[] = {2}
        arr2[] = {3, 10}  

Input: arr1[] = {1, 5, 9, 10, 15, 20};
       arr2[] = {2, 3, 8, 13};
Output: arr1[] = {1, 2, 3, 5, 8, 9}
        arr2[] = {10, 13, 15, 20} 
Input Format:
First line contains an integer T, denoting the number of test cases. First line of each test case contains two space separated integers X and Y, denoting the size of the two sorted arrays. Second line of each test case contains X space separated integers, denoting the first sorted array P. Third line of each test case contains Y space separated integers, denoting the second array Q.

Output Format:
For each test case, print (X + Y) space separated integer representing the merged array.

Constraints:
1 <= T <= 100
1 <= X, Y <= 5*104
0 <= arr1i, arr2i <= 109

Example:
Input:
2
4 5
1 3 5 7
0 2 6 8 9
2 3
10 12
5 18 20

Output:
0 1 2 3 5 6 7 8 9
5 10 12 18 20

Explanation:
Testcase 1: After merging two non-decreasing arrays, we have, 0 1 2 3 5 6 7 8 9.
 */


#include <bits/stdc++.h> 
using namespace std; 

void merge(int arr1[], int arr2[], int n, int m);

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    int arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    
	    merge(arr1, arr2, n, m); 
        for (int i = 0; i < n; i++) 
            cout << arr1[i] << " ";
        
       
	    for (int i = 0; i < m; i++) 
		    cout << arr2[i] << " ";
	    
	    cout<<endl;
	}
	return 0; 
} 

/* 
The idea is to begin with last element of second array and search it in first array.
If there is a greater element in ar1 , then we move last element from ar1 to ar2.
To keep ar1 and ar2 sorted we need to place the last element of ar2 at correct place in ar1.
We can use insertion sort type of insertion for this.

Algo: 
1. Iterate through every element of ar2 starting from last element.
Do the following for every element ar2[i]
    a. Store the last element of ar1[].
    b. Loop through the last element of ar1 while ar1[j] is greater than ar2[i]
        ar1[j+1] = ar1[j]
        j--
    c. If any element of ar1 was not moved or j != m-1
        ar1[j+1] = ar2[i]
        ar2[i] = last
 */
void merge(int arr1[], int arr2[], int n, int m) 
{ 
    // traverse the second array from the last
    for(int i = m-1; i >= 0; i--) {
        int j;
        // last would contain the last element of the first array
        int last = arr1[n-1];
        // find the correct postion of arr2[i] in the first array
        for(j = n-2; j >= 0 && arr1[j] > arr2[i]; j--)
            arr1[j+1] = arr1[j];
        // if the positon of j in changed or last is greater than arr2[i] {
            if (j != n-2 || last > arr2[i]) {
                arr1[j+1] = arr2[i];
                arr2[i] = last;
            }
    }
} 


// Time Complexity:  O(m*n), 
// The worst case occurs when all the elements in the first array arr1[] are greater than second array arr2[]