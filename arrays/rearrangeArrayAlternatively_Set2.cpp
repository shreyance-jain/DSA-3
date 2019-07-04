// C++ program to rearrange an array in minimum 
// maximum form 
#include <iostream>
using namespace std;

// OPTIMIZED SOLUTION

void rearrange(int *arr, int n) 
{ 
    int max_idx = n-1, min_idx = 0;
    int max_element = arr[max_idx] + 1;
    for(int i = 0; i < n; i++){
        if (i%2 == 0){
            arr[i] += (arr[max_idx] % max_element) * max_element;
            max_idx--;
        } else {
            arr[i] += (arr[min_idx] % max_element) * max_element;
            min_idx++;
        }
    }
    for(int i = 0; i< n; i++){
        arr[i] = arr[i] / max_element;
    }
}

/**
 * How does expression 
 * “arr[i] += arr[max_index] % max_element * max_element” work ?
 * The approach is in the end all the even positions is taken by the max_elements
 * and odd postions by min_elements
 * The purpose of this expression is to store two elements at index arr[i]. 
 * arr[max_index](in case of even positions) or arr[mix_index](in case of odd positons) 
 * is stored as multiplier and “arr[i]” is stored as remainder. 
 * For example in {1 2 3 4 5 6 7 8 9}, max_element is 10 and we store 91 at index 0. 
 * With 91, we can get original element as 91%10 and new element as 91/10.
 */

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
// Time Complexity: O(n)
// Space Complexity : O(1)