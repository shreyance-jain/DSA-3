/* 
Hashing for pair - 1

Problem Statement

You are given an array A (distinct integers) of size N, and you are also given a sum.
You need to find if two numbers in A exists that have sum equal to the given sum.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains three lines of input.
The first line contains N denoting the size of the array A.
The second line contains N elements of the array.
The third line contains element sum.

Output Format:
For each testcase, in a new line, print  "1"(without quotes) if any pair found,
othwerwise print "0"(without quotes) if not found.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= Ai <= 106
1 <= sum <= 1000

Examples:
Input:
2
10
1 2 3 4 5 6 7 8 9 10
14
2
2 5
10
Output:
1
0

In test case 1, arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} and sum = 14.  There is a pair {4, 10} with sum 14.
In test case 2, arr[]  = {2, 5} and sum = 10. There is no pair with sum 10.
 */


#include <bits/stdc++.h>
using namespace std;
int sumExists(int arr[], int sizeOfArray, int sum);

int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        int sum;
        cin>>sum;
        
        cout << sumExists(arr,sizeOfArray,sum) << endl;
    }
	return 0;
}
/* 
Approach: Use hash, if x + y = sum
and x and y needs to belong to array,
we have hashed x. x + y = sum can be re-written as: x = sum - y
So we need to traverse the array and check if hash contains sum - arr[i], if yes then pair exists 
 */

int sumExists(int arr[], int sizeOfArray, int sum)
{
    // using an unordered se
   unordered_set <int> s;
    // traverse the array and check if sum - arr[i] is already present
   for(int i = 0; i < sizeOfArray; i++) {
       if (s.find(sum - arr[i]) != s.end()) {
           return 1;
       }
       s.insert(arr[i]);
   }
   return 0;
}

// Time Complexity: O(n)
// Aux Space Complexity: O(n)