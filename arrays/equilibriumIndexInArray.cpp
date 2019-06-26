#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout  << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {};
    int n = sizeof(arr)/sizeof(arr[0]);
}