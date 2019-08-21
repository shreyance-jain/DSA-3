/*
Square root

Problem Statement

Given an integer x. The task is to find the square root of x. If x is not a perfect square, then return floor(√x).

Input Format:
First line of input contains number of testcases T. For each testcase, the only line contains the number x.

Output Format:
For each testcase, print square root of given integer.

Constraints:
1 ≤ T ≤ 1000
1 ≤ x ≤ 107

Example:
Input:
2
5
4

Output:
2
2

Explanation:
Testcase 1: Since, 5 is not perfect square, so floor of square_root of 5 is 2.
Testcase 2: Since, 4 is a perfect square, so its square root is 2.
*/

#include<bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int x);
  
//Position this line where user code will be pasted.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;   
}

// Function to find square root
// x: element to find square root

long long int getSquareRoot(long long int x) {
    // Base cases
    if (x == 0 || x == 1) return x;
    
    // binary search for floor(sqrt(x))
    long long int start = 1, end = x, ans = 1;
    
    while (start <= end) {
        
        long long int mid = start + (end - start)/2;
        
        // if x is perfect square
        if (mid * mid == x)
            return mid;

        // since we need floor(sqrt(x)), we update ans when mid*mid is smaller than x
        // we  move closer to sqrt(x)
        if (mid * mid < x) {
            start = mid + 1;
            ans = mid;
        } else { // if mid*mid is greater than x
            end = mid - 1;
        }
    }
    return ans;
}

long long int floorSqrt(long long int x) 
{
    long long int root = getSquareRoot(x);
    return root;
}

// Time Complexity: O(log x)
// Note: The Binary Search can be further optimized to start with ‘start’ = 0 and ‘end’ = x/2. 
// Floor of square root of x cannot be more than x/2 when x > 1.

// Company tags: Accolite, Amazon, Flipkart, Microsoft, VMWare