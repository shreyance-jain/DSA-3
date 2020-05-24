/* 

Rotten Oranges

Difficulty: Medium

Problem Statement

Given a matrix of dimension r*c where each cell in the matrix can have values
0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges.
A rotten orange at index [i,j] can rot other fresh orange
at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.
If it is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases.
Each test case contains two integers r and c, where r is the number of rows and
c is the number of columns in the array a[].
Next line contains space separated r*c elements each in the array a[].

Output:
Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).

Constraints:
1 <= T <= 100
1 <= r <= 100
1 <= c <= 100
0 <= a[i] <= 2

Example:
Input:
2
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
3 5
2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

Output:
2
-1

Explanation:
Testcase 1:
2 | 1 | 0 | 2 | 1
1 | 0 | 1 | 2 | 1
1 | 0 | 0 | 2 | 1

Oranges at positions {0,0}, {0, 3}, {1, 3} and {2, 3} will
rot oranges at {0, 1}, {1, 0}, {0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st unit time.
And, during 2nd unit time, orange at {1, 0} got rotten and will rot orange at {2, 0}.
Hence, total 2 unit of time is required to rot all oranges.
 */

#include<bits/stdc++.h>
using namespace std;

int nearest(vector<vector<int>> &arr, int row, int col);

int main()
 {
	//code
	int tc;
	cin >> tc;
	while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        cout << nearest(graph, row, col) << endl;
    } 
	return 0;
}

/* 
Approach: Same as Distance of nearest cell having 1
which uses Multi-Source BFS Based Approach

The idea is to user Breadth First Search. Below is algorithm.
    1) Create an empty Q.

    2) Find all rotten oranges and enqueue them to Q.
    Also enqueue a delimiter to indicate beginning of next time frame.

    3) While Q is not empty do following
    ….3.a) Do following while delimiter in Q is not reached
    …….. (i) Dequeue an orange from queue, rot all adjacent oranges.
            While rotting the adjacent, make sure that time frame is incremented only once.
            And time frame is not incremented if there are no adjacent oranges.
    ….3.b) Dequeue the old delimiter and enqueue a new delimiter.
            The oranges rotten in previous time frame lie between the two delimiters.

 */
struct Triplet {
  pair<int, int> u;
  int time;
  Triplet(int i, int j, int t) {
      u = make_pair(i, j);
      time = t;
  }
};

int nearest(vector<vector<int>> &arr, int row, int col) {
    int count_fresh = 0;
    int rotten = 0;
    int time_req = -1;
    
    queue<struct Triplet> q;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            if (arr[i][j] == 2) {
                q.push(Triplet(i, j, 0));
            }
            if (arr[i][j] == 1)
                count_fresh++;
        }
        
    while(q.empty() == false) {
        Triplet temp = q.front();
        q.pop();
        
        int x = temp.u.first;
        int y = temp.u.second;
        
        time_req = temp.time;
        
        int nextx[] = {0, 0, -1, 1};
        int nexty[] = {-1, 1, 0, 0};
        
        for(int i = 0; i < 4; i++) {
            int adjx = x + nextx[i];
            int adjy = y + nexty[i];
            
            if (adjx >= 0 && adjx < row && adjy >= 0 && adjy < col && 
                arr[adjx][adjy] == 1) {
                    arr[adjx][adjy] = 2;
                    rotten++;
                    q.push(Triplet(adjx, adjy, time_req + 1));
                }
        }
        
    }
    if (rotten == count_fresh)
        return time_req;
    return -1;
}

// Company Tags: Accolite, Amazon, MakeMyTrip, Microsoft, OYO Rooms, Samsung
