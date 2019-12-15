/* 
Determine if Two Trees are Identical

Difficulty: Easy
Problem Statement

Given two binary trees, the task is to find if both of them are identical or not. 

Input:
The task is to complete the method isIdentical(),
which takes 2 argument, the roots r1 and r2 of the Binary Trees.
The struct Node has a data part which stores the data,
pointer to left child and pointer to right child.
There are multiple test cases.
For each test case, this method will be called individually.

Output:
The function should return true if both trees are identical else false.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <=Data of a node <= 1000

Example:
Input
2
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 3 L 1 2 R

Output
1
0

Explanation:
Testcase 1: There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
Testcase 2: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

bool isIdentical(Node *, Node *);

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		// input first tree
		map<int, Node *> m;
		int n;
		cin >> n;
		struct Node *root = NULL;
		struct Node *child;
		while (n--)
		{
			Node *parent;
			int n1, n2;
			char lr;
			cin >> n1 >> n2 >> lr;
			if (m.find(n1) == m.end())
			{
				parent = new Node(n1);
				m[n1] = parent;
				if (root == NULL)
					root = parent;
			}
			else
				parent = m[n1];
			child = new Node(n2);
			m[n2] = child;
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
		}
		// input second tree
		map<int, Node *> mm;
		int nn;
		cin >> nn;
		struct Node *rott = NULL;
		while (nn--)
		{
			int n1, n2;
			char lr;
			Node *parent;
			cin >> n1 >> n2 >> lr;
			if (mm.find(n1) == mm.end())
			{
				parent = new Node(n1);
				mm[n1] = parent;
				if (rott == NULL)
					rott = parent;
			}
			else
				parent = mm[n1];
			child = new Node(n2);
			mm[n2] = child;
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
		}
		cout << isIdentical(root, rott) << endl;
	}
	return 0;
}

/*
Approach:
1. If both tree are empty then return 1
2. Else if both tree are non-empty
	(a) check data of root nodes (tree1->data == tree2->data)
	(b) check left subtrees recursively i.e. call sameTree(tree1->left_subtree, tree2->left_subtree)
	(c) check right subtress recusively i.e. call sameTree(tree1->right_subtree, tree2->right_subtree)
	(d) If a, b and c are true then return 1
2. Else return 0 (one is empty and other is not)
*/
bool isIdentical(Node *r1, Node *r2)
{
	// both empty
	if (r1 == NULL && r2 == NULL)
		return true;
	// both: non-empty, so compare them
	if (r1 != NULL && r2 != NULL)
	{
		return (r1->data == r2->data &&
				isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
	}
	// if one empty and one not empty - false
	return false;
}

// Time Complexity: Time complexity will be according to tree with lesser number of nodes.
// Let the number of nodes in two trees be m and n, then complexity of identicalTree() is
// O(m) where (m < n)

// Company Tags: Amazon, Microsft
