/*
Counting Sort

Problem Statement

Given a string S consisting of lowercase latin letters,
arrange all its letters in lexographical order using Counting Sort.

Input Format:
The first line of the input contains T denoting number of testcases.
Then T test cases follow. Each testcase contains positive integer N denoting the length of string.
The last line of input contains the string S.

Output Format:
For each testcase, in a new line, output the sorted string.

Constraints:
1 <= T <= 10^5
1 <= N <= 10^5

Example:
Input:
2
5
edsab
13
geeksforgeeks

Output:
abdes
eeeefggkkorss
*/

#include <bits/stdc++.h>

using namespace std;

#define RANGE 255
// The main function that sort the given string arr[] in
// alphabatical order
void countSort(char arr[]);


int main()
{
    long int t;
    cin >> t;
    while(t--)
    {
        long int n;
        cin >> n;
        char arr[n+1];
        cin >> arr;
        countSort(arr);
        cout << arr << endl;
    }
    return 0;
}

// Function to sort the given string arr[] in
// alphabatical order
void countSort(char arr[])
{
    // The output character array that will have
    // the sorted array
    char output[strlen(arr)];
    
    /* count array to store to count of individual character
    and initiaize the count array as 0 */
    int count[RANGE + 1];
    memset(count, 0, sizeof(count));
    
    /* store the count of each character
    for example: if we are given that the input array is in the range [0-9]
    like {2, 3, 5, 1, 3, 4,5}
    we create a count array that has index from 0 to 9, we traverse the input array and increase the count
    in count array where the index in count array will be the value in the input array */
    for(int i = 0; arr[i]; i++)
        count[arr[i]]++;
        
    // change count[i] so that count[i] now contains actual position of this character in output array
    for(int i = 1; i <= RANGE; i++)
        count[i] += count[i-1];
    
    // build the output character array, for stable algorithm traverse the array from last
    for(int i = 0; arr[i]; i++) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
        
    // copy the ouput array to original array, so the original array now stores the sorted character array
    for(int i = 0; arr[i]; i++)
        arr[i] = output[i];
        
}

// Company Tags: Cisco, Goldman Sachs

/* Theory Notes

Counting Sort

Counting sort is a sorting technique based on keys between a specific range.
It works by counting the number of objects having distinct key values (kind of hashing).
Then doing some arithmetic to calculate the position of each object in the output sequence.

Let us understand it with the help of an example.

For simplicity, consider the data in the range 0 to 9. 
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index. 
  
  Points to be noted:
1. Counting sort is efficient if the range of input data is not significantly greater
    than the number of objects to be sorted.
    Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K.
2. It is not a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data.
3. It is often used as a sub-routine to another sorting algorithm like radix sort.
4. Counting sort uses a partial hashing to count the occurrence of the data object in O(1).
  */
