#include<iostream>
using namespace std;

/**
 *  Problem: Rearrange the given array so that arr[i] becomes arr[arr[i]]. 
 * This should be done with O(1) extra space.*/ 
    
// Function to rarrange the elements in O(1) extra space

/*The important thing is, after the increment operation
of first step, every element holds both old values and new values. 
Old value can be obtained by arr[i]%n and new value can be obtained
by arr[i]/n */
void arrange(long long arr[], int n) {
    int max = n;
    for(int i = 0; i < n; i++){
        arr[i] += (arr[arr[i]]%max)*max;
    }
    for(int i = 0; i < n; i++)
        arr[i] /= max;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        arrange(A, n);
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}