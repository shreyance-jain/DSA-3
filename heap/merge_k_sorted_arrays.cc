/* 
Merge k Sorted Arrays

Difficulty: Medium
       
Problem Statement

Given K sorted arrays arranged in the form of a matrix.The task is to merge them.
You need to complete mergeKArrays() function which takes 2 arguments,
an arr[k][k] 2D Matrix containing k sorted arrays and an integer k
denoting the number of sorted arrays.
The function should return a pointer to the merged sorted arrays.

Input:
The first line of input contains the number of test cases, then T test cases follow.
Each test case will contain an integer K denoting the number of sorted arrays(each with size K).
Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

Constraints:
1 <= T <= 50
1 <= K <= 100

Example:
Input:
1
3
1 2 3 4 5 6 7 8 9 

Output:
1 2 3 4 5 6 7 8 9

Explanation:
Testcase 1:
Above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

             [4, 5, 6],

             [7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
 */

#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends


/* 
An efficient solution is to use heap data structure.
The time complexity of heap based solution is O(nk Log k).

1. Create an output array.
2. Create a min heap of size k and insert 1st element in all the arrays into the heap
3. Repeat following steps while priority queue is not empty.
…..a) Remove minimum element from heap (minimum is always at root) and store it in output array.
…..b) Insert next element from the array from which the element is extracted.
If the array doesn’t have any more elements, then do nothing.
 */
struct Triplet {
    int val, aPos, vPos;
    
    Triplet(int v, int ap, int vp) {
        val = v;
        aPos = ap;
        vPos = vp;
    }
};

// Custom comparator for User Defined Data Type MinHeap
struct MyCmp {
    bool operator()(Triplet &t1, Triplet&t2) {
        return t1.val > t2.val;
    }
};

int *mergeKArrays(int arr[][N], int k)
{
    int size = k * k;
    int *res = new int[size];
    int index = 0;
    
    priority_queue<Triplet, vector<Triplet>, MyCmp> pq;
    
    for(int i = 0; i < k; i++) {
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }
    
    while(pq.empty() == false) {
        Triplet curr = pq.top();
        pq.pop();
        res[index++] = curr.val;
        int ap = curr.aPos, vp = curr.vPos;
        if (vp + 1 < k) {
            Triplet t(arr[ap][vp+1], ap, vp+1);
            pq.push(t);
        }
    }
    return res;
}

// Time Complexity: O(nk log k)
// where k is the number of sorted arrays
// and n is the max number of elements in an array,
// so total elements will be upper bounded by n*k
// and extractMin and insert are O(log k) are heap size is k

// Company Tags: Amazon, Citrix, Flipkart, Microsoft, VMWare
