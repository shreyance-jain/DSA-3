/*Problem Statement
Given a square matrix mat[][] of size N*N, print the sum of upper and lower triangular elements. 
Upper Triangle consists of elements on the diagonal and above it. 
Lower triangle consists of elements on the diagonal and below it. */

/*
Input Format:
The first line consists of an integer T i.e number of test cases. 
The first line of each test case consists of an integer N denoting the size of the matrix. 
The next line contains N*N spaced separated integers.

Output Format:
For each testcase, in a new line, print the required output.

Example:
Input:
1
3
6 5 4 1 2 5 7 9 7
Output:
29 32*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 100

/*  Function to find sum of upper and lower triangles
*   n: row/col in matrix
*   mat[][]: input matrix
*/
void sumTriangles(int n, int mat[SIZE][SIZE]){
    
    // Your code here
    int upperTriangleSum = 0;
    int lowerTriangleSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                // lower triangle
                lowerTriangleSum += mat[i][j];
            } else if (j > i) {
                // upper triangle
                upperTriangleSum += mat[i][j];
            } else {
                // diagnol element or trace of a matrix
                lowerTriangleSum += mat[i][j];
                upperTriangleSum += mat[i][j];
            }
        }
    }
    cout << upperTriangleSum << " " << lowerTriangleSum;
    
}

int main()
{
    int t;
    cin>>t; //input the testcases
    while(t--) //while testcases exist
    {
        long int r,n,c,us=0,ls=0;
        cin>>n; //input number of rows 
        r=n;
        c=r; //Since the matrix is a square matrix, number of cols=number of rows
        int i,j,mat[SIZE][SIZE];
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            cin>>mat[i][j]; //input the elements of matrix
        }
        
        sumTriangles(r, mat);
        
        cout<<endl;
    }
    return 0;
}
