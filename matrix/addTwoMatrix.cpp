/*
Input:
1
2 3
1 2 3 4 5 6
2 3
1 3 3 2 3 3
Output:
2 5 6 6 8 9
 Each testcase contains four lines of input. The first line contains dimensions 
 of the first array n1 and m1. The second line contains n1*m1 elements separated by spaces. 
 The third line contains dimensions of the second array n2 and m2. 
 The fourth line contains n2*m2 elements separated by spaces.
*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 100


/*  Function to find sum of matrices
*   n1, m1, n2, m2: rows and columns of matrices respectively
*   arr1[][], arr2[][]: two input matrices
*/
void sumMatrix(int n1, int m1, int n2, int m2, int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]){
    
    // Your code here
    if (n1 != n2 || m1 != m2) {
        cout << -1;
        return;
    }
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){
            cout << arr1[i][j] + arr2[i][j] << " ";
        }
    }
}


int main() {
    int t;
    cin>>t;//input the number of testcases
    
    while(t--) //while testcases exist
    {
        int n1,m1; //input rows and columns of matrix 1
        cin>>n1>>m1;
        int arr1[SIZE][SIZE]; //initialize the matrix 1 with n1 row and m1 columns.
        for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
        cin>>arr1[i][j]; //inputting the data in the matrix 1
        
        int n2,m2; //input rows and columns of matrix 2
        cin>>n2>>m2;
        int arr2[SIZE][SIZE];//initialize the matrix 2 with n2 row and m2 columns.
        for(int i=0;i<n2;i++)
        for(int j=0;j<m2;j++)
        cin>>arr2[i][j];//inputting the data in matrix 2
        
        sumMatrix(n1, m1, n2, m2, arr1, arr2);
        cout<<endl;
        
    }
    
	return 0;
}
