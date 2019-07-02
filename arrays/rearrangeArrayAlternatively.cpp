/*
Given a sorted array of positive integers. 
Your task is to rearrange  the array elements alternatively 
i.e first element should be max value, second should be min value, 
third should be second max, fourth should be second min and so on.

Note: O(1) extra space is allowed. 
Also, try to modify the input array as required. */

// NAIVE SOLUTION

// C++ program to rearrange an array in minimum 
// maximum form 
#include <iostream>
using namespace std;

void putIndex(int *arr, int index, int n){
    int temp = arr[n-1];
    for(int i = n-2; i >=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = temp;
}
void rearrange(int *arr, int n) 
{ 
    // 1 2 3 4 5 6
    // 6 1 2 3 4 5 in pair
    // 6 1 5 2 3 4
    // 6 1 5 2 4 3
    int count = n/2;
    int i = 0;
    while(count--){
        putIndex(arr, i, n);
        i = i+2;
    }
}

// Driver program to test above function 
int main() 
{
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        rearrange(arr, n);
        
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
}