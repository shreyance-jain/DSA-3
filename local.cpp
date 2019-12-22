/*
Print a Binary Tree in Vertical Order | Set 1

Given a binary tree, print it vertically. The following example illustrates vertical order traversal.

           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9 
               
              
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9 
 */

/* The idea is to traverse the tree once and get the min and max horizontal distance
with respect to root. For the tree shown above, min distance is -2(for node wiht value 1)
and maximum distance is 3(for node with value 9)
Once we have maximum and minimum distances from root, we iterate each vertical line
at distance minimum to maximum from root,
and for each vertical line traverse the tree and print nodes which lies on that vertical line*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	Node (int x) {
		data = x;
		left = right = NULL;
	}
};

void findMinMax(Node *node, int *min, int *max, int hd) {
	if (node == NULL)
		return;
	if (hd < *min)
		*min = hd;
	else if (hd > *max)
		*max = hd;
	findMinMax(node->left, min, max, hd -1);
	findMinMax(node->right, min, max, hd+1);
}

void printVerticalLine(Node *node, int line_no, int hd) {
	// base case
	if (node == NULL)
		return;
	if (line_no == hd)
		cout << node->data << " ";
	printVerticalLine(node->left, line_no, hd - 1);
	printVerticalLine(node->right, line_no, hd + 1);
}

void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " "; 
		inorder(root->right);
	}
}

void verticalOrder(Node *root) {
	int min = 0, max = 0;
	findMinMax(root, &min, &max, 0);
	inorder(root);
	cout << "min: " << min << "max: " << max << endl;
	for(int line_no = min; line_no <= max; line_no++) {
		printVerticalLine(root, line_no, 0);
		cout << endl;
	}
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		Node *root = NULL;
		map<int, Node *> m;
		while(n--) {
			int n1, n2;
			char lr;
			Node *parent, *child;
			cin >> n1 >> n2 >> lr;
			if (m.find(n1) == m.end()) {
				parent = new Node(n1);
				m[n1] = parent;
				if (root == NULL)
					root = parent;
			} else
				parent = m[n1];
			child = new Node(n2);
			m[n2] = child;
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
		}
		verticalOrder(root);
		cout << endl;
	}
}