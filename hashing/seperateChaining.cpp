/* 
Separate chaining in Hashing

Problem Statement

Separate chaining technique in hashing allows to us to use a linked list at each hash slot to handle
the problem of collisions.
That is, every slot of the hash table is a linked list,
so whenever a collision occurs, the element can be appened as a node to the linked list at the slot.

In this question, we'll learn how to fill up the hash table using Separate chaining technique.
You are given hash table size which you'll use to insert elements into their correct position in the hash table.
You are also given an array arr. The size of the array is denoted by sizeOfArray.
You need to fill up the hash table using Separate chaining and print the resultant hash table.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains 3 lines of input. The first line contains size of the hashtable.
The second line contains size of the array. The third line contains elements of the array.

Output Format:
For each testcase, in a new line, print the hash table.

Your Task:
This is a function problem. You need to complete the function separateChaining that takes hashTable,
hashSize, arr, and sizeOfArr as parameters and inserts elements of arr in the hashTable at positions by
using arr[i]%hashSize. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
2 <= hashSize <= 103
1 <= sizeOfArray <= 103
0 <= arri <= 107

Examples:
Input:
1
10
6
92 4 14 24 44 91
Output:
1->91
2->92
4->4->14->24->44

Explanation:
Testcase1: 92%10=2 so 92 goes to slot 2. 4%10=4 so 4 goes to slot 4. 14%10=4. But 4 is already occupied so we make a linked list at this position and add 14 after 4 in slot 4 and so on.
 */

#include <bits/stdc++.h>
using namespace std;

void separateChaining(vector<vector<int>> &hashTable,int hashSize,int arr[],int sizeOfArray);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    vector<vector<int>> hashTable(hashSize);
	    
	    
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    
	    
	    separateChaining( hashTable, hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashTable.size();i++)
	    {
	        if(hashTable[i].size()>0)
	        {
	            cout<<i<<"->";
	            for(int j=0;j<hashTable[i].size()-1;j++)
	            {
	                cout<<hashTable[i][j]<<"->";
	            }
	            cout<<hashTable[i][hashTable[i].size()-1];
	            cout<<endl;
	        }
	    }
	    
	    
	    
	}
	return 0;
}

void separateChaining(vector<vector<int>> &hashTable,int hashSize,int arr[],int sizeOfArray)
{
   for(int i = 0; i < sizeOfArray; i++)
    hashTable[arr[i] % hashSize].push_back(arr[i]);
}