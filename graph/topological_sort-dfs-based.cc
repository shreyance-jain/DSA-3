/* 
Topological sort

Difficulty: Medium
                      
Problems
Given a directed graph, you need to complete the function topoSort which returns
an array having the topologically sorted elements of the array and takes two arguments.
The first argument is the Graph graph represented as adjacency list and the second is the number of vertices N.

Note : There can be multiple topological sorts of a Graph.
The driver program that calls your function doesn't match your output element by element,
but checks whether the output produced by your function is a valid topological sort or not.

Input:
The first line of input takes the number of test cases then T test cases follow .
Each test case contains two lines. The first  line of each test case  contains two integers
E and N representing no of edges and the number of vertices. Then in the next line are E  pairs of integers u, v
representing an edge from u to v in the graph.

Output:
For each test case output will be 1 if the topological sort is done correctly else it will be 0.

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
0 <= u, v <= N-1
Graph doesn't contain multiple edges, self loops and cycles.
Graph may be disconnected.

Example:
Input
2
6 6
5 0 5 2 2 3 4 0 4 1 1 3
3 4
3 0 1 0 2 0

Output:
1
1

Explanation:
Testcase 1: The output 1 denotes that the order is valid.  So, if you have implemented your function correctly,
then output would be 1 for all test cases.
 */

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int *topoSort(int N, vector<int> adj[]);

bool check(int V, int res[], vector<int> adj[]) {
  vector<int> map(V, -1);
  for(int i = 0; i < V; i++) {
    map[res[i]] = i;
  }
  for(int i = 0; i < V; i++) {
    for(int v : adj[i]) {
      if (map[i] > map[v]) return false;
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, E;
    cin >> E >> N;
    int u, v;

    vector<int> adj[N];

    for(int i = 0; i < E; i++) {
      cin >> u >> v;
      adj[u].push_back(v);
    }

    int *res = topoSort(N, adj);

    cout << check(N, res, adj) << endl;
  }
}

/*
Approach: DFS Based Approach
For detailed explanation refer notes
*/
void dfs(vector<int> adj[], int s, bool vis[], stack<int> &st) {
    vis[s] = true;
    
    for(int u : adj[s]) {
        if (vis[u] == false)
            dfs(adj, u, vis, st);
    }
    
    st.push(s);
}

int* topoSort(int V, vector<int> adj[]) {
    // dfs based solution
    int *res = new int[V];
    stack<int> st;
    bool vis[V];
    for(int i = 0; i < V; i++)
        vis[i] = false;
    
    for(int i = 0; i < V; i++)
        if (vis[i] == false)
            dfs(adj, i, vis, st);
    
    int j = 0;
    while(st.empty() == false) {
        int u = st.top();
        st.pop();
        res[j++] = u; 
    }
    return res;
}

// Time Complexity: O(V+E) same as DFS
// Time Complexity: The outer for loop will be executed V number of times and 
// he inner for loop will be executed E number of times, Thus overall time complexity is O(V+E).

// Company Tags: Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, Morgan Stanley, OYO Rooms, Samsung, Visa
