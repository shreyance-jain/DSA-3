/* 
Maximum Width of Tree

Difficulty: Easy
Problem Statement

Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains two lines of input. The first line contains number of edges.
The second line contains relation between the nodes.

Output Format:
For each testcase, in a new line, print the maximum width.

Constraints:
1 <= T <= 100
1 <= edges <= 100
1 <= nodes values <= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
2
2

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
The second level has 2 nodes and hence the width is 2.

Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
Both second and third level have 2 nodes and hence max width is 2.
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

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root);

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
     cout << getMaxWidth(root) << endl;
  }
  return 0;
}

int getMaxWidth(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int res = 0;
    while (q.empty() == false) {
        int count = q.size();
        res = max(count, res);
        for (int i = 0; i < count; i++) {
            Node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    return res;
}