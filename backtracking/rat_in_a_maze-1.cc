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

bool isSafe(vector<vector<int> >  maze, int x, int y, int n) {
  return (x < n && y < n && maze[x][y]);
}

bool solveMazeUtil(vector<vector<int> >  maze, int x, int y, vector<vector<int> >  &sol, int N) {
  if (x == N-1 && y == N-1 && maze[x][y] == 1) {
    sol[x][y] = 1;
    return true;
  }
  if (isSafe(maze, x, y, N)) {
    sol[x][y] = 1;
    if (solveMazeUtil(maze, x + 1, y, sol, N) == true)
      return true;
    if (solveMazeUtil(maze, x, y + 1, sol, N) == true)
      return true;
    sol[x][y] = 0;
  }
  return false;
}

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
