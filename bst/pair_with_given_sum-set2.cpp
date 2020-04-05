/* 
Pair Sum in BST

Difficulty: Medium
Problem Statement

Given an array arr[] of N elements to be inserted into BST and a number X.
The task is to check if a pair exists in BST whose sum is equal to X.

Input:
First line of input contains number of testcases T. For each testcase,
first line of input contains number of elements to be inserted into BST.
Next line contains elements to be inserted into BST and last line contains X.

Output:
For each testcase, print "1" (without quotes) if
pair with sum X exists in BST, else print "0" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105

Example:
Input:
2
5
8 5 1 3 9
4
6
0 1 2 7 8 3
6

Output:
1
0

Explanation:
Testcase 1: Pair (3, 1) exists in the array with sum 4.
Testcase 2: No pair exists for given X = 6
 */


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key) {
    if (root == NULL)
        return new Node(j=key);
    if (root->key > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

bool findPair(Node *root, int sum);

int main() {
    int t;
    cin >> t;
    while(t--) {
         int n, x, val;
         Node *root;
         cin >> n;
         for(int i = 0; i < n; i++) {
             cin >> val;
             root = insert(root, val);
         }
         cin >> x;
         if (findPair(root, x))
             cout << "1" << endl;
         else
            cout << "0" << endl;
    }
    return 0;
}

/* Approach: Traverse the tree in pre-order manner from both side, left and right and
store the values of left and right side into the ArrayList LeftList and RightList respectively
On reaching the leaf node, take out the left side last value and the right side last value
from respective list: There will be three conditions:

1. left side value + right side value < sum:
Delete the last value of LeftSide and make left side execution to right side
because from moving left side to right side in the tree the value of node increases

2. left side value + right side value > sum
Delete the last value of Rightide and make right side execution to left side
because from moving from right to left side in the tree the value decreases

3. left side value + right side value = sum
pair with given sum exists


In other words,
We will solve the problem using a space efficient method by reducing the space complexity
to O(h), where h is the height of the bst.
For that we will use TWO POINTER APPROACH on bst
Thus we maintain a forward and a backward iterator that will iterate the bst in the order of
inorder and reverse inorder traversal respectively.
Algo:
1. Create a forward and backward iterator for BST. Let's say the nodes value are pointing to v1 and v2
2. Now at each step,
    - if v1 + v2 = X, we found sum
    - if v1 + v2 < X, we will make forward iterator point to the next element
    - if v1 + v2 > X, we will make backward iterator to point to previous element
3. If no such pair, answer will be NO
 */


bool findPair(Node *root, int sum) {
    stack<Node *> sleft, sright;
    Node *curr1 = root;
    Node *curr2 = root;
    while(1) {
        while(curr1 != NULL) {
            sleft.push(curr1);
            curr1 = curr1->left;
        }
        while(curr2 != NULL) {
            sright.push(curr2);
            curr2 = curr2->right;
        }
        curr1 = sleft.top();
        curr2 = sright.top();
        if (curr1 == curr2)
            break;
        int v1 = curr1->data;
        int v2 = curr2->data;
        if (v1 + v2 < sum) {
            sleft.pop();
            curr1 = curr1->right;
            curr2 = NULL; // to avoid changes in right pointer
        }
        else if (v1 + v2 > sum) {
            sright.pop();
            curr2 = curr2->left;
            curr1 = NULL; // to avoid changes in left pointer
        }
        else
            return true;
    }
    return false;
}// .... see another style of writing the same funciton in set-3

// Time complexity: O(n)
// Space complexity: O(h), which will be logn in case the bst is balanced

// Company tags: VMWare
