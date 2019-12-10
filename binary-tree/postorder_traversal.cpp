/* 
Postorder Traversal

Difficulty: Basic
Problem Statement

Given a binary tree, print postorder traversal of it. Postorder traversal of below tree is 5 10 39 1

        1
     /     \
   10     39
  /
5

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains two lines of input. The first line contains number of edges.
The second line contains the connections between the nodes.

Output Format:
For each testcase, in a new line, print the postorder traversal.

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
3 2 1
40 60 20 30 10

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the postorder would be 3 2 1
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the postorder would be 40 60 20 30 10.
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
/* Computes the number of nodes in a tree. */
void postOrder(struct Node* root);

/* Driver program to test function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     postOrder(root);
     cout << endl;
  }
  return 0;
}

void postOrder(Node* root)
{
  if (root == NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

// Company Tags: Morgan Stanley, Snapdeal, Walmart