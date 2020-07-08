/* 
N-Queen Problem [Print All Possible Placements]
The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
such that no two queens attack each other. Given an integer n, 
print all distinct solutions to the n-queens puzzle.

Each solution contains distinct board configurations of the n-queens’ placement, 
where the solutions are a permutation of [1,2,3..n] in increasing order, 
here the number in the ith place denotes that the ith-column queen is placed 
in the row with that number. 
For eg below figure represents a chessboard [3 1 4 2].

Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. 
Each test case contains an integer n denoting the size of the chessboard.

Output:
For each test case, output your solutions on one line where each solution 
is enclosed in square brackets '[', ']' separated by a space . 
The solutions are permutations of {1, 2, 3 …, n} in increasing order where 
the number in the ith place denotes the ith-column queen is placed in the 
row with that number, if no solution exists print -1.

Constraints:
1 <= T <= 10
1 <= n <= 10

Example:
Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]
 */

#include<iostream>
#include<vector>
#include<cstring>
#define MAX 10
using namespace std;

void nqueen(int n);

int main()
 {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    nqueen(n);
	}
	return 0;
}

// utitlity funciton to print the output
void print(int placement[MAX][MAX], int n) {
    vector<int> rows;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if (placement[j][i] == 1)
                rows.push_back(j+1);
    cout << "[";
    for(int i = 0; i < rows.size(); i++)
        cout << rows[i] << " ";
    cout << "] ";
}

bool isSafe(int placement[MAX][MAX], int col, int row, int n) {
    // check this row on the left side
    for(int i = 0; i < col; i++)
        if(placement[row][i] == 1)
            return false;
    // check upper diagnol on left side
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (placement[i][j] == 1)
            return false;
    // check lower diagnol on left side
    for(int i = row, j = col; i < n && j >= 0; i++, j--)
        if(placement[i][j] == 1)
            return false;
    return true;
}

/* Recursive backtracking functon */
bool nqueenUtil(int col, int placement[MAX][MAX], int n) {
    if (col == n) {
        print(placement, n);
        // return true
        return true;
    }
    // initiate result for every call
    bool res = false;
    for(int i = 0; i < n; i++) {
        if (isSafe(placement, col, i, n)) {
            placement[i][col] = 1;
            // if true even once, will remain true for the column
            res = nqueenUtil(col+1, placement, n) || res;
            placement[i][col] = 0; 
        }
    }
    // return res
    return res;
}

void nqueen(int n) {
    int placement[MAX][MAX];
    memset(placement, 0, sizeof(placement));
    bool res = nqueenUtil(0, placement, n);
    if (!res)
        cout << -1;
    cout << endl;
}

// Compnay Tags: Accolite, Amazon, Amdocs, DE-Shaw, MAQ Software, Twitter, Visa
