#include <iostream>
using namespace std;

// Company tags: Amazon, FactSet, GoldmanSachs, Paytm

// Function to convert given array to wave like array
// a1 >= a2 <= a3 >= a4 <= a5...

void convertToWave(int *arr, int n){
    
    // a1 >= a2 <= a3 >= a4 <= a5...
    for(int i = 0; i < n-1; i++){
        if(i%2 == 0){
            if(arr[i+1] > arr[i]){
                swap(arr[i], arr[i+1]);
            }
        } else {
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
    }
    /* can also be achieved by ensuring even positons are placed correctly
    for(int i = 0; i < n-1; i=i+2){
        if(i > 0 && arr[i] < arr[i-1])
            swap(arr[i], arr[i-1]);
        if(i < n-1 && arr[i] < arr[i+1])
            swap(arr[i], arr[i+1]);
    } */
    
}

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        int a[n]; //declare array of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        
        convertToWave(a, n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}