// { Driver Code Starts

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
Creating a distance matrix, initialise it with INT_MAX
for all source matrix set distance as 0
perform dfs on source of
this multi-source DFS based approach.

Idea is to perform dfs on all 4 neighbours
and perform relax operation based values of distance matrix
Multi-source dfs concept is used and it calls dfs in outer loop
for vertices with distance as 0
Coding style is similar to count number of islands
 */
bool isSafe(int row, int col, int R, int C) {
    if (row < 0 || row >= R || col < 0 || col >= C)
        return false;
    return true;
}

void dfs(vector<vector<int>> &arr, vector<vector<int>> &distance, int row, int col, int R, int C) {
    int nextRow[] = {0, 0, -1, 1};
    int nextCol[] = {-1, 1, 0, 0};
    
    for(int i = 0; i < 4; i++) {
        int nextR = row + nextRow[i];
        int nextC = col + nextCol[i];
        if (isSafe(nextR, nextC, R, C) && distance[nextR][nextC] > distance[row][col] + 1) {
            distance[nextR][nextC] = distance[row][col] + 1;
            dfs(arr, distance, nextR, nextC, R, C);
        }
    }
}

void nearest(vector<vector<int>> &arr, int row, int col) {
    
    // DFS Based approach
    // Use Distance Matrix
    vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
     
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            if (arr[i][j] == 1) {
                distance[i][j] = 0;
            }
        }
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if (distance[i][j] == 0)
                dfs(arr, distance, i, j, row, col);

    print(distance, row, col);
}

// NOTE: Code gives TLE
// this is why BFS is best to solve shortest distance based problems

// TIME COMPLEXITY: traversing every element is matrix is (M*N)
// and is is traversing the complete matrix for every source vertex
// so we can say greater then O(M*N)
// If every vertex is source vertex we have an optimisation in code which check if is source vertex
// then return, so in that case we will be simply calling the function for every vertex and
// no other work, so it will be Theta(M*N) in that case
