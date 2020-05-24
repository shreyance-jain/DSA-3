/* 

Unit Area of largest region of 1's

Difficulty: Medium
       
Problem Statement

Consider a matrix with N rows and M columns, where each cell
contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell.
Two cells are said to be connected if they are adjacent to each other horizontally,
vertically, or diagonally. If one or more filled cells are connected, they form a region.
The task is to find the unit area of the largest region.

Input:
The first line of input will be the number of testcases T, then T testcases follow.
The first line of each testcase contains 2 space separated integers n and m.
Then in the next line are the nxm inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1 <= T <= 100
1 <= N, M <= 100
0 <= A[ ][ ] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1

Largest region of 1s in the above matrix is with total 4 1s (colored in Red).
 */

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100
int findMaxArea(int n, int m, int g[SIZE][SIZE]);

/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   g[][]: 2D matrix from input
*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
} 

/* 
Idea is based on the problem of finding number of islands in Boolean 2D-matrix
A cell in 2D matrix can be connected to at most 8 neighbors.
So in DFS, we make recursive calls for 8 neighbors.
We keep track of the visited 1’s in every DFS and update maximum length region. 
 */
bool isSafe(int adjrow, int adjcol, int n, int m) {
    if (adjrow >= 0 && adjrow < n && adjcol >= 0 && adjcol < m)
        return true;
    return false;
}

void dfs(int g[SIZE][SIZE], bool visited[SIZE][SIZE], int row, int col, int n, int m, int &number_of_one) {
    visited[row][col] = true;
    number_of_one++;
    
    int nextRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int nextCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for(int i = 0; i < 8; i++) {
        int adjrow = row + nextRow[i];
        int adjcol = col + nextCol[i];
        
        if (isSafe(adjrow, adjcol, n, m) && visited[adjrow][adjcol] == false && g[adjrow][adjcol] == 1)
            dfs(g, visited, adjrow, adjcol, n, m, number_of_one);
    }
}

int findMaxArea(int n, int m, int g[SIZE][SIZE] )
{
    // since SIZE is constant and is present as global variable
    // we can skip creating dynamic 2D matrix
    bool visited[SIZE][SIZE] = {false};
        
    // sometimes if it is allowed to modify the input we can avoid use of visited matrix
    // and in the binary input matrix make 1 as 0 After visited/processed
    
    // perform dfs
    int res = INT_MIN;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if (g[i][j] == 1 && visited[i][j] == false) {
                int number_of_one = 0;
                dfs(g, visited, i, j, n, m, number_of_one);
                res = max(number_of_one, res);
            }
        }
    return res;
}

// TIME COMPLEXITY:  O(ROW x COL) = O(N*M)

// COMPANY TAGS: Amazon, Flipkart, Microsoft, Ola Cabs, Salesforce, Samsung
