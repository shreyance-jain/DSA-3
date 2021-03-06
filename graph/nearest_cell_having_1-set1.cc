/* 
Distance of nearest cell having 1

Difficulty: Medium

Problem Statement

Given a binary matrix of size N x M.
The task is to find the distance of nearest 1 in the matrix for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the
row number and column number of the current cell and i2, j2
are the row number and column number of the nearest cell having value 1.

Input:
The first line of input is an integer T denoting the number of test cases. Then T test cases follow.
Each test case consists of 2 lines. The first line of each test case contains two integers M and N
denoting the number of rows and columns of matrix. Then in the next line are N*M space separated
values of the matrix (mat) .

Output:
For each test case in a new line print the required distance matrix in a single line separated by space.

Constraints:
1 <= T <= 50
1 <= N, M <= 1000
0 <= mat[i][j] <= 1

Example:
Input:
2
2 2 
1 0 0 1
1 2
1 1

Output:
0 1 1 0
0 0

Explanation:
Testcase 1:
1 0
0 1
0 at {0, 1} and 0 at {1, 0} are at 1 distance from 1s at {0, 0} and {1, 1} respectively.
 */
#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> &arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << "\n";
}

void nearest(vector<vector<int>> &arr, int row, int col);
int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        nearest(graph, row, col);
    }

    return 0;
}

/* 
Approach: 
DFS Based approach: Multi-source DFS based approach
Creating a visited matrix for backtracking
And a source matrix to perform dfs on source of
this multi-source DFS based approach.

Idea is to perform dfs on all 4 neighbours, use concept of backtracking
and perform relax operation based on distance from source node
Multi-source dfs concept is used and it calls dfs in outer loop
for vertices with value 1

Coding style is similar to count number of islands
 */
bool isSafe(int row, int col, int R, int C, vector<vector<int>> &arr, vector<vector<bool>> &source) {
    if (row < 0 || row >= R || col < 0 || col >= C || (arr[row][col] == 1 && source[row][col] == 1))
        return false;
    return true;
}

void dfs(vector<vector<int>> &arr, vector<vector<bool>> &source, int row, int col, int R, int C, int dist_from_nearest_1, vector<vector<bool>> &visited) {
    // out of bound check and source check
    if (!isSafe(row, col, R, C, arr, source))
        return;
    
    visited[row][col] = true;

    int nextRow[] = {0, 0, -1, 1};
    int nextCol[] = {-1, 1, 0, 0};
    
    if (arr[row][col] == 0) {
        arr[row][col] = dist_from_nearest_1;
    } else if (arr[row][col] > dist_from_nearest_1) {
        arr[row][col] = dist_from_nearest_1;
    }
    
    for(int i = 0; i < 4; i++) {
        int nextR = row + nextRow[i];
        int nextC = col + nextCol[i];
        if (isSafe(nextR, nextC, R, C, arr, source) && visited[nextR][nextC] == false)
            dfs(arr, source, nextR, nextC, R, C, dist_from_nearest_1+1, visited);
    }
    visited[row][col] = false;
}

void nearest(vector<vector<int>> &arr, int row, int col) {
    
    // DFS Based approach
    // might have to take visited matrix
    // perform relax operation
    
    vector<vector<bool>> source(row, vector<bool>(col, false));
    vector<vector<bool>> visited(row, vector<bool>(col, false));
     
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            if (arr[i][j] == 1) {
                source[i][j] = true;
            }
        }
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            if (arr[i][j] == 1 && source[i][j] == true) {
                // We have to call for all the neighbour vertices
                // if we don't then, though all the vertices would be reachable
                // but the difference will come in distance from nearest 1
                // (beacuse ifSafe function is returning false for source)
                dfs(arr, source, i, j-1, row, col, 1, visited);
                dfs(arr, source, i, j+1, row, col, 1, visited);
                dfs(arr, source, i-1, j, row, col, 1, visited);
                dfs(arr, source, i+1, j, row, col, 1, visited);
            }
        }
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            if (source[i][j] == true) {
                arr[i][j] = 0;
            }
        }
    
    print(arr, row, col);
}

// NOTE: Code gives TLE
// this is why BFS is best to solve shortest distance based problemss

// TIME COMPLEXITY: traversing every element is matrix is (M*N)
// and is is traversing the complete matrix for every source vertex
// so we can say greater then O(M*N)
// If every vertex is source vertex we have an optimisation in code which check if is source vertex
// then return, so in that case we will be simply calling the function for every vertex and
// no other work, so it will be Theta(M*N) in that case
