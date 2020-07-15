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

// EXECUTION TIME IN GFGS IDE IS COMING approx 4.20 sec
// Passing the current by reference reduces it to 0.40 sec
void combinationSumUtil(vector<int> &A, int sum, vector<vector<int>> &result, vector<int> &current, int pos) {
    // push the combination if sum becomes 0
    // !IMP Avoids sum calulation of current in every recursive calls
    if (sum == 0) {
        result.push_back(current);
        return;
    }
    // return if conditions out of bound
    // NOTE: We can wrap the below recursive calls in this logic
    // and make it look like standard backtracking solution (see function below)
    if (sum < 0 || pos >= A.size()) 
        return;
    
    // push to current possible answer
    current.push_back(A[pos]);
    // recurse for futher inclusions
    combinationSumUtil(A, sum - A[pos], result, current, pos);
    // backtrack, to remove already present number in combinations
    // provide space for futher additions and possible answers
    current.pop_back();
    // iterate to next index as all possible combination for current index has been done
    combinationSumUtil(A, sum, result, current, pos+1);
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int> > result;
    vector<int> current, C;
    int i, j;

    // storing only distinct elements in vector C
    for(int i = 0; i < A.size(); i++) {
        j = i+1;
        while(j < A.size() && A[i] == A[j]) {
            j++;
        }
        C.push_back(A[i]);
        i = j-1;
    }

    // calling main recursive function
    combinationSumUtil(C, B, result, current, 0);
    return result;
}

// Company Tags: Adobe, Amazon, Microsoft


// YET ANOTHER STYLE
// same as my code with sum calculation optimisation
void findNumbers(vector<int>& ar, int sum, 
                 vector<vector<int> >& res, 
                 vector<int>& r, int i) 
{ 
    // If  current sum becomes negative 
    if (sum < 0) 
        return; 
  
    // if we get exact answer 
    if (sum == 0) 
    { 
        res.push_back(r); 
        return; 
    }
  
    // Recur for all remaining elements that 
    // have value smaller than sum. 
    while (i < ar.size() && sum - ar[i] >= 0) 
    { 
  
        // Till every element in the array starting 
        // from i which can contribute to the sum 
        r.push_back(ar[i]); // add them to list 
  
        // recur for next numbers 
        findNumbers(ar, sum - ar[i], res, r, i); 
        i++; 
  
        // remove number from list (backtracking) 
        r.pop_back(); 
    } 
} 