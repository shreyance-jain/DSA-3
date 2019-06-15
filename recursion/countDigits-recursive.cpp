//Initial Template for C++
#include <iostream>
using namespace std;

int countDigits(int n)
{
   //Your code here
   if (n < 0) {
       n = -n;
   }
   if (n == 0) {
       return 1;
   } else {
       n = n/10;
       if (n == 0) {
           return 1;
       }
       return (1 + countDigits(n));
   }
}


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<countDigits(n)<<endl;
	    
	    
	}
	return 0;
}