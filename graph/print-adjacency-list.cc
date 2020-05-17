/*
Print adjacency list

Difficulty: Easy

Problem Statement

Given number of edges 'E' and vertices 'V' of a bidirectional graph.
Your task is to build a graph through adjacency list and print the adjacency list for each vertex.

Input:
The first line of input is T denoting the number of testcases.
Then first line of each of the T contains two positive integer V and E where 
'V' is the number of vertex and 'E' is number of edges in graph. 
Next, 'E' line contains two positive numbers showing that there is an edge between these two vertex.

Output:
For each vertex, print their connected nodes in order you are
pushing them inside the list . See the  given  example.

Constraints:
1 <= T <= 200
1 <= V <= 103
1 <= E = V*(V-1)

Example:
Input:
1
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4

Output:
0-> 1-> 4
1-> 0-> 2-> 3-> 4
2-> 1-> 3
3-> 1-> 2-> 4
4-> 0-> 1-> 3

Explanation:
Testcase 1: Given graph has 5 nodes and 7 edges. After creating adjacency list of given graph, we have list as:
0-> 1-> 4
1-> 0-> 2-> 3-> 4
2-> 1-> 3
3-> 1-> 2-> 4
4-> 0-> 1-> 3
 */

#include <bits/stdc++.h>
using namespace std;

void printGraph(vector<int> [], int);

int main() {
    int t;
    cin >> t;
    while(t--) {
        int v, e;
        cin >> v >> e;
        int a, b;
        vector<int> adj[v];
        for(int i = 0; i < e; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printGraph(adj, v);
    }
    return 0;
}

void printGraph(vector<int> adj[], int v) {
    for(int i = 0; i < v; i++) {
        cout << i;
        for(int j : adj[i])
            cout << "-> " << j;
        cout << endl;
    }
}

/* 
 Time complexity: O(V + E)
 Where V is number of vertices and E is no of edges.
 This alogorithm simply traverse the adjacency list of the graph
 and the length of adjacency list is 2*|E| for undirected graph (because if there is an edge from u->v the entry is made
 in list of u as well as list of v. So it is 2*|E|)
 and |E| for directed graph
 The factor of V in (V+E) covers corner case for diconnected vertices
 */