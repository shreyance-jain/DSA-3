/*
Median of Two sorted arrays

Problem Statement

Given two sorted arrays arr[] and brr[] of sizes N and M respectively.
The task is to find the median of the two arrayswhen they get merged.

Input:
First line of input contains number of testcases T. First line of input contains
number of elements in both arrays N and M respectively. Next two lines contains the array elements.

Output:
For each testcase, print the median of two sorted arrays.
If there are total even elements, we need to print floor of average 
of middle two elements.

Constraints:
1 <= T <= 100
1 <= N, M <= 106
1 <= arr[i], brr[i] <= 107

Example:
Input:
3
5 6
1 2 3 4 5
3 4 5 6 7 8
2 3
1 2
2 3 4
4 4
1 2 3 4
11 12 13 14

Output:
4
2
7

Explanation:
Testcase 1: After merging two arrays, elements will be as 1 2 3 3 4 4 5 5 6 7 8. So, median is 4.
*/


#include <iostream>
using namespace std;

// Notes from geeks:
/*
The process of the partition :
To make two halves, make the partition such that the index that partitioning array A[] + 
the index that partitioning array B[] are equal to the total number of elements plus one divided by 2, 
i.e. (n + m + 1) / 2 (+1 is, if the total number of elements is odd).
First, define two variables : min_index and max_index, and initialize min_index to 0, and max_index to the 
length of the smaller array. In these below examples A[] is the smaller array.
To partition A[], use the formula (min_index + max_index) / 2 and insert it to a variable i. To partition B[], 
use the formula (n + m + 1) / 2 – i and insert it to a variable j.
the variable i means the number of elements to be inserted from A[] into the first half, and j means the number
of elements to be inserted from B[] into the first half, the rest of the elements will be inserted into the second half.
*/

/*
Why the above condition leads to the median ?
Imp concept: The median is the (n + 1) / 2 smallest element of the array,
and here, the median is the (n + m + 1) / 2
smallest element among the two arrays. If, all the elements in the first half are less than (or equal) to all
elements in the second half, in case of odd numbers in total, just calculate the maximum between the last two
elements in the first half (a2 and b2 in our example),and this will lead us to the (n + m + 1) / 2 smallest element
among the two arrays, which is the median ((7 + 4 + 1) / 2 = 6). But in case of even numbers in total,
calculate the average between the maximum of the last two elements in the first half (a1 and b2 in our example)
with its successive number among the arrays which is the minimum of first two elements in the second half
(a2 and b3 in our example).
*/

int getMedianOfTwoSortedArray(int a[], int b[], int n, int m) {
    int min_index = 0, max_index = n, i , j, median;
    
    while(min_index <= max_index) {
        i = (min_index + max_index) / 2;
        j = ((n + m + 1) / 2) - i;
        // search right
        if (i < n && j > 0 && b[j-1] > a[i])
            min_index = i + 1;
        // search left
        else if (i > 0 && j <m && b[j] < a[i-1])
            max_index = i - 1;
        // found req halves
        else {
            if (i == 0)
                median = b[j-1];
            else if (j == 0)
                median = a[i-1];
            else
                median = max(a[i-1], b[j-1]);
            break;
        }
    }
    if ((n + m) % 2 == 1)
        return median;
    if (i == n)
        return (median + b[j]) / 2;
    if (j == m)
        return (median + a[i]) / 2;
    return (median + min(a[i], b[j])) / 2;
}

int main() {
	//
	
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	    for(int i = 0; i < n; i++)
	        cin >> a[i];
	    for(int j = 0; j < m; j++)
	        cin >> b[j];
	    if (n < m)
	        cout << getMedianOfTwoSortedArray(a, b, n, m) << endl;
	    else
	        cout << getMedianOfTwoSortedArray(b, a, m ,n) << endl;
	}
	return 0;
}

// Time Complexity: O(log(min(n, m))), where n and m are the sizes of given sorted array

// Company tags: DE-Shaw, Ola-Cabs, Samsung