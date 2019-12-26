/* 
Left View of Binary Tree

Difficulty: Easy
Problem Statement

Given a Binary Tree, print Left view of it
 Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
 The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8

            

Input:
The input contains T, denoting number of testcases. For each testcase there will be two lines.
The first line contains number of edges.
The second line contains two nodes and a character separated by space.
The first node denotes data value, second node denotes where it will be assigned to the previous node
which will depend on character 'L' or 'R'
i.e. the 2nd node will be assigned as left child to the 1st node if character is 'L' and so on.
The first node of second line is root node.
The struct or class Node has a data part which stores the data,
pointer to left child and pointer to right child. There are multiple test cases.
For each test case, the function will be called individually.

Output:
The function should print nodes in left view of Binary Tree.

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
1 3
10 20 40

Explanation:
Testcase 2: below is a given tree with its nodes.
       10 
     /    \
    20    30
   /  \
  40   60
 */

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// A wrapper over leftViewUtil()
void leftView(struct Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
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
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     leftView(root);
     cout << endl;
  }
  return 0;
}


void printLeftView(Node *node, int level, int *max_level) {
    // base case
    if (node == NULL)
        return;
    
    // if this is first node of its level
    if (*max_level < level) {
        cout << node->data << " ";
        *max_level = level;
    }
    
    // recur for left and right subtrees
    printLeftView(node->left, level + 1, max_level);
    printLeftView(node->right, level + 1, max_level);
}

/* A simple iterative approach can be to do level order traversal
and print the first node of every level

The problem can also be solved using simple recursive traversal
Pre-order traversal traverse the left node first

We can keep track of level of node by passing a parameter to all recursive calls
The idea is to keep track of maximum_level also.
maximum_level is to maintain the max level which is visited so far
Whenever we see a node whose level is less than max_level we don't print it i.e. we discard it
Whenever we see a node whose level is more than maximum level so far, we print the node
because it is the first node in its level (note: we use preorder traversal) */
void leftView(Node *root)
{
   int max_level = 0;
   int level = 1;
   // pre order traverse the left node first
   // we do a pre-order traversal and maintain the levels which are visited
   printLeftView(root, level, &max_level);
}

// Time Complexity: The function does a simple traversal of tree, O(n)
// Auxiliary Space Complexity: O(n), Theta(heigt + 1) due to function call stack (recusrsive calls overhead)

// Company Tags: Accolite, Amazon, Flipkart, Knowlarity, MakeMyTrip, OlaCabs, Open Solutions, OYO Rooms, Paytm,
// Qualcomm, Samsung, Snapdeal, Twitter