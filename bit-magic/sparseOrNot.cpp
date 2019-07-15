/*
Given a number N.  The task is to check whether it is sparse or not. 
A number is said to be a sparse number if no two or more consecutive bits 
are set  in the binary representation.
 */

//Initial Template for C++
// C++ program to check if n is sparse or not
#include<iostream>
using namespace std;

/*
If we observe carefully, then we can notice if we can use bitwise AND of binary representation
of the given number and the right shift of the number to figure out if the no is sparse or not
result of AND would be 0 if sparse and non-zero if not sparse
 */

bool isSparse(int n){
    
    // Your code
    if (n & n>>1) return false;
    return true;
    
}

// Driver Code
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        
        if(isSparse(n)){
            cout << "1" << endl;
        }
        else cout << "0" << endl;
        
    }
    return 0;
}