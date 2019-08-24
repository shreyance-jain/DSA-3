// pair with given sum in sorted array
// two pointer approach

#include<bits/stdc++.h>

using namespace std;

bool isPairWithGivenSum(int arr[], int n, int x) {
    int start = 0;
    int end = n-1;
    while (start < end) {
        if (arr[start] + arr[end] == x)
            return true;
        else if (arr[start] + arr[end] < x)
            start++;
        else 
            end--;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        if (isPairWithGivenSum(arr, n, x))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;   
    }
}