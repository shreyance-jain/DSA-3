/* 
DFS of Graph

Difficulty: Easy - connected and undirected graph we also have a source given

Problem Statement

Given N nodes and E edges of a connected undirected graph.
The task is to do depth first traversal of the graph.

Note: Use recursive approach.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases.
Then 'T' test cases follow. Each test case consists of two lines. 
Description of testcases is as follows: 
The First line of each test case contains two integers 'N' and 'E'  
which denotes the no of vertices and no of edges respectively. 
The Second line of each test case contains 'E'  space separated pairs u and v 
denoting that there is a edge from u to v .

Output:
For each testcase, print the nodes while doing DFS starting from node 0.

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
Graph doesn't contain multiple edges and self loops.

Example:
Input:
2
5 4
0 1 0 2 0 3 2 4
4 3
0 1 1 2 0 3

Output:
0 1 2 4 3   
0 1 2 3

Explanation:
Testcase 1:
0 is connected to 1 , 2 , 3
1 is connected to 0
2 is connected to 0 and 4
3 is connected to 0
4 is connected to 2
so starting from 0 , dfs will be 0 1 2 4 3.
 */

#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> g[], bool vis[]);

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, E;
        cin >> N >> E;
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));

        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, g, vis);
        cout << endl;
    }
    return 0;
}

/*
Approach: Similar to pre-order traversal, but is more complex than pre-order traversal.
THink in terms of going in depth from each node recursively. 

For detailed study of DFS refer DSA Notes
 */
void dfs(int s, vector<int> g[], bool vis[]) {
    vis[s] = true;              // mark the current source vertex as visited
    cout << s << " ";           // print the vertex
    for(int u : g[s]) {         // traverse through all connected component of source s
        if (vis[u] == false) {
            vis[u] = true;
            dfs(u, g, vis);     // if they are not visited, recur on them i.e recursively call dfs
        }
    }
}

/* 
Time Complexity: O(V+E)
If we take a closer look at the innermost statement which is going through
adjacent node of every other node
Which means we are traversing the adjacency list.
So If I know the sum of length of all the adjacency list that will be the time
complexity of this algorithm.
Now what is the sum of adjacency list?
For Undirected Graph: 2 * |E|
for Directed Graph: |E|
This is how we get factor of E in O(V+E)
How or why V in O(V+E)?
There can be a corner case when graph is completely disconnected
but we will still run the outer loop (in cases where we are BFS of
graph which may be disconnected and no soruce if given)
 */

// Company Tags: Accolite, Amazon, Intuit, Samsung
