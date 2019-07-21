/*
Search in a matrix

Problem Statement: Given a matrix mat[] of size n x m, where every row and column is sorted 
in increasing order, and a number x is given. The task is to find whether element x is present 
in the matrix or not.
Expected Time Complexity : O(m + n)

Input Format:
The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of three lines. First line of each test 
case consist of two space separated integers N and M, denoting the number of element in a 
row and column respectively. Second line of each test case consists of N*M space separated 
integers denoting the elements in the matrix in row major order. Third line of each test 
case contains a single integer x, the element to be searched.

Output Format:
Corresponding to each test case, print in a new line, 1 if the element x is present in the matrix,
otherwise simply print 0.

Constraints:
1 <= T <= 200
1 <= N, M <= 1000
1 <= mat[][] <= 105
1<= X <= 1000
Example:
Input:
2
3 3
3 30 38 44 52 54 57 60 69
62
1 6
18 21 27 38 55 67
55

Output:
0
1
*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 801

/*  Function to search x in the input matrix
*   n, m: rows and columns of matrix
*   x: element to check presence in matrix
*   mat[][]: input matrix
*/
int search( int n,int m, int x, int mat[SIZE][SIZE])
{
   // Your code here
   if (n == 0 || m ==0) return 0;
   int smallest = mat[0][0], largest = mat[n-1][m-1];
   if (x < smallest || x > largest) return 0;
   int i = 0, j = m-1;
   while (i < n && j >= 0) {
       if (x > mat[i][j]) {
           i++;
       } else if (x < mat[i][j]) {
           j--;
       } else {
           return 1;
       }
   }
   return 0;
}

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    int n,m,x,i,j;
    cin>>n>>m;
    
    int mat[SIZE][SIZE];
    
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
          mat[i][j] = 0;
        cin>>mat[i][j];
      }
    }
    
    cin>>x;
    cout << search(n,m,x, mat) << endl;
  
  }
  return 0;
}

// Company tags: Accolite, Directi, Goldman Sachs, Groupon, InMobi, MakeMyTrip, OlaCabs, One97,
// Oracle, Paytm, Polycon, Tinyowl, Visa