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

/* Approach: Uses BFS Based Topological Sorting */
bool isCyclic(int V, vector<int> adj[])
{
    int indegree[V];
    for(int i = 0; i < V; i++)
        indegree[i] = 0;
        
    for(int i = 0; i < V; i++)
        for(int u : adj[i])
            indegree[u]++;
    
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while(q.empty() == false) {
        int v = q.front();
        // print
        count++;
        q.pop();
        // reduce indegree of adjacent of v by 1
        for(int u : adj[v]) {
            indegree[u]--;
            if (indegree[u] == 0)
                q.push(u);
        }
    }
    return (count != V);
}


// Time Complexity: O(V+E) Same as BFS we just maintain an extra array

// Company Tags: Adobe, Aamzon, BankBazaar, Flipkart, Goldman Sachs, MakeMyTrip, Microsoft,
// Oracle, Rockstand, Samsung
