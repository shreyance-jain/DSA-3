/* 
Maximum Rectangular Area in a Histogram

Problem Statement

Find the largest rectangular area possible in a given histogram where the largest
rectangle can be made of a number of contiguous bars. For simplicity,
assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases.
T test-cases follow. In each test cases,
the first line contains an integer 'N' denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN
denoting the elements of the array.
The elements of the array represents the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 1018

Example:
Input: 
2
7
6 2 5 4 5 1 6
8
7 2 8 9 1 3 6 5

Output:
12
16

Explanation:
Testcase1: Max Area = 3 * 4 = 12
 */


#include <bits/stdc++.h>
using namespace std;

long getMaxArea(long long[], int);

/* Driver code */
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

/* 
Approach:
- For every bar 'x', calculate the area with 'x' as the smallest bar in the rectangle
- To calculate area with 'x' as smallest bar, find index of the first smaller(smaller than 'x')
bar on left of 'x' and index of first smaller bar on the right of 'x'. Assume these indexes as
'left_index' and 'right_index' respectively.
- Traverse the bar from left to right, maintain a stack of bars. Every bar is pushed in stack once.
- POP a bar from stack when a bar of smaller height is seen
- When bar is popped, calculate the area with popped bar as the smallest bar.
- Get the right and left indexes of the popped bar - the current index tells us the 'right_index'
and the index of previous item in stack is the 'left index'

Algorithm:
1. Create an empty stack
2. Start from the first bar, and do the following for every bar 'arr[i]' where 'i' varies from 0 to n-1
    a) If stack is empty or arr[i] is higher than the bar at top of stack, the push 'i' to stack
    b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of stack is greater
       Let the removed bar be arr[tp]. Calculate area of rectangle with arr[tp] as smallest bar. For arr[tp],
       the 'left_index' is previous(previous to tp) item in stack and 'right_index' is i.
3. If the stack is not empty, then one by one remove all bars from stack and do step2.b for every removed bar
 */
long getMaxArea(long long arr[], int n){
    stack<int> st;
    long long max_area = 0;
    int i = 0;
    while(i < n) {
        if (st.empty() || arr[st.top()] <= arr[i]) {
            st.push(i++);
        } else {
            // i will give us the right index
            // left index will be the element in stack just below the current element
            // beacuse we are pushing in stack when an element is greater than previous element
            // so the previous element in stack will serve the left index for the current top
            // of stack
            // we will pop the top element
            // calculate the max area assming this popped element as smallest bar
            long long tp = arr[st.top()];
            st.pop();
            // now after we have popped the current element
            // st.top() will serve as left index
            long long current_area = tp * (st.empty() ? i : i - st.top() - 1);
            if (current_area > max_area)
                max_area = current_area;
        }
    }
    while(!st.empty()) {
        long long tp = arr[st.top()];
            st.pop();
            // now after we have popped the current element
            // st.top() will serve as left index
            long long current_area = tp * (st.empty() ? i : i - st.top() - 1);
            if (current_area > max_area)
                max_area = current_area;
    }
    return max_area;
}

// Time Complexity: O(n)