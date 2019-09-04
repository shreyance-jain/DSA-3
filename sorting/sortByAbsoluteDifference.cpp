/* 
Sort by Absolute Difference

Problem Statement

Given an array of N elements and a number K.
The task is to arrange array elements according to the absolute difference with K, i. e.,
element having minimum difference comes first and so on.
Note : If two or more elements are at equal distance arrange them in same sequence as in the given array.

Input Format:
First line of input contains a single integer T which denotes the number of test cases.Then T test cases follows.
First line of test case contains two space separated integers N and K.
Second line of each test case contains N space separated integers.

Output Format:
For each test case print the given array in the order as described above.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= K <= 105

Example:
Input:
3
5 7
10 5 3 9 2
5 6
1 2 3 4 5
4 5
2 6 8 3

Output:
5 9 10 3 2
5 4 3 2 1
6 3 2 8

Explanation:
Testcase 1: Sorting the numbers accoding to the absolute difference with 7, we have array elements as 5, 9, 10, 3, 2.
 */
#include <bits/stdc++.h>
using namespace std;

/* This solution is based on Functors. Compare the absolute value of the difference of the given number, k 
with the array value arr[i] and returns true if the value of first object is less than second object.

Functors in cpp: https://www.geeksforgeeks.org/functors-in-cpp
Stable sort in cpp: https://www.geeksforgeeks.org/stable_sort-c-stl
*/

class compare {
    private:
        int num;
    public:
        compare(int n) {
            num = n;
        }
        
        /* Overloads () operator to perform the desired comparison */
        int operator() (int arr_num1, int arr_num2) {
            return abs(num- arr_num1) < abs(num - arr_num2);
        }
};

void sortABS(int A[],int N, int k)
{
    /* To preserve the order */
   stable_sort(A, A+N, compare(k));
}

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin >> N >> diff;
	    int A[N];
	    
	    for(int i = 0; i < N; i++)
	        cin >> A[i];
	   
	    sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout << val << " ";
	    cout << endl;
	    
	}
	
	return 0;
}

// TimeComlexity: O(nlogn)
// SpaceComplexity: O(1)