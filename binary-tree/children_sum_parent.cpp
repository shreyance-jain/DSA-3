/* 
Children Sum Parent

Difficulty: Easy
Problem Statement

Given a binary tree, complete the function that returns true if the tree satisfies the following property:
For every node, data value must be equal to the sum of data values in left and right children.
Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

Input Format:
The first line consists of T test cases. The first line of every test case consists of N,
denoting the number of edges in the tree. The second and third line of every test case consists of N,
nodes of the binary tree.

Output Format:
Return 1 if the given tree satisfies the given property else return 0.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
3
4 1 L 4 3 R 3 3 L
5
10 8 L 10 2 R 8 3 L 8 5 R 2 2 L

Output:
1
1

Explanation:
Testcase 1: Tree is like:
              4
           /     \
         1       3
                 /
               3

Here, every node is sum of its left and right child.
 
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

void insert(Node *root, int n1, int n2, char lr) {
	if (root == NULL)
		return;
	if (root->data == n1) {
		switch(lr) {
			case 'L':
				root->left = new Node(n2);
				break;
			case 'R':
				root->right = new Node(n2);
				break;
		}
	} else {
		insert(root->left, n1, n2, lr);
		insert(root->right, n1, n2, lr);
	}
}

int isSumProperty(Node *node);
	
int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		Node *root = NULL;
		while(n--) {
			int n1, n2;
			char lr;
			cin >> n1 >> n2 >> lr;
			if (root == NULL) {
				root = new Node(n1);
				switch(lr) {
					case 'L':
						root->left = new Node(n2);
						break;
					case 'R':
						root->right = new Node(n2);
						break;
				}
			} else {
				insert(root, n1, n2, lr);
			}
		}
		cout << isSumProperty(root) << endl;
	}
}


/* For each node we check if the sum of left subtree and sum of right subtree is equal to parent's data.
If this property is followed by each node then we return 1
 */
int isSumProperty(Node *node) {
	if (node == NULL) return 1;
	// for leaf node we say it follows the property
	if (node->left == NULL && node->right == NULL) return 1;
	
	int sum = 0;
	// if left child is not null then store value of left data
	if (node->left != NULL) {sum += node->left->data;}

	// if right child is not null then store value of right data
	if (node->right != NULL) {sum += node->right->data;}
	
	// if stored data of right and left child is equal to current node data
	// we return true and this should be true for every node, so recurse for left and right node/tree
	return (sum == node->data && isSumProperty(node->left) && isSumProperty(node->right));
}

// Time complexity: O(n), simply traverse the tree and at every node we do constant work
// Space complexity: O(height) exactly atmost height+1 funciton calls in function call stack at a time
// Company Tags: Amazon, Accolite