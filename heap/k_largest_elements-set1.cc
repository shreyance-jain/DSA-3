/* 
k largest elements

Difficulty: Basic

Problem Statement

Given an array of N positive integers, print k largest elements from the array.
The output elements should be printed in decreasing order.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N and k, N is the size of the array and
K is the largest element to be returned.
The second line of each test case contains N input C[i].

Output:
Print the k largest element in descending order.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10000
K ≤ N
1 ≤ C[i] ≤ 100000

Example:
Input:
2
5 2
12 5 787 1 23
7 3
1 23 12 9 30 2 50

Output:
787 23
50 30 23

Explanation:
Testcase 1: 1st largest element in the array is 787 and the second-largest is 23.
Testcase 2: 3 Largest element in the array are 50, 30 and 23.
 */

#include<bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        
        kLargest(arr, n, k);
        
    }
    return 0;
}

/* Approach: Use a MAX HEAP data structure.
1. Build a max heap of n elements. Time Complexity: O(n)
2. Remove k elements one by one. Time Complexity: O(k*logn)
*/
void kLargest(int arr[], int n, int k){
    priority_queue<int> pq(arr, arr+n);
    while(k--) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

// Time Complexity: O(n + klogn)
// Aux Space Complexity: O(n), for creating a priority queue of n elements, does not modify the original array

// Company Tags: Amazon, Microsoft, Walmart
