/* 
BFS of graph

Difficulty: Easy - connected graph source given
     
Problem Statement

Given N and E, the number of nodes and edges in a directed graph.
The task is to do Breadth First Search of this graph.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases.
Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v .

Output:
For each testcase, print the BFS of the graph starting from 0.

Note: The expected output button always produces BFS starting from node 0.

User Task:
Since, this is a functional problem, your task is to complete the function bfs()
which do BFS of the given graph starting from node 0 and prints the nodes in BFS order.

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
3 2
0 1 0 2

Output:
0 1 2 3 4    // BFS from node 0
0 1 2

Explanation:
Testcase 1: 
0 is connected to 1 , 2 , 3
2 is connected to 4
so starting from 0 , bfs will be 0 1 2 3 4.
 */

#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> g[], vector<bool> &vis, int N);

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        vector<bool> vis(N, false);
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        bfs(0, adj, vis, N);
        cout << endl;
    }
}

/* 
Approach: Seems similar like level order traversal of tree
but is little more complex.

Algo:
Create a queue and enqueue the source node
POP a node from the queue, print it and mark it is as visited
traverse all the node connected to the POP node and check whether the node
has already been visited or not.
If not visited enqueue it.
repeat the above steps till queue isn't empty.
 */
void bfs(int s, vector<int> g[], vector<bool> &vis, int N) {
    queue<int> q;
    vis[s] = true; // initially mark the source node as visited(true)
    q.push(s);     // push the source vertex to the queue
    while(q.empty() == false) {
        int u = q.front();
        cout << u << " ";   // print the fron of the queue
        q.pop();            // pop the queue front
        for(int v : g[u]) { // traverse through all connected components of front
            if (vis[v] == false) { // if they are not visited mark them as visited and add to queue
                vis[v] = true;
                q.push(v);
            }
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

// Company Tags: Adobe, Amazon, Flipkart, Microsoft, Ola Cabs, Samsung, SAP Labs
