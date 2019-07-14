//Initial Template for C++
#include <iostream>
using namespace std;

/*
Given a number N and a bit number K, check if Kth bit of N is set or not. 
A bit is called set if it is 1. Position of set bit '1' should be indexed 
starting with 0 from LSB side in binary representation of the number.
Example, Consider N = 4(100):  0th bit = 0, 1st bit = 0, 2nd bit = 1.
 */

// Function to check if Kth bit is set or not
bool checkKthBit(int n, int k){
    // Your code here
    // It can be a one liner logic!! Think of it!!
    if (n & (1 << k)) return true;
    else return false;
}

// Driver Code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    int k;
	    cin>>k;
	    
	    if(checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	return 0;
}