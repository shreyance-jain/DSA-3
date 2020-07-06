/* 
Rat in a Maze Problem
Difficulty: Medium
      
Problems
Consider a rat placed at (0, 0) in a square matrix of order N*N.
It has to reach the destination at (n-1, n-1).
Find all possible paths that the rat can take to reach from source to destination.
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed
while value 1 at a cell in the matrix represents that it can be travelled through.

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. Each test case contains two lines.
The first line contains an integer N denoting the size of the square matrix.
The next line contains N*N space separated values of the matrix m where 0's 
represents blocked paths and 1 represent valid paths.

Output:
For each test case, the output will be space separated sorted strings denoting all directions, 
which the rat could take to reach the destination. 
Print -1 if no such path exists.

User Task:
Your task is to complete the function printPath() which returns 
a sorted array of strings denoting all the possible paths which 
the rat can take to reach the destination at (n-1, n-1). 
If no such path exists the function should return an empty array.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L*X), L = length of the path, X = number of paths.


Constraints:
1 <= T <= 100
2 <= N <= 5
0 <= matrix[i][j] <= 1

Example
Input:
3
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
2
1 0 1 0 

Output:
DRDDRR
DDRDRR DRDDRR
-1

Explanation:
Testcase 2: The given input is in the form
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 5

vector<string> printPath(int m[MAX][MAX], int n);

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int m[MAX][MAX];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> m[i][j];
    
    vector<string> result = printPath(m, n);
    if (result.size() == 0)
      cout << "-1";
    else
      for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
  }
  return 0;
}

void path(int m[MAX][MAX], int n, string dir, vector<string> &res, int x, int y, int visited[MAX][MAX]) {
  if (x == n-1 && y == n-1 && m[x][y] == 1) {
    res.push_back(dir);
    return;
  }
  // is safe (index bounds checked when making the call)
  if (m[x][y] == 0 || visited[x][y] == 1) return;
  
  // DFS
  visited[x][y] = 1;
  // up
  if (x > 0) path(m, n, dir+'U', res, x-1, y, visited);
  // left
  if (y > 0) path(m, n, dir+'L', res, x, y-1, visited);
  // right
  if (x < n-1) path(m, n, dir+'D', res, x+1, y, visited);
  // down
  if (y < n-1) path(m, n, dir+'R', res, x, y+1, visited);
  visited[x][y] = 0;
}

vector<string> printPath(int m[MAX][MAX], int n) {
  // visited to avoid cycles
  // (or we can use the input matrix for this purspose
  // by marking the current node as 0 like '0' in 'X', '0' path question)
  int visited[MAX][MAX];
  memset(visited, 0, sizeof(visited));

  vector<string> result;
  result.clear();
  // optimisation by checking corner cases
  // if the source(first) or the desitnation(last) is blocked
  if (m[0][0] == 0 || m[n-1][n-1] == 0) return result;

  path(m, n, "", result, 0, 0, visited);
  sort(result.begin(), result.end());
  return result;
}

// Time Complexity: O((N^2)^4)
// Space Complexity: O(L*X), L = lenght of paths, X = no of paths

// Company tags: Amazon
