/* 
Fractional Knapsack

Difficulty: Easy   

Problems

Given weights and values of N items, we need to put these items in a knapsack
of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to bread the item.

Input:
First line consists of an integer T denoting the number of test cases.
First line consists of two integers N and W, denoting number of items and weight respectively.
Second line of every test case consists of 2*N spaced integers denoting Values and weight respectively.

Output:
Print the maximum weight possible to put items in a knapsack, with decimal place of 2.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= W <= 100

Example:
Input:
2
3 50
60 10 100 20 120 30
2 50
60 10 100 20

Output:
240.00
160.00

Explanation:
Testcase 1: Total maximum value of item we can have is 240.00 from the given capacity of sack.
 
 */


#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};
double fractionalKnapsack(int W, Item arr[], int n);

int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}

/* 
The basic idea of the greedy approach is to calculate the ratio value/weight for each item
and sort the item on the basis of this ratio. Then take the item with the highest ratio and
add them until we can't add the next item as whole and the end add the next item as much as
we can. Which will always be optimal soltution to this problem
 */

// comparator function to sort the weight in decreasing order of
// value/weight ratio
struct cmp {
    bool operator()(Item &i1, Item &i2) {
        return (double(i1.value)/double(i1.weight)) > (double(i2.value)/double(i2.weight));
    }
};


// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    // sort the items in decreasing order of value/weight ratio
    sort(arr, arr+n, cmp());
    
    double res = 0;
    for(int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {
            res += arr[i].value;
            W -= arr[i].weight;
        } else {
            res += (arr[i].value)*(double(W)/double(arr[i].weight));
            return res;
        }
    }
    return res;
} // PRO CODE can be a better using variable names and taking the complex values in a variable and
// then do the calculation

/* PRO CODE
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    int curWeight = 0;
    double finalvalue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
 */
