/* 
Vertical Width of a Binary Tree

Difficulty: Easy
Problem Statement

Given a Binary Tree of N nodes. The task is to find the vertical width of the tree.

The width of a binary tree is the number of vertical paths in that tree.

The above tree contains 6 vertical lines which is the required vertical width of the tree.

Input:
First line of input contains number of testcases T.
For each testcase, there will be two lines,
first of which containing the number of edges (between two nodes) in the tree.
Next line contains N pairs (considering a and b) with a 'L' (means node b on left of a) or 'R'
(means node b on right of a) after a and b.

Output:
For each test case, there will be a single line of output containing the vertical widht of the binary tree.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
3
8
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 6 8 R 7 9 R
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

Output:
6
3
4
 */


#include <bits/stdc++.h>
using namespace std;

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

int verticalWidth(Node* root);

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
     cout<<verticalWidth(root)<<endl;
  }
  return 0;
}
/* we use the approach for printing vertical view of binary tree
we pass Horizontal distance (hd) for root is 0
recur for left sub-tree and right sub-tree
For left sub-tree we pass hd as hd of root - 1
For right sub-tree we pass hd as hd of root + 1
We maintain min and max variables to store left most and right most hd
 */
void getWidthUtil(Node *node, int *min, int *max, int hd) {
    if (node == NULL)
        return;
        
    if (*min > hd)
        *min = hd;
    else if (*max < hd)
        *max = hd;
    getWidthUtil(node->left, min, max, hd - 1);
    getWidthUtil(node->right, min, max, hd + 1);
} // note: we are doing preorder, inorder or postorder traversals would also be same

int verticalWidth(Node* root)
{
    int min = 0, max = 0;
    int hd = 0;
    // get min and max hd from root
    getWidthUtil(root, &min, &max, hd);
    return max - min + 1;
}
