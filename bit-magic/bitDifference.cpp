/*You are given two numbers A and B. 
Write a program to count number of bits needed to be flipped 
to convert A to B. */

#include<iostream>
using namespace std;

// Function to find number of bits to be flip
// to convert A to B
int countSetBits(int n) {
    int res = 0;
    while (n > 0) {
        n = n & n-1;
        res++;
    }
    return res;
}

int countBitsFlip(int a, int b){
    
    // Your logic here
    // take XOR of a and b to get the bits difference
    // those no of bits need to be flipped
    int noOfBitsNeedToBeFlipped = countSetBits(a^b);
    return noOfBitsNeedToBeFlipped;
}

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b
		cout<<countBitsFlip(a, b)<<endl;
	}
	return 0;
}