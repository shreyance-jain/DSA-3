/*
Majority Element

Problem Statement:

Given an array A of N elements. Find the majority element in the array. 
A majority element in an array A of size N is an element that appears more 
than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. 
The first line of the test case will be the size of array and second line 
will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. 
Output "-1" if no majority element is there in the array.

Constraints:
1 <= T<= 100
1 <= N <= 10^7
0 <= Ai <= 10^6

Example:
Input:
2
5
3 1 3 3 2
3
1 2 3

Output:
3
-1

Explanation:
Testcase 1: Since, 3 is present more than N/2 times, so it is the majority element.
*/


#include <iostream> 
using namespace std;


int majorityElement(int arr[], int n) {
    int max_count = 0;
    int index = -1;
    for(int i = 0; i < n; i++) {
        int count = 1;
        for(int j = i+1; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > max_count) {
            max_count = count;
            index = i;
        }
    }
    if (max_count > n/2){
        return arr[index];
    }
    return -1;
}

/* Driver program to check above functions */
int main() 
{ 
    int arr[] = {10, 10, 1, 10, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int ele = majorityElement(arr, n);
    cout << "majority element: " << ele << endl;
    return 0; 
} 


// Time: O(n^2)
// Space: O(1)