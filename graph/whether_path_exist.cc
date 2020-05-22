/*
Find whether path exist

Difficulty: Medium
                
Problems
Given a N X N matrix (M) filled with 1, 0, 2, 3.
The task is to find whether there is a path possible from source to destination,
while traversing through blank cells only.
You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.


Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow.
Each test case consists of 2 lines. The first line of each test case contains an integer N
denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix (M).

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1 <= T <= 20
1 <= N <= 20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:
Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.
Testcase 2: The matrix for the above given input is:
0 3 2
3 0 0
1 0 0
From the matrix we can see that there does not exists any path to reach destination 2 from source 1.

 */

#include<bits/stdc++.h>
using namespace std;

bool path(vector<int> adj[], int N);

int main()
 {
	//code
	int T;
	cin >> T;
	while (T--) {
	    int N;
	    cin >> N;
	    vector<int> adj[N];
	    for(int i = 0; i < N; i++) {
	        vector<int> temp(N);
	        adj[i] = temp;
	        for(int j = 0; j < N; j++)
	            cin >> adj[i][j];
	    }
	    cout << path(adj, N);
	    cout << endl;
	}
	return 0;
}

/* 
Approach: DFS is best suited for path problems
Coding approach is similar to Number of Islands
 */
bool isSafe(int row, int col, int N, vector<int> adj[], bool **visited) {
    if (row >= 0 && row < N && col >= 0 && col < N &&
        visited[row][col] == false && (adj[row][col] == 3 || adj[row][col] == 2))
        return true;
    return false;
}

bool dfs (vector<int> adj[], int row, int col, int N, bool **visited) {
    visited[row][col] = true;
    
    if (adj[row][col] == 2)
        return true;
    
    int nextRow[] = {0, 0, -1, 1};
    int nextCol[] = {-1, 1, 0, 0};
    
    for(int i = 0; i < 4; i++) {
        if (isSafe(row + nextRow[i], col + nextCol[i], N, adj, visited) &&
        dfs(adj, row + nextRow[i], col + nextCol[i], N, visited) == true)
            return true;
    }
    return false;
}

bool path(vector<int> adj[], int N) {
    
    int sourceRow, sourceCol;

    bool **visited = new bool*[N];
    for(int i = 0; i < N; i++)
        visited[i] = new bool[N];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) 
            visited[i][j] = false;
            
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            if (adj[i][j] == 1) {
                sourceRow = i;
                sourceCol = j;
            }
        }

    return dfs(adj, sourceRow, sourceCol, N, visited);
}

// TIME COMPLEXITY: Same as DFS: O(ROW x COL) = O(N*M), since we visit the 

// Company Tags: Adobe, Amazon, Morgan Stanley, Samsung
