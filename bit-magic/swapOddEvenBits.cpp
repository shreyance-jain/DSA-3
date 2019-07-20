//Initial Template for C++
#include<iostream>
using namespace std;

// function to swap odd and even bits
unsigned int swapBits(unsigned int n)
{
    // all the even bits
    unsigned int even_bits = n & 0xAAAAAAAA;
    // all the odd bits
    unsigned int odd_bits = n & 0x55555555;
    // right shift even bits
	even_bits >>= 1;
	// left shift odd bits
	odd_bits <<= 1;
	return (even_bits | odd_bits);
}

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned int n;
		cin>>n;
		cout << swapBits(n) << endl;
	}
	return 0;
}