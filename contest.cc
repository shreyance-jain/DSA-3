#include <bits/stdc++.h>
using namespace std;

void printGraph(vector<int> g[], int v) {
    for(int i = 0; i < v; i++) {
        cout << i << " ";
        for(int j = 0; j < g[i].size(); j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}

void DFS(vector<int> g[], int source, bool visited[]) {
    if (visited[source] == false) {
        cout << source << " ";
        visited[source] = true;
        for(int i = 0; i < g[source].size(); i++)
            DFS(g, g[source][i], visited);
    }
}

void printDFS(vector<int> g[], int v) {
    bool visited[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
    int s = 0;
    DFS(g, s, visited);
}

int main() {
    int v = 7;
    vector<int> g[v];
    vector<pair<int, int>> edge;
    cout << "Enter edges of graph u, v " << endl;
    cout << "To finish entering edges enter -1 -1" << endl;
    while(1) {
        int n1, n2;
        cin >> n1 >> n2;
        if (n1 != -1 && n2 != -1) {
            edge.push_back(make_pair(n1, n2));
        } else {
            break;
        }
    }
    // make adjacency list
    for(int i = 0; i < edge.size(); i++) {
        int u = edge[i].first;
        int v = edge[i].second;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    system("clear");
    // print adjacency list
    // printGraph(g, v);
    printDFS(g, v);
}