/* 
Lowest Common Ancestor in a Binary Tree

Difficulty: Easy
Problem Statement

Given a Binary Tree and two nodes value n1 and n2.
The task is to find the lowest common ancestor of the given two nodes.

Input Format:
The input contains T, denoting number of testcases.
For each testcase there will be third lines.
The first line contains number of edges.
The second line contains relation between nodes.
The second line contains two nodes and a character separated by space.
The first node denotes data value, second node denotes where it will be assigned to the
previous node which will depend on character 'L' or 'R' i.e.
the 2nd node will be assigned as left child to the 1st node if character is 'L' and so on.
The third line contains two nodes separated by space for which you have to compute LCA.
The first node of second line is root node. The struct or class Node has a data part
which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, the function will be called individually.

Output Format:
For each testcase, in a new line, print the Lowest Common Ancestor of the two nodes.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input
2
2
1 2 L 1 3 R
2 3
3
5 2 L 2 3 L 2 4 R
3 4
Output 
1
2

Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
The LCA of 2 and 3 is 1.
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

Node * lca(Node* ,int ,int );
bool find(Node *root, int n, vector<Node *> &v);

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
     int a,b;
     cin>>a>>b;
     Node * k = lca(root,a,b);
     cout<<k->data<<endl;
  
  }
  return 0;
}

/* 
Approach: Start traversing tree from root
If any of the given keys(n1 and n2) matches with root, then root is LCA(assuming both keys are present)
If root does not match with any of the keys, we recur for left subtree and right subtree
The node which has one key present in its left sub-tree and other key present in its right sub-tree
is the LCA
If both nodes lies in left sub-tree, then left sub-tree has LCA also, otherwise
LCA lies in right sub-tree
 */
// function retrun LCA asssumes both nodes are present in tree
Node * lca(Node* root ,int n1 ,int n2 )
{
    if (root == NULL)
        return NULL;
        
    if (root->data == n1 || root->data == n2)
        return root;
        
    Node *left_lca = lca(root->left, n1, n2);
    Node *right_lca = lca(root->right, n1, n2);
    
    if (left_lca != NULL && right_lca != NULL)
        return root;
    
    return (left_lca != NULL ? left_lca : right_lca);
        
}

/* Note: Computation of lowest common ancestor(LCA) may be useful,
for instance, as part of a procedure for determining distance between pair of nodes in a tree
The distance from n1 to n2 can be computed as distance of n1 from root, plus
distance of n2 from root, minus double the distance of LCA from root */

// Time Complexity: O(n)
// Aux Space: O(height) for function call stack

// Company Tags: Accolite, Amazon, American Express, Cisco, Expedia, Flipkart, MakeMyTrip
// Microsoft, OYO Rooms, Paypal, Payu, Snapdeal, Times Internet, Twitter
