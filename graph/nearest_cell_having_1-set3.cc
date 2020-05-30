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
BFS Based approach:
Creating a distance matrix, initialise it with INT_MAX
for all source matrix set distance as 0
perform dfs on source of

Idea is to perform bfs on all 4 neighbours
based on relax operation based values of distance matrix
 */
void nearest(vector<vector<int>> &arr, int row, int col) {
    
    // BFS Based approach
    // & perform relax operation
    vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
    queue<pair<int, int>> q;
     
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            if (arr[i][j] == 1) {
                distance[i][j] = 0;
                q.push({i, j});
            }
        }
    
    while(q.empty() == false) {
        pair<int, int> u = q.front();
        q.pop();
        
        int x = u.first;
        int y = u.second;
        
        int nextx[] = {0, 0, -1, 1};
        int nexty[] = {1, -1, 0, 0};
        
        // all 4 adjacent neighbours
        for(int i = 0; i < 4; i++) {
            int adjx = x + nextx[i];
            int adjy = y + nexty[i];
            // relax opertation
            if (adjx >= 0 && adjx < row && adjy >= 0 && adjy < col &&
                distance[adjx][adjy] > distance[x][y] + 1) {
                    // update distance
                    // & push to queue for further BFS, otherwise will check for
                    // only neighbours of initial elements in queue and stop there
                    distance[adjx][adjy] = distance[x][y] + 1;
                    q.push({adjx, adjy});
                }
        }
    }

    print(distance, row, col);
}

// TIME COMPLEXITY: traversing every element is matrix is (M*N)
// and is is traversing the matrix for every source vertex
// so we can say greater then O(M*N)

// NOTE: Here we would not vist a vertex twice as BFS visits in shortest
// path manner (see explicit implementation in set-5)
