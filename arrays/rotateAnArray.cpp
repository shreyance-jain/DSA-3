#include <iostream>
using namespace std;

void reverseArray(int arr[], int l, int r);
void rotateArr(int arr[], int d, int n);

int main() {
	//code
	
	int t;
	cin >> t;
	
	while(t--){
	    int n, d;
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    rotateArr(arr, d,n);
	    
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	    
	}
	
	return 0;
}

// This function rotate array by D elements
// arr: input elements
// n: size of the array

void reverseArray(int arr[], int l, int r){
    while(l < r) {
        swap(arr[l++], arr[r--]);
    }
}

void rotateArr(int arr[], int d, int n){
    
   reverseArray(arr, 0, d-1);
   reverseArray(arr, d, n-1);
   reverseArray(arr, 0, n-1);
    
}