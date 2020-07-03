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
