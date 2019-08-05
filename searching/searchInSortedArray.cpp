#include <bits/stdc++.h> 
using namespace std;


// Function to find element in sorted array
// arr: input array
// n: size of array
// x: element to be searched

int binarySearch(int arr[], int lo, int hi, int x) {
    if (lo > hi) return -1;
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] < x) {
        return binarySearch(arr, mid + 1, hi, x);
    }
    return binarySearch(arr, lo, mid -1, x);
}

int searchInSorted(int arr[], int n, int x) 
{ 
   // Your code here
   int index = binarySearch(arr, 0, n-1, x);
   if(index != -1) return 1;
   return -1;
}

int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << searchInSorted(arr, n, k) << endl;
    }
	return 0; 
} 
