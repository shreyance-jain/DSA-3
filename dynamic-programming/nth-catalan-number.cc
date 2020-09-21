/* 
Nth catalan number

Difficulty: Easy

Problem Statement

Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
Note: Positions start from 0 as shown above.

Example 1:

Input:
N = 5
Output: 42

Example 2:

Input:
N = 4
Output: 14

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 100
 */

// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

cpp_int findCatalan(int);

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    
	    //calling function findCatalan function
	    cout<< findCatalan(n) <<"\n";    
	}
	return 0;
}

// Approach: Same as Find Number of Unqiue BST's
cpp_int findCatalan(int n) {
    cpp_int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = 0;
        for(int j = 0; j < i; j++)
            dp[i] += dp[j]*dp[i-j-1];
    }
    return dp[n];
}

// Tags: Easy

// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Compnany Tags: Amazon
