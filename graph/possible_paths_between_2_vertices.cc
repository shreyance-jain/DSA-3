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
Approach: Idea is to dfs, without using visited array
and look for every possible path from the source node

Algorithm:
1. Create a recursive function that takes index of a node and destination index
Keep a global or a static variable count to store the count
2. If current node is the desitnaiton index, increment count
3. Else for all the adjacent nodes, i.e. nodes that are accessible from the current node,
call the recursive function with the index of adjacent node and destination
4. Print count 
 */
void dfs(list<int> *adj, int s, int d, int &count) {
    // if current vertex is same as destinaiton, increment count
    if (s == d)
        count++;
    // if vertex is not destinaiton
    else {
        // recur for all vertices adjacent to current vertex
        for(int u : adj[s])
            dfs(adj, u, d, count);
    }
}

int Graph::countPaths(int s, int d) {
    int count = 0;
    dfs(adj, s, d, count);
    return count;
}
// Time Complexity: O(N!)
// If the graph is complete then there can be around N! recursive calls, so it is upper bounded by N!
