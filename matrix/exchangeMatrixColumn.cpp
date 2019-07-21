/*
Exchange matrix columns

Problem Statement:
You are given a matrix A of dimensions n1 x m1. 
You have to exchange A's first column with last column.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. 
Each testcase contains two lines of input. The first line contains 
dimensions of the matrix A, n1 and m1. 
The second line contains n1*m1 elements of matrix separated by spaces.

Output Format:
For each testcase, in a new line, print the resultant matrix.

Constraints:
1 <= T <= 100
1 <= n1, m1<= 30
0 <= arr[i] <= 100

Examples:
Input:
1
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
Output:
4 2 3 1 8 6 7 5 12 10 11 9 16 14 15 13

Explanation:
Testcases 1: Matrix is as follow:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

After exchanging first  column with last column, we have matrix as follows:
4 2 3 1
8 6 7 5
12 10 11 9
16 14 15 13
*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 100

/*  Function to exchange columns
*   n1, m1: rows and cols of matrix
*   SIZE: defined globally for matrix
*   arr1[][]: input matrix
*/
void exchangeColumns(int n1, int m1, int arr1[SIZE][SIZE]){
    
    // Your code here
    for(int i = 0; i < n1; i++){
        swap(arr1[i][0], arr1[i][m1-1]);
    }
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++) {
            cout << arr1[i][j] << " ";
        }
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
        
        exchangeColumns(n1, m1, arr1);
        cout<<endl;
    }
    
	return 0;
}