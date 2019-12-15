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
