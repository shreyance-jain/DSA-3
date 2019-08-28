#include <bits/stdc++.h>
using namespace std;

// QUICK SORT

/* The key process in quickSort is partition().
Target of partitions is, given an array and an element x of array as pivot,
put x at its correct position in sorted array and put all smaller elements (smaller than x) before x,
and put all greater elements (greater than x) after x. All this should be done in linear time. */

int partition (int arr[], int low, int high);
// arr[] --> Array to be sorted, low  --> Starting index, high  --> Ending index
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        quickSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)
{
   int pivot = arr[high];
   int i = low - 1;
   for (int j = low; j <= high - 1; j++) {
       if (arr[j] < pivot) {
           i++;
           swap(arr[j], arr[i]);
       }
   }
   swap(arr[i+1], arr[high]);
   return i + 1;
}