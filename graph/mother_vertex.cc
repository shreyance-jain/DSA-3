/* 
Mother Vertex

Difficulty: Easy
      
Problem Statement
Find the smallest Mother vertex in a directed graph.
A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be
reached by a path from v. If there are more than one vertices satisfying this condition,
return the vertex with smallest value.

Input:
The first line of input contains an integer T. Then T test cases follow.
Each test case contains two integers N (number of vertices) and M (number of edges).
In the next line are M space separated values u,v denoting an edge from u to v.

Output: For each testcase return the mother vertex of graph (if existes) else return -1.

Note: This is a functional probem. Complete function findmother().

Constraints:
1 <= T <= 500
1 <= N <= 500
1 <= M <= 3000
0 <= u, v < N

Example:
Input:
2
5 5
1 0 0 2 2 1 0 3 3 4
3 2
0 1 2 1

Ouput:
0
-1

Explanation:
Testcase 1: According to the given edges, all nodes can be reaced from nodes from 0, 1 and 2.
But, since we are traversing from node 0, so 0 is the output.

Testcase 2: According to the given edges, no vertices are there from where we can reach all vertices. So, output is -1.
 */

#include <bits/stdc++.h> 
using namespace std; 

int findMother(int V, vector<int> adj[]);

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}

/* Approach & realted theory:
How to find mother vertex?

Case 1:- Undirected Connected Graph :
In this case, all the vertices are mother vertices as we can reach to all the other nodes in the graph.

Case 2:- Undirected/Directed Disconnected Graph :
In this case, there is no mother vertices as we cannot reach to all the other nodes in the graph.

Case 3:- Directed Connected Graph :
In this case, we have to find a vertex -v in the graph such that we can reach to all the other nodes
in the graph through a directed path.

A Naive approach :
A trivial approach will be to perform a DFS/BFS on all the vertices and find whether
we can reach all the vertices from that vertex.
This approach takes O(V(E+V)) time, which is very inefficient for large graphs.

Can we do better?
We can find a mother vertex in O(V+E) time.
The idea is based on Kosaraju’s Strongly Connected Component Algorithm.

In a graph of strongly connected components, mother vertices are always
vertices of source component in component graph. The idea is based on below fact.

If there exist mother vertex (or vertices), then one of the mother vertices
is the last finished vertex in DFS. (Or a mother vertex has the maximum finish time in DFS traversal).

A vertex is said to be finished in DFS if a recursive call for its DFS is
over, i.e., all descendants of the vertex have been visited.

How does the above idea work?
Let the last finished vertex be v. Basically, we need to prove that there
cannot be an edge from another vertex u to v if u is not another mother vertex
(Or there cannot exist a non-mother vertex u such that u-→v is an edge).
There can be two possibilities.

Recursive DFS call is made for u before v.
1. If an edge u-→v exists, then v must have finished before u because v is reachable through u and a vertex
finishes after all its descendants.

2. Recursive DFS call is made for v before u. In this case also, if an edge u-→v exists, 
then either v must finish before u (which contradicts our assumption that v is finished 
at the end) OR u should be reachable from v (which means u is another mother vertex).

Algorithm :

1. Do DFS traversal of the given graph. While doing traversal keep track of last finished vertex ‘v’.
This step takes O(V+E) time.
2.If there exist mother vertex (or vetices), then v must be one (or one of them).
Check if v is a mother vertex by doing DFS/BFS from v. This step also takes O(V+E) time.
 */
void dfs(vector<int> adj[], int s, bool vis[]) {
    vis[s] = true;
    
    for(int u : adj[s]) {
        if (vis[u] == false)
            dfs(adj, u, vis);
    }
}

int findMother(int V, vector<int> adj[]) 
{ 
    int mother = -1;
    bool vis[V];
    for(int i = 0; i < V; i++)
        vis[i] = false;
    
    for(int i = 0; i < V; i++) {
        if (vis[i] == false) {
            mother = i;
            dfs(adj, i, vis);
        }
    }
    for(int i = 0; i < V; i++)
        vis[i] = false;
    
    dfs(adj, mother, vis);
    
    for(int i = 0; i < V; i++) {
        if (vis[i] == false)
            return -1;
    }
    return mother;
} 

// useful link: https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/
// Time Compexity: Same as DFS: O(V+E)
