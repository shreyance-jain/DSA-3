/* 
Detect cycle in an undirected graph

Difficulty: Medium       
         
Problem Statement

Given a undirected graph, the task is to complete the method isCyclic()
to detect if there is a cycle in the undirected graph or not.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases.
Then 'T' testcases follow. Each testcase consists of two lines.
Description of testcases are as follows: 
The First line of each testcase contains two integers 'N' and 'M' which denotes 
the no of vertices and no of edges respectively. 
The Second line of each test case contains 'M'  space separated pairs u and v 
denoting that there is a bidirectional  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= M <= (N*(N-1))/2
0 <= u, v <=  N-1
Graph doesn't contain multiple edges and self loops.

Example:
Input:
3
2 1
0 1
4 3
0 1 1 2 2 3
5 4
0 1 2 3 3 4 4 2

Output:
0
0
1

Explanation:
Testcase 1: There is a graph with 2 vertices and 1 edge from 0 to 1. So there is no cycle.
Testcase 2: There is a graph with 3 vertices and 3 edges from 0 to 1, 1 to 2 and 2 to 3.
Testcase 3: There is a cycle in the given graph formed by vertices 2, 3 and 4.
 */

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool isCyclic(vector<int> adj[], int V);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}

/* 
DFS BASED SOLUTION
uses visited array, and maintains a parent variable
if an adjacent is already visited and is not its parent
we can say a cycle exits
For detailed explanation see DSA NOTES
 */
bool dfs(vector<int> adj[], int s, bool vis[], int parent) {
    vis[s] = true;
    
    for(int u : adj[s]) {
        if (vis[u] == false) {
            if (dfs(adj, u, vis, s) == true)
                return true; // float true up
        }
        else if (u != parent)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   int i;
   bool vis[V];
   for(i = 0; i < V; i++)
        vis[i] = false;
   for(i = 0; i < V; i++) {
       if (vis[i] == false)
            if (dfs(adj, i, vis, -1) == true)
                return true;
   }
   return false;
}

/*
Time Complexity: Same as DFS, O(V+E)
It simply does DFS and extra work is pass parent variable which is constant amount of work
In the same line we can modify the BFS based soltion, we can maintain a parent array
and update the parent of that vertex whenever we go to the vertex through some vertex
and we can check if adjacent is parent or not
*/