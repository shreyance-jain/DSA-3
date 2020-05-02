#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with root i
// which is an index in arr. n is the size of heap
void heapify(int arr[], int n, int i);

void buildHeap(int arr[], int n);

// main function to do heap sort
void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for(int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// function to print an array
void print(int arr[], int size) {
    int i;
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// driver program to test above functions
int main() {
    int n, T, i;
    cin >> T;
    while(T--) {
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        heapSort(arr, n);
        print(arr, n);
    }
    return 0;
}

int left(int i) {
    return (2 * i + 1);
}

int right(int i) {
    return (2 * i + 2);
}

// for increasing order we use MAX HEAP
void heapify(int arr[], int n, int i) {
    // get the left child
    int lt = left(i);
    // get the right child
    int rt = right(i);
    // variable to hold largest of root, left and right child
    int largest = i;

    // find the largest of root, left and right child, because MAX_HEAP
    
    // compare with left child, if left child is greater update latgest
    if (lt < n && arr[lt] > arr[largest])
        largest = lt;

    // compare largest with right child, if right child is greater update largest
    if (rt < n && arr[rt] > arr[largest])
        largest = rt;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // recur for that child
        heapify(arr, n, largest);
    }

}

// Reaaranges input array so that is becomes MAX HEAP
void buildHeap(int arr[], int n) {
    // Rightmost Internal Node
    int i = (n-2) / 2; // => parent of the last node
    // call heapify from all internal nodes till root
    for(i; i >= 0; i--)
        heapify(arr, n, i);
}

// Time Complexity: O(nlogn), refer DSA notes for few special notes

// Company Tags: 24*7 Innovation Labs, Amazon, Belzabar, Intuit, Orcale,
// Samsung, SAPLabs, Visa
