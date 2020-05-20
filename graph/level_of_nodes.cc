/* 
Level of Nodes

Difficulty: Medium
      
Problems
Given an connected undirected graph of N edges and a node X is given.
The task is to find the level of X. if X does not exist in the graph then print -1.

Input:
First line of input contains number of testcases T. For each testcase,
first line of input contains number of nodes and edges N and E.
Next E lines contais U and V, which represents that there is an edge between U and V.
The final line contains X whose level we have to find.

Output:
For each testcase, print the level of the given node X.

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
0 <= U, V < N
1 <= X <= 104
Graph doesn't contain multiple edges and self loops.

Example:
Input:
1
8 8
0 1
0 2
1 3
1 4
1 5
2 6
6 7
2 5
7

Output:
3

Explanation:
Testcases 1: In the given graph(above), 7 is at 3rd level starting from source node 0 which is at 0th level.
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
  int V;
  vector<int> *adj;

public:
  Graph(int v);
  void addEdge(int u, int v);
  int levels(int x, int in);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new vector<int>(V+1);
}

void Graph::addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n, e;
    cin >> n >> e;
    Graph g(n);
    int u, v;
    for(int i = 0; i < e; i++) {
      cin >> u >> e;
      g.addEdge(u, e);
    }

    int x;
    cin >> x;

    if (x >= n) {
      cout << -1 << endl;
    } else {
      cout << g.levels(0, x) << endl;
    }
  }
  return 0;
}

/* 
Approach: BFS(Breadth First Search) is a graph traversal technique where a node and its neighbours
are visited first and then the neighbours of neighbours.
In simple terms, it traverses level wise form the source.
First, it traverses level 1 nodes(direct neighbours of source node) and then level 2 nodes(neighbours of source node)
and so on. The BFS can be used to determine level of each node from a given soruce node
 */
int Graph::levels(int x, int in) {
  bool vis[V];
    for(int i = 0; i < V; i++)
        vis[i] = false;
        
    queue<pair<int, int>> q;
    q.push({x, 0});
    vis[x] = true;
    
    while(q.empty() == false) {
        pair<int, int> u = q.front();
        q.pop();
        int level = u.second;
        
        if (u.first == in)
            return u.second;
        
        for(int v : adj[u.first]) {
            if (vis[v] == false) {
                vis[v] = true;
                q.push({v, level+1});
            }
        }
    }
    return -1;
}

// we can also maintain a seperate array of size V to store the level of nodes

// Time Compelxity: Same as BFS: O(V+E)

/* 
ALSO, we can say in terms of n
Time Complexity: O(n).
In BFS traversal every node is visited only once, so Time Complexity is O(n).
Space Complexity: O(n).
The space is required to store the nodes in a queue.
 */
