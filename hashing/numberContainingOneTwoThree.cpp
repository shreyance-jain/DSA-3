/* 
Numbers containing 1, 2 and 3

Problem Statement

Given an array arr[] of N numbers. The task is to print only those numbers whose digits are from set {1,2,3}.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines.
First line of each test case contains an integer N and the second line contains N space separated array elements.

Output:
For each test case, In new line print the required elements in increasing order.
if there is no such element present in the array print "-1".

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 106

Example:
Input:
3
3
4 6 7
4
1 2 3 4
5
12 111 34 13 55

Output:
-1
1 2 3
12 13 111

Explanation:
Testcase 1: No elements are there in the array which contains digits 1, 2 or 3.

Testcase 2: 1, 2 and 3 are the only elements in the array which conatins digits as 1, 2 or 3.
 */

#include <bits/stdc++.h>
using namespace std;

int flag[1000001];

/* Approach: Hash all the numbers that can be generated using the digits 1, 2 and 3
Traverse the hash table and check if the number exist in the input array, this also keeps track of inrcreasing order */

int main() {
	int t;
	cin >> t;
	vector<int> a;
	int j = 1;
	a.push_back(j);
	a.push_back(j+1);
	a.push_back(j+2);
	int num = 1, num2;
	j = 0;
    // push the number which have digit as 1, 2 and 3 only
	while(num <= 1000000) {
	    num2 = a[j++];
	    
	    if ((num2 * 10) + 1 <= 1000000) {
	        a.push_back((num2 * 10) + 1);
	    }
	    
	    if ((num2 * 10) + 2 <= 1000000) {
	        a.push_back((num2 * 10) + 2);
	    }
	    
	    num2 = (num2 * 10) + 3;
	    if (num2 <= 1000000) {
	        a.push_back(num2);
	    }
	    
	    num = num2;
	}
	
	while(t--) {
	    int n, k, i;
	    cin >> n;
	    bool flag2 = 0;
	    memset(flag, 0, sizeof(flag));
	    int max2 = 0;
        // find max in the array, this would help us in keeping track which all elements from 
        // pre-processed vector (which has numbers with digit 1,2 and 3 only called a<vector> in code) need to looked 
        // up in direct access table (flag) using index as the array input element
	    for(i = 0; i < n; i++) {
	        cin >> k;
	        flag[k]++;
	        max2 = max(max2, k);
	    }
	    for(i = 0; a[i] <= max2 && i < a.size(); i++) {
            // check the frequency in the array element in vector which is filled in preprocessing
	        while (flag[a[i]] > 0) {
	            cout << a[i] << " ";
	            flag2 = 1;
	            flag[a[i]]--;
	        }
	    }
	    if (flag2 == 0) {
	        cout << "-1";
	    }
	    cout << endl;
	}
	return 0;
}

// Comapny Tags: Goldman Sachs