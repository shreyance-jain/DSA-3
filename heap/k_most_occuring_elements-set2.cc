/* 

K Most occurring elements

Difficulty: Medium
   
Problem Statement

Given an array arr[] of N integers in which elements may be repeating several times.
Also, a positive number K is given and the task is to
find sum of total frequencies of K most occurring elements

Note: The value of K is guaranteed to be less than or equal to the number of distinct elements in arr.

Input:
First line of input contains number of testcases T. For each testcase,
first line of input contains the size of array N, and next line contains N positive integers.
The last line contains K.

Output:
For each testcase, print the sum of total frequencies of K most occurring elements in the given array.

Constraints:
1 <= T <= 100
1 <= K <= N
1 <= N <= 107
1 <= arr[i] <= 106

Example:
Input:
2
8
3 1 4 4 5 2 6 1
2
8
3 3 3 4 1 1 6 1
2

Output:
4
6

Explanation:
Testcase 1: Since, 4 and 1 are 2 most occurring elements in the array with their frequencies as 2, 2. So total frequency is 2 + 2 = 4.

Testcase 2: Since, 3 and 1 are most occurring elements in the array with frequencies 3, 3 respectively. So, total frequency is 6.
 */

#include <bits/stdc++.h>
using namespace std;

int print_N_mostFrequentNumber(int arr[], int n, int k);

int main() {
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        cin >> k;
        cout << print_N_mostFrequentNumber(arr, n, k) << endl; 
    }

	return 0; 
}


/* 
Approach:
Using concept of hashing, create a frequency table which stores the frequency of each number in array.
Define hash table as (x, y) tuple, x being key(number) & y being its frequency in the array.

Now traverse the hash table and create an frequency array which stores these tuples.

We can improve the complexity of the program by using max heap instead of sorting.
Build the max heap using elements of the frequency array.

The root of the max heap will be the most frequent number and
in case of conflicts the larger number gets the preference.

Now remove the top k numbers of this max heap.
 */

struct compare {
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        // if frequencies of two elements are same then the larger
        // number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;
        // insert elements in the priority queue on the basis of 
        // decreasing order of frequencies
        return p1.second < p2.second;
    }
};

int print_N_mostFrequentNumber(int arr[], int n, int k) 
{ 
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
        m[arr[i]]++;
    
    // store the elements of 'm' in the vector 'freq_arr'
    // vector<pair<int, int>> freq_arr(m.begin(), m.end()); we can avoid this step INTERNAL STEP

    // build a max heap out of the tuples in 'freq_arr'
    // with custom comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq(m.begin(), m.end());

    int ans = 0;
    // display the top k numbers
    for(int i = 0; i < k; i++) {
        ans += pq.top().second;
        pq.pop();
    }
    return ans;
}

// Time Complexity: O(n + nlogn + klogn) = O(n + (n+k)log n), RECHECK
// Space Complexity: O(n) for Map + O(n) for Heap = O(n)
