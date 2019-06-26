//Initial Template for C++
#include <iostream>
using namespace std;

void arrayReversal(int arr[],int sizeOfArray);

int main() 
{
	int testcases;
	cin>>testcases; //testcases
	while(testcases--)
	{
	    int sizeOfArray; //size of the array
	    cin>>sizeOfArray;
	    int arr[sizeOfArray]; //array is declared with size as sizeOfArray
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i]; //inputting the elements of the array
	    
	    arrayReversal(arr,sizeOfArray); //calling the reversal function
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cout<<arr[i]<<" "; //printing the array
	    
	    cout<<endl;
	}
	return 0;
}

//User function Template for C++
// This function should reverse contents of
// arr[0..sizeOfArray-1]
void arrayReversal(int arr[],int sizeOfArray) 
{
   //Write your code here
   int i = 0, j = sizeOfArray -1;
   while(i < j) {
       swap(arr[i++], arr[j--]);
   }
}