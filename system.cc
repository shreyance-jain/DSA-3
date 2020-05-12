#include <bits/stdc++.h>
using namespace std;


/* 
system() is used to invoke an operating system command from a C/C++ program.
Using system(), we can execute any command that can run on terminal if operating system allows.
For example, we can call system(“dir”) on Windows and system(“ls”) to list contents of a directory.

For detailed information: https://www.geeksforgeeks.org/system-call-in-c/
 */

int main() {
	int arr[] = {1, 2, 3};
	int k = 2;

	priority_queue<int, vector<int>, greater<int>> pq;
	
	// for(int i = 0; i <= k; i++)
	// 	pq.push(arr[i]);

	// make pair
	// on pair min heap will work on key
	// int c = 3;
	// while(c--) {
	// 	pq.push(1);
	// }

	// while(pq.empty() == false) {
	// 	cout << pq.top() << " ";
	// 	pq.pop();
	// }
	system("echo $name");

	cout << endl;
	return 0;
}
