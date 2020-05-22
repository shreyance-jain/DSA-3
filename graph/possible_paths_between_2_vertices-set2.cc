/* 

Possible paths between 2 vertices

Difficulty: Medium

Problem Statement

Count the total number of ways or paths that exist between two vertices in a directed graph.
These paths doesn’t contain a cycle.

Input:
The first line of input contains an integer T. Then T test cases follow.
Each test case contains two integers N and M .
In the next line are M space separated values u,v denoting an edge from u to v.
Next line contains the starting node s and the ending node e. (The vertices start from 1)

Output: For each testcase print the total number of paths that exists between the starting and the ending node.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= M <= (N*(N-1))/2
1 <= u, v, s, e <= N
Graph doesn't contain multiple edges, self loop and cycles.

Example:
Input:
1
5 7
1 2 1 3 1 5 2 4 2 5 3 5 4 3
1 5

Output:
4

Explanation:
Testcase 1 :  
        There are 4 paths from 1 to 5.
        1 -> 5
        1 -> 2 -> 5
        1 -> 3 -> 5
        1 -> 2 -> 4 -> 3 -> 5
 */

//Driver Code
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

  public:
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V + 1];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int u, v;
        Graph g(N);
        while (M--) {
            cin >> u >> v;
            g.addEdge(u, v);
        }
        int s, e;
        cin >> s >> e;
        cout << g.countPaths(s, e) << endl;
    }
    return 0;
}

/* 
Approach: The idea is to use concept of backtracking & DFS
That is take a path and start walking.(i.e perform dfs from the source node).
Check if lead to the desitnation vertex then count the path and backtrack
to take another path
If the path doesn't leads to destination vertex, discard the path
 */
void dfs(list<int> *adj, int s, int d, int &count, bool vis[]) {
    vis[s] = true; // mark the current node as visited
    // if current node is equal to destination, increase count
    if (s == d)
        count++;
    else {
        // traverse all connected vertices
        for(int u : adj[s])
                if(vis[u] == false) // if not visited
                    dfs(adj, u, d, count, vis); // call the function for adjacent nodes
    }
    vis[s] = false;
}

int Graph::countPaths(int s, int d) {
    bool vis[V+1];
    for(int i = 0; i <= V; i++)
        vis[i] = false;
    int count = 0;
    // call to function to calculate path from s to d
    dfs(adj, s, d, count, vis);
    return count;
}

/* This code seems redundant, as visited array is extra is not required
as in the question it is said the graph does not contain cycles */