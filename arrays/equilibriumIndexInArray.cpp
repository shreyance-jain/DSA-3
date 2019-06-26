#include <iostream>

using namespace std;

/**
 * Description - Equilibrium index of an array is an index such that
 * the sum of elements at lower indexes is equal to 
 * the sum of elements at higher indexes
 */

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout  << arr[i] << " ";
    }
    cout << endl;
}

int getEqmIndex(int arr[], int n){
    int sum = 0, left_sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    for(int i = 0; i < n; i++){
        sum -= arr[i];
        if (left_sum == sum) return i;
        left_sum += arr[i];
    }
    return -1;
}

int main(){
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int equilibriumIndex = getEqmIndex(arr, n);
    cout << "equilibrium Index " << equilibriumIndex << endl;
}