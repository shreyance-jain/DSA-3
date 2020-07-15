/* 

Combination Sum

Difficulty: Medium

Problem Statement

Given an array of integers and a sum B, 
find all unique combinations in the array where 
the sum is equal to B. 
The same number may be chosen from the array any number of times to make B.

Note:
1. All numbers will be positive integers.
2. Elements in a combination (a1, a2, …, ak) 
   must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
3. The combinations themselves must be sorted in ascending order.

Input:
The first line of input contains the number of test cases T. 
For each test case, there will be three lines of input, 
first of which contains N, size of the array. 
Next line contains N space-separated integers, and 
the last line contains B.

Output:
For each testcase, print the sets enclosing a bracket "(" and ")".
No space between the two sets. If no set can be formed with the given set,
then print "Empty" (without quotes).

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function combinationSum() 
which takes the array A and a sum B as inputs and returns 
a list of arrays denoting the required combinations in the 
order specified in the problem description.

Constraints:
1 <= T <= 100
1 <= N <= 30
1 <= A[i] <= 20
1 <= B <= 100

Example:
Input:
3
4
7 2 6 5
16
11
6 5 7 1 8 2 9 9 7 7 9
6
4
2 4 6 8
8

Output:
(2 2 2 2 2 2 2 2)(2 2 2 2 2 6)(2 2 2 5 5)(2 2 5 7)(2 2 6 6)(2 7 7)(5 5 6)
(1 1 1 1 1 1)(1 1 1 1 2)(1 1 2 2)(1 5)(2 2 2)(6)
(2, 2, 2, 2)(2, 2, 4)(2, 6)(4, 4)(8)

Explanation:
Testcase 3: Required sets with sum equal to B (8) are as follows:
[2, 2, 2, 2]
[2, 2, 4]
[2, 6]
[4, 4]
[8]
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > combinationSum(vector<int> &A, int B);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        vector<vector<int> > result;
   		result=combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}

// sum vector passed as reference to avoid copy overhead
bool isSum(vector<int> &sum, int B) {
    int total = 0;
    for(int i = 0; i < sum.size(); i++)
        total += sum[i];
    return total == B;
}

// sum vector passed as reference to avoid copy overhead
bool isSafe(vector<int> &sum, int B, int item) {
    int total = 0;
    for(int i = 0; i < sum.size(); i++)
        total += sum[i];
    total += item;
    return total <= B;
}

// ! NOTE: We can pass sum vector (which represents individual sum array in res) as reference
// as we will be using one array at a time in recursion to store results
// it also eliminates copy overhead and reduces execution time
void combinationSumUtil(vector<int> &A, vector<vector<int>> &res, int B, vector<int> &sum, int index) {
    // if sum push to result and return as no more elements can be included in this sum now
    if (isSum(sum, B)) {
        res.push_back(sum);
        return;
    }
    // try for every element
    for(int i = index; i < A.size(); i++) {
        // if sum is less than required sum
        if (isSafe(sum, B, A[i])) {
            sum.push_back(A[i]);
            // NOTE: index is not incremented in recursive calls as we want to include
            // same element more than once as mentioned/required in problem statement
            combinationSumUtil(A, res, B, sum, i);
            sum.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    // sorting for increasing results
    sort(A.begin(), A.end());
    // removing duplicates
    A.erase(unique(A.begin(), A.end()), A.end());
    // individual sum vector to store elements in current recursion
    vector<int> sum;
    combinationSumUtil(A, res, B, sum, 0);
    return res;
}

// Company Tags: Adobe, Amazon, Microsoft
