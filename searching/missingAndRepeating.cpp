/*
Repeating And Missing

Problem Missing: Find the repeating and the missing Given an unsorted array of size n. 
Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing
 and one number occurs twice in the array. Find these two numbers.

Examples:

 
Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 
2 is missing and 3 occurs twice 

Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: Missing = 5, Repeating = 1

*/


#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printMissingRepeating(int repeating, int missing) {
    cout << "Repeating: " << repeating << endl;
    cout << "Missing: " << missing << endl;
}

void repeatingMissing(int arr[], int n) {
    int repeating, missing;
    for(int i = 0; i < n; i++){
        int temp = arr[abs(arr[i])-1];
        if (temp < 0) {
            repeating = abs(arr[i]);
        }
        arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
    }
    printArray(arr, n);
    for(int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
        }
    }
    printMissingRepeating(repeating, missing);
}

int main() {
    int arr[] = {2, 3, 2, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    repeatingMissing(arr, n);
}

// Time: O(n)
// Space: O(1)