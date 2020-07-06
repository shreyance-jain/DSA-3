/* 
RAT MAZE WITH MULTIPLE JUMPS

A Maze is given as N*N matrix of blocks where 
source block is the upper left most block i.e., maze[0][0] and 
destination block is lower rightmost block i.e., maze[N-1][N-1]. 
Find the minimum number of Hops required for the rat to reach 
from the source block to the destination block. 
The number of steps rat can jump from (i, j) is represented by maze[i][j].

Note:
If multiple solutions exist, the shortest earliest hop will be accepted. 
For the same hop distance at any point, forward will be preferred over downward.
In the maze matrix, 0 means the block is the dead end and non-zero number means 
the block can be used in the path from source to destination. 
The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j].

Input:
The first line of input contains an integer T denoting the number of test cases. 
For each test case, the first line contains an integer n denoting the size of the 
square matrix followed by N*N space-separated values of the matrix maze with each 
row in new line where 0's represents blocked paths and any number represents valid paths. 

Output:
For each test case, the output is a matrix containing 1 for the path taken and 
0 for not chosen path. 
If no path exists print -1. 

Expected Time Complexity: O(N^N).
Expected Auxiliary Space: O(N) if we don't consider the solution matrix for this.

Constraints:
1 <= T <= 50
2 <= n <= 50
0 <= maze[i][j] <= 20

Example:
Input
2
4 
2 1 0 0
3 0 0 1
0 1 0 1
0 0 0 1
4
2 1 0 0
2 0 0 1
0 1 0 1
0 0 0 1

Output:
1 0 0 0
1 0 0 1
0 0 0 1
0 0 0 1
-1

Explanation:
Testcase 1:  Rat started with m[0][0] and can jump up to 2 steps right/down.
First check m[0][1] as it is 1, next check m[0][2], this won't lead to the solution. 
Then check m[1][0], as this is 3(non-zero), so we can make 3 jumps to reach m[1][3]. 
From m[1][3] we can move downwards taking 1 jump each time to reach destination at m[3][3].

Testcase 2: As no path exists, so -1.  
 */

/* 
POINT TO NOTE!
Problem statement restricts the rat to move in forward and downward
which in turn in equivalent to forcing the rat to move only in
forward direction which avoid cycle creation in path of rat
within the maze matrix
 */

#include <iostream>
#include <vector>
using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}

/* 
Naive Approach:
The Naive Algorithm is to generate all paths from source to destination
and one by one check if the generated path satisfies the constraints
Naive Algo:
while there are untried paths {
  generate the next path
  if this path hsa all blocks as non zero{
    print this path
  }
}
 */
/* Backtracking Approach:
If destination is reached print the matrix
  print the solution matrix
Else
  a) Mark the current cell in solution matrix as 1
  b) Move forward/jump (for each valid steps) in horizontal direction
     and recursively check if this leads to a solution
  c) If the move chosen in the above step doesn't lead to a solution
     then move down and check if this move leads to a solution
  d) If none of the above solutions work then unmark this cell as 0
     (BACKTRACK) and return false
 */
bool isSafe(int N, vector<int> maze[], int x, int y) {
  // the safe condition is when x and y are in bounds and matrix value is != 0
  return (x < N && y < N && maze[x][y] != 0);
}

bool solveUtil(int N, vector<int> maze[], vector<int> sol[], int x, int y) {
  // if condition matches return true, also base case
  if (x == N-1 && y ==  N-1) {
    // mark x and y as part of sol
    sol[x][y] = 1;
    return true;
  }
  if (isSafe(N, maze, x, y)) {
    // marking (x, y) as part of the current solution
    sol[x][y] = 1;

    // checking for further paths
    for(int i = 1; i <= maze[x][y] && i < N; i++) {
      if (solveUtil(N, maze, sol, x, y+i) == true)
        return true;
      else if (solveUtil(N, maze, sol, x+i, y) == true)
        return true;
    }
    // if no possible path in the direction, then mark (x,y) as
    // not part of the solution
    // DOING BACKTRACKING and RETRUN FALSE
    sol[x][y] = 0;
    return false;
  }
  // if not safe return false
  return false;
}

void solve(int N, vector<int> maze[]) {
  vector<int> sol[N];
  for(int i = 0; i < N; i++)
    sol[i] = vector<int>(N, 0);
    // if no path found
    if (solveUtil(N, maze, sol, 0, 0) == false) {
      cout << "-1" << endl;
    } else {
      // if path found
      print(N, sol);
    }
}

// To do - do time complexity analysis
// Time Complexity: O(N^N)
// Space Complexity: O(N) if we don't consider the solution matrix for this
