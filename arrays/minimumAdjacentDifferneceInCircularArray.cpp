#include <iostream>
using namespace std;

// Function to find minimum adjacent difference

int minAdjDiff(int arr[], int n){    
    int currMinAdjDiff;
    currMinAdjDiff = abs(arr[n-1]-arr[0]);
    for(int i = 0; i < n-1; i++){
            currMinAdjDiff = min(abs(arr[i+1]-arr[i]), currMinAdjDiff);
    }
    return currMinAdjDiff;
}

// Driver code
int main()
{
    int t;
    cin>>t; //Input testcases
    
    while(t--) //While testcases exist
    {
        int n;
        cin>>n; //Input size of array
        
        int arr[n]; //Array of size n
        
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i]; //input elements of array
        }
        
        cout << minAdjDiff(arr, n) << endl;
    }
    return 0;
}