#include <iostream>

using namespace std;

/*If brute force require k steps
 to process a window of size k
and there were n windows in the sequence,
then it would require n.k steps for burte force to complete
but because only two elememts change with every move,
we can achieve an overall running time proportional to 2n*/

void printArray(int arr[], int n){
    int i = 0;
    while(i < n){
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}
// O(n) solution for finding maximum sum of 
// a subarray of size k
int maxSubArray(int arr[], int k, int n){
    // k must be greater than n
    if (k > n) return -1;
    int sumOfWindow = 0, maxSum;
    // compute sum of first window of size k
    for(int i = 0; i < k; i++){
        sumOfWindow += arr[i];
    }
    maxSum = sumOfWindow;
    /* Compute sum of remaining windows by 
    removing first element of the previous window 
    and adding last element of the current window */
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