/* 
Zero Sum Subarrays     
   
Problem Statement

You are given an array A of size N.
You need to print the sub-arrays having their sum equal to 0

Input:
First line of the input contains an integer T denoting the number of test cases.
Each test case consists of two lines. First line of each test case contains an
Integer N denoting the size of the array, and the second line contains N space separated integers.

Output:
For each test case, in a new line, print the subarrays whose sum is equal to 0.

Constraints:    
1 <= T <= 100
1<= N <= 107
-1010 <= Ai <= 1010

Example:
Input:
1
11
6 3 -1 -3 4 -2 2 4 6 -12 -7

Output:
Subarray found from Index 2 to 4
Subarray found from Index 2 to 6          
Subarray found from Index 5 to 6
Subarray found from Index 6 to 9
Subarray found from Index 0 to 10
 */

#include <bits/stdc++.h>
using namespace std;

void printSubarrayWithZeroSum(int arr[], int n);

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
	    printSubarrayWithZeroSum(arr, n);
	}
	return 0;
}

/* 
A simple solution is to consider all subarrays one by one and check if sum of every subarray 
is equal to zero or not. The complexity of this solution would be O(n^2)

A better approach is to do hashing

Do the following for each element in the array
1. Maintain sum of elements encountered so far in a variable (say sum)
2. If current sum is 0, we found a subarray starting from index 0 and ending at index current index
3. Check if current sum exists in hash table or not.
4.If current sum already exists in hashtable then it indicates that this sum was the sum of some subarrays
elements arr[0]...arr[i] and now the same sum is obtained for the current sub-array arr[0]...arr[j], which means that
sum of the subarray arr[i+1]...arr[j] must be zero.
5.Insert current sum into the hash table 
 */
void printSubarrayWithZeroSum(int arr[], int n) {
    // counter
    int count = 0;
    
    // create an empty map
    unordered_map<int, vector<int> > m;

    // create an empty vector of pairs to store subarray starting and ending index
    vector<pair<int, int>> out;
    
    // sum stores the prefix sum (sum og elements so far)
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        // add current element to sum
        sum += arr[i];
         
        // if sum is 0, we found a subarray starting from index 0
        // and ending at index i
        if (sum == 0)
            out.push_back(make_pair(0, i));
        
        // if sum already exists in the map there exists at-least one subarray ending at index i with 0 sum
        if (m.find(sum) != m.end()) {
            vector<int> v = m[sum];
            vector<int>:: iterator it;
            for(it = v.begin(); it != v.end(); it++) {
                out.push_back(make_pair(*it +1 , i));
            }
        }
        // important- no else
        m[sum].push_back(i); // increase the value of key of sum i.e increment the frequecny of this sum
    }
    // return or print the output vector
    for(auto j = out.begin(); j != out.end(); j++) {
        cout << "Subarray from index " << j->first << " to " << j->second << endl;
    }
    
    m.clear();
}

// Time Compelxity: O(n), under hashing standard assumptions
// Aux Space: O(n)