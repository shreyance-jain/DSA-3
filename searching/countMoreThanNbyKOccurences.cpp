/*
Count More than n/k Occurences

Problem Statement:

Given an array arr[] of size N and an element k. The task is to find all elements in array that
appear more than n/k times.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
Each test case contains an integer n denoting the size of the array. Then the next line contains n space
separated integers forming the array. The last line of input contains an integer k.

Output:
Print the count of elements in array that appear more than n/k times.

Constraints:
1 <= T <= 102
1 <= N <= 106
1 <= a[i] <= 106
1 <= k <= N

Example:
Input:
2
8
3 1 2 2 1 2 3 3
4
4
2 3 3 2
3

Output:
2
2

Explanation:
Testcase 1: In the given array, 3 and 2 are the only elements that appears more than n/k time
*/


// A C++ program to print elements with count more than n/k
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Function to find element with count more than n/k times
// arr: input array
struct eleCount {
    int e; // element
    int c; // count
};

int countOccurence(int arr[], int n, int k)
{
    // k must be greater than 1 to get some output
    
    if (k < 2)
        return 0;
    int totalCount = 0;

    // temp array of size k-1 contains elements and counts,
    
    struct eleCount temp[k-1];
    
    // initialised count of all element as 0
    
    for(int i = 0; i < k-1; i++)
        temp[i].c = 0;
        
    // loop over all the elements of the array
    
    for(int i = 0; i < n; i++) {
        int j;
        
        // if arr[i] is already present in the count array than increment its count
        
        for(j = 0; j < k-1; j++) {
            if (temp[j].e == arr[i]) {
                temp[j].c += 1;
                break;
            }
        }
        
        // If arr[i] is not present in temp[]
        
        if (j == k-1) {
            
            // if there is a positon available in temp, then placing arr[i]
            // in first available position and set count as 1
            int l;
            for(l = 0; l < k-1; l++) {
                if (temp[l].c == 0) {
                    temp[l].e = arr[i];
                    temp[l].c = 1;
                    break;
                }
            }
            
            // if all the positions in the temp array is filled,
            // then decrement the count of all the elements
            if (l == k-1)
                for(l = 0; l < k-1; l++)
                    temp[l].c -= 1;
        }
    }
    // step3:  check actual counts of potential candidates in temp[]
    
    for(int i = 0; i < k-1; i++) {
        // calculating actual counts of elements
        
        int ac = 0; // actual counts
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].e)
                ac++;
        
        // check if actual count is greater than n/k
        
        if (ac > n/k) {
            totalCount++;
            cout << "Number: " << temp[i].e << " Count: " << ac << endl;
        }
        
    }
    return totalCount;
    
}

/* Driver program to test above function */
int main()
{
    int t ,k;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        
        int arr[n];
        
        for(i=0;i<n;i++)
        cin>>arr[i];
        cin>>k;
        cout<<countOccurence(arr, n, k)<<endl;
        
    }
    return 0;
}

// Time: 0(nk)
// Space: O(k)

// Company tags: Amazon