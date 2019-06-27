// CPP code to find largest and 
// second largest element in the array
#include <iostream>
#include <climits>
using namespace std;
void largestAndSecondLargest(int, int[]);
//Position this line where user code will be pasted.
// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    largestAndSecondLargest(sizeOfArray, arr);
	}
	
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
     
/* Function to find largest and second largest element
*sizeOfArray : number of elements in the array
* arr = input array
*/
void largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT_MIN, max2= INT_MIN;
    max = arr[0];
    max2 = -1;
    for(int i = 1; i < sizeOfArray; i++){
        if(arr[i] > max) {
            max2 = max;
            max = arr[i];
        }
        if (arr[i] != max && arr[i] > max2) {
            max2 = arr[i];
        }
    }
     
     cout << max << " " << max2 << endl;
}