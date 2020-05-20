/* 
Find the number of islands

Difficulty: Medium   Marks: 4
                                      
Problem Statement
A group of connected 1's forms an island. The task is to complete the method findIslands()
which returns the number of islands present. The function takes three arguments the first
is the boolean matrix A and then the next two arguments are N and M denoting the size(N*M) of the matrix A .

Input:
The first line of input will be the number of testcases T, then T test cases follow.
The first line of each testcase contains two space separated integers N and M.
Then in the next line are the NxM inputs of the matrix A separated by space .

Output:
For each testcase in a new line, print the number of islands present.

Constraints:
1 <= T <= 100
1 <= N, M <= 100
0 <= A[i][j] <= 1

Example(To be used only for expected output) :
Input
2
3 3
1 1 0 0 0 1 1 0 1
4 4
1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

Output
2
2

Explanation:
Testcase 1: The graph will look like
1 1 0
0 0 1
1 0 1
Here, two islands will be formed
First island will be formed by elements {A[0][0] ,  A[0][1], A[1][2], A[2][2]}
Second island will be formed by {A[2][0]}.s
 */

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}

/* 
THEORY CONNECTED COMPONENT
Before we go to the problem, let us understand what is a connected component.
A connected component of an undirected graph is a subgraph in which every two
vertices are connected to each other by a path(s),
and which is connected to no other vertices outside the subgraph.
A graph where all vertices are connected with each other has exactly one connected component,
consisting of the whole graph. Such a graph with only one connected component is called a Strongly Connected Graph.
 */

/*
This is a variation of the standard problem: “Counting the number of connected components in an undirected graph”.

The problem can be easily solved by applying DFS() on each component.
In each DFS() call, a component or a sub-graph is visited.
We will call DFS on the next un-visited component.
The number of calls to DFS() gives the number of connected components.
BFS can also be used.

What is an island?
A group of connected 1s forms an island. For example, the below matrix contains 5 islands

                        {1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1}
Note: Keep in mind that you need to cover all the 8 neighbours (instead of 4 in normal case).
A cell in 2D matrix can be connected to 8 neighbours.
So, unlike standard DFS(), where we recursively call for all adjacent vertices,
here we can recursively call for 8 neighbours only.
We keep track of the visited 1s so that they are not visited again.
*/
bool isSafe(int row, int col, int N, int M, bool **visited, vector<int> A[]) {
    if (row >= 0 && row < N && col >= 0 && col < M && A[row][col] && visited[row][col] == false)
        return true;
    return false;
}

void dfs(vector<int> A[], int row, int col, bool **visited, int N, int M) {
    visited[row][col] = true;
    
    int nextRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int nextCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for(int i = 0; i < 8; i++) {
        if (isSafe(row + nextRow[i], col + nextCol[i], N, M, visited, A))
            dfs(A, row + nextRow[i], col + nextCol[i], visited, N, M);
    }
}

int findIslands(vector<int> A[], int N, int M) {
    bool **visited = new bool*[N] ;
    for(int i = 0; i < N; i++)
        visited[i] = new bool[M];
        
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            visited[i][j] = false;
            
    int count = 0;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            if (A[i][j] && visited[i][j] == false) {
                dfs(A, i, j, visited, N, M);
                count++;
            }
        }
    return count;
}
// NOTE: This problem can also be solved using Disjoint Set

// TIME COMPLEXITY:  O(ROW x COL) = O(N*M)

// COMPANY TAGS: Amazon, Cisco, D-E-Shaw, Informatica, Intuit, LinkedIn, Microsoft, Ola Cabs, One97,
// Opera, OYO Rooms, Paytm, Samsung, Snapdeal, Streamoid Technologies, Visa
