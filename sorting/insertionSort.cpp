// C program for insertion sort
#include <bits/stdc++.h>

using namespace std;

void insert(int arr[], int i);

void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i <n; i++)
      insert(arr, i);
}

void insert(int arr[], int i)
{
    // Your code here
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i= 0; i < size; i++)
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
        for(int i=0; i < n; i++)
            cin >> arr[i];
            insertionSort(arr, n);
            printArray(arr, n);
    }
    return 0;
}
