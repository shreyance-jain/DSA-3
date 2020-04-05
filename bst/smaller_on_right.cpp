/* 
Smaller on Right

Difficulty: Medium
Problem Statement

Given an array arr[] of N elements.
The task is to count maximum number of distinct smaller elements on right side of any array element.
For example, in {10, 6, 9, 7, 20, 19, 21, 18, 17, 16}, the result is 4. 
Note that 20 has maximum 4 smaller elements on right side.
Other elements have less count, for example 10 has 3 smaller elements on right side.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains number of elements in the array and next line contains array elements.

Output:
For each testcase, print the maximum count of smaller elements on right side.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 106

Example:
Input:
4
10
10 6 9 7 20 19 21 18 17 16
5
5 4 3 2 1
5
1 2 3 4 5
5
1 2 3 2 1

Output:
4
4
0
2

Explanation:

Testcase 1: Number of smaller elements on right side of every element (from left to right) in the array are 3 0 1 0 4 3 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.
Testcase 2: Number of smaller elements on right side of every element (from left to right) in the array are 4 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.
 */
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
  int height;
  int size;
  Node(int x) {
      key = x;
      left = right = NULL;
      height = 1;
      size = 1;
  }
};

int count(Node *n) {
    if (n == NULL)
        return 0;
    return n->size;
}

int height(Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int size(Node *n) {
    if (n == NULL)
        return 0;
    return n->size;
}

int getBalance(Node *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    
    // perform rotations
    y->left = x;
    x->right = T2;
    
    // update height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    // update size
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
    
    // return new root
    return y;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    
    // perform rotations
    x->right = y;
    y->left = T2;
    
    // update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    // update size
    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;
    
    // return new root
    return x;
}

Node *insert(Node *node, int key, int *count) {
    // perform insert like normal bst
    if (node == NULL)
        return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key, count);
    else if (key > node->key) {
        node->right = insert(node->right, key, count);
        *count = *count + size(node->left) + 1;
    }
    // if node is already present
    else {
         *count = *count + size(node->left);
         return node;// key already present, avoid duplicates
    }
    
    // update height of this ancestor node
    node->height = max(height(node->left), height(node->right)) + 1;
    // update size of this ancestor node
    node->size = size(node->left) + size(node->right) + 1;
    
    // check balance
    int balance = getBalance(node);
    
    // check imbalance
    
    // Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    
    // Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    
    // Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

void smallerOnRight(int arr[], int smaller[], int n) {
    for(int i = 0; i < n; i++)
        smaller[i] = 0;
    Node *root = NULL;
    for(int i = n-1; i >= 0 ; i--)
        root = insert(root, arr[i], &smaller[i]);
    return;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int smaller[n];
        smallerOnRight(arr, smaller, n);
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
            res = max(res, smaller[i]);
        cout << res << endl;
    }
    return 0;
}

// Time complexity: O(nlogn)
// Space complexity: O(n)
/* Approach:
We can augment the self balancing bst so that every node N contains size of subtree rooted with N
We have used AVL tree in the above implementation.
We traverse the array from right to left and insert all the elements one by one in an AVL Tree.
While inserting a new node in AVL Tree, we first compare it with root. If key is greater than root,
then its is greater than all the nodes in left subtree of root.
So we add the size of left subtree to the count of smaller element for the key being inserted.
We recusrsively follow the same approach for all nodes down the root.
*/
