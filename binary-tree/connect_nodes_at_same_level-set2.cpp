/*
Connect Nodes at Same Level

Difficulty: Medium
Problem Statement

Given a binary tree, connect the nodes that are at same level.
Structure of the given Binary Tree node is like following.
struct Node
{
      int data;
      Node* left;
      Node* right;
      Node* nextRight;
}

Initially, all the nextRight pointers point to garbage values.
Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL

Input Format:
The input contains T, denoting number of testcases. For each testcase there will be third lines.
The first line contains number of edges. The second line contains relation between nodes.
The second line contains two nodes and a character separated by space.
The first node denotes data value, second node denotes where it will be assigned 
to the previous node which will depend on character 'L' or 'R' i.e. the 2nd node will be 
assigned as left child to the 1st node if character is 'L' and so on. 
The first node of second line is root node. 
The struct or class Node has a data part which stores the data, 
pointer to left child and pointer to right child. 
There are multiple test cases. 
For each test case, the function will be called individually.

Output Format:
For each testcase, in a new line, print the level order and inorder traversals.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2
3 1 L 3 2 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 1 2
1 3 2
10 20 30 40 60
40 20 60 10 30

Explanation:
Testcase1: The connected tree is
        3 ------> NULL
     /      \
   1 -----> 2 ------ NULL
Testcase2: The connected tree is
                           10 ----------> NULL
                        /        \
                     20 ------> 30 -------> NULL
                  /       \
               40 ----> 60 ----------> NULL
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* nextRight;
    Node(int x){
        data = x;
        left = right = NULL;
        nextRight = NULL;
    }
};

void connect(struct Node *p);
void connectRecur(struct Node *p);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      cout<<node->data<<" ";
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
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
     connect(root);
     printSpecial(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
  }
  return 0;
}


/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
/* Approach: Extend pre order travresal

In this, we set the nextRight in pre-order fashion
to make sure that nextRight of parent is set before its children

When we are at node p we set nextRight of its left and right children

Since the tree is complete binary tree,
- p->left->nextRight = p->right
- p->right->nextRight = p->nextRight->left
- if p is right most node, p->right->nextRight = NULL
 */
void connect(Node *p) // assume tree is complete binary tree
{
   p->nextRight = NULL;
   connectRecur(p);
}
// asssume p is complete binary tree
void connectRecur(Node *p) {
    if (p == NULL)
        return;
    
    if (p->left)
        p->left->nextRight = p->right;
    
    if (p->right)
        p->right->nextRight = (p->nextRight ? p->nextRight->left : NULL);

    connectRecur(p->left);
    connectRecur(p->right);
}

// Time Complexity: Same as level order traversal, O(n)

// Aux Space: Same as pre order traversal,
// Aux Space: O(height)

/* 
Why doesn’t method 2 work for trees which are not Complete Binary Trees?
Let us consider following tree as an example.

            1
          /    \
        2        3
       / \      /  \
      4   5    6    7
     / \           / \  
    8   9        10   11

In Method 2, we set the nextRight pointer in pre order fashion.
When we are at node 4,
we set the nextRight of its children which are 8 and 9 (the nextRight of 4 is already set as node 5).
nextRight of 8 will simply be set as 9,
but nextRight of 9 will be set as NULL which is incorrect.
We can’t set the correct nextRight, because when we set nextRight of 9,
we only have nextRight of node 4 and ancestors of node 4,
we don’t have nextRight of nodes in right subtree of root.
 */

// CAN BE OPTIMIZED FOR IF BINARY TREE IS NOT COMPLETE