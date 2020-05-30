/* 
Minimum Swaps to Sort

Difficulty: Medium

Problem Statement

Given an array of integers.
Find the minimum number of swaps required to sort the array in non-decreasing order.

Input:
The first line of input contains an integer T denoting the no of test cases.Then T test cases follow.
Each test case contains an integer N denoting the no of element of the array A[ ].
In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting
minimum number of swaps that are required to sort the array.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[] <= 106

Expected Time Complexity: O(NlogN).
Expected Auxiliary Space: O(N).

Example(To be used only for expected output):
Input:
2
4
4 3 2 1
5
1 5 4 3 2

Output:
2
2

Explanation:
Test Case 1: We need two swaps, swap 1 with 4 and 3 with 2 to make it sorted.
Test Case 2: We need two swaps, swap 2 with 5 and 3 with 4 to make it sorted. 
 */

#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

/* 
Here the approach is same as set-1 same time and space complexity.
Here idea is to do actual swaps instead of moving in cycles(but the concept is same)

So the idea is to create a vector of pair in C++ with
first element as array values and second element as array indices.
The next step is to sort the vector of pair according to the first element of the pair.
After that traverse the vector and check if the index mapped with the value is correct or not,
if not then keep swapping until the element is placed correctly and keep counting the number of swaps.
 */
int minSwaps(int A[], int N){
    // an array of pair
    pair<int, int> arrPos[N];
    for(int i = 0; i < N; i++) {
        arrPos[i].first = A[i];
        arrPos[i].second = i;
    }
    
    // sort array w.r.t. first element of pair
    sort(arrPos, arrPos+N);
    
    int ans = 0;
    
    for(int i = 0; i < N; i++) {
        // if element is already placed correct then continue
        if (arrPos[i].second == i)
            continue;
        
        // else swap with respective index
        swap(arrPos[i].first, arrPos[arrPos[i].second].first);
        swap(arrPos[i].second, arrPos[arrPos[i].second].second);
        
        // swap until correct index matches
        if (i != arrPos[i].second)
            i--;
        // count every swap
        ans++;
    }
    return ans;
}

// Time complexity: O(nlogn)
// Space compelxity: O(n)
