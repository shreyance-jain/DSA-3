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

void nearest(vector<vector<int>> &arr, int row, int col) {
    
    vector<vector<int>> sol(row, vector<int>(col, INT_MAX));

    queue<pair<int, int>> que;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j]) {
                sol[i][j] = 0;
                // insert all cells that contains 1 into the queue
                que.push(make_pair(i, j));
            }
        }
    }

    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        int x = p.first;
        int y = p.second;
        // check for the adjacent cells
        if ((x > 0) && (sol[x - 1][y] == INT_MAX)) {
            sol[x - 1][y] = sol[x][y] + 1;
            que.push(make_pair(x - 1, y));
        }
        if ((x < (row - 1)) && (sol[x + 1][y] == INT_MAX)) {
            sol[x + 1][y] = sol[x][y] + 1;
            que.push(make_pair(x + 1, y));
        }
        if ((y > 0) && (sol[x][y - 1] == INT_MAX)) {
            sol[x][y - 1] = sol[x][y] + 1;
            que.push(make_pair(x, y - 1));
        }
        if ((y < (col - 1)) && (sol[x][y + 1] == INT_MAX)) {
            sol[x][y + 1] = sol[x][y] + 1;
            que.push(make_pair(x, y + 1));
        }
    }

    print(sol, row, col);
}

// TIME COMPLEXITY: same as BFS O(M*N)

// NOTE: Based on BFS concept, visits nodes in shortest path manner
