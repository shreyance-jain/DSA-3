/* 
Linear Probing in Hashing

Problem Statement

Linear probing is a collision handling technique in hashing.
Linear probing says that whenever a collision occurs, search for the immediate next position.

In this question, we'll learn how to fill up the hash table using linear probing technique.
You are given hash table size which you'll use to insert elements into their correct position in the hash table.
You are also given an array arr of size n.
You need to fill up the hash table using linear probing and print the resultant hash table.
Note: All the positions that are unoccupied are denoted by -1 in the hash table.
If there is no more space to insert, then just drop that element.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains 3 lines of input. The first line contains size of the hashtable.
The second line contains size of the array. The third line contains elements of the array.

Output Format:
For each testcase, in a new line, print the hash table.

Your Task:
This is a function problem. You only need to complete this function linearProbing that takes parameters
hash, hashSize, arr, sizeOfArray and inserts elements of arr in hash that is of size sizeOfArray.
The driver code automatically prints the output.

Constraints:
1 <= T <= 100
1 <= hashSize <= 100
1 <= sizeOfArray <= 100

Examples:
Input:
2
10
4
4 14  24 44
10
4
9 99 999 9999
Output:
-1 -1 -1 -1 4 14 24 44 -1 -1
99 999 9999 -1 -1 -1 -1 -1 -1 9

Explanation:
Testcase1: 4%10=4. So put 4 in hashtable[4]. Now, 14%10=4, but hashtable[4] is already filled so put 14 in the next slot and so on.
Testcase2: 9%10=9. So put 9 in hashtable[9]. Now, 99%10=9, but hashtable[9] is already filled so put 99 in the (99+1)%10 =0 slot so 99 goes into hashtable[0] and so on.
 */

#include <bits/stdc++.h>

using namespace std;

void linearProbing(int hash[],int hashSize,int arr[],int sizeOfArray);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    int hash[hashSize];
	    
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    
	    
	    for(int i=0;i<hashSize;i++)
	    hash[i]=-1;
	    
	    linearProbing( hash, hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}

void linearProbing(int hash[],int hashSize,int arr[],int sizeOfArray)
{   
    // initialize the hash[] with -1
    int i, j;
    memset(hash, -1, hashSize);

    for(j = 0; j < sizeOfArray; j++) {
        // if the hash[index afther hashing of key using hash function] is -1, we can insert
        if (hash[arr[j] % hashSize] == -1) {
            hash[arr[j] % hashSize] = arr[j];
        } else {
            // we need to find the next -1 and insert the element in that position
            // if can't find such a position the we need to drop this element
            int count = 1;
            // condition for count to be less than hashSize if because we are doing modulus using hashSize, once
            // count will become greater than hashSize then its modulus will give us repeated values
            while( hash[(arr[j] + count ) % hashSize] != -1 && count < hashSize)
                count++;
            if (count != hashSize) {
                hash[(arr[j] + count) % hashSize] = arr[j];
            }
            // nothing in else part as there is no empty space, we do nothing and element is dropped
        }
    }
}

/* 
The main problem with linear probing is clustering,
many consecutive elements form groups and
it starts taking time to find a free slot or to search an element.
 */