#include<iostream>
using namespace std;
// missing number in the array

int segregate(int arr[], int n){
    int i, j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return j;
}

/* Find the smallest positive missing number  
in an array that contains all positive integers */
int missingPositiveNumber(int arr[], int size){
    int i;
    // Mark arr[i] as visited by making arr[arr[i] - 1] negative.  
    // Note that 1 is subtracted because index start  
    // from 0 and positive numbers start from 1 
    for(i = 0; i < size; i++){
        if(abs(arr[i])-1 < size && arr[abs(arr[i])-1] > 0)
            arr[abs(arr[i])-1] *= -1;
    }
    // Return the first index value at which is positive  
    for(i = 0; i < size; i++){
        if(arr[i] > 0)
         // 1 is added because indexes start from 0  
            return i+1;
    }
    return size+1;
}

/* Find the smallest positive missing  
number in an array that contains  
both positive and negative integers */
int missingNumber(int arr[], int n) { 
    // First separate positive and negative numbers 
    // segregate the negative numbers on the left part of the array
    int shift = segregate(arr, n);
    // findMissingPositive forpositive part 
    return missingPositiveNumber(arr+shift, n-shift);
} 

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0; 
}
// Company tags : Accolite, Amazon, Samsung, Snapdeal