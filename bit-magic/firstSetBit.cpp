//Initial Template for C++
#include<iostream>
#include<math.h>
using namespace std;


/*  function to find position of first set 
    bit in the given number
 * n: given input for which we want to get
      the position of first set bit
 */

/* Algorithm: (Example 12(1100))
Let I/P be 12 (1100)

1. Take two's complement of the given no as all bits are reverted
except the first '1' from right to left (0111)

2  Do a bit-wise & with original no, this will return no with the
required one only (0100)

3  Take the log2 of the no, you will get (position - 1) (2)

4  Add 1 (3)
 */
unsigned int getFirstSetBit(int n){
    
    // Your code here
    return log2(n & -n)+1;
}


// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        printf("%u", getFirstSetBit(n)); // function to get answer
    }
	return 0;
}
