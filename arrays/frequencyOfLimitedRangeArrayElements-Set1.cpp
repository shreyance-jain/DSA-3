#include<iostream> 
using namespace std;

// Function to count frequencies of elements in the array

void printfrequency(int arr[], int n)
{ 
     // Traverse all array elements 
	int i = 0;
	while(i < n) {

        // If this element is already processed, 
        // then nothing to do 
	    if (arr[i] < 0) {
	        i++;
	        continue;
	    }

        // Find index corresponding to this element 
        // For example, index for 5 is 4 
	    int elementIndex = arr[i]-1;

        // If the elementIndex has an element that is not 
        // processed yet, then first store that element 
        // to arr[i] so that we don't loose anything. 
	    if (arr[elementIndex] > 0) {
	        arr[i] = arr[elementIndex];
            // After storing arr[elementIndex], change it 
            // to store initial count of 'arr[i]'
	        arr[elementIndex] = -1;
	    } else {
            // If this is NOT first occurrence of arr[i], 
            // then decrement its count.
	        arr[elementIndex]--;
            // And initialize arr[i] as 0 means the element 
            // 'i+1' is not seen so far 
	        arr[i] = 0;
	        i++;
	    }
	}
	for(int j = 0; j < n; j++){
	    if (arr[j] < 0) arr[j] = -arr[j];
	    cout << arr[j] << " ";
	}
	
}

int main() 
{ 
	long long t;
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n; // taking input size of array
	    
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; // input elements of array
	    }
	    
	    printfrequency(arr,n); // print frequency of elements 
	    cout << endl;
	}
	
	return 0; 
}

// company tags: Paytm, VMWare, Zoho