/* 
Stock span problem

Problem Statement

The stock span problem is a financial problem where we have a series of n daily price quotes
for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of
consecutive days just before the given day, for which the price of the stock on the
current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85},
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, N is the size of the array.
The second line of each test case contains N input C[i].

Output:
For each testcase, print the span values for all days.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 200
1 ≤ C[i] ≤ 800

Example:
Input:
2
7
100 80 60 70 60 75 85
6
10 4 5 90 120 80

Output:
1 1 1 2 1 4 6
1 1 2 4 5 1
 */


#include<bits/stdc++.h>
using namespace std;

void calculateSpan(int price[], int n, int S[]);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n],s[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		calculateSpan(a, n, s);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

/* Add comments */
void calculateSpan(int price[], int n, int S[])
{
    // we need to keep track of position wise closest (because contiguous)
    // greater element on left of it
    // we push the index in stack which will able us to calculate diff in days
   stack<int> st;
   st.push(0); // index of array
   // cout << 1
   S[0] = 1;
   for(int i = 1; i < n; i++) {
       while(!st.empty() && price[i] >= price[st.top()])
            st.pop();
        int span = (st.empty() ? i + 1: i - st.top());
        S[i] = span;
        st.push(i);
   }
}

// Company tags: Accolite, Samsung