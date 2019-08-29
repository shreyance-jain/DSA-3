/*

Count possible triangles

Problem Statement

Given an unsorted array arr of positive integers. Find the number of triangles that can be formed with 
three different array elements as lengths of three sides of triangles. 

Input Format: 
The first line of the input contains T denoting the number of testcases.
First line of test case is the length of array N and second line of test case are its elements.

Output Format:
Number of possible triangles are displayed to the user.

Constraints:
1 <= T <= 10
3 <= N <= 103
1 <= arr[i] <= 103

Example:
Input:
2
3
3 5 4
5
6 4 9 7 8

Output:
1
10

Explanation:
Testcase 1: A triangle is possible with all the elements 5, 3 and 4.
*/

#include <bits/stdc++.h>
using namespace std;

/*Approach/Logic:
Two Pointer Technique:
The time complexity can be greatly reduced using Two pointer method in just two nested loops.
Lets suppose the array given is {4,3,5,7,6}. On sorting the array becomes {3,4,5,6,7}.
We take three variables l ,r and i, pointing to start , end-1 and array element starting
from end of the array.
Now if we can form triange using arr[l] and arr[r] then we can obviously form triangles
from a[l+1],a[l+2]…..a[r-1], arr[r] and a[i], because the array is sorted
which we can directly calculate using (r-l). So the overall complexity of iterating
through all array elements reduces. 
*/

long long findNumberOfTriangles(long long arr[], long long n)
{
    sort(arr, arr+n);
    long long count = 0;
    for(long long i = n - 1; i >= 1; i--) {
        long long l = 0, r = i - 1;
        while (r > l) {
            if (arr[l] + arr[r] > arr[i]) {
                count += r - l;
                r--;
            } else {
                l++;
            }
        }
    }
    return count;
}

int main()
{
    long long size,T;
    
    cin >> T;
    while(T--){
        
    cin >> size;
    long long arr[size];
    for(long long i = 0; i < size; i++)
     cin>>arr[i];
     
    cout<<findNumberOfTriangles(arr, size) <<endl;
    }
    return 0;
}

// Time Complexity: O(n^2)
// Company Tags: Amazon