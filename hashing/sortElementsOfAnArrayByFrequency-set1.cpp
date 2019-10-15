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

#include <bits/stdc++.h>

using namespace std;

int a[1000000];

void sortByFreq(int arr[],int n);

// Driver code for above program
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

/* Approach: Naive Solution
The idea it to traverse the input array and store the count of every element in unordered_map
Then while there are elements is the map, iterate over the map and find the element with max frequecy
Also check if two elements have same frequency then the element which is smaller in number should comes first
As soon as we one itertaion of map is done print the max frequency element and remove it from the map
and this process continues */
void sortByFreq(int arr[],int n)
{
  // unordered map to keep count of all elements
    unordered_map <int, int> m;
    unordered_map <int, int>::iterator itr;
    // iterate over input array and store the count of every element in map
    for(int i = 0; i < n; i++)
        m[arr[i]]++;
 
    int t = m.size();
    // loop while there are elements in the map
    while(t--) {
      // find the maxx frequency
        int maxx = -1;
        int answer = -1;
        for(itr = m.begin(); itr != m.end(); ++itr) {
            if (itr->second > maxx) {
                maxx = itr->second;
                answer = itr->first;
            }
            // if two elements have same frequency then pick smaller one
            if (itr->second == maxx && itr->first < answer) {
                answer = itr->first;
            }
        }
        // remove the element with max frequency from map
        m.erase(answer);
        // print it its frequency times
        while(maxx--) {
            cout << answer << " ";
        }
        // loop continues
    }
}

// Time Complexity: O(n^2) in worst case, when all the elements have same frequency
// Company tags: Oracle, Zycus