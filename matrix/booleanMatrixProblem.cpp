/*
Boolean Matrix Problem

Problem Statement:

Given a boolean matrix mat[r][c] of size r X c, modify it such that 
if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.


Input Format:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is r and c, r is the number of rows and c is the number of columns.
The next r lines contain c elements having either 0 or 1 and separated by spaces.

Output Format:
Print the modified array.

Constraints:
1 ≤ T ≤ 100
1 ≤ r, c ≤ 1000
0 ≤ A[i][j] ≤ 1

Example:
Input:
3
2 2
1 0
0 0
2 3
0 0 0 
0 0 1
4 3
1 0 0
1 0 0
1 0 0
0 0 0

Output:
1 1
1 0
0 0 1 
1 1 1
1 1 1
1 1 1
1 0 0
*/


/*
Approach: // variables to check if there are any 1 
    // in first row and column 
This method is a space optimized version of above method 1. 
This method uses the first row and first column of the input matrix in place of 
the auxiliary arrays row[] and col[] of method 1. 
So what we do is: first take care of first row and column and store the info about 
these two in two flag variables rowFlag and colFlag. Once we have this info, 
we can use first row and first column as auxiliary arrays and apply method 1 
for submatrix (matrix excluding first row and first column) of size (M-1)*(N-1).

1) Scan the first row and set a variable rowFlag to indicate whether we need to set all 1s
in first row or not.
2) Scan the first column and set a variable colFlag to indicate whether we need to set all 1s
in first column or not.
3) Use first row and first column as the auxiliary arrays row[] and col[] respectively, 
consider the matrix as submatrix starting from second row and second column and apply method 1.
4) Finally, using rowFlag and colFlag, update first row and first column if needed.

Time Complexity: O(M*N)
Auxiliary Space: O(1)*/


#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000

/*This is a function problem.You only need to complete the function given below*/
//Complete this function
void booleanMatrix(int r, int c, int a[SIZE][SIZE])
{
    // variables to check if there are any 1 
    // in first row and column 
    bool rowFlag = false, colFlag = false;

    // updating the first row and col if 1 is encountered 
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++){
            if (i == 0 && a[i][j] == 1) {
                rowFlag = true;
            }
            if (j == 0 && a[j][j] == 1) {
                colFlag = true;
            }
            if (a[i][j] == 1) {
                a[0][j] = 1;
                a[i][0] = 1;
            }
        }
    }
    

    // Modify the input matrix a[] using the 
    // first row and first column of Matrix a
    for(int i = 1; i < r; i++){
        for(int j = 1; j < c; j++){
            if (a[0][j] == 1 || a[i][0] == 1) {
                a[i][j] = 1;
            }
        }
    }
    
    // modify first row if there was any 1 
    if (rowFlag) {
        for(int i = 0; i < r; i++) {
            a[i][0] = 1;
        }
    }
    
    // modify first col if there was any 1 
    if (colFlag) {
        for(int j = 0; j < c; j++) {
            a[0][j] = 1;
        }
    }
    
    // print matrix
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
	
	int t;
    cin >> t;
    
    while(t--){
        int r,c;
    
        cin >> r >> c; //input the number of rows and columns
        
        int a[SIZE][SIZE]; 
        
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                cin >> a[i][j]; //input the matrix
            }
        }
        
        booleanMatrix(r, c, a);
            
    }
	
	return 0;
}
