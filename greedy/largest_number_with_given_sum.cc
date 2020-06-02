/* 
Largest number with given sum

Difficulty: Easy   

Problem Statement

A boy lost the password of his super locker.
He remembers the number of digits N as well as the sum S of all the digits of his password.
He know that his password is the largest number of N digits that can be possible with given sum S.
As he is busy doing his homework, help him retrieving his password.

Input:
The first line of input contains an integer T denoting the number of test cases.Then T test cases follow.
The first line of each test case contains two space separated integers N and S,
where N is the number of digits in password and S is the sum of all the digits of the password.

Output:
Corresponding to each test case, in a new line, print the largest integer if possible , else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 104
0 <= S <= 106

Example:
Input:
3
5 12
3 29
3 26

Output:
93000
-1
998

Explanation :
Testcase 1: Sum of elements is 12. Largest possible 5 digit number is 93000.
Testcase 2: There is no such three digit number whose sum is 29.
 */

#include <bits/stdc++.h>
using namespace std;

string largestNumber(int n, int sum);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,sum;
		cin>>n>>sum;

		cout<<largestNumber(n, sum)<<endl;
	}
	return 0;
}

/* 
As we have to find the largest possible number of N digits such that sum of all its digits is equal to S.
we know that a digit can have maximum value of 9, so if the sum S is greater than 9*N, then no number is possible
    if(S > 9*N)  // no number is possible, print -1.
Now, if number is possible,
then we will make the number largest by putting higher possible numbers(0-9) from left to right.
let's say sum S is 12 and N is 4. Then we will print 9 first, remaining sum = 3.
Now we will print 3, remaing sum = 0. Now as we have to form 4 digit number, we will print 2 zeroes.
hence number is 9300.
 */
string largestNumber(int n, int sum){
    string res = "";
    while(n--) {
        if (sum >= 9) {
            sum -= 9;
            res += '9';
        } else {
            res += to_string(sum);
            sum = 0;
        }
    }
    if (sum != 0)
        res = "-1";
    return res;
}
