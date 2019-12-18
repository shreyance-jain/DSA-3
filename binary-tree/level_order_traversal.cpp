/* 
Level order traversal

Difficulty: Easy
Problem Statement

You are given a tree and you need to do the level order traversal on this tree.
Level order traversal of a tree is breadth-first traversal for the tree.

Input Format:
The task is to complete the method which takes one argument, root of Binary Tree.
The struct Node has a data part which stores the data, pointer to left child and pointer to the right child.
There are multiple test cases. For each test case, this method will be called individually.

Output Format:
The function should print the level order traversal of the tree as specified in the problem statement.

Constraints:
1 <= T <= 100
1 <= Number of edges <= 1000
1 <= Data of a node <= 100

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
Output:
1 3 2
10 20 30 40 60

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the level order would be 1 3 2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the level order would be 10 20 30 40 60
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

void levelOrder(Node *node);

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		map<int, Node*> m;
		Node *root = NULL;
		while(n--) {
			Node *parent, *child;
			int n1, n2;
			char lr;
			cin >> n1 >> n2 >> lr;
			if (m.find(n1) == m.end()) {
				parent = new Node(n1);
				m[n1] = parent;
				if (root == NULL)
					root = parent;
			} else
				parent = m[n1];
			child = new Node(n2);
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
			m[n2] = child;
		}
		levelOrder(root);
		cout << endl;
	}
}

void levelOrder(Node *node) {
	queue<Node*> q;
	q.push(node);
	while(q.empty() == false) {
		Node *curr = q.front();
		cout << curr->data << " ";
		q.pop();
		if (curr->left != NULL)
		q.push(curr->left);
		if (curr->right != NULL)
		q.push(curr->right);
	}
}
