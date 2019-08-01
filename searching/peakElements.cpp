
#include<bits/stdc++.h>
using namespace std;

/* The function should return the index of any
   peak element present in the array */
// arr: input array
// n: size of array

int getPeak(int arr[], int lo, int hi, int n) {
    // check for corner elements
    // if (arr[lo] >= arr[lo+1]) return lo;
    // if (arr[hi] >= arr[hi - 1]) return hi;
    int  mid = lo + (hi - lo) / 2;
    //if (mid > lo && arr[mid - 1] <= arr[mid] && arr[mid] >= arr[mid + 1] && mid < hi)
    //    return mid;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n-1 || arr[mid + 1] <= arr[mid]))
        return mid;
    // if mid element is not a peak check if left is greater
    // if left is greater on peak must be in left half
    if (mid > lo && arr[mid - 1] > arr[mid]) {
        return getPeak(arr, lo, mid -1, n);
    } else {
        // if mid element is not peak and left element is not greater than mid
        // it implies right element must be greater than mid
        // and so peak must be on right half
        return getPeak(arr, mid + 1, hi, n);
    }
}

int peakElement(int arr[], int n)
{
   int peak = getPeak(arr, 0, n-1, n);
   return peak;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}
	return 0;
}