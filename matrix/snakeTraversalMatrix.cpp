/*
Problem Statement: 
Given a matrix mat[][] of size N x N. The task is to print the elements 
of the matrix in the snake pattern.


Input Format:
First line consists of an integer T denoting the number of test cases. 
First line of each test case consists of N, denoting number of elements(N x N) in Matrix. 
Second line of every test case consists of N x N spaced integers denoting elements of Matrix 
elements.

Output Format:
For each testcase, in a new line, print the matrix in snake pattern.

Your Task:
This is a function problem. You only need to complete the function print that takes a matrix
and n as parameters and prints the matrix. The newline is automatically appended by the driver 
code.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= mat[i][j] <= 100

Example:
Input:
1
3
45 48 54 21 89 87 70 78 15

Output:
45 48 54 87 89 21 70 78 15 

Explanation:
Testcase 1: Matrix is as below:
45 48 54
21 89 87
70 78 15

Printing it in snake pattern will lead to the output as 45 48 54 87 89 21 70 78 15.
*/

#include <bits/stdc++.h>
using namespace std;

/*  Function to print the matrix in snake pattern
*   mat[][]: input matrix
*   n: size of matrix n x n
*/
void print(int mat[][100],int n)
{
    // Your code here
    for(int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for(int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
        } else {
            for(int j = n-1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
    }
}


// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    print(a,n);
    cout<<endl;
    }
    return 0;
}