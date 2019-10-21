/* 
Zero Sum Subarrays     
   
Problem Statement

You are given an array A of size N.
You need to print the total count of sub-arrays having their sum equal to 0

Input:
First line of the input contains an integer T denoting the number of test cases.
Each test case consists of two lines. First line of each test case contains an
Integer N denoting the size of the array, and the second line contains N space separated integers.

Output:
For each test case, in a new line, print the total number of subarrays whose sum is equal to 0.

Constraints:    
1 <= T <= 100
1<= N <= 107
-1010 <= Ai <= 1010

Example:
Input:
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7

Output:
6
4
 */

#include <bits/stdc++.h>
using namespace std;

int countSubarrayWithZeroSum(int arr[], int n);

// drive code for the program
int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    cout << countSubarrayWithZeroSum(arr, n) << endl;
	}
	return 0;
}

/* 
We need to find the count of all the subarrays that gives zero sum

Now,we may deduce that keeping a sum variable would be a good idea.
The sum variable would store the sum of elements of the arrays as we traverse the array from 
left to right. When the sum variable becomes zero, this means we found a subarray with zero sum.

Hashing would also come into play here. Keep on hashing the intermediate sum at each element.
When we get the same sum again, this means somewhere a zero sum subarray would have occured.
So we can simply add it to total count.
 */
int countSubarrayWithZeroSum(int arr[], int n) {
    // counter
    int count = 0;
    
    // this map stores the frequency of different intermediate sums
    unordered_map<int, int> m;
    
    // sum stores the prefix sum
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
         
        // if prefix sum is zero that means we encountered a zero sum sub-array
        if (sum == 0) {
            // increment the counter
            count++;
        }
        
        // if map contains the sum that means we have previously seen the sum
        if (m.count(sum) != 0) {
            /* this is the main key step
            suppose we found the same sum at index 2 then at index 4
            so the frequency of that sum would be 2
            now let's say we encounter the same sum at index 6
            that implies that subrray from index 2 to 6 and 
            subarray from index 4 to 6
            would also be zero sum subarrays
            so we add the frequency of current sum to the counter */
            count += m[sum]; // key is sum and we need the value
        }
        
        m[sum]++; // increase the value of key of sum i.e increment the frequecny of this sum
    }
    
    m.clear();
    
    return count;
}