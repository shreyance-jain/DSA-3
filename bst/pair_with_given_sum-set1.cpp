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

/* Apporach:  This program is based on hashing
Traverse the bst in inorder way and insert node value in a set
Also, check for every node, difference between sum and node's value in set,
if found then pair exists otherwise it doesn't exist */
bool findSumUtil(Node *root, int sum, unordered_set<int> &s) {
    if (root == NULL)
        return false;
        
    bool l = findSumUtil(root->left, sum, s);
    if (l == true) return true;
    
    if (s.find(sum - root->data) != s.end())
        return true;
    s.insert(root->data);
    
    bool r = findSumUtil(root->right, sum, s);
    if (r == true) return true;
    
    
    return false;
} // see code style pro below

bool findPair(Node* root, int sum) {
    unordered_set<int> s;
    bool result = findSumUtil(root, sum, s);
    return result;
}

// pro code style
bool sumUtil(Node *root, int sum, unordered_set<int> &s) {
    // base case
    if (root == NULL) return false;

    // recurse for left subtree
    if (sumUtil(root->left, sum, s)) return true;

    // check is pair exists with given sum
    if (s.find(sum - root->data) != s.end())
        return true;
    else
        s.insert(root->data);
    
    // recur for right
    return sumUtil(root->right, sum, s);
}

// Time complexity: O(n)
// Space complexity: O(n)

// Company Tags: VMWare
