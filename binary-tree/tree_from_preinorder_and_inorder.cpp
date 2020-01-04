/*
Construct Tree from Inorder & Preorder

Difficulty: Easy
Problem Statement

Given 2 Arrays of Inorder and preorder traversal.
Construct a tree and print the Postorder traversal. 

Input:
First line consists of T test cases.
First line of every test case consists of N , denoting the number of elements in array.
Second and Third line of every test case consists of Inorder and preOrder traversal of a tree.

Output:
Single line output, return the Node of the tree.

**Use already defined preIndex in template

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
1
7
3 1 4 0 5 2 6 
0 1 3 4 2 5 6 
Output:
3 4 1 5 6 2 0
 */

/* Let us consider the below traversals
Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

In a preorder sequence, leftmost element is the root of the tree. So we know 'A' 
is the root for the given sequences. By searching 'A' in Inorder sequence, we can find
out all elements on left side of A are in left subtree and elements on right are on right subtree
So we know below structure now.
        A
      /   \
     /     \
   D B E  F C

We recursively follow above steps and get the following tree
          A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F

Algorihtm: buildTree()

1. Pick an element from Preorder. Increment a preorder index variable(pre index in below code)
to pick next element in recursive call
2. Create a new tree node tNode with the data as picked element
3. Find the picked element's index in Inorder. Let the index be inIndex.
4. Call buildTree for elements before inIndex and make the built tree as left subtree of tNode
5. Call buildTree for elements after inIndex and make the build tree as right subtree of tNode
6. return tNode
*/
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node that has data, pointer ot left child 
and a pointer to right child*/
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

Node *buildTreeWrap(int in[], int pre[], int n);
Node *buildTree(int in[], int pre[], int inStrt, int inEnd, int *preIndex, unordered_map<int, int> &m);

void printPostOrder(Node *root) {
	if (root == NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->data << " ";
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, i;
		cin >> n;
		int in[n], pre[n];
		for(i = 0; i < n; i++)
			cin >> in[i];
		for(i = 0; i < n; i++)
			cin >> pre[i];
		Node *root = buildTreeWrap(in, pre, n);
		printPostOrder(root);
		cout << endl;
	}
}

/* This function mainly creates an unordered_map, the calls buildTree() */
Node *buildTreeWrap(int in[], int pre[], int n) {
	// store indexes of all items, so that we can quickly find later
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++)
		m[in[i]] = i;
	
	int preIndex = 0;

	Node *root = buildTree(in, pre, 0, n-1, &preIndex, m);
	return root;
}

/* Recrsive function to construct bianry tree of size len from inroder traversal in[] and
preorder traversal pre[]. Initial value of inStrt and inEnd should be 0 and len-1
The function doesn't do any error checking for cases where inorder and preorder
do not form a tree */
Node *buildTree(int in[], int pre[], int inStrt, int inEnd, int *preIndex, unordered_map<int, int> &m) {
	// base case
	if (inStrt > inEnd)
		return NULL;

	// pick current node from Preorder traversal using preIndex and increment preIndex
	Node *root = new Node(pre[*preIndex]);
	(*preIndex)++;
	
	// if this node has no children then retrun
	if (inStrt == inEnd)
		return root;
	
	// else find index of this node in Inorder traversal
	int inIndex = m[root->data];
	
	// using index in inorder traversal, construct left and right subtrees
	root->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex, m);
	root->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex, m);

	return root;
}


// Time Complexity: O(n), where n is no of nodes in tree or items in in[] or pre[]

// Company Tags: Accolite, Amazon, Microsoft