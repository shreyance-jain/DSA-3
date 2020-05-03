/* 
k largest elements

Difficulty: Basic

Problem Statement

Given an array of N positive integers, print k largest elements from the array.
The output elements should be printed in decreasing order.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N and k, N is the size of the array and
K is the largest element to be returned.
The second line of each test case contains N input C[i].

Output:
Print the k largest element in descending order.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10000
K ≤ N
1 ≤ C[i] ≤ 100000

Example:
Input:
2
5 2
12 5 787 1 23
7 3
1 23 12 9 30 2 50

Output:
787 23
50 30 23

Explanation:
Testcase 1: 1st largest element in the array is 787 and the second-largest is 23.
Testcase 2: 3 Largest element in the array are 50, 30 and 23.
 */

#include<bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        
        kLargest(arr, n, k);
        
    }
    return 0;
}

/* Approach: Use a MIN HEAP data structure.


1. Build a min heap, and start inserting the elements into it.
2. If heap size becomes equal to K,
then compare the incoming element with the element at the top of the heap.
3. If element at the top is less than the incoming element,
then pop the top from heap and insert the new element into the heap.
4. Finally, you are having K largest elements in the heap.
Now, since you need to print the elements in decreasing order,
so you can now pop the elements from heap one by one and store it in a vector.
5. Print the elements in the vector in reverse order.

Time Complexity: O(NLogK)
Auxiliary Space: O(K) // heap is created and destroyed and then vector of size K is used.

*/
void kLargest(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < k; i++)
        pq.push(arr[i]);
    
    for(int i = k; i < n; i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    // now pq has the k largest elements
    vector<int> res;
    while(pq.empty() == false) {
        res.push_back(pq.top());
        pq.pop();
    }
    
    for(int i = k-1; i >= 0; i--)
        cout << res[i] << " ";
    cout << endl;
}

// Time Complexity: O(NLogK)
// Auxiliary Space: O(K)

// Company Tags: Amazon, Microsoft, Walmart

// PRO CODE
void proCode(int arr[], int n, int k){

    priority_queue<int, vector<int>, greater<int>> q; // Minheap
    vector<int> v;
    
    for(int i = 0; i < n;i++){
        if(q.size() == k){ // if size becomes equal to k
            if(q.top() < arr[i]){ // if top element is smaller than arr[i]
                q.pop();   
                q.push(arr[i]);  
            }
        }
        else
            q.push(arr[i]);
    }
    
    // push all heap elements in vector
    while(!q.empty()) v.push_back(q.top()), q.pop(); 
        
    for(int i = v.size()-1;i>=0;i--)
        cout<< v[i] << " ";
    cout << endl;
}