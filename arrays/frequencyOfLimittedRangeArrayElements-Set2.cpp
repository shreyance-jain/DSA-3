#include<iostream> 
using namespace std; 


// Function to count frequencies of elements in the array
void printfrequency(int arr[], int n)
{ 
	for(int i = 0; i < n; i++)
	    arr[i] -= 1;
	for(int i = 0; i< n; i++){
	    arr[arr[i]%n] += n;
	}
	for(int i = 0; i < n; i++){
	    arr[i] /= n;
	}
	for(int i = 0; i < n; i++){
	    cout << arr[i] << " ";
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