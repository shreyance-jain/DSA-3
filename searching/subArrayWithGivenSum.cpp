/*

Subarray with given sum

Problem Statement:

Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array
and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring
subarray from the left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= Ai <= 1010

Example:
Input:
3
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
4 15
5 7 1 2
Output:
2 4
1 5
1 4

Explanation :
Testcase1: sum of elements from 2nd position to 4th position is 12.
Testcase2: sum of elements from 1st position to 5th position is 15.
*/


#include <bits/stdc++.h>
using namespace std;

// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int arr[], int n, int s){
    int start = 0;
    int i;
    int curr_sum = arr[0];
    int found = 0;
    for (i = 1; i <= n; i++) {
        while (curr_sum > s && start < i) {
            curr_sum = curr_sum - arr[start];
            start++;
        }
        if (curr_sum == s) {
            // found
            found = 1;
            cout << start+1 << " " << i;
            break;
        }
        if (i < n) {
            curr_sum += arr[i];
        }
    }
    if (!found) {
        cout << -1;
    }
}


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        subarraySum(arr, n, s);
        cout<<endl;
        
    }
	return 0;
}

/*


The time complexity of method looks more than O(n), but if we take a closer look at the program,
then we can figure out the time complexity is O(n). We can prove it by counting the number of operations
performed on every element of arr[] in the worst case. There are at most 2 operations performed on every element:
(a) the element is added to the curr_sum (b) the element is subtracted from curr_sum.
So the upper bound on the number of operations is 2n which is O(n).
*/

// Company tags: Amazon, Facebook, Google, Visa