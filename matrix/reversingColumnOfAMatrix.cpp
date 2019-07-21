/*
Reversing the columns of a Matrix

Problem Statement:
You are given a matrix A of dimensions n1 x m1.
The task is to reverse the columns(first column exchanged with last column and so on).

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. 
Each testcase two lines of input. 
The first line contains dimensions of the matrix A, n1 and m1. 
The second line contains n1*m1 elements separated by spaces.

Output Format:
For each testcase, in a new line, print the resultant matrix.

Constraints:
1 <= T <= 100
1 <= n1, m1 <= 30
0 <= arri <= 100

Examples:
Input:
1
4 3
1 2 3 5 6 7 9 10 11 13 14 15
Output:
3 2 1 7 6 5 11 10 9 15 14 13

Explanation:
Testcase 1: Original array is as follows:
1 2 3
5 6 7
9 10 11
13 14 15

Array after exchanging columns:
3 2 1
7 6 5
11 10 9
15 14 13
*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 50

void reverseCol(int n1, int m1, int arr1[SIZE][SIZE])
{
    for(int i = 0; i < n1; i++){
        int start = 0; int end = m1-1;
        while (start < end) {
            swap(arr1[i][start], arr1[i][end]);
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
        
        reverseCol(n1, m1, arr1);
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<m1;j++)
            cout<<arr1[i][j]<<" ";
        }
        
        cout<<endl;
    }
    
	return 0;
}