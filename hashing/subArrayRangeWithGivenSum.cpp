/* 
Subarray range with given sum

Problem Statement

Given an unsorted array arr[] of N integers and a sum.
The task is to count the number of subarray which adds to a given number.

Input Format:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
Each test case contains an integer N denoting the size of the array.
The next line contains N space separated integers forming the array.
The last line contains an integer denoting the value of the sum.

Output Format:
For each testcase, in a new line, print the count of the subarray which adds to the given sum.

Constraints:
1 <= T <= 200
1 <= N <= 105
-105 <= arr[i] <= 105
-105 <= sum <= 105

Example:
Input:
2
5
10 2 -2 -20 10
-10
6
1 4 20 3 10 5
33

Output:
3
1

Explanation:
Testcase 1: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].
 */

#include<bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum);

// dirver code for the below program
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    cout<<subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}

/* A way is to use hashmap. The idea is to maintain sum of elements encountered so far in a variable(say curr_sum)
Let the given number is sum. Now for each element we check if curr_sum - sum exists  in map or not.
If we found it in map/hash, it means, we have a subarray with given sum, else we insert curr_sum into hash/map 
and procees to next element. If all the elements of the array are processed and we didn't find a subarray with
given sum, the subarray does not exists.*/

int subArraySum(int arr[], int n, int sum)
{
    // this map stores the frequency of different intermediate sums
    unordered_map<int, int> m;
    
    int count = 0;
    
    int curr_sum = 0;
    
    // iterate over array
    for(int i = 0; i < n; i++) {
        // update current sum
        curr_sum += arr[i];
        
        // check if sum upto current elements is equal to given sum
        if (curr_sum == sum) {
            count++;
        }
        
        /* if map contains curr_sum - sum, there exists a subarray with given sum
        and count is equal to number of times of occurence of curr_sum-sum */
        if (m.find(curr_sum - sum) != m.end()) {
            count += m[curr_sum - sum];
        }
        
        m[curr_sum]++;
    }
    m.clear();
    return count;
}

// Time Complexity: O(n) under assumption hashing takes O(1) insert and search
// Aux Space: O(n)