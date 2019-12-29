/*
Diameter of Binary Tree

Difficulty: Easy
Problem Statement

Given a Binary Tree, find diameter of it.
+The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains two lines of input. The first line contains number of edges.
The second line contains the relation between nodes.

Output Format:
For each testcase, in a new line, print the diameter.

Constraints:
1 <= T <= 30
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
3
4

Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
The diameter is of 3 length.
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
The diameter is of 4 length.
 
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

/* Function to get diameter of a binary tree */
int diameter(struct Node * tree);

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
     cout << diameter(root) << endl;
  }
  return 0;
}

/* 
Approach: Take some(may be 1) examples and observe the patter
Diameter can be calculated using height function
Diameter will be max value of (lh + rh + 1)
 */
int height(Node *node, int *dia) {
    if (node == NULL)
        return 0;
    int lh = height(node->left, dia);
    int rh = height(node->right, dia);
    
    // dia is no of nodes
    *dia = max(lh + rh + 1, *dia);
    
    return max(lh, rh) + 1;
}

int diameter(Node* node)
{
    int dia = 0;
    height(node, &dia);
    return dia;
}

// Time Complexity: Simple traversal O(n)
// Aux Space Complexity: O(height)

// Company Tags: Amazon, Cadence India, Directi, MakeMyTrip, Microsoft, Oracle, OYO Rooms,
// Phillips, PropTiger, Salesforce, Snapdeal, VMWare
