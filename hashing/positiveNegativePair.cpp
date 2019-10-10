/* 
Positive Negative Pair

Problem Statement

Given an array arr[] of N positive and negative integer pairs, may not be in sorted order.
The task is to pair the positive and negative element in such a way that a positive element
is paired with a negative element of same absolute value.
If a pair element is not present for an element, then ignore it.
The output should contain all pairs in increasing order of absolute values.
To print a pair, positive value should be printed before its corresponding negative value.
Note: The elements in array are distinct.

Input:
First line of input contains number of testcases T.
For each testcase, first line contains an integer N, number of elements in the array.
Next line contains N space separated array elements.

Output:
For each testcase, print the pairs of positive and negative, sorted with positive numbers.
If no such pair exists, print 0.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
8
1 3 6 -2 -1 -3 2 7
3
3 2 -3
 

Output:
1 -1 2 -2 3 -3
3 -3
 

Explanation:
Testcase 1: 1, 2 and 3 are present pairwirse postive and negative. 6 and 7 have no pair.
 */

#include <bits/stdc++.h>
using namespace std;

/* The idea is to use hashing.
Approach 1: Use Map
In this, traverse the given array and increase the count at the absolute value of hash table. If count becomes 2,
store the absolute value in another vector, and finally sort the vector
Approach 2: Uses Set
In this, traverse the given array and check if the corresponding -ve exists in it or not, if yes, add to vector.
If not add to set */

void printPair(int arr[], int n) {
    vector<int> pair;
    unordered_set <int> s;

    // traverse the input array
    for(int i = 0; i < n; i++) {
        
        // check is corresponding element is there in set, if yes, add to result vector
        if (arr[i] != 0 && s.find(-arr[i]) != s.end()) {
            pair.push_back(abs(arr[i]));
    
        } else {
            // else simply push in set for further check
            s.insert(arr[i]);
        }
    }
    // print element and its pair
    if (pair.size()) {
        vector<int>::iterator p;

        // sort result containg vector to print result in increasing order
        sort(pair.begin(), pair.end());

        // print the elements in required format
        for(p = pair.begin(); p != pair.end(); p++) {
            cout << *p << " " << -*p << " ";
        }
    } else {
        // if vector is empty then no pair exists
        cout << "0";
    }

    s.clear();
    pair.clear();
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    printPair(arr, n);
	    cout << endl;
	}
	return 0;
}
