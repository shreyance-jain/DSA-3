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

/* We have discussed a O(n^2) soultion in set-1
In this, we implement an efficient solution based on hashmap
We need to check horizontal distances from root for all nodes.
If two nodes have same horizontal distances(HD), then they are on same vertical lines.
The idea of HD is simple. HD for root is 0, a right edge connecting to right subtree
is considered as +1 horizontal distance and a left edge is considered as -1 horizontal distance.
For example, in above tree, HD for node 4 is -2, HD for node 2 is -1, HD for 5 and 6 is 0 and HD for node 7 is +2
We can do preorder travresal of the given binary tree. While traversing the tree, we can recusively calculate HDs
We initially pass the horizontal distance for root as 0.
For left subtree we pass the hd as hd of root -1 
for right subtree we pass the hd as hd of root +1
For every HD value, we maintain a list of nodes in a hash map.
Whenever we see a node in traversal, we go to hash map entry and
add the node to the hash map using HD as a key in map*/
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

/*fucntion to store vertical order in map 'm'
'hd' is horizontal distance of current node from root
'hd' is initially passed as 0*/
void getVerticalOrder(Node *node, int hd, map<int, vector<int>> &m) {
	// base case
	if (node == NULL)
		return;
	// store current node in map 'm'
	m[hd].push_back(node->data);
	// store nodes in left subtree
	getVerticalOrder(node->left, hd - 1, m);
	// store nodes in right subtree
	getVerticalOrder(node->right, hd + 1, m);
}


void verticalOrder(Node *root) {
	// map to store vertical order
	map<int, vector<int>> m;
	int hd = 0;
	getVerticalOrder(root, hd, m);
	map<int, vector<int>>::iterator it;
	// traverse map and store nodes at each horizontal distance
	for(it = m.begin(); it != m.end(); it++) {
		for(int i = 0; i < it->second.size(); ++i)
			cout << it->second[i] << " ";
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

// Time Complexity: Time complexity of this hashing based solution cane be considered as O(n) under
// the assumption that we have a good hashing function that allows insertion and retrieval operations
// as O(1) time. In above C++ implementation, map of STL is used.
// map in STL is typically impelemented using a Self-Balancing Binary Search Tree, where all operations
// take O(logn) time. Therefore the time complexity of above solution is O(nlogn)
// This solution MAY print nodes 	
