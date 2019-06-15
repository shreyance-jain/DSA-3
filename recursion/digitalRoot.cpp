//Initial Template for C++
#include <iostream>
using namespace std;
//Position this line where user code will be pasted.
int digitalRoot(int n);
int digitsSum(int n);
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function
int digitsSum(int n) {
    if (n == 0) {
        return 0;
    }
    int digit = n % 10;
    n = n/10;
    return (digit + digitsSum(n));
}

int digitalRoot(int n)
{
    //Your code here
    int temp = digitsSum(n);
    while (temp / 10 != 0) {
        temp = digitsSum(temp);
    }
    return temp;
}