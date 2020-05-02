/* 
Binary Heap Operations

Difficulty: Easy
Problems

A binary heap is a Binary Tree with following properties:
1) It’s a complete tree (All levels are completely filled except possibly the last level
and the last level has all keys as left as possible).
This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap.In a Min Binary Heap,
the key at root must be minimum among all keys present in Binary Heap.
The same property must be recursively true for all nodes in Binary Tree.
Max Binary Heap is similar to MinHeap.

Given some queries and your task is to implement the three methods insertKey, 
deleteKey,  and extractMin on a Binary Min Heap and call them as per the query given below:
1) 1  x  (a query of this type means to insert an element in the min heap with value x )
2) 2  x  (a query of this type means to remove an element at position x from the min heap)
3) 3  (a query like this removes the min element from the min heap and prints it ).

Input:
The first line of the input contains an integer 'T' denoting the number of test cases.
Then T test cases follow. First line of each test case contains an integer Q
denoting the number of queries.
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1
if the heap is empty else the min element of the heap.

Constraints:
1 <= T <= 100
1 <= Q <= 104
1 <= x <= 104

Example:
Input:
2
7
1 4 1 2 3 1 6 2 0 3 3
5
1 8 1 9 2 1 3 3

Output:
2 6 - 1
8 -1
 

Explanation:
Testcase 1:
In the first test case for query 
1 4      the heap will have  {4}  
1 2      the heap will be {2 4}
3         removes min element from heap ie 2 and prints it now heap is {4} 
1 6      inserts 6 to heap now heap is {4 6}
2 0      delete element at position 0 of heap now heap is {6}
3         remove min element from heap ie 6 and prints it  now the heap is empty {}
3         since heap is empty thus no min element exist so -1 is printed .
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct MinHeap {
    int *harr;
    int capacity;
    int heap_size;


    MinHeap(int c) {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i-1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right (int i) { return (2 * i + 2); }

    void MinHeapify(int);
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a;
        cin >> a;
        MinHeap h(a);
        for(ll i = 0; i < a; i++) {
            int c;
            int n;
            cin >> c;
            if (c == 1) {
                cin >> n;
                h.insertKey(n);
            }
            if (c == 2) {
                cin >> n;
                h.deleteKey(n);
            }
            if (c == 3) {
                cout << h.extractMin() << " ";
            }
        }
        cout << endl;
        // delete h.harr
        h.harr = NULL;
    }
    return 0;
}

/* Extracts the min value which is the top value of the root.
Algo:
1. Swaps the value with the last element of min heap
2. Decrease the size of the heap by 1
3. Call heapify for the root i.e. index = 0
Heapify assumes only the given node is disturbed but the left and right
subtree are following the min heap properties */
int MinHeap::extractMin() {
    // base condition
    if (heap_size == 0) return -1;
    // explicitly handle size = 1
    // because we don't want to call MinHeapify with size 0
    if (heap_size == 1) {
        heap_size--;
        return harr[heap_size];
    }
    swap(harr[0], harr[heap_size-1]);
    heap_size--;
    MinHeapify(0);
    return harr[heap_size];
} // Time Complexity: O(1) + O(log n) = O(log n)

/* Delete a node at a given index.
Call decrease key for the index with value INT_MIN so it floats up to the root.
And the it calls extract Min, so it is finally deleted from the heap */
void MinHeap::deleteKey(int i) {
    if (i > heap_size)
        return;
    decreaseKey(i, INT_MIN);
    extractMin();
} // Time Complexity: O(log n) + O(log n) = O(log n)

/* Insert a new key in the min heap.
It adds the value in the last => which insures min heap 1st property i.e.
Property 1: Min Heap should be a compelet tree is followed.
Then it travels up till the root of the min heap (because these are only the nodes where violations
might have occured because of the insertion of a new value)
and make sures the Min Heap Property 2 is followed.
Property 2: A root node should have the min value in all its descendants.
For this it compares the value of left and right child with the parent and 
performs swaps if any violation is there and stops at the root. */
void MinHeap::insertKey(int k) {
    heap_size++;
    harr[heap_size - 1] = k;
    for(int i = heap_size - 1; i >= 0 && harr[parent(i)] > harr[i];) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
} // Time Complexity: O(log n)

/* Decrease the value of key with the new val, if the new_val would be greater than the
original value then no change would be required as it is a min heap.
This function updates the value with a value less than the current value
It only not just updates the value but make sure the min heap properties are satisfied
after updating the value with given decreased value.
It follows a procedure similar like insert and travel up from the updated value to the root
and make sures min heap properties are followed */
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while(i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
} // Time Complexity: O(log n)

/* Assumes the root of the tree rooted with i is disturbed
but the left subtree and the right subtree are min heap */
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[smallest])
        smallest = l;
    
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
} // Time Complexity: O(log n)

// Company Tags: Amazon, Ola Cabs, Samsung, Synopsys, Walmart