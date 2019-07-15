//Initial Template for C++
#include <iostream>
using namespace std;

/*  Function to calculate the largest consecutive ones
*   x: given input to calculate the largest consecutive ones
*/
/* This idea is based on the concept that if we AND  a bit sequence with a 
shifted version of itself, we're effectively removing trailing 1 from every
sequence of consecutive 1s
The no of iteration requied to reach 0 is actually length of longest consecutive 1s */
int maxConsecutiveOnes(int x)
{
 
    // we will use the same concept used to check if the no is sparse or not
    // we will keep on repeating unitl number is zero and keep increment the 
    // res count until no is not zero
    //           1 1 1 1 1 0 1 
    // iter = 1  0 1 1 1 1 1 0 // right shift by 1
    //           0 1 1 1 1 0 1 // bitwise AND
    // iter = 2  0 0 1 1 1 1 0 // right shift by 1
    //           0 0 1 1 1 0 0 // biwise AND
    // iter = 3  0 0 0 1 1 1 0 // right shift by 1
    //           0 0 0 1 1 0 0 // bitwise AND
    // iter = 4  0 0 0 0 1 1 0 // right shift by 1
    //           0 0 0 0 1 0 0 // bitwise AND
    // iter = 5  0 0 0 0 0 1 0 // right shift by 1
    //           0 0 0 0 0 0 0 // bitwise AND
    // stop as x = 0
    int res = 0;
    while (x) {
        x = x & x>>1;
        res++;
    }
    
    return res;
}

// Driver Code
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}