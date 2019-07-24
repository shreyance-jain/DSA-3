/*
Make Matrix Beautiful

Problem Statement:

Given a Square matrix mat[] of size NxN. Your task is to find minimum number of operation(s)
that are required to make the matrix Beautiful.
A Beautiful matrix is a matrix in which sum of elements in each row and column is equal. 
In one operation you can only increment any value of cell of matrix by 1.

Input Format:
First line of the input contains an integer T denoting the number of test cases. 
Then T test case follows. First line of each test case contains an integer N denoting the 
size of the matrix. Next line contains NxN space separated integers denoting the elements 
of the matrix.

Output Format:
For each test case print a single integer in a new line denoting the minimum number of 
operations required that needed to be performed.

Constraints:
1 <= T <= 150
1 <= N <= 100
1 <= mat[i][j] <= 150

Example:
Input:
2
2
1 2 3 4
3
1 2 3 4 2 3 3 2 1

Output:
4
6

Explanation:
TestCase 1:
4 3
3 4
1. Increment value of cell(0, 0) by 3
2. Increment value of cell(0, 1) by 1
Hence total 4 operation are required.
*/


#include <bits/stdc++.h>
using namespace std;

// Function to find minimum number of operation
int findMinOpeartion(int matrix[][100], int n)
{
    int sumRow[n];
    int sumCol[n];
    // init with 0
    for(int i = 0; i < n; i++){
        sumRow[i] = 0;
        sumCol[i] = 0;
    }
    // cal row sum sumRow[]
    // cal col sum sumCol[]
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            sumRow[i] += matrix[i][j];
            sumCol[j] += matrix[i][j];
        }

    // Find maximum sum value in either row or in column 
    int maxSum = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        maxSum = max(maxSum, sumRow[i]);
        maxSum = max(maxSum, sumCol[i]);
    }

    // Find minimum increment required in either row or column 
    for(int i = 0, j = 0; i < n && j< n;){
        int diff = min(maxSum - sumRow[i],
                       maxSum - sumCol[j]);

        // Add difference in corresponding cell, sumRow[] and sumCol[] array 
        matrix[i][j] += diff;
        sumRow[i] += diff;
        sumCol[j] += diff;
        
        // Update the count variable 
        count += diff;
        // If ith row satisfied, increment ith value for next iteration 
        if (sumRow[i] == maxSum) ++i;
        // If jth column satisfied, increment jth value for next iteration 
        if (sumCol[j] == maxSum) ++j;
    }
    return count;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[n][100];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>mat[i][j];
        cout << findMinOpeartion(mat, n) << endl;
    }
    return 0;
}