/*
Triplet Sum in Array

Problem Statement

Given an array A[] of N numbers and another number x.
The task is to determine whether or not there exist three elements in A[] whose sum is exactly x.

Input Format:
First line of input contains number of testcases T.
For each testcase, first line of input contains n and x. Next line contains array elements.

Output Format:
Print "1" (without quotes) if there exist three elements in A whose sum is exactly x, else "0" (without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
1 ≤ A[i] ≤ 105

Example:
Input:
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
1
1

Explanation:
Testcase 1: There is one triplet with sum 13 in the array. Triplet elements are 1, 4, 8, whose sum is 13.
*/


#include <bits/stdc++.h>
using namespace std;

/* Navie approach will be to run three loops and check for every triplet O(n^3)

    So the other better approach is to sort the array and run 2 loops, and use 2 pointer approach in inner loop and search
    for value equal to x - arr[i] , where arr[i] is the current value of element in outer loop O(n^2)

    We can also use hashing based solution which will also be O(n^2), so the above approach is better beacuse there would
    be no hash function compuation and calculations for avoiding collisions

*/

bool find3Numbers(int A[], int arr_size, int x)
{
    // sort the array to use the 2 pointer approach
    sort(A, A + arr_size);
    // outer loop: 
    for(int i = 0; i < arr_size; i++) {
        // 2 pointer approach on inner loop, where sum would be x - arr[i] (element of outer loop)
        int lo = i + 1;
        int hi = arr_size - 1;
        // we only need to run till hi < lo, because there would be equality also on hi and lo
        while (hi > lo) {
            // if we found the required sum
            if (A[hi] + A[lo] + A[i] == x) {
                return true;
            // if the required sum is smaller, then since the array is sorted we decrement the hi pointer
            } else if (A[hi] + A[lo] + A[i] > x) {
                hi--;
            // if the required sum in greater, increment the lo pointer, since the array is sorted we need to approch
            // greater sum
            } else {
                lo++;
            }
        }
    }
    return false;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin >> N >>sum;
		int i,A[N];
		for(i = 0; i < N; i++)
			cin >> A[i];
        cout <<  find3Numbers(A, N, sum) << endl;
    }
}


// Time Complexity: O(n^2)
// Aux Space Complexity: O(1)

// Company tags: Accolite, Amazon, Carwale, OYORooms, Samsung