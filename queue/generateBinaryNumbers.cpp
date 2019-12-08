/* 
Generate Binary Numbers

Difficulty: Basic
Problem Statement

Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Input Format:
The first line of input contains an integer T denoting the number of test cases.
There will be a single line for each testcase which contains N.

Output Format:
Print all binary numbers with decimal values from 1 to N in a single line.

Constraints:
1 ≤ T ≤ 106
1 ≤ N ≤ 106

Example:
Input:
2
2
5

Output:
1 10
1 10 11 100 101

Explanation:
Testcase 1: Binary numbers from 1 to 2 are 1 and 10.
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void generate(ll);

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        generate(n);
        cout << endl;
    }
    return 0;
}

/* Approach:
1. Create an empty queue of strings
2. Enqueue the first binary number "1" to queue
3. Now run a loop and for generating and printing n binary numbers
 - Pop from queue and print it
 - Add '0' to popped item and push to queue to generate next binary number
 - Add '1' to the popped item and push to queue to generate next binary number
*/
void generate(ll n)
{
	queue<string> q;
	q.push("1");
	int count = 0;
	while(count != n / 2) {
	   string s = q.front();
	   q.pop();
	   cout << s << " ";
	   q.push(s + '0');
	   q.push(s + '1');
	   count++;
	}
	while(count != n && !q.empty()) {
	    cout << q.front() << " ";
	    q.pop();
	    count++;
	}
}

// Time Complexity
// Company Tags: Amazon, OYO Rooms