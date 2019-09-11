/* 

Quadratic Probing in Hashing

Problem Statement

Quadratic probing is a collision handling technique in hashing.
Quadratic probing says that whenever a collision occurs, search for i2 position.

In this question, we'll learn how to fill up the hash table using Quadratic probing technique.
You are given hash table size which you'll use to insert elements into their correct position in the hash table. You are also given an array arr[] of size N. You need to fill up the hash table using Quadratic probing and print the resultant hash table.

Note:

    All the positions that are unoccupied are denoted by -1 in the hash table.
    An empty slot can only be found if load factor < 0.5 and hash table size is a prime number.
    The given testcases satisfy the above condition so you can assume that an empty slot is always reachable.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains 3 lines of input. The first line contains size of the hashtable.
The second line contains size of the array. The third line contains elements of the array.

Output Format:
For each testcase, in a new line, print the hash table.

Your Task:
This is a function problem. You only need to complete the function QuadraticProbing that takes
hash, hashSize, arr, and sizeOfArray as parameters and inserts elements of arr in hash.
The printing is done by the driver code.

Constraints:
1 <= T <= 100
2 <= hashSize (prime) <= 97
1 <= sizeOfArray < hashSize*0.5

Examples:
Input:
1
11
4
21 10 32 43
Output:
10 -1 -1 32 -1 -1 -1 -1 43 -1 21

Explanation:
Testcase1: 21%11=10 so 21 goes into hashTable[10] position. 10%11=10. hashTable[10] is already filled so we try for (10+12)%11=0 position. hashTable[0] is empty so we put 10 there. 32%11=10. hashTable[10] is filled. We try (32+12)%11=0. But hashTable[0] is also already filled. We try (32+22)%11=3. hashTable[3] is empty so we put 32 in hashTable[3] position. 43 uses (43+33)%11=8. We put it in hashTable[8]
 */

#include <bits/stdc++.h>

using namespace std;

void QuadraticProbing(int hash[],int hashSize,int arr[],int sizeOfArray);

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
	    
	    QuadraticProbing( hash, hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}

/* 
Quadratic Probing We look for i2‘th slot in i’th iteration.

let hash(x) be the slot index computed using hash function.  
If slot hash(x) % S is full, then we try (hash(x) + 1*1) % S
If (hash(x) + 1*1) % S is also full, then we try (hash(x) + 2*2) % S
If (hash(x) + 2*2) % S is also full, then we try (hash(x) + 3*3) % S
 */

void QuadraticProbing(int hash[],int hashSize,int arr[],int sizeOfArray)
{
    // initialise the hash[] wiht -1 to indicate an empty place is hash
    memset(hash, -1, hashSize);
    
    int i, j;
    
    for(i = 0; i < sizeOfArray; i++) {
        // if hash[index after hashing key by hash function] is -1 (empty), we can insert
        if (hash[arr[i] % hashSize] == -1) {
            hash[arr[i] % hashSize] = arr[i];
        } else {
            // if the above position is occupied, collision occurs, as different key are giving same ouput in has function,
            // in our case % by hashSize we find next empty position, using binary probing

            // Binary Probing
            int count = 1;
            // condition for count to be less than hashSize as we are hashing using % hashSize,
            // once the count is greater than hashSize, it % will start giving same values
            while(hash[(arr[i] + count * count) % hashSize] != -1 && count < hashSize)
                count++;
            
            if (count != hashSize)
                hash[(arr[i] + count * count) % hashSize] = arr[i];

             // nothing in else part as there is no empty space, we do nothing and element is dropped
        }
    }
}