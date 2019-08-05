/*
Search an Element in an array

Problem Statement:

Given an integer array Arr[] and an element x. The task is to find if the given element is present in array or not.

Input:
First line contains an integer, the number of test cases 'T'. For each test case, first line contains an integer 'N', 
size of array. The second line contains the elements of the array separated by spaces. Third line contains element to ;
be find in the array.

Output:
For each testcase, output a single line containing first index of element to be found in array. 
If element is not in the array, then print "-1" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Arr[i] <= 100

Example:
Input:
1
4
1 2 3 4
3

Output:
2

Explanation:
Testcase 1: There is one test case with array as {1, 2, 3 4} and element to be searched as 3.  Since 3 is present at index 2, output is 2.
*/


#include<bits/stdc++.h>
using namespace std;

// Function to search x in arr
// arr: input array
// x: element to be searched for
int search(int arr[], int n, int x)
{
    
    // Your code here
    for(int i = 0; i < n; i++) {
        if(arr[i] == x)
            return i;
    }
    return -1;
}


int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        int x;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cin>>x;
        cout<<search(arr,sizeOfArray,x)<<endl; //Linear search
    }
    return 0;
    
}