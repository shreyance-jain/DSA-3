#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    int i = 0;
    while(i < n){
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}

int maxSubArray(int arr[], int k, int n){
    if (k > n) return -1;
    int sumOfWindow = 0, maxSum;
    for(int i = 0; i < k; i++){
        sumOfWindow += arr[i];
    }
    maxSum = sumOfWindow;
    for(int i = k; i < n; i++){
        sumOfWindow += arr[i] - arr[i-k];
        maxSum = max(sumOfWindow, maxSum);
    }
    return maxSum;
}


int main(){
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int maxSumOfK = maxSubArray(arr, k, n);
    cout << "maximum sum of subarray of size k " << maxSumOfK << endl;
}