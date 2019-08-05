/*
Roof Top

Problem Statement:
You are given heights of consecutive buildings. You can move from 
the roof of a building to the roof of next adjacent building. 
You need to find the maximum number of consecutive steps 
you can put forward such that you gain an increase in altitude.

Input:
The first line contains an integer T, denoting number of test cases. 
First line of each test case contains an integer N, denoting number of buildings. 
Second line of the test case contains N space separated integers, 
the ith integer denote the hieght of the ith building.

Output:
For each test case, print maximum number of consecutive steps he can put forward such that 
he increase in altitude, in separate lines. He initially is on the roof of the first building.

Constraints:
1 <= T <= 104
1 <= N <= 104
1 <= Ai <= 104

Example:
Input:
2
5
1 2 2 3 2
4
1 2 3 4

Output:
1
3

Explanation:
Testcase 1: 1, 2 or 2, 3 are the only consecutive buildings with increasing heights.
Testcase 2: 1 to 2 to 3 to 4 is the jump of length 3 to have maximum number of buildings with increasing heights.
*/

// !IMPORTANT
/*This problem is basically a variation of Longest increasing subarray*/

#include <bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
int maxStep(int arr[], int n) {
    int count = 0, maximum = 0;
    for(int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) {
            count++;
        } else {
            maximum = max(count, maximum);
            count = 0;
        }
    }
    return max(maximum, count);
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    cout << maxStep(a, n) << endl;
	}
	return 0;
}
