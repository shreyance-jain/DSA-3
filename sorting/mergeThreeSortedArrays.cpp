/*

Merge three sorted arrays
     
Problem Statement

Given three sorted arrays A, B and C of size N, M and P respectively.
The task is to merge them into a single array which must be sorted in increasing order.

Input Format:
First line of input contains number of testcases T. For each testcase,
first line of input contains size of three arrays N, M and P.
Next three lines contains N, M and P elements for arrays.

Output Format:
Output the merged sorted array.

Constraints:
1 <= T <= 100
1 <= N, M, P <= 106
1 <= A[i], B[i], C[i] <= 106

Example:
Input:
2
4 5 6
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
2 3 4
1 2
2 3 4
4 5 6 7

Output:
1 1 1 2 2 2 3 3 3 4 4 4 5 5 6
1 2 2 3 4 4 5 6 7

 

Explanation:
Testcase 1: Merging these three sorted arrays, we have elements as 1 1 1 2 2 2 3 3 3 4 4 4 5 5 6. 
 */


#include<bits/stdc++.h>
using namespace std; 

typedef vector<int> Vector;

void printVector(const Vector& a) 
{ 
    for (auto e : a) { 
        cout << e << " "; 
    }
    cout<<endl;
} 

// Function to merge three sorted arrays
// A, B, and C: input sorted arrays
Vector mergeThree(Vector& A, Vector& B, Vector& C) ;

int main() 
{ 
    int t;
    cin>>t;
    while(t--){
    int n,m,o;
    cin>>n>>m>>o;
    Vector A,B,C;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    
    for(int i=0;i<o;i++){
        int x;
        cin>>x;
        C.push_back(x);
    }
  
    printVector(mergeThree(A, B, C)); 
    
    }
   
    return 0; 
} 

/* The idea is to merge three arrays simultaneouly
This avoid the extra space required for merge of two arrays */
Vector mergeThree(Vector& A, Vector& B, Vector& C) 
{
    int m, n, o, i, j, k;
    m = A.size();
    n = B.size();
    o = C.size();
    
    Vector D;
    D.reserve(m + n + o);
    
    i = j = k = 0;
    
    // compare in all the three arrays
    while (i < m && j < n && k < o) {
        int m = min(min(A[i], B[j]), C[k]);
        D.push_back(m);
        if (m == A[i])
            i++;
        else if (m == B[j])
            j++;
        else
            k++;
    }

    /* After the above step at-least 
    on array is exhausted*/
    
    // while C is exhausted
    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            D.push_back(A[i]);
            i++;
        } else {
            D.push_back(B[j]);
            j++;
        }
    }
    
    // while B is exhausted
    while (i < m && k < o) {
        if (A[i] <= C[k]) {
            D.push_back(A[i]);
            i++;
        } else {
            D.push_back(C[k]);
            k++;
        }
    }
    
    // while A is exhausted
    while (j < n && k < o) {
        if (B[j] <= C[k]) {
            D.push_back(B[j]);
            j++;
        } else {
            D.push_back(C[k]);
            k++;
        }
    }

    /* After the above step at-least
    two arrays are sorted */
    
    // while A and B are exhausted
    while (k < o)
        D.push_back(C[k++]);
    
    // while B and C are exhausted
    while (i < m)
        D.push_back(A[i++]);
        
    // while A and C are exhausted
    while (j < n)
        D.push_back(B[j++]);

    return D;
}

// Time Complexity: O(n+m+o) since we process each element from the three arrays once