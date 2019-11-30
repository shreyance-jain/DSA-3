/* 
Get min at pop

Problem Statement

Now, we'll try to solve a famous stack problem.

You are given an array A of size N.
You need to push the elements of the array into a stack and
then print minimum in the stack at each pop.

Input Format:
The first line of input contains T denoting the number of testcases.
T testcases follow. Each testcase contains two lines of input.
The first line of input contains size of array N.
The second line of array contains the elements of array separated by spaces.

Output Format:
For each testcase, in a new line, print the required output.

Constraints:
1 <= T <= 100
1 <= Ai <= 107

Examples:
Input:
2
5
1 2 3 4 5
7
1 6 43 1 2 0 5

Output:
1 1 1 1 1
0 0 1 1 1 1 1

Explanation:
Testcase 1: After pushing elements to the stack, the stack will be top --- > 5, 4, 3, 2, 1.
Now, start popping elements from stack:
popping 5: min in the stack is 1. popped 5
popping 4: min in the stack is 1. popped 4
popping 3: min in the stack is 1. popped 3
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1.
 */

#include <bits/stdc++.h>
using namespace std;

stack<int>_push(int arr[],int n);
void _getMinAtPop(stack<int>s);

//driver code
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    stack <int> mys = _push(arr,n);
	    _getMinAtPop(mys);
	    cout << endl;
	}
	return 0;
}

stack<int>_push(int arr[],int n)
{
   stack<int> st;
   // traverse the array and push in stack
   for(int i = 0; i < n; i++)
        st.push(arr[i]);
   return st;
}

/*
Algo:
Push the first element of the array in stack, then start comparing from second element
  if top element of stack is > arr[i] then,
    push(arr[i])
  else
    push(stack.top())
The stack will have minimum element for each removal.
 */
void _getMinAtPop(stack<int>s)
{
    vector<int> v;
    // while there is element in stack
    while(!s.empty()) {
        // push the top element into the vector
        v.push_back(s.top());
        // pop the elment from stack
        s.pop();
    }
    stack<int> minStack;
    // pushing last element as min element
    s.push(v.back());
    minStack.push(v.back());

    // iterating vector from second last
    for(int i = v.size() - 2; i >= 0; i--) {
        s.push(v[i]);
        // compare the top element with minStack top
        // and then push the element if required
        if (minStack.top() > v[i])
            minStack.push(v[i]);
        else
            minStack.push(minStack.top());
    }
    // print the minimum at every pop
    while(!s.empty()) {
        cout << minStack.top() << " ";
        s.pop();
        minStack.pop();
    }
}