#include <iostream>

using namespace std;

int trapRainWater(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[] = {2, 1, 3, 4, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int trappedUnitsOfWater = trapRainWater(arr, n);
    cout << trappedUnitsOfWater << endl;
}

int trapRainWater(int arr[], int n){
    int  l_max =0,  r_max = 0;
    int trappedUnitsWater = 0;
    int lo = 0, hi = n-1;
    while(lo < hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > l_max) {
                l_max = arr[lo];
            } else {
                trappedUnitsWater += l_max - arr[lo];
                lo++;
            }
        } else {
            if (arr[hi] > r_max) {
                r_max = arr[hi];
            } else {
                trappedUnitsWater += r_max - arr[hi];
                hi--;
            }
        }
    }
    return trappedUnitsWater;
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}