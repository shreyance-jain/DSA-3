// C program for implementation of Merge Sort
//#include <stdio.h>
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Driver program to test above functions
int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        mergeSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
     int i, j, k;
     int n1 = m - l + 1;
     int n2 = r - m;
     int L[n1], R[n2];
     
     for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
        
     for(int j = 0; j < n2; j++)
        R[j] = arr[j + m + 1];
        
    i = 0;
    j = 0;
    k = l;
    
    while(i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    while(i < n1)
        arr[k++] = L[i++];
        
    while(j < n2)
        arr[k++] = R[j++];
}