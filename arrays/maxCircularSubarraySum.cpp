#include<iostream>
#include<climits>
using namespace std;


int kadane(int arr[], int n){
    int max_so_far = INT_MIN, max_so_far_here = 0;
    for(int i = 0; i < n; i++){
        max_so_far_here += arr[i];
        if(max_so_far < max_so_far_here) {
            max_so_far = max_so_far_here;
        }
        if (max_so_far_here < 0){
            max_so_far_here = 0;
        }
    }
    return max_so_far;
}

int reverseKadane(int arr[], int n){
    int arrSum = 0, max_so_far = INT_MIN, max_so_far_here = 0;
    for(int i = 0; i < n; i++){
        arrSum += arr[i];
        arr[i] *= -1;
        max_so_far_here += arr[i];
        if (max_so_far < max_so_far_here) {
            max_so_far = max_so_far_here;
        }
        if (max_so_far_here < 0) {
            max_so_far_here = 0;
        }
    }
    // max sum with corner elements will be:  
    // array_sum - (-max subarray sum of inverted array)
    return arrSum+max_so_far;
}

// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array

/*There can be two cases for the maximum sum:

Case 1: The elements that contribute to the maximum sum are arranged such
that no wrapping is there. Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. 
In this case, Kadane’s algorithm will produce the result.

Case 2: The elements which contribute to the maximum sum are arranged such 
that wrapping is there. Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. 
In this case, we change wrapping to non-wrapping. Let us see how. 
Wrapping of contributing elements implies non wrapping of non contributing 
elements, so find out the sum of non contributing elements and subtract 
this sum from the total sum. To find out the sum of non contributing, 
invert sign of each element and then run Kadane’s algorithm.
Our array is like a ring */
int circularSubarraySum(int arr[], int num){
    int k = kadane(arr, num);
    int rk = reverseKadane(arr, num);
    return max(k, rk);
}

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	    
	    
	    cout << circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}