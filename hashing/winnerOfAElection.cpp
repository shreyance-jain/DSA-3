/* 
Winner of an election

Problem Statement

Given an array of names (consisting of lowercase characters) of candidates in an election.
A candidate name in array represents a vote casted to the candidate.
Print the name of candidate that received Max votes.
If there is tie, print lexicographically smaller name.

Input Format:
The first line of the input contains a single integer T, denoting the number of test cases.
Then T test case follows. Each testcase contains two lines:-
The number of votes cast N
The name of the candidates separated by a space. Each name represents one vote casted to that candidate.

Output Format:
For each testcase, print the name of the candidate with the maximum votes,
and also print the votes casted for the candidate. The name and votes are separated by a space.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
3
andy blake clark

Output:
john 4
andy 1

Explanation:
Testcase1: john has 4 votes casted for him, but so does johny. john is lexicographically smaller, so we print john and the votes he received.
Testcase2: All the candidates get 1 votes each. We print andy as it is lexicographically smaller.
 */

// #include <iostream>
// #include <map>
// #include <algorithm>
// #include <cstdlib>
#include<bits/stdc++.h>
using namespace std;

void winner(string arr[],int n);

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        
        winner(arr,n);
        
        cout<<endl;
        
        
    }
    return 0;
}
/* 
Efficient solution is to use hashing. Insert all the votes in a hash map
and keep track of counts of different names.
Traverse the map and print the person with maximum votes
 */
void winner(string arr[],int n)
{   
    // map to store name and count for each name
    unordered_map <string, int> m;

    // storing frequency of each name
    for(int i = 0; i < n; i++) {
        m[arr[i]]++;
    }
    
    int maxx = -1;
    string answer = "";

    // iterating over map to find name with highest frequency
    for(auto it = m.begin(); it != m.end(); it++) {
        if (it->second > maxx) {
            maxx= it->second;
            answer = it->first;
        }
        // if count of two names are equal, select lexicographically smaller name.
        if (it->second == maxx && answer.compare(it->first) > 0) {
            answer = it->first;
        }
    }
    cout << answer << " " << maxx;
}

// Company Tags: Adobe