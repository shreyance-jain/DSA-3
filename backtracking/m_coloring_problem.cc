/* 

M-Coloring Problem

Difficulty: Medium

Problem Statement

Given an undirected graph and an integer M. 
The task is to determine if the graph can be colored with at 
most M colors such that no two adjacent vertices of the graph 
are colored with the same color. 
Here coloring of a graph means the assignment of colors to all vertices. 
Print 1 if it is possible to colour vertices and 0 otherwise.

Input:
The first line of input contains an integer T 
denoting the number of test cases. Then T test cases follow. 
Each test case consists of four lines. 
The first line of each test case contains an integer N 
denoting the number of vertices. 
The second line of each test case contains an integer M 
denoting the number of colors available. 
The third line of each test case contains an integer E 
denoting the number of edges available. 
The fourth line of each test case contains E pairs of 
space-separated integers denoting the edges between vertices.

Output:
For each test case, print 1 if coloring is possible otherwise 0.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function graphColoring() 
which takes the 2d-array graph[], the number of colours and 
the number of nodes as inputs and returns 1 if answer exists otherwise 0.
Note: In the given 2d-array graph[], if there is an edge between vertex X 
and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0.

Expected Time Complexity: O(M^N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 20
1 <= E <= (N*(N-1))/2
1 <= M <= N

Example:
Input :
2
4
3
5
1 2 2 3 3 4 4 1 1 3
3
2
3
1 2 2 3 1 3

Output:
1
0

Explanation:
Testcase 1: It is possible to colour the given graph using 3 colours.

Note: The given inputs are 1-base indexed but you have to consider the graph 
given in the adjacency matrix/list as 0-base indexed.
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}


bool isSafe(bool graph[101][101], int color[], int v, int c) {
    // we check only upto current vertx because we are putting color
    // one by one from vertex 0 ...v...V
    for(int i = 0; i < v; i++) {
        // color c should not be same as color of any adjacent vertex of vertex v
        if (graph[v][i] && c == color[i])
            return false;
    }
    // return true if no connected node has the same color
    return true;
}

// Main Recursion function same like Sudoku Problem
bool colorUtil(bool graph[101][101], int color[], int m, int v, int V) {
    // all vertices has been assigned return true
    if (v == V) {
        return true;
    }
    // try putting the color one by one
    for(int c = 1; c <= m; c++) {
        // check if safe to put color c to vertex v 
        // i.e. this color should not be matching with
        // any of the adjacent vertex of the current vertex
        if (isSafe(graph, color, v, c)) {
            color[v] = c;
            // put the color and recur for next (v+1) vertex
            if (colorUtil(graph, color, m, v+1, V) == true)
            // return true if solution found/current allocation was successful
                return true;
            // backtrack => uncolor the vertex again and try the other color
            color[v] = 0;
        }
    }
    // if none of the color can be put return false
    return false;
}

// Like current sum vector in the combination sum matrix
// we will keep a color array of size V (no of vertices)
// which will store the color of each vertex in the current call
bool graphColoring(bool graph[101][101], int m, int V) {
    int color[V];
    for(int i = 0; i < V; i++)
        color[i] = 0;
    
    return colorUtil(graph, color, m, 0, V);
}


// Time Complexity: O(M ^ N), N vertices and for every vertex we try M colors
// Aux Space Complexity: O(N), for color array which stores color of N vertices in recursion call

// Company Tags: Amazon
