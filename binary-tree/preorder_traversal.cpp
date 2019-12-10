/* 
Preorder Traversal

Difficulty: Basic
Problem Statement

Given a binary tree, print preorder traversal of it.
The task is to complete the function preorder(), which accept root of the tree as argument.
For example: preorder traversal of below tree is "1 10 5 39"

        1
     /     \
   10     39
  /
5

Input:
The first line of input contains T, denoting the number of testcases.
Each testcase contains two lines.
The first line contains number of edges in a tree.
The second line contains number of edges+1 number of nodes.
The struct Node has a data part which stores the data, pointer to left child and pointer to right child.

Output:
The function should print preorder traversal.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function preorder() that prints the data in preorder way. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 30
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 3 2
10 20 40 60 30

Explanation:
Testcase 1: There are 3 nodes in tree and the preorder traversal would give 1 3 2.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(Node * root);

int main() {
    int t;
    cin >> t;
    while(t--) {
        map<int, Node *> m;
        int n;
        cin >> n;
        Node *root = NULL;
        while(n--) {
            Node *parent;
            char lr;
            int n1, n2;
            cin >> n1 >> n2 >> lr;
            if (m.find(n1) == m.end()) {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            } else 
                parent = m[n1];
            Node *child = new Node(n2);
            if (lr == 'L') 
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        preOrder(root);
        cout << endl;
    }
}

void preOrder(Node *root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}