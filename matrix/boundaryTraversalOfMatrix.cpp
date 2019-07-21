/*
Boundary traversal of matrix 

You are given a matrix A of dimensions n1 x m1. The task is to perform boundary traversal 
on the matrix in clockwise manner.

Input Format:
The first line of input contains T denoting the number of testcases. 
T testcases follow. Each testcase two lines of input. The first line contains dimensions
 of the matrix A, n1 and m1. The second line contains n1*m1 elements separated by spaces.

Output Format:
For each testcase, in a new line, print the boundary traversal of the matrix A.

Constraints:
1 <= T <= 100
1 <= n1, m1<= 30
0 <= arri <= 100

Examples:
Input:
1
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
Output:
1 2 3 4 8 12 16 15 14 13 9 5

Explanation:
Testcase1: The matrix is:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
The boundary traversal is 1 2 3 4 8 12 16 15 14 13 9 5
*/

/*
Important: Edge cases to take care when :
1. The matrix has only one row 
eg: 1 2 3 4 5
2. The matrix has only one column
eg: 1
    2
    3
    4
    5
*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 50

/*  Function to print boundary traversal of the matrix
*   n1, m1: rows and cols of matrix
*   arr[][]: input matrix
*/
void boundaryTraversal(int n1, int m1, int arr[SIZE][SIZE]){
    
    // Your code here
    for(int i = 0; i < m1; i++) {
        cout << arr[0][i] << " ";
    }
    for(int i = 1; i < n1; i++) {
        cout << arr[i][m1 - 1] << " ";
    }
    for(int i = m1-2; i>= 0 && n1-1 > 0; i--) {
        cout << arr[n1-1][i] << " ";
    }
    for(int i = n1-2; i >= 1 && m1 != 1; i--) {
        cout << arr[i][0] << " ";
    }
}

int main() {
    long long t;
    cin>>t;
    
    while(t--)
    {
        int n1,m1;
        cin>>n1>>m1;
        int arr1[SIZE][SIZE];
        for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
        cin>>arr1[i][j];
        
        boundaryTraversal(n1, m1, arr1);
        
        cout <<endl;
    }
    
	return 0;
}

