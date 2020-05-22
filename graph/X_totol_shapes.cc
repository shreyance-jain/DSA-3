/* 

X Total Shapes

Difficulty: Medium

Problem Statement

Given N * M string array of O's and X's. The task is to find the number of 'X' total shapes.
'X' shape consists of one or more adjacent X's (diagonals not included).

Input: The first line of input takes the number of test cases T. Then T test cases follow.
Each of the T test cases takes 2 input lines. The first line of each test case have
two integers N and M.The second line of N space separated strings follow which
indicate the elements in the array.

Output:
For each testcase, print number of shapes.

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

Explanation:
Testcase 1: Given input is like:
OOOOXXO
OXOXOOX
XXXXOXO
OXXXOOO

So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included).
So, there are 4 different groups in the given matrix.

Testcase 2: Given input is like:
XXO
OOX
OXO
OOO
XOX
XOX
OXO
XXO
XXX
OOO
So, this matrix has 6 groups with is having adjacent Xs. Total number of groups is 6.
 */

#include<bits/stdc++.h>
using namespace std;

int countXShapes(char **adj, int N, int M);

int main()
 {
	//code
	int T;
	cin >> T;
	while(T--) {
	    int N, M;
	    cin >> N >> M;
	    string str;
	    char **adj = new char*[N];
	    for(int i = 0; i < N; i++) {
	        cin >> str;
	        adj[i] = new char[M];
	        for(int j = 0; j < M; j++)
	            adj[i][j] = str[j];
	    }
	    cout << countXShapes(adj, N, M) << endl;
	}
	return 0;
}

/* 
Approach: 
Naive Approach: Same as number of islands
Maintains a visited array and recur on all the 4 allowed directions
 */
bool isSafe(char **adj, int row, int col, bool **visited, int N, int M) {
    if (row >= 0 && row < N && col >= 0 & col < M &&
        visited[row][col] == false && adj[row][col] == 'X')
        return true;
    return false;
}

void dfs(char **adj, int row, int col, bool **visited, int N, int M) {
    visited[row][col] = true;
    
    int nextRow[]= {0, 0, 1, -1};
    int nextCol[] = {-1, 1, 0, 0};
    
    for(int i = 0; i < 4; i++)
        if (isSafe(adj, row + nextRow[i], col + nextCol[i], visited, N, M))
            dfs(adj, row + nextRow[i], col + nextCol[i], visited, N, M);
}

int countXShapes(char **adj, int N, int M) {
    bool **visited = new bool*[N];
    for(int i = 0; i < N; i++)
        visited[i] = new bool[M];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            visited[i][j] = false;
    
    int count = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            if (visited[i][j] == false && adj[i][j] == 'X') {
                dfs(adj, i, j, visited, N, M);
                count++;
            }
        }
    return count;
}

/* Naive approach contains a lot of redundant code, see set-2 for the efficient and pro code */
// Time Complexity: Same as DFS of adjacency matrix

// Company Tags: Amazon, Google
