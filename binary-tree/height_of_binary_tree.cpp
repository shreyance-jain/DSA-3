/* 
Height of Binary Tree

Difficulty: Basic
Problem Statement

Given a binary tree, find height of it.

        1
     /     \
   10      39
  /
5
The above tree has a height of 3.
Note: Height of empty tree is considered 0.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains two lines of input. The first line contains number of edges.
The second line contains relation between nodes.

Output Format:
For each testcase, in a new line, print the height of tree.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
2
3

Explanation:
Testcase1: The tree is
        1
     /      \
   2       3
So, the height would be 2.
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, height would be 3.
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

int height(Node *node);

int main() {
    int t;
    cin >> t;
    while(t--) {
        map<int, Node*> m;
        Node *root = NULL;
        Node *child;
        int n;
        cin >> n;
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
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        cout << height(root) << endl;
    }
    return 0;
}

/* Approach:
1. If tree is empty return 0
2. Else
    (a) Get the max depth of left sub tree recursively i.e.
        call maxDepth(tree->left-subtree)
    (b) Get the max depth of right sub tree recursively i.e.
        call maxDepth(tree->right-subtree)
    (c) Get the max of depth of right and left subtrees and
        1 to it for the current node
        max_depth = max(max depth of left subtree and max depth of right sub tree) + 1
    (d) return max_depth
*/
int height(Node *node) {
    // base case
    if (node == NULL)
        return 0;
    // recurse for left height and right height and sum this with 1 which indicates root
    return 1 + max(height(node->left), height(node->right));
}

// Time Complexity: O(n), we simply traverse every node of tree and at every node we do 
// constant work(compare left height and right height and one addition operation, which is constant work)
// so time complexity is theta(n)

// Space complexity: O(height) at any time At Most (height + 1) function calls are there in function call stack

// Company Tags: Amazon, Cadence India, CouponDunia, D-E-Shaw, FactSet, FreeCharge, MakeMyTrip, Monotype Solutions
// Snapdeal, Synopsys, Teradata, VMWare, Zoho