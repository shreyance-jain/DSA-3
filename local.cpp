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

Node *buildTreeWrap(int in[], int pre[], int n) {
	Node *root = NULL;
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++)
		m[in[i]] = i;
	int preIndex = 0;
	root = buildTree(in, pre, 0, n-1, &preIndex, m);
	return root;
}

Node *buildTree(int in[], int pre[], int inStrt, int inEnd, int *preIndex, unordered_map<int, int> &m) {
	if (inStrt > inEnd)
		return NULL;

	Node *root = new Node(pre[*preIndex]);
	(*preIndex)++;
	
	if (inStrt == inEnd)
		return root;
	
	int inIndex = m[root->data];
	
	root->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex, m);
	root->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex, m);

	return root;
}
