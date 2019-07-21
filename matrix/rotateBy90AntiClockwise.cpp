/*
Given a square matrix mat[][] of size N x N. 
The task is to rotate it by 90 degrees in anti-clockwise direction without using any extra space.


Input:
The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consist of two lines. 
The first line of each test case consists of an integer N, where N is the size of the 
square matrix. The second line of each test case contains N x N space separated values 
of the matrix mat.

Output:
Corresponding to each test case, in a new line, print the rotated matrix. 

User Task:
The task is to complete the function rotateby90() which rotates the input matrix by 90 degree.
You just need to rotate the matrix, printing the matrix will be automatically done the 
driver code.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 50
1 <= mat[][] <= 100

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9
2
1 2 3 4
Output:
3 6 9 2 5 8 1 4 7
2 4 1 3


Explanation:
Testcase 1: Matrix is as below:
1 2 3
4 5 6
7 8 9

Rotating it by 90 degrees in anticlockwise directions will result as below matrix:
3 6 9
2 5 8
1 4 7
*/


#include<bits/stdc++.h>
using namespace std;
#define N 50


void transpose( int A[][N],int n) 
{ 
	// Your code here
	for(int i = 0; i < n; i++){
	    for (int j = i+1; j < n; j++){
	        swap(A[i][j], A[j][i]);
	    }
	}
}

void mirror(int a[][N], int n) {
    for(int i = 0; i < n; i++){
        int start = 0, end = n-1; // n is no of columns in matrix here
        while (start < end) {
            swap(a[i][start], a[i][end]);
            start++;
            end--;
        }
    }
}

/*  Function to rotate matrix by 90 degrees
*   n: input for matrix size
*   N: size defined globally
*/
void rotateby90(int n, int a[][N]){
    
    mirror(a, n);
    transpose(a, n);
}

int main()
{
	int t;
	cin>>t; //inputting testcases
	while(t--)
	{
		int n;
		cin>>n; //inputing n for square matrix
		int a[N][N],i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j]; //Inputting the matrix
			}
		}
		
		rotateby90(n, a);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<a[i][j]<<" "; //printing the resultant matrix
			}
		}
		cout<<endl;
	    
	}
	return 0;
}
