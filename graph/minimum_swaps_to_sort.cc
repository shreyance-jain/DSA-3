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
This can be easily done by visualizing the problem as a graph.
We will have n nodes and an edge directed from node i to node j if
the element at i’th index must be present at j’th index in the sorted array.

The graph will now contain many non-intersecting cycles.
Now a cycle with 2 nodes will only require 1 swap to reach the correct ordering,
similarly a cycle with 3 nodes will only require 2 swap to do so.

Hence,

ans = Σi = 1k(cycle_size – 1), where k is the number of cycles

For detailed explanation of this concept see notes
 */
int minSwaps(int arr[], int N){
    // create an array of pairs where first element is the array element
    // and second element is position of the element
    pair<int, int> pos[N];
    for(int i = 0; i < N; i++)
        pos[i] = {arr[i], i};

    // sort this newly created array, (pair elements by default use the first element to sort)
    // besides having element value and initial index(which hace as pair in pos array)
    // we would also get their final indexes in sorted array
    sort(pos, pos+N);
    
    // to keep track of visited elements
    bool vis[N];
    for(int i = 0; i < N; i++)
        vis[i] = false;

    int ans = 0;
    // traverse arrray elements
    for(int i = 0; i < N; i++) {
        // already swapped and corrected and already present at correct position
        if (vis[i] || pos[i].second == i)
            continue;
        
        // find out number of nodes in this cycle
        int j = i;
        int cycle_size = 0;
        while(!vis[j]) {
            vis[j] = true;
            // move to next node
            j = pos[j].second;
            cycle_size++;
        }
        // update ans by adding current cycle
        if (cycle_size > 0)
            ans += cycle_size -1;
    }
    return ans;
}

// Time complexity: O(nlogn)
// Space compelxity: O(n)
