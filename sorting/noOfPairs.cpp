/* 
Number of pairs

Problem Statement
Given two arrays X and Y of positive integers, find number of pairs such that xy > yx (raised to power of)
where x is an element from X and y is an element from Y.

Input Format:
The first line of input contains an integer T, denoting the number of test cases.
Then T test cases follow. Each test consists of three lines.
The first line of each test case consists of two space separated M and N denoting size of arrays X and Y
respectively. 
The second line of each test case contains M space separated integers denoting the elements of array X. 
The third line of each test case contains N space separated integers denoting elements of array Y.

Output Format:
Corresponding to each test case, print in a new line, the number of pairs such that xy > yx.

Constraints:
1 ≤ T ≤ 100
1 ≤ M, N ≤ 105
1 ≤ X[i], Y[i] ≤ 103

Example:
Input
1
3 2
2 1 6
1 5

Output
3

Explanation:
Testcase 1: The pairs which follow xy > yx are as such: 21 > 12,  25 > 52 and 61 > 16 
 */

#include<bits/stdc++.h>
using namespace std;

/* 
Efficient Solution:
The problem can be solved in O(nLogn + mLogn) time.
The trick here is, if y > x then x^y > y^x with some exceptions.

Following are simple steps based on this trick.

Sort array Y[].
For every x in X[], find the index idx of smallest number greater than x (also called ceil of x) in Y[]
using binary search or we can use the inbuilt function upper_bound() in algorithm library.
All the numbers after idx satisfy the relation so just add (n-idx) to the count.
 */

long long countPairs(int x, int Y[], int n, int noOfY[]) {
    
    // if x is zero no such pairs
    if (x == 0) return 0;
    
    // if x = 1, the no of pairs is equal to no of 0s in y[]
    if (x == 1) return noOfY[0];
    
    /* as y > x for all elements after upper bound and at upper bound and element at upper bound,
    we add all these elements and then we handle exceptions */
    int *idx = upper_bound(Y, Y + n, x);
    long long ans = Y + n - idx;
    
    // no if x is not 0 or 1 the we add no of 0s and no of 1s in Y[] as they will also make pair with x
    ans += (noOfY[0] + noOfY[1]);
    
    // if x is 2, then we deduct no of 3 and no of 4 as they are already counted
    if (x == 2) ans -= (noOfY[3] + noOfY[4]);
    
    // if x is 3, we add no of 2 in Y[] as they make pair with 3
    if (x == 3) ans += (noOfY[2]);
    
    return ans;
}

long long countPairs(int X[], int Y[], int m, int n)
{
  // this array is used to keep track of count of no of 0, 1, 2, 3, 4s in Y[]
    int noOfY[5] = {0};
    
    for(int i = 0; i < n; i++)
        if (Y[i] < 5)
            noOfY[Y[i]]++;

    // sort the Y[]    
    sort(Y, Y + n);
    
    long long totalCount = 0;
    // search upper bound of X[i] in Y[] and count no of pairs
    for(int i = 0; i < m; i++)
        totalCount += countPairs(X[i], Y, n, noOfY);
        
    return totalCount;
}


int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, M, N)<<endl;
	}
}

/* TIME COMPLEXITY: O(nlogn + mlogn), where m and n are the sizes of X[] and Y[] respectively.
The sort step takes O(nlogn) time. Then every element of X[] is searched from in Y[]
using binary search. This steps takes O(mlogn) time*/