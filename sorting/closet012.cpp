/*
Closet 0s 1s and 2s

Problem Statement

Given an array A of size N containing 0s, 1s, and 2s. The task is:
to segregate the 0s , 1s and 2s in the array
as all the 0s should appear in the first part of the array, 1s should appear in middle part of the array and
finally all the 2s in the remaining part of the array.

Note: Do not use inbuilt sort function.

Input Format:
The first line contains an integer 'T' denoting the total number of test cases. 
Then T testcases follow. Each testcases contains two lines of input.
The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output Format: 
For each testcase, in a newline, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
*/

#include<bits/stdc++.h>
using namespace std;

void segragate012(int A[], int N);

int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }
        segragate012(A, N);
        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }
        cout << endl;
    }
}

// Function to segregate 0s, 1s and 2s
// A[]: input array
// N: size of array
void segragate012(int A[], int N)
{
    /*
    we keep three pointers
    lo to keep the track on the left end of the array (which will contain 0s)
    mid to keep track of the current element of the array (it also denotes the middle
    part of the array which will contain 1s)
    hi to keep the track of the right end of the array (which will contains 2s)
    */
    int lo = 0;
    int mid = 0;
    int hi = N-1;
    

    while (mid <= hi) {
        switch(A[mid]) {
            // since the element is zero we need to keep it in the start of the array
            // so we swap it with the left pointer and increment left and mid pointer
            case 0:
                swap(A[lo], A[mid]);
                lo++;
                mid++;
                break;
            // now the current element is 1, we don't need to change its position
            // as mid section will be of 1s, we just increment the pointer in this case
            case 1:
                mid++;
                break;
            // now if the current element is 2, we need to swap it with the end pointer
            // and decrement the end pointer and incremnet the mid pointer
            case 2:
                swap(A[mid], A[hi]);
                hi--;
                break;
        }
    }
}

// Time Complexity: O(n), requires one traversal

// Company tags: Adobe, Amazon, Hike, MAQSoftware, Microsoft, MorganStanley, OlaCabs, OYORooms,
// Paytm, SAPLabs, Walmart, Yatra.com