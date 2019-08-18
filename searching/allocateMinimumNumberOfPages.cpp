/*

Allocate minimum number of pages

Problem Statement

You are given N number of books. Every ith book has Pi number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. 
In each permutation one of the M students will be allocated the maximum number of pages.
Out of all these permutations, the task is to find that particular permutation in which the maximum number of
pages allocated to a student is minimum of those in all the other permutations, and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated atleast one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order
(see explanation for better understanding).

Other language of asking the same:
Given number of pages in n different books and m students.
The books are arranged in ascending order of number of pages.
Every student is assigned to read some consecutive books.
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum. 

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:
Each case begins with a single positive integer N denoting the number of books.
The second line contains N space separated positive integers denoting the pages of each book.
And the third line contains another integer M, denoting the number of students.


Output:
For each test case, output a single line containing minimum number of pages each student has to read for corresponding test case.

Constraints:
1<= T <= 100
1 <= N <= 106
1 <= A [ i ] <= 106
1 <= M <= 106

Example:
Input:
2
4
12 34 67 90
2
3
15 17 20

Output:
113
32

Explaination: Allocation can be done in following ways:
{12} and {34, 67, 90}     Maximum Pages = 191
{12, 34} and {67, 90}     Maximum Pages = 157
{12, 34, 67} and {90}        Maximum Pages = 113

Therefore, the minimum of these cases is 113, which is selected as output
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int m, long long curr_min) {
    
    int studentRequired = 1;
    long long curr_sum = 0;
    // iterate over all books
    for(int i = 0; i < n; i++) {
        // check if current no of pages is greater than curr_min
        // that means we will get the min after mid no of pages
        if (a[i] > curr_min)
            return false;
        
        // count how many students are required to distribute curr_min pages
        if (a[i] + curr_sum > curr_min) {
            
            // increment student count
            studentRequired++;
            
            // update curr_sum
            curr_sum = a[i];
            
            // if required no of students become greater than given no of pages, return false
            if(studentRequired > m)
                return false;
        } else
        // else update curr_sum
            curr_sum += a[i];
    }
    return true;
}

int findPages(int a[], int n, int m) {
    // return -1 if no of books is less than no of students
    if (n < m)
        return -1;
        
    // count total no of pages
    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
        
    // initalising start as 0 and end as total pages
    long long start = 0, end = sum;
    long long result = LLONG_MAX;
    
    // traversing until start <= end
    while(start <= end) {
        
        long long mid = (start + end) / 2;
        
        // check if possible to distribute books using mid as current minimum
        if (isPossible(a, n, m, mid)) {
            
            // if yes, we find the min distribution
            result = min(result, mid);
            
            // as we are finding minimum and books are sorted so reduce end = mid -1
            end = mid -1;
        } else 
        // if not possible that means pages need to be incremented
        // so update start = mid + 1
            start = mid + 1;
    }
    // at last return min no of pages
    return result;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n;
	    int a[n];
	    for(int i = 0; i < n; i++)
	        cin >> a[i];
	    cin >> m;
	    int min_pages = findPages(a, n, m);
	    cout << min_pages << endl;
	}
	return 0;
}

// Time: BinarySearch with one check which requires O(n) traversal through array, 
// TimeComplexity: O(nlogn)

// Company Tags: Google