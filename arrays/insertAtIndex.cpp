#include <iostream>
using namespace std;

void insertAtIndex(int arr[],int sizeOfArray,int index,int element);

int main() {
    int t;
    cin>>t;//Input testcases
    while(t--)
    {
        int sizeOfArray; 
        cin>>sizeOfArray;
        
        int arr[sizeOfArray];
        for(int i=0;i<sizeOfArray-1;i++)
        cin>>arr[i];
        
        int index;
        cin>>index;
        int element;
        cin>>element;
        
        insertAtIndex(arr,sizeOfArray,index,element);
        
        for(int i=0;i<sizeOfArray;i++)
        cout<<arr[i]<<" ";
        
        cout<<endl;
        
    }
    
	return 0;
}

/**You need to insert the given element at the given index. 
 * You may assume that the array already has sizeOfArray - 1
 * elements. */
void insertAtIndex(int arr[], int sizeOfArray, int index, int element)
{
    for(int i = sizeOfArray-2; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
}