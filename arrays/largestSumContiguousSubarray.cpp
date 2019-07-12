#include<iostream>
#include<climits>
using namespace std;


// Function to find subarray with maximum sum
int maxSubarraySum(int arr[], int n){
    
    int max_so_far = INT_MIN; int max_ending_here = 0;
    int start = 0, end = 0, s = 0;
    for(int i = 0; i < n; i++){
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here){
            max_so_far = max_ending_here;
            end = i;
            start = s;
        }
        if (max_ending_here < 0){
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Starting index: " << start << endl;
    cout << "Ending index: " << end << endl;
    return max_so_far;
    
}

// Time Complexity : O(n)
// Algorithmic paradigm : Dynamic Programming

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}