/* 
Implementing Floor in BST

Difficulty: Medium
Problem Statement

Given an array arr[] of N positive integers to be inserted into BST and a positive integer X.
The task is to find floor of X in the BST.
Floor(X) is an element that is either equal to X or immediately smaller to X.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains number of
elements to be inserted in BST, next line contains N elements.

Output:
For each testcase, print the greatest smaller element of X.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
4
6
7 8 3 4 1 9
3

Output:
4
3

Explanation:
Testcase 1: We find 4 in the BST to floor of 4 is 4.
Testcase 2: We find 3 in the BST to floor of 3 is 3.
 */

// CPP code to find floor of a key in BST 
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

int floor(Node* root, int key) 
{ 
	if (!root) 
		return INT_MAX; 

	// Your code here
	int res = INT_MAX;
	Node *curr = root;
	while(curr != NULL) {
	    if (curr->data == key)
	        return key;
	    else if (curr->data > key)
	        curr = curr->left;
	    else {
	        res = curr->data;
	        curr = curr->right;
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
	    cout << floor(root, x) << endl; 
	}
	
	return 0; 
}

// Time complexity: O(h)
// Space complexity: O(1)
