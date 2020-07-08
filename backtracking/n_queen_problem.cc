/* 
N QUEEN PROBLEM
The N Queen is the problem of placing N chess queens on an N×N chessboard 
so that no two queens attack each other. 

For example, following is a solution for 4 Queen problem
The expected output is a binary matrix which has 1s for the blocks where queens are placed. 
for example, following is the output matrix for above 4 queen solution.

  { 0,  1,  0,  0}
  { 0,  0,  0,  1}
  { 1,  0,  0,  0}
  { 0,  0,  1,  0}
 */

/* 
Naive Algorithm
Generate all possible configurations of queens on board and 
print a configuration that satisfies the given constraints.
while there are untried configurations
{
   generate the next configuration
   if queens don't attack in this configuration then
   {
      print this configuration;
   }
}
 */

/* Backtracking Concept
The idea is to place queens one by one in different columns, 
starting from the leftmost column.
When we place a queen in a column, we check for clashes for already placed queens.
In the current column, if we find a row for which there is no clash, we mark this
row and column as part of the solution.
If we do not find such a row due to clashes then we backtrack and return false
 */

/* Backtracking Algorithm
1) Start with the leftmost column
2) If all queens are placed
    return true
3) Try all rows in current column
  Do the following for every tried row
  a) If the queen can be placed safely in this row
    then mark this [row, column] as part of the solution
    and recursively check if placing queen here leads to
    a solution
  b) If placing the queen in [row, column] leads to a solution
    then return true
  c) If placing queen doesn't lead to a solution then 
    unmark this [row, column] (Backtrack) and go to step(a)
    to try other rows
4) If all rows have been tried and nothing worked, 
  return false to trigger backtracking
 */

#include<iostream>
#include<vector>
#include<cstring>
#define MAX 10
using namespace std;

void nqueen(int n);

int main()
 {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    nqueen(n);
	}
	return 0;
}

/* A utility function to print solution */
void print(int placement[MAX][MAX], int n) {
    vector<int> rows;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++)
            cout << placement[i][j] << " ";
      cout << endl;
    }
}

/* A utility function to check if a queen can 
   be placed on board[row][col]. Note that this 
   function is called when "col" queens are 
   already placed in columns from 0 to col-1. 
   So we need to check only left side for 
   attacking queens*/
bool isSafe(int placement[MAX][MAX], int col, int row, int n) {
    // check this row on the left side
    for(int i = 0; i < col; i++)
        if(placement[row][i] == 1)
            return false;
    // check upper diagnol on left side
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (placement[i][j] == 1)
            return false;
    // check lower diagnol on left side
    for(int i = row, j = col; i < n && j >= 0; i++, j--)
        if(placement[i][j] == 1)
            return false;
    return true;
}
/* Recursive backtracking functon */
bool nqueenUtil(int col, int placement[MAX][MAX], int n) {
  // if all queens are placed
    if (col == n) {
        print(placement, n);
        return true;
    }
    // Consider this column and try placing this queen
    // in all rows one by one
    for(int i = 0; i < n; i++) {
      // check if the queen can be placed on board[i][col]
        if (isSafe(placement, col, i, n)) {
          // Place this queen in board[i][col]
            placement[i][col] = 1;

            // recur to place rest of the queens
            if (nqueenUtil(col+1, placement, n))
                return true;
            
            // If placing queen in board[i][col] doesn't lead to a
            // solution, then remove queen from board[i][col]
            placement[i][col] = 0; // BACKTRACK
        }
    }
    // If queen cannot be placed in any row in this column col
    // then return false
    return false;
}

// Wrapper over the main recursive function
// NOTE: This solution prints one of the feasible solutions
// there may be more solutions
void nqueen(int n) {
    int placement[MAX][MAX];
    memset(placement, 0, sizeof(placement));
    bool res = nqueenUtil(0, placement, n);
    if (!res)
        cout << -1;
    cout << endl;
}

// Compnay Tags: Accolite, Amazon, Amdocs, DE-Shaw, MAQ Software, Twitter, Visa
