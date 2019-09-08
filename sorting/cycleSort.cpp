#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n);
void cycleSort(int arr[], int n);

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cycleSort(arr, n);
        printArray(arr, n);
        cout << endl;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void cycleSort(int arr[], int n) {
    int writes = 0;
    for(int cycle_start = 0; cycle_start <= n-2; cycle_start++) {
        int pos = cycle_start;
        int item = arr[cycle_start];

        // find positon where we put this element
        for(int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;
        
        // items is already in its correct position
        if (pos == cycle_start)
            continue;
        
        // ignore all duplicates elements
        while (item == arr[pos])
            pos++;

        // put the item to its correct position
        if (pos != cycle_start) {
            swap(arr[pos], item);
            writes++;
        }

        // rotate the rest of the cycle
        while(pos != cycle_start) {
            pos =  cycle_start;
            // find position where we put this element
            for(int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;
            
            // ignore all duplicates
            if (item == arr[pos])
                pos++;
            
            // put the item to its correct position
            if (item != arr[pos]) {
                swap(arr[pos], item);
                writes++;
            }
        }
    }
}

/* 
Time Complexity : O(n^2)
Worst Case : O(n^2)
Average Case: O(n^2)
Best Case : O(n^2)

This sorting algorithm is best suited for situations where memory write or swap operations are costly.
 */