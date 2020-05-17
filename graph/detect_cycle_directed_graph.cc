/* 
Detect cycle in a directed graph

Difficulty: Medium

Problem Statement

Given a directed graph, the task is to complete the method isCyclic()
to detect if there is a cycle in the graph or not.
You should not read any input from stdin/console. There are multiple test cases.
For each test case, this method will be called individually.

Input: The first line of the input contains an integer 'T' denoting the number of test cases.
Then 'T' test cases follow. Each test case consists of two lines. 
Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'M'  
which denotes the no of vertices and no of edges respectively. 
The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is 
an uni-directed  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

Constraints:
1 <= T <= 1000
1<= N,M <= 1000
0 <= u,v <= N-1

Example:
Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2
Output:
1
0
1

Explanation:
Testcase 1: In the above graph there are 2 vertices. The edges are as such among the vertices.
From graph it is clear that it contains cycle.
 
 */

#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[]);

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}

/* 
DFS BASED SOLUTION

Perform DFS traversal of the graph. DFS for a connected graph produces a tree.
There is a cycle in a graph only if there is a back edge present in the graph.

A back edge is an edge that is from a node to itself (self-loop) or one of its ancestor in the tree produced by DFS
.
To detect a back edge, keep track of vertices currently in recursion stack of function for DFS traversal.
If you reach a vertex that is already in the recursion stack, then there is a cycle in the tree.
The edge that connects current vertex to the vertex in the recursion stack is a back edge.

Tip: Use an extra array to keep track of vertices in the recursion stack.
To detect cycle, check for a cycle in individual trees by checking back edges.

So if we say there is an edge from one of the descendants to one of the ancestor
which is currently active in the recursion call stack then we say there is a cycle. We call such an edge as backedge

To figure out if there is an edge to one of the ancestor in the recursion call stack, we maintain a boolean
array recursionStack. we set it to true for a vertex that this vertex is now in recursion call stack
when it enters the dfs call and when recursion for this
particular vertex is over we make it as false that it is gone out of the recursion call stack

For detailed explanation see notes. */
bool dfs(vector<int> adj[], int s, bool vis[], bool recSt[]) {
    vis[s] = true;
    recSt[s] = true;
    
    for(int u: adj[s]) {
        if (vis[u] == false && dfs(adj, u, vis, recSt) == true)
            return true;
        else if (recSt[u] == true)
            return true;
    }
    recSt[s] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // detect cycle in directed graph
    // DFS based solution maintains recursion stack
    bool vis[V];
    for(int i = 0; i < V; i++)
        vis[i] = false;
    
    bool recSt[V];
    for(int i = 0; i < V; i++)
        recSt[i] = false;
    
    for(int i = 0; i < V; i++) {
        if (vis[i] == false)
            if (dfs(adj, i, vis, recSt) == true)
                return true;
    }
    return false;
}

// Time Complexity: O(V+E) Same as DFS we just maintain an extra array

// Company Tags: Adobe, Aamzon, BankBazaar, Flipkart, Goldman Sachs, MakeMyTrip, Microsoft,
// Oracle, Rockstand, Samsung
