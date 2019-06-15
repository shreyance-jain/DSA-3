//Initial Template for C++
#include <iostream>
using namespace std;
//Position this line where user code will be pasted.
int RecursivePower(int n,int p)
{
    //Your code here
    if (p == 0) {
        return 1;
    }
    if (p == 1) {
        return n;
    } else {
        return n*RecursivePower(n, p-1);
    }
}
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n,p;
	    cin>>n>>p;
	    cout<<RecursivePower(n,p)<<endl;
	}
	return 0;
}
