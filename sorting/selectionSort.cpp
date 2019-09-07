/* 

Selection Sort

Problem Statement

The task is to complete select() function which is used to implement Selection Sort.

Input:
First line of the input denotes number of test cases 'T'.
First line of the test case is the size of array and second line consists of array elements.

Output:
Sorted array in increasing order is displayed to the user.

Constraints:
1 <=T<= 50
1 <=N<= 1000
1 <=arr[i]<= 1000

Example:

Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Output:
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10
 */


// C program for implementation of Bubble sort
#include <bits/stdc++.h>

using namespace std;

int select(int arr[], int i);
 
void selectionSort(int arr[], int n)
{
   int i, j;
   for (i = n-1; i >=0; i--)      
   {
        int j = select(arr, i);
        swap(arr[i], arr[j]);
   }
}

int select(int arr[], int i)
{
    int max_index = i;
    int j;
    for(j = i - 1; j >= 0; j--) {
        if (arr[j] > arr[max_index])
            max_index = j;
    }
    return max_index;
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for(i=0; i < size; i++)
        cout << arr[i] << " ";
}
 
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// Time Complexity: O(n^2)
// In-place algorithm

// Comapany tags: Medlife