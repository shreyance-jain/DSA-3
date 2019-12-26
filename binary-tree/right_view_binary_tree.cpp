/* 
Right View of Binary Tree

Difficulty: Easy
Problem Statement

Given a Binary Tree, print Right view of it.
Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Input Format:
The first line of the input contains a single integer T denoting the number of test cases.
T testcases follow.
Each testcase contains two lines of input.
The first line contains number of edges.
The second line contains relation between nodes.

Output Format:
For each test case, in a new line, print right view of the binary tree.

Constraints:
1 <=T<= 100
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 2
10 30 60

Explanation:
Test case 1:

           1

        /     \

      3        2

For the above test case the right view is: 1 2

Test case 2:

            10

         /        \

     20          30

   /      \      

40      60

Right View is: 10 30 60.
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

// A wrapper over rightViewUtil()
void rightView(struct Node *root);

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
     rightView(root);
     cout << endl;
  }
  return 0;
}

/* A simple iterative approach can be to do level order traversal
and print the last node of every level

The problem can also be solved using simple recursive traversal

We can keep track of level of node by passing a parameter to all recursive calls
The idea is to keep track of maximum_level also.
And traverse tree in a manner such that right sub-tree is visited before left sub-tree
maximum_level is to maintain the max level which is visited so far
Whenever we see a node whose level is less than max_level we don't print it i.e. we discard it
Whenever we see a node whose level is more than maximum level so far, we print the node
because it is the first node in its level (note: we traverse right sub-tree before left sub-tree) */
void rightViewUtil(Node *root, int level, int *max_level) {
    // base case
    if (root == NULL)
        return;
    
    // if this is last node of its level
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }
    
    // recur for right sub-tree first
    rightViewUtil(root->right, level + 1, max_level);
    // then recur for left sub-tree
    rightViewUtil(root->left, level + 1, max_level);
}

void rightView(Node *root)
{
   // the idea is same as left view
   // here we need to traverse the right sub tree before the left sub tree
   int max_level = 0;
   rightViewUtil(root, 1, &max_level);
}

// Time Complexity: The function does a simple traversal of tree, O(n)
// Auxiliary Space Complexity: O(n), Theta(heigt + 1) due to function call stack (recusrsive calls overhead)

// Company Tags: Accolite, Adobe, Amazon, MakeMyTrip, Snapdeal