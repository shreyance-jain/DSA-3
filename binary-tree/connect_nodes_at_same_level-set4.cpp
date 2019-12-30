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
Node *getNextRight(Node *p);


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



/* Approach: 
 */

// Notations: p for parent
// analogy: parent p sets nextRIght of left and right children



// iterative
void connect(Node *p)
{
    // set nextRight of NULL
   p->nextRight = NULL;
   
   // set next of all levels one by one
   while(p != NULL) {
       Node *q = p;
       // Connect children nodes of p and children nodes of all other nodes at same level as p
       while(q != NULL) {
           // set the nextRight pointer for left child
           if (q->left) {
               if (q->right) {
                   q->left->nextRight = q->right;
               } else {
                   q->left->nextRight = getNextRight(q);
               }
           }
           // set the nextRight for right child
           if (q->right) {
               q->right->nextRight = getNextRight(q);
           }
           // set nextRight for other nodes in same level
           q = q->nextRight;
       }
       // level over
       // repeat for next level
       // we can go to next level by 3 possible ways
       if (p->left)
            p = p->left;
        else if (p->right)
            p = p->right;
        else
            p = getNextRight(p);
   }
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
// Time Complexity: More than O(n)

// Aux Space: O(1)

// Company Tags: Accolite, Adobe, Amazon, Boomerang Commerce, Flipkart, Google, Microsoft,
// Ola Cabs, Oracle, OYO Rooms, Xome
