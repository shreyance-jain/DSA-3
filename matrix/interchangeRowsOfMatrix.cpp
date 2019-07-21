/*
Interchanging the rows of a Matrix

Problem Statement:
You are given a matrix A of dimensions n1 x m1. 
You have to interchange the rows(first row becomes last row and so on).

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. 
Each testcase two lines of input. 
The first line contains dimensions of the array A, n1 and m1. 
The second line contains n1 * m1 elements separated by spaces.

Output Format:
For each testcase, in a new line, print the resultant matrix.

Your Task:
This is a function problem. You only need to complete the function interchangeRows() 
that takes n1,m1, and matrix as parameter and modifies the array. 
The driver code automatically appends a new line.

Constraints:
1 <= T <= 100
1 <= n1, m1 <= 30
1 <= arri <= 100

Examples:
Input:
1
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

Output:
13 14 15 16 9 10 11 12 5 6 7 8 1 2 3 4

Explanation:
Testcase 1: Original matrix is as follows:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Matrix after exchanging rows:
13 14 15 16
9 10 11 12
5 6 7 8
1 2 3 4
*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 50

void interchangeRows(int n1, int m1, int arr1[SIZE][SIZE])
{
    for(int i = 0; i < m1; i++) {
        int start = 0, end = n1-1;
        while(start < end) {
            swap(arr1[start][i], arr1[end][i]);
            start++;
            end--;
        }
    }
}


int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n1,m1;
        cin>>n1>>m1;
        int arr1[SIZE][SIZE];
        for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
        cin>>arr1[i][j];
        
        interchangeRows(n1, m1, arr1);
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<m1;j++)
            cout<<arr1[i][j]<<" ";
        }
        
        cout<<endl;
    }
    
	return 0;
}