/* 
Implementing Ceil in BST

Difficulty: Medium
Problem Statement

Given an array arr[] of N positive integers to be inserted into BST and a number X.
The task it to find Ceil of X.
Ceil(X) is a number that is either equal to X or is immediately greater than X.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains number of elements in the BST,
i.e N. Next line contains N elements to be inserted into BST and last line contains X.

Output:
For each testcase, print the smallest element in BST which is larger than X.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105

Example:
Input:
2
5
5 7 1 2 3
3
6
10 5 11 4 7 8
6

Output:
5
7

Explanation:
Testcase 1: We find 3 in BST, so ceil of 3 is 3.
*/

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

/* This function is used to insert 
new values in BST*/
Node* insert(Node* root, int key) 
{ 
	if (!root) 
		return new Node(key); 
	if (key < root->data) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 

int findCeil(Node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1; 
  
    // Your code here
    int res = -1;
    Node *curr = root;
    while(curr != NULL) {
        if (curr->data == input)
            return input;
        else if (curr->data < input) {
            curr = curr->right;
        }
        else {
            res = curr->data;
            curr = curr->left;
        }
    }
    return res;
} 

int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    Node* root = NULL;
	    int n, x;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	        if(root == NULL) root = insert(root, arr[i]);
	        else insert(root, arr[i]);
	    }
	    cin >> x;
	    cout << findCeil(root, x) << endl;
	}
	
	return 0; 
}

// Time complexity: O(h)
// Space complexity: O(1)

// Company Tags: Samsung