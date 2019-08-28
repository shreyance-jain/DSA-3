/*
Inversion of array
                   
Problem Statement
Given an array arr[] consisting of N positive integers. The task is to find inversion count of array.

!--Important--!
Inverison count basically means the how many pairs are there in input array which is not in order
as they would be in sorted order.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted.
If array is already sorted then inversion count is 0. If array is sorted in reverse order that
inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input Format:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, the size of array.
The second line of each test case contains N elements.

Output Format:
Print the inversion count of array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C ≤ 1018

Example:
Input:
3
5
2 4 1 3 5
5
2 3 4 5 6
3
10 10 10

Output:
3
0
0

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/

#include <bits/stdc++.h>
using namespace std;

long long int _merge(long long arr[], long long temp[], long long left, long long mid, long long right);
long long int _mergeSort(long long arr[], long long temp[], long long left, long long right);
long long int inversionCount(long long arr[],long long N);

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}

long long int _merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
    long long int inv_count = 0;
    long long i, j, k;
    i = left;
    j = mid;
    k = left;
    
    while((i <= mid -1) && (j <= right)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count += mid - i;
        }
    }
    
    while (i <= mid - 1)
        temp[k++] = arr[i++];
        
    while (j <= right)
        temp[k++] = arr[j++];
    
    for(long long i = left; i <= right; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

long long int _mergeSort(long long arr[], long long temp[], long long left, long long right) {
    long long inv_count = 0;
    long long mid;
    if (right > left) {
        mid = left + (right - left) / 2;
        inv_count = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += _merge(arr, temp, left, mid +1, right);
    }
    return inv_count;
}

// Function to find inversion count in the array
// A[]: input array
// N: size of the array
long long int inversionCount(long long arr[],long long N)
{
    long long temp[N];
    return _mergeSort(arr, temp, 0, N-1);
}

// Time Complexity:  O(nlogn)
// Company tags: Adobe, Amazon, BankBazaar, Flipkart, Microsoft, Myntra