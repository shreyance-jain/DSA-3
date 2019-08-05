/*

Majority Element

Problem Statement:
Given an array A of N elements. Find the majority element in the array. A majority element in an array A 
of size N is an element that appears more than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. The first line 
of the test case will be the size of array and second line will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. Output "-1" if no 
majority element is there in the array.

Constraints:
1 <= T<= 100
1 <= N <= 107
0 <= Ai <= 106

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

/*
 (Using Moore’s Voting Algorithm)
This is a two step process.

NOTE : This Method only works when we are given that majority element do exist
 in the array , otherwise this method won’t work , 
 as in the problem definition we said that majority element may or may not exist 
 but for applying this approach you can assume that majority element do exist 
 in the given input array

The first step gives the element that may be majority element in the array. 
If there is a majority element in an array, then this step will definitely return majority element,
otherwise it will return candidate for majority element.
Check if the element obtained from above step is majority element.
This step is necessary as we are not always sure that element return by first step is majority element
*/

#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
// Function to find majority element in the array
// a: input array
// size: size of input array

int getCandidate(int a[], int size) {
    int maj_index = 0;
    int count = 1;
    for(int i = 0; i < size; i++) {
        if(a[maj_index] == a[i+1]) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

int majorityElement(int a[], int size)
{   
    int candidate = getCandidate(a, size);
    int count = 0;
    for(int i = 0; i < size; i++) {
        if (a[i] == candidate)
            count++;
    }
    if (count > size/2) {
        return candidate;
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }
    return 0;
}
// Time Complexity: O(n)
// Auxiliary Space: O(1)

// Comapany tags: Accolite, Amazon, D-E-Shaw, Microsoft, Nagarro