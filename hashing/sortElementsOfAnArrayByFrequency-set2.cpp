/* 
Sorting Elements of an Array by Frequency
            
Problems
Given an array A[] of integers, sort the array according to frequency of elements.
That is elements that have higher frequency come first.
If frequencies of two elements are same, then smaller number comes first.

Input Format:
The first line of input contains an integer T denoting the number of test cases.
The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output Format:
For each testcase, in a new line, print each sorted array in a seperate line.
For each array its numbers should be seperated by space.

Constraints:
1 ≤ T ≤ 70
30 ≤ N ≤ 130
1 ≤ Ai ≤ 60 

Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5

Explanation:
Testcase1: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are same then smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.

Testcase2: The highest frequency here is 3. The element 9 has the highest frequency. So 9 9 9 comes first. Now both 2 and 5 have same frequency. So we print smaller element first.
The output is 9 9 9 2 5.
 */

// Driver code for below program
#include <bits/stdc++.h>
using namespace std;
int a[1000000];
void sortByFreq(int arr[],int n);
int main() {
	int t;
	cin >> t;

	while(t--){
	    int n;
	    cin >> n;
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    
	    sortByFreq(a,n);
	    cout << endl;
	}
	return 0;
}

bool sortByVal(const pair<int, int> &a, const pair<int, int> &b) {
  // if frequency is same, smaller number comes first
    if (a.second == b.second) return a.first < b.first;
    
    // number with greater frequency comes first
    return a.second > b.second;
}

/* Approach: The idea is to use hashing
1. We insert all the elements and their counts into a hash.
This step takes O(n) time where n is the no of elements.
2. We copy contents to a hash to an array (or vector) and sort them by count.
This step take O(mlogm) time, where m is the no of distinct elements.
 */
void sortByFreq(int arr[],int n)
{
    /* now the new thing to learn is
    is use to think how to keep track of two things which are related and need to put in array/vector
    the solution key here is to make pair and make a vector of it */

    // initialise a unordered_map for hashing
    unordered_map <int, int> m;
    vector<pair<int, int> > v;

    // traverse the input array and hash the elements and their count
    for(int i = 0; i < n; i++)
        m[arr[i]]++;
    
    /* copy the contents of hash, in vector v using back_inserter
    back_inserter is different than push_back as it gives/returns iterator from last of the container
    you want to push into 
    For back_iterator visit: https://www.geeksforgeeks.org/stdback_inserter-in-cpp/*/
    copy(m.begin(), m.end(), back_inserter(v));
    
    // sort the vector by using custom comparator
    sort(v.begin(), v.end(), sortByVal);
    
    // print the output
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].second; j++)
            cout << v[i].first << " ";
    
    m.clear();
}

// Time Complexity: O(nlogn), worst case when all elements occur once
// Comapany Tags: Oracle, Zycus