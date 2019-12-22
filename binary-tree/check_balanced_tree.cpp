/* 
Check for Balanced Tree

Difficulty: Easy
Problem Statement
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if -
difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Input Format:
The input contains T, denoting number of testcases. For each testcase there will be two lines.
The first line contains number of edges.
The second line contains two nodes and a character separated by space.
The first node denotes data value, second node denotes where it will be
assigned to the previous node which will depend on character 'L' or 'R'
i.e. the 2nd node will be assigned as left child to the 1st node if character is 'L' and so on.
The first node of second line is root node.
The struct or class Node has a data part which stores the data,
pointer to left child and pointer to right child.
There are multiple test cases.
For each test case, the function will be called individually.

Output Format:
For each testcase, in a new line, print 0 or 1 accordingly.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
0 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 L 2 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
1
Explanation:
Testcase1: The tree is
        1
     /    
   2
      \
       3 
The max difference in height of left subtree and right subtree is 2, which is greater than 1. Hence unbalanced.
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
The max difference in height of left subtree and right subtree is 1. Hence unbalanced.
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

bool isBalanced(struct Node *root);

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
     cout << isBalanced(root) << endl;
  }
  return 0;
}

/* This function returns -1 if tree is not balanced
and if -1 is returned we simply return from function
If tree is balanced we will return height of tree */
int checkBalanced(Node *root) {
    // base case
    if (root == NULL) // root is considered to be balanced
        return 0;
    int lh = checkBalanced(root->left);
    if (lh == -1) return -1;
    int rh = checkBalanced(root->right);
    if (rh == -1) return -1;
    // if not balanced return -1
    if (abs(lh - rh) > 1) return -1;
    // else return height of subtree
    return max(lh, rh) + 1;
}

/*
The idea here is what if call to left subtree and right subtree returns two values:
1. Whether it is balanced or not
2. Its height

This can be achieved easily (if we change the return type of the function) by one variable.
This function would return -1 if the tree is not balanced and return height of the tree if balanced.
(So one value can serve both the purpose)
See tree notes dsa + video for detailed explanation
*/
bool isBalanced(Node *root)
{
    // call different function with return type int
    int res = checkBalanced(root);
    if (res == -1) return false;
    return true;
}

// Company Tags: Amamzon, Walmart