/* 

Steps by Knight

Difficulty: Medium

Problem Statement

Given a square chessboard of N x N size,
the position of Knight and position of a target is given. 
We need to find out minimum steps a Knight will take to reach the target position.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains an integer n denoting the size of the square chessboard. 
The next line contains the X-Y coordinates of the knight. 
The next line contains the X-Y coordinates of the target. 

Output:
Print the minimum steps the Knight will take to reach the target position.

Constraints:
1<=T<=100
1<=N<=20
1<=knight_pos,targer_pos<=N

Example:
Input:
2
6
4 5
1 1
20
5 7
15 20

Output:
3
9

Explanation:
Testcase 1:
The most optimal path is: (4,5) -> (2,4) -> (3,2) -> (1,1). 
Hence, we can reach the destination in 3 steps.
 */

#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

int findMinSteps(int n, int sx, int sy, int dx, int dy);

int main()
 {
	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        
        int sx, sy;
        cin >> sx >> sy;
        
        int dx, dy;
        cin >> dx >> dy;

        cout << findMinSteps(n, sx, sy, dx, dy) << endl;
    }
	return 0;
}

/* Approach: We can consider the chessboard as unweighted and undirected graph.
We can always find the shortest path in an unweighted graph using BFS

When we consider the chessboard as a graph, make sure that knight never reaches out of
the chessboard, i.e., all edges connect cells of the chessboard only.

Coding style is similar to rotten oranges
 */
struct Triplet {
  pair<int, int> u;
  int step;
  Triplet(int i, int j, int t) {
      u = make_pair(i, j);
      step = t;
  }
};

int findMinSteps(int n, int sx, int sy, int dx, int dy) {
    // make all cell unvisited
    bool vis[SIZE][SIZE] = {false};
    
    // queue for storig states of Knight in board
    queue<struct Triplet> q;
    // visiting starting state
    vis[sx][sy] = true;
    int step = 0;
    // pushing starting position of knight with 0 distance
    q.push(Triplet(sx, sy, step));

    // loop until we have one element in the queue
    while(q.empty() == false) {
        Triplet temp = q.front();
        q.pop();
        int x = temp.u.first;
        int y = temp.u.second;
        int step = temp.step;
        
        // if current cell is equal to target cell
        // return its distance
        if (x == dx && y == dy)
            return step;    

        // x adn y direction where Knight can move
        int nextx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
        int nexty[] = {-1, 1, -1, 1, -2, -2, 2, 2};
        
        // loop for all reachable states
        for(int i = 0; i < 8; i++) {
            int adjx = x + nextx[i];
            int adjy = y + nexty[i];
            
            // if reachable state is not yet visited and inside board, push that state into queue
            if (adjx >= 1 && adjx <= n && adjy >= 1 && adjy <= n && vis[adjx][adjy] == false) {
                vis[adjx][adjy] = true; // update visited
                q.push(Triplet(adjx, adjy, step+1)); // update state step distance
            }
        }
    }
    return step;
}

// TIME COMPLEXITY: TO DO

// COMPANY TAGS: Amazon, Goldman Sachs, Intuit, LinkedIn, MakeMyTrip, OYO Rooms
