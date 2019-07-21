/*Two matrices A[][] and B[][] can only be multiplied if A's column size is equal to B's row size.
 The resultant matrix will have dimensions equal to A's row size and B's column size.

You are given two matrices A and B. A is of dimension n1 x m1; and B is of dimension n2 x m2. 
You have to multiply A with B and print the resultant matrix. If multiplication is not possible 
then print -1.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains four lines of input. The first line contains dimensions of the first array n1 and m1. The second line contains n1 * m1 elements separated by spaces. The third line contains dimensions of the second array n2 and m2. The fourth line contains n2 * m2 elements separated by spaces.

Output Format:
For each testcase, in a new line, print the resultant matrix if possible; else print -1

Examples:
Input:
1
3 2
4 8 0 2 1 6
2 2
5 2 9 4

Output:
92 40 18 8 59 26*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 30


/*  Function to multiply matrices
*   n1, m1, n2, m2: rows and cols of matrices
*   arr1[][], arr2[][]: input matrices
*   SIZE: defined globally
*/
void multiplyMatrix(int n1, int m1, int n2, int m2, long long arr1[SIZE][SIZE], long long arr2[SIZE][SIZE]){
    
    // Your code here
    if (m1 != n2) {
        cout << -1;
        return;
    } 
    for(int i = 0; i < n1; i++){
        for (int j = 0; j < m2; j++){
            int cij = 0;
            for(int k = 0; k < m1; k++){
                cij += arr1[i][k] * arr2[k][j];
            }
            cout << cij << " ";
        }
    }
    
}

int main() {
    long long t;
    cin>>t; //inputting testcases
    while(t--) //while testcases exist
    {
        int n1,m1; //input rows and columns of matrix 1
        cin>>n1>>m1;
        long long arr1[SIZE][SIZE]; //declare the matrix 1
        for(long long i=0;i<n1;i++)
        for(long long j=0;j<m1;j++)
        cin>>arr1[i][j]; //input the matrix 1
        
        int n2,m2;
        cin>>n2>>m2; //inputting the rows and columns of matrix 2
        long long arr2[SIZE][SIZE]; //declare the matrix 2
        for(long long i=0;i<n2;i++)
        for(long long j=0;j<m2;j++)
        cin>>arr2[i][j]; //input the elements of matrix 2
        
        multiplyMatrix(n1, m1, n2, m2, arr1, arr2);
        cout<<endl;
        
    }
    
    return 0;
}
