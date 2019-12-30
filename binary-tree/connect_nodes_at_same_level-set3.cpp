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



/* Approach: Extends approach in set2 for all kinds of trees
In the method of set2, we traversed the nodes in pre order fashion
Instead of traversing in PreOrder fashion (root, left, right)
if we traverse the nextRight node before the left and right children
we can ensure that all nodes at level i have the nextRight set,
before the level i + 1 nodes.
So this works for cases when binary tree is not complete
 */

// Notations: p for parent
// analogy: parent p sets nextRIght of left and right children
void connect(Node *p)
{
   // sets nextRight of root
   p->nextRight = NULL;
   // sets nextRight of nodes other than root
   connectRecur(p);
}

/* This function retruns the left most child of nodes at p's level
This function is used to get nextRight of p's right child.
If right child of p is null then this can also be used for the left child */
Node *getNextRight(Node *p) {
   // traverse the nodes at p level and retruns first node first child
    Node *temp = p->nextRight;
    while(temp != NULL) {
        if (temp->left)
            return temp->left;
        if (temp->right)
            return temp->right;
        temp = temp->nextRight;
    }
    // if all nodes at p's level are leaf node retrun NULL
    return NULL;
}

// sets nextRight of all descendants of p.
// This function makes sure that nextRight of nodes at level i are set before nodes at level i + 1
void connectRecur(Node *p) {
   // base case
    if (p == NULL)
        return;
   /* Before setting nextRight of left and right children, set nextRight
   of children of other nodes at same level(because we can access children of other nodes
   using p's rightNode only)*/
    if (p->nextRight != NULL)
        connectRecur(p->nextRight);
    
    // set the nextRight for p's left child
    if (p->left) {
        if (p->right) {
            p->left->nextRight = p->right;
            p->right->nextRight = getNextRight(p);
        } else
            p->left->nextRight = getNextRight(p);
         // recur for next level nodes. Note we only recur for left child
         // call for left child will call for right child
        connectRecur(p->left);
    }
    // if left child is NULL the first node of next level will either be p->right or NULL
    else if (p->right) {
        p->right->nextRight = getNextRight(p);
        connectRecur(p->right);
    }
}

// Time Complexity: More than O(n), because of recursive calls first on nextRight and then on left child
// there is possiblity of processing a subtree more than once,
// once while nextRight call in row above it will call for left or right also
// and other while nextRight in same row

// Aux Space: For function call stack

// CAN BE OPTIMIZED ON TIME AND SPACE