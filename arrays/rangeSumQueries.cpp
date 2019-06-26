// PREFIX SUM ARRAYS
#include <iostream>

/**
 * Description : We are given an Array of n integers, 
 * We are given q queries having indices l and r . 
 * We have to find out sum between the given range of indices.
 * 
 * Input 
 * [4, 5, 3, 2, 5]
 *  3
 * 0 3
 * 2 4
 * 1 3
 * Output
 * 14 (4+5+3+2)
 * 10 (3+2+5)
 * 10 (5+3+2)
 */
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout  << arr[i] << " ";
    }
    cout << endl;
}

void generate_prefix_sum(int arr[], int prefix_sum[], int n) {
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
}

int getSum(int prefix_sum[], int l, int r){
    if (l == 0) return prefix_sum[r];
    return prefix_sum[r] - prefix_sum[l-1];
}

int main() {
    int arr[] = {4, 5, 3, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int prefix_sum[n];
    generate_prefix_sum(arr, prefix_sum, n);
    // FIND A BETTER WAY TO CALL THE FNS
    cout << getSum(prefix_sum, 0, 3) << endl;
    cout << getSum(prefix_sum, 2, 4) << endl;
    cout << getSum(prefix_sum, 1, 3) << endl;
}