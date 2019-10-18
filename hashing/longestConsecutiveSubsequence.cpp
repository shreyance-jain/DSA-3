/* 
Longest consecutive subsequence

Problem Statement
Given an array arr[] of positive integers.
Find the length of the longest sub-sequence such that
elements in the subsequence are consecutive integers,
the consecutive numbers can be in any order.

Input Format:
The first line of input contains T, number of test cases.
First line of line each test case contains a single integer N.
Next line contains N integer array.

Output Format:
Print the output of each test case in a seprate line.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= a[i] <= 105

Example:
Input:
2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:
6
4

Explanation:
Testcase 1:  The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

Testcase2: 1, 2, 3, 4 is the longest consecutive subsequence.
 */

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}

/* 
Rather than checking in a brute force way (sorting here), we will use hashing.
Apprach:
- create an empty hash
- insert all the elements in the hash
- do the following for every element of arr[i]
- check if this element is the starting point of a subsequence. To check this we simply look for arr[i] - 1
in the hash, if not found, then this is the first element in the hash
- if this element is the first element of a subsequence, then find the number of elements in the consecutive
starting with this element. Iterate from arr[i] + 1, till the last element that can be found
- if the count is more than previous subsequence, the update this.
 */
int findLongestConseqSubseq(int arr[], int n)
{
  unordered_set <int> s;
  int maxx = -1;
  // hash all the array elements
  for(int i = 0; i < n; i++)
    s.insert(arr[i]);
    
  // check each possible sequence from the start and update optimal length
  for(int i = 0; i < n; i++) {
      // int count = 0;
      int temp = arr[i];
      // if the current element is the starting element of a sequence
      if (s.find(temp - 1) == s.end()) {
        // check for other elements in the sequence
          while(s.find(temp) != s.end()) {
          temp++;
          // count++;
        }
        // update optimal lenght if this length is more
        maxx = max(maxx, temp - arr[i]);
      }
  }
  return maxx;
}

// Company tags: Amazon, Walmart
/* Time Complexity: At first look the time complexity of this looks more than O(n).
If we take a closer look, we can notice that is is O(n) under the assumption that hash insert and search takes
O(1) time. The function s.find() inside while loop is called at most twice for every element
In this case the outer find is called for every element, but we go inside the if condition only for
the smallest element. Once we are inside if condition then we can call find() one more time for every element */