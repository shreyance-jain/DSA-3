/* 
Convert Level Order Traversal to BST

Difficulty: Medium
Problems

Given an array of size N containing level order traversal of a BST.
The task is to complete the function constructBst(),
that construct the BST (Binary Search Tree) from its given level order traversal.

Input:
First line of input contains number of testcases T.
For each testcase, first line contains number of elements and
next line contains n elements which is level order travesal of a BST.

Output:
For each test return the pointer to the root of the newly constructed BST.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
9
7 4 12 3 6 8 1 5 10
6
1 3 4 6 7 8

Output:
7 4 3 1 6 5 12 8 10
1 3 4 6 7 8

Explanation:
Testcase 1: After constructing BST, the preorder traversal of BST is 7 4 3 1 6 5 12 8 10.
 */


// Driver Code
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
Node *insert(Node *root, int key);
void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}

/* A simple approach:
Simply traverse the array and call bst insert function for every node
Traversing the array is O(n) operation and insert in bst is O(h)
which is O(n) in worst case which occurs in skew trees
So the worst case time complexity would be O(n^2)
Aux Space: O(1) if we do insert in bst iteratively */
Node* constructBst(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node *root = NULL;
    int i = 0;
    while(i < n) {
        root = insert(root, arr[i]);
        i++;
    }
    return root;
}

Node *insert(Node *root, int key) {
    Node *curr = root;
    Node *prev = NULL;
    while(curr != NULL) {
        prev = curr;
        if (curr->data == key)
            return root;
        else if (curr->data > key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    Node *temp = new Node(key);
    if (prev == NULL)
        return temp;
    if (prev->data > key)
        prev->left = temp;
    else if (prev->data < key)
        prev->right = temp;
    return root;
}

// time complexity: O(n^2)
// space compexity: O(1)

// for a time optimised solution see set-2
// idea is to use a queue to construct bst from level order
// (like we used in create binary tree from linked list)
// and at the same time take care of bst properties which we do
// by maintainig range (like we did in check bst)
