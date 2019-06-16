//Initial Template for C++
#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    //Your code here
    if (n < 0) {
        n = -n;
    }
    if (n == 0) {
        return 0;
    }
    int digit = n%10;
    n = n/10;
    return (digit + sumOfDigits(n));
}

 
//  unsigned int foo(unsigned int n, unsigned int r) {
//   if (n  > 0) return (n%r +  foo (n/r, r ));
//   else return 0;
// }

//Position this line where user code will be pasted.
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<sumOfDigits(n)<<endl;
	    
	    
	}
	return 0;
}

