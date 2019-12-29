/*
Mirror Tree

Difficulty: Easy
Problem Statement

Given a Binary Tree, convert it into its mirror.
MirrorTree1            

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains two lines of input. The first line contains number of edges.
The second line contains relation between nodes.

Output Format:
For each testcase, in a new line, print inorder traversal of mirror tree.

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
2 1 3
30 10 60 20 40

Explanation:
Testcase1: The tree is
        1         (mirror)     1
     /      \         =>        /     \
   3       2                  2         3
The inorder of mirror is 2 1 3
Testcase2: The tree is
                           10                                      10
                        /        \           (mirror)         /        \
                     20         30            =>        30        20
                  /       \                                              /    \
               40       60                                        60    40
The inroder traversal of mirror is 30 10 60 20 40. 
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

void mirror(struct Node* node);

/* Helper function to test mirror().*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}

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
     mirror(root);
     inOrder(root);
     cout << endl;
  }
  return 0;
}

/* Approach:
1. Swap left and right sub tree
2. Call for left subtree
3. Call for right subtree */
void mirror(Node* node) 
{
    if (node == NULL)
        return;
    // swap pointers of this node
    // Note: we avoid creating a function for swap which allows us to keep code simple
    // as now we dont't need to deal with pointers to pointers
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
    
    // recur for left and right subtree
    mirror(node->left);
    mirror(node->right);
} // note we have to swap pointes of each node, so we can make either tail recursive or head recursive
// it will make no difference in end

// We can do this iteratively by doing level order traversal using queue
// while doing traversal swap left and right children of every node

// Time Complexity: Same as traversal O(n)
// Space Complexity: Same as traversal O(height)

// Company Tags: Accolite, Adobe, Amazon, Belzabar, eBay, Goldman Sachs, Microsoft, Morgan Stanley
//  Myntra, Ola Cabs, Paytm, PropTiger, Samsung, SAP Labs, Snapdeal, VMWare, Walmart
