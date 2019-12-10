/* 
Inorder Traversal

Difficulty: Basic
Problem Statement

Given a binary tree, the task is to print the nodes in inorder traversal of it.
Inorder traversal of below tree is 5 10 1 39

        1
     /      \
   10      39
  /
5

Input Format:
First line of input contains number of testcases T. For each testcase,
first line of input contains number of edges in the tree.
For each edge there will be three consecutive inputs,
first two integers contains parent node and child node,
and the last character defines whether the child is in left or right.

Output Format:
For each testcase, in a new line, print the inorder traversal.

Constraints:
1 <= T <= 100
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
3 1 2
40 20 60 10 30

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the inorder would be 3 1 2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the inorder would be 40 20 60 10 30
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

void inOrder(Node *root);

int main() {
    int t;
    cin >> t;
    while(t--) {
        map<int, Node*> m;
        int n;
        cin >> n;
        Node *root = NULL;
        while(n--) {
            int n1, n2;
            char lr;
            cin >> n1 >> n2 >> lr;
            Node *parent;
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
            {
                parent->right = child;
            }
            m[n2] = child;
        }
        inOrder(root);
        cout << endl;
    }
}
void inOrder(Node* root)
{
  if (root == NULL) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

// Company Tags: Adobe, Amazon, Snapdeal