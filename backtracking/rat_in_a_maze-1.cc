/* 
RAT IN A MAZE is an another example problem
that can be solved using BACKTRACKING

A Maze is given as N*N binary matrix of blocks where source block is the upper left most block
i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts
from source and has to reach the destination. The rat can move only in two directions: forward
and down.
In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the 
path from source to destination. Note that this is a simple version of the typical Maze problem. 
For example, a more complex version can be that the rat can move in 4 directions and a more 
complex version can be with a limited number of moves.
 */

/* 
BACKTRACKING ALGORITHM:
Backtracking is an alogrithmic technique for solving problem recursively by trying to build a solution
incrementally. Solving one piece at a time and remvoing those solutions which fail to satisfy the 
constraints of a problem at any point of time(by time, here , is referred to the time elapsed
till reaching any level of the search tree) it the process of backtracking
 */

/* Approach:
Form a recursive function, which will follow a path and check if the path reaches
the destination or not. If path does not reaches the destination the backtrack and try other paths
 */

/* Algorithm:
1. Create a solution matrix, initially filled with 0's
2. Create a recursive function, which takes initial matrix, output matrix and position of rat(i, j)
3. If position is out of the matrix or is not valid then return
4. Mark the position output[i][j] as 1 and check if the current position is destination or not.
  If destination is reached print the output matrix and return
5. Recursively call for position (i+1, j) and (i, j+1)
6. Unmark position (i,j) i.e. output[i][j] = 0
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solveMaze(vector<vector<int> >  maze, int n);

/* Utitlity function to print solution matrix */
void print(vector<vector<int> >  sol, int N) {
  cout << "Maze solved\n";
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++)
      cout << sol[i][j] << " ";
    cout << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<vector<int> >  maze(n);
    for(int i = 0; i < n; i++)
      maze[i] = vector<int>(n, 0);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> maze[i][j];
  solveMaze(maze, n);
  cout << endl;
  }
  return 0;
}

// BACKTRACKING STANDARD IS-SAFE FUNCTION
// Function to check if x and y is a vaid move
bool isSafe(vector<vector<int> >  maze, int x, int y, int n) {
  return (x < n && y < n && maze[x][y]);
}

bool solveMazeUtil(vector<vector<int> >  maze, int x, int y, vector<vector<int> >  &sol, int N) {
  // if x and y is goal return true
  if (x == N-1 && y == N-1 && maze[x][y] == 1) {
    sol[x][y] = 1;
    return true;
  }
  // check if x and y is valid move
  if (isSafe(maze, x, y, N)) {
    // mark x and y as the solution path
    sol[x][y] = 1;
    // move forward in downward(D) direction
    if (solveMazeUtil(maze, x + 1, y, sol, N) == true)
      return true;
    // if moving in downward direction doesn't give a solution
    // move forward in Right(D) direction
    if (solveMazeUtil(maze, x, y + 1, sol, N) == true)
      return true;
    // if none of the above movements work then BACKTRACK: unmark
    // x and y as part of the solution matrix
    sol[x][y] = 0;
  }
  return false;
}

// Wrapper over the main recursive function above
bool solveMaze(vector<vector<int> >  maze, int n) {
  vector<vector<int> >  sol(n);
  for(int i = 0; i < n; i++)
      sol[i] = vector<int>(n, 0);
  
  if (solveMazeUtil(maze, 0, 0, sol, n) == false) {
    cout << "Soulution does not exist" << endl;
    return false;
  } else {
    print(sol, n);
    return true;
  }
}

/* Complexity:
Time Complexity: O(2^(n^2))
The recursion can run upper bound 2^(n^2) times
Space Complexity:
For output matrix extra space n*n is needed
 */

/* 
POINT TO NOTE!
Problem statement restricts the rat to move in forward and downward
which in turn in equivalent to forcing the rat to move only in
forward direction which avoid cycle creation in path of rat
within the maze matrix
 */