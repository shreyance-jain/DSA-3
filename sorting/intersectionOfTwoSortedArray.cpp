/*
Intersection of two sorted arrays

Problem Statement
Given two sorted arrays arr1[] and arr2[] of sizes N and M respectively.
The task is to find intersection of the two arrays.

Intersection of two arrays contains the elements common to both the arrays.
The intersection should not count duplicate elements.

Input Format:
First line of input contains number of testcases T.
For each testcase, first line of input contains size of arrays N and M.
Next two lines contains N and M elements.

Output Format:
For each testcase, there will be a single line of output containing
intersection elements of the two arrays in sorted order.

Constraints:
1 <= T <= 100
1 <= N, M <= 105
1 <= arr[i], brr[i] <= 106

Example:
Input:
3
4 5
1 2 3 4
2 4 6 7 8
5 6
1 2 2 3 4
2 2 4 6 7 8
2 3
1 2
3 4

Output:
2 4
2 4
-1

Explanation:
Testcase 2: 2 an 4 are only the common elements.
Testcase 3: no common elements so print -1.

*/

#include <bits/stdc++.h>
using namespace std; 

void printIntersection(int arr1[], int arr2[], int N, int M);  
  
int main() 
{ 
    int T;
    cin >> T;
 
    while(T--){
        
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for(int i = 0;i<N;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<M;i++){
            cin >> arr2[i];
        }
        
        // Function calling 
        printIntersection(arr1, arr2, N, M); 
        
        cout << endl;
    }
    
  return 0; 
} 

void printIntersection(int arr1[], int arr2[], int N, int M) 
{ 
    int i = 0, j = 0;
    int intersection = 0;
    while (i < N && j < M) {
        while (arr1[i] == arr1[i+1])
            i++;
        while (arr2[j] == arr2[j+1])
            j++;
        if (arr1[i] == arr2[j]) {
            intersection = 1;
            cout << arr1[i] << " ";
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else
            j++;
    }
    if (!intersection) {
        cout << -1;
    }
}