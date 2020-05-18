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
#include <queue>

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
Approach: BFS Based Approach
Algorithm:
Steps involved in finding the topological ordering of a DAG:

Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG
and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.

Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
Step 5: Repeat Step 3 until the queue is empty.

Step 5: If count of visited nodes is not equal to the number of nodes in the graph then
the topological sort is not possible for the given graph.

How to find in-degree of each node?
There are 2 ways to calculate in-degree of every vertex:
Take an in-degree array which will keep track of
1) Traverse the array of edges and simply increase the counter of the destination node by 1.

for each node in Nodes
    indegree[node] = 0;
for each edge(src,dest) in Edges
    indegree[dest]++
Time Complexity: O(V+E)

2) Traverse the list for every node and then increment the in-degree of all the nodes connected to it by 1.

    for each node in Nodes
        If (list[node].size()!=0) then
        for each dest in list
            indegree[dest]++;
Time Complexity: The outer for loop will be executed V number of times and 
he inner for loop will be executed E number of times, Thus overall time complexity is O(V+E).

The overall time complexity of the algorithm is O(V+E)
For detailed explanation refer notes
*/
int* topoSort(int V, vector<int> adj[]) {
    // bfs based solution
    int *res = new int[V];
    int index = 0;
    
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
    
    while(q.empty() == false) {
        int v = q.front();
        // print
        res[index++] = v;
        q.pop();
        // reduce indegree of adjacent of v by 1
        for(int u : adj[v]) {
            indegree[u]--;
            if (indegree[u] == 0)
                q.push(u);
        }
    }
    return res;
}

// Time Complexity: O(V+E) same as BFS
// Time Complexity: The outer for loop will be executed V number of times and 
// he inner for loop will be executed E number of times, Thus overall time complexity is O(V+E).

// Company Tags: Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, Morgan Stanley, OYO Rooms, Samsung, Visa
