/* 
Next larger element

Problem Statement

Given an array A[] of size N having distinct elements,
the task is to find the next greater element for each element of the array in order
of their appearance in the array. If no such element exists, output -1.

Input Format:
The first line of input contains a single integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines.
The first line contains an integer N denoting the size of the array.
The Second line of each test case contains N space separated positive integers
denoting the values/elements in the array A.

Output Format:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
5
6 8 0 1 3

Output
3 4 4 -1
8 -1 1 3 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.
 */


#include<bits/stdc++.h>
using namespace std;

void nextLargerElement(long long arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        nextLargerElement(arr, n);
        
        cout<<endl;
    }
	return 0;
}

/* Comments */
/* Naive Approach */
/* Time Complexity */
void nextLargerElement(long long arr[], int n){
    // same problems as PreviousGreaterElement as uses logic as stock span problem
    // here we traverse the array from right to left
    
    // we will use an extra stack or vector to print the ouput in correct order
    // i will use vector to keep code readable
    
    vector<long long> out;
    stack<long long> st;
    
    st.push(arr[n-1]);
    out.push_back(-1);
    
    for(long long i = n-2; i >= 0; i--) {
        while(!st.empty() && arr[i] > st.top())
            st.pop();
        long long nextGrtr = (st.empty() ?  -1 : st.top());
        out.push_back(nextGrtr);
        st.push(arr[i]);
    }
    reverse(out.begin(), out.end());
    for(long long i = 0; i < n; i++)
        cout << out[i] << " ";
}

// Company Tags: Flipkart