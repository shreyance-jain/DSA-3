#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout  << arr[i] << " ";
    }
    cout << endl;
}

void merge_sorted(int arr1[], int arr2[], int m, int n){
    int arr3[m+n];
    int i = 0, j  = 0, k = 0;
    while(i < m && j < n){
        if (arr1[i] > arr2[j])
            arr3[k++] = arr2[j++];
        else 
            arr3[k++] = arr1[i++];
    }
    while (i < m){
        arr3[k++] = arr1[i++];
    }
    while(j < n){
        arr3[k++] = arr3[j++];
    }
    printArray(arr3, m+n);
}

int main(){
    int arr1[] = {1, 3, 5, 7, 9};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {2, 4, 6, 8};
    int n = sizeof(arr2)/sizeof(arr2[0]);
    merge_sorted(arr1, arr2, m, n);
}