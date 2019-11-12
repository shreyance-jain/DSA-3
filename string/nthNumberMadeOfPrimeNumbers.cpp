/* 
Nth number made of prime digits

Problems

Given a number 'N'.
The task is to find the Nth number whose each digit is a prime number i.e 2, 3, 5, 7.
In other words you have to find nth number of this sequence : 2, 3, 5, 7, 22, 23 ,.. and so on.

Input:
The first line contains a single integer T i.e. the number of test cases.
The first and only line of each test case consists of an integer N. 

Output: 
In one line print the nth number of the given sequence made of prime digits.

Constraints:
1 <= T <= 100
1 <= N <= 100

Examples:
Input:
2
10
21

Output:
33
222

Explanation:
Testcase 1: 10th number in the sequence of numbers whose each digit is prime is 33.
 */

#include <bits/stdc++.h>
using namespace std;

string getNthPrime(int n);

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    string p = getNthPrime(n);
	    cout << p << endl;
	}
	return 0;
}

/* 
A O(log n) solution: 
based on below pattern in numbers. The 
numbers can be seen
                                  ""
      /                |                    |                 \
     2                 3                    5                  7
 / |  | \           / | |  \             /  | | \          /  | |  \ 
22 23 25 27        32 33 35 37         52 53 55 57        72 73 75 77
/||\/||\/||\/||\   /||\/||\/||\/||\   /||\/||\/||\/||\   /||\/||\/||\/||\

We can notice following :
1st. 5th, 9th. 13th, ..... numbers have 2 as last digit.
2nd. 6th, 10th. 14th, ..... numbers have 3 as last digit.
3nd. 7th, 11th. 15th, ..... numbers have 5 as last digit.
4th. 8th, 12th. 16th, ..... numbers have 7 as last digit.

 */
string getNthPrime(int n) {
    string num;
    int rem;
    while (n) {
    // remainder for check element position
    rem = n % 4;
        switch (rem) {
            // if number 1st position in tree
            case 1:
                num.push_back('2');
                break;
            // if number 2nd position in tree
            case 2:
                num.push_back('3');
                break;
            // if number 3rd position in tree
            case 3:
                num.push_back('5');
                break;
            // if number 4th position in tree
            case 0:
                n = n - 1; // deducting 1 when number is completely divisble by 4 its edge
                num.push_back('7');
                break;
        }
        n = n / 4;
    }
    reverse(num.begin(), num.end());
    return num;
}
// Time Complexity: O(log n)