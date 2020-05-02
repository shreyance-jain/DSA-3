/* 
Preorder to Postorder
Difficulty: Medium
            
Problem Statement
Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, the size of array. The second line of each test case contains N input as arr[i].

Output:
Postorder traversal of the given preorder traversal is printed.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= arr[i] <= 104

Example:
Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120

Output:
35 30 100 80 40
35 32 30 120 100 90 80 40
 */

#include<iostream>
using namespace std;

void convert(int arr[], int n);

int main()
 {
	// construct bst from preorder
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    convert(arr, n);
	    cout << endl;
	}
	return 0;
}

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

/* Approach:
Approach is to construct BST from preOrder, like we did in construct BST from preOrder set-1

O(n^2) complexity
The first element of preorder traversal will always be root. We first construct the root.
Then we find index of the first element greater than root. Let the index be 'i'.
The values between root and 'i' will be the part of left subtree, and 
the values between 'i+1' and 'n-1' will be part of right subtree

For example {10, 5, 1, 7, 40, 50}, 10 is the first element, so we make it root.
Now we look for the first element greater than 10, we find 40. So we structure of BST is as following
             10
           /    \
          /      \
  {5, 1, 7}       {40, 50}
We recursively follow above steps for subarrays {5,1 ,7} and {40, 50}, and get the complete tree
(based on construct tree from preOrder and postOrder)
 */
Node* construct(int arr[], int *i, int start, int end) {
    if (start > end)
        return NULL;
    Node *root = new Node(arr[*i]);
    
    int preIndex;
    for(preIndex = start+1; preIndex <= end; preIndex++)
        if (arr[preIndex] > arr[*i])
            break;
    (*i)++;
    root->left = construct(arr, i, start+1, preIndex -1 );
    root->right = construct(arr, i, preIndex, end);
    return root;
}

void convert(int arr[], int n) {
    int i = 0;
    Node *root = construct(arr, &i, 0, n-1);
    postOrder(root);
}

// Time complexity: O(n^2)
// Space complexity: O(h) for function call stack

// set2: is O(n) implementation, without constucting tree

// Company tags: Amazon, LinkedIn
