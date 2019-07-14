//Initial Template for C++
#include <iostream>
#include <math.h>
using namespace std;

/*  Function to find the first position with different bits
This function returns the position with different bit
XOR is set when both the bits are different and unset when both
the bits are same.
*/
int posOfRightMostDiffBit(int m, int n)
{
    
    // XOR of m and n will set all the different bits in m and n
    int k = m ^ n;
    // now return the first set bit
    return log2(k & -k)+1;
    
}
 
//Position this line where user code will be pasted.
// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         cout << posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
}