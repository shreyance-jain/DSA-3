/* 

X Total Shapes

Difficulty: Medium

Problem Statement

Given N * M string array of O's and X's. The task is to find the number of 'X' total shapes.
'X' shape consists of one or more adjacent X's (diagonals not included).

Input: The first line of input takes the number of test cases T. Then T test cases follow.
Each of the T test cases takes 2 input lines. The first line of each test case have
two integers N and M.The second line of N space separated strings follow which
indicate the elements in the array.

Output:
For each testcase, print number of shapes.

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

Explanation:
Testcase 1: Given input is like:
OOOOXXO
OXOXOOX
XXXXOXO
OXXXOOO

So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included).
So, there are 4 different groups in the given matrix.

Testcase 2: Given input is like:
XXO
OOX
OXO
OOO
XOX
XOX
OXO
XXO
XXX
OOO
So, this matrix has 6 groups with is having adjacent Xs. Total number of groups is 6.
 */

#include<bits/stdc++.h>
using namespace std;

int countXShapes(vector<string> &A);

int main()
 {
	int T;
	cin >> T;
	while(T--) {
	    int N;
	    cin >> N;
	    int M;
	    cin >> M;
	    vector<string> A;
	    for(int i = 0; i < N; i++) {
	        string str;
	        cin >> str;
	        A.push_back(str);
	    }
	    cout << countXShapes(A) << endl;
	}
	return 0;
}

/* Approach: The idea is same as number of islands
Algo:
result = 0
for i = 1 to N
    for j = 1 to M
        if A[i][j] equal to 'X' and not visited
            BFS/DFS to mark connected ares as visited
            update result
print result

Here, we do not maintain an extra vector of string to maintain visited
instead we modify the original vector by marking 'X' to 'O'
which will make it serve the purpose of visited which is - not to visit/count
this vertex/node again */
void dfs(vector<string> &A, int x, int y) {
    if (x >= A.size() || y >= A[x].size())
        return;
        
    int nextx[]= {0, 0, 1, -1};
    int nexty[] = {-1, 1, 0, 0};
    
    if (A[x][y] == 'X') {
        A[x][y] = 'O';
        for(int i = 0; i < 4; i++)
            dfs(A, x + nextx[i], y + nexty[i]);
            // or
            // dfs(A,x+1,y);dfs(A,x,y+1);dfs(A,x-1,y);dfs(A,x,y-1);
    }
}

int countXShapes(vector<string> &A) {
    
    int res = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[i].size(); j++) {
            if (A[i][j] == 'X') {
                dfs(A, i, j);
                res++;
            }
        }
    }
    return res;
}

// Time Complexity: Same as DFS of adjacency matrix

// Company Tags: Amazon, Google
