/* 

Solve the Sudoku

Difficulty: Hard

Problem Statement

Given an incomplete Sudoku configuration 
in terms of a 9 x 9  2-D square matrix (mat[][]). 
The task to print a solved Sudoku. 
For simplicity, you may assume that there 
will be only one unique solution.

Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains 9*9 space-separated 
values of the matrix mat[][] representing an incomplete Sudoku state 
where a 0 represents an empty block.

Output:
For each test case, in a new line, print the space-separated values 
of the solution of the sudoku, from the top row to bottom row, 
and for each row left to right.

User Task:
This is a Function problem where you need to
complete the two functions:
SolveSudoku(): Takes a grid as its argument and 
returns true if a solution is possible and false if it is not.
printGrid(): Takes a grid as its argument and prints 
the 81 numbers of the solved Sudoku in a single line.

Expected Time Complexity: O(9N*N).
Expected Auxiliary Space: O(N*N).

Constraints:
1 <= T <= 10
0 <= mat[] <= 9

Example:
Input:
1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

Output:
3 1 6 5 7 8 4 9 2 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 2 6 3 4 1 5 9 8 7 9 7 4 8 6 3 1 2 5 8 5 1 7 9 2 6 4 3 1 3 8 9 4 7 2 5 6 6 9 2 3 5 1 8 7 4 7 4 5 2 8 6 3 1 9

Explanation:
Testcase 1: The solved Sudoku is:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

 */
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}

/* Utitity funtion to print the output */
void printGrid (int grid[N][N]) 
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        // cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int n) {
    // check in same row and column
    for(int k = 0; k < N; k++)
        if (grid[row][k] == n || grid[k][col] == n)
            return false;
    
    // check in same subgrid
    int s = sqrt(N);
    int rs = row - (row % s);
    int cs = col - (col % s);
    
    for(int i = 0; i < s; i++)
        for(int j = 0; j < s; j++)
            if(grid[i + rs][j + cs] ==  n)
                return false;
    
    return true;
}

bool SolveSudoku(int grid[N][N])  
{ 
    int i, j;
    bool flag = false;
    // Find empty cell
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++)
            if (grid[i][j] == UNASSIGNED) {
                flag = true;
                break;
            }
        // remember to break from outer loop as well
        if (flag)
            break;
    }
    // if it doesn't break and if we reached end, return true as all are filled now
    if (i == N && j == N)
        return true;
    
    // if we reached here that means an empty cell,
    // try putting the no, check for safety before putting the no
    for(int n = 1; n <= N; n++) {
        // if safe
        if (isSafe(grid, i, j, n) == true) {
            // put the no
            grid[i][j] = n;
            // recur for remaining empty cells
            if (SolveSudoku(grid) == true)
                // after we have solved the solution recursively for remaining empty cells we are done
                // and we need to return true
                return true;
            // if recursive calls do not return true, then we need to BACKTRACK, we need to remove the
            // no. we placed and ttry the next no.
            grid[i][j] = 0;
        }
    }
    // if none of them worked, return false
    return false;
}

/* 
Time Complexity: O(9 ^ (N*N))
Space Complexity: O(N*N) // if we do not modify the original matrix
 */

// Company Tags: Amazon, Directi, Flipkart, MakeMyTrip, MAQ Software, Microsoft, Ola Cabs,
// Oracle, Paypal, Zoho
