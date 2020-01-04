/* 
Maximum difference between node and its ancestor

Difficulty: Medium
Problem Statement

Given a Binary Tree you need to find maximum value which you can get by
subtracting value of node B from value of node A,
where A and B are two nodes of the binary tree and A is an ancestor of B.
You are required to complete the function maxDiff.

Input:
The task is to complete the function maxDiff which takes 1 argument, root of the Tree.
The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return an integer denoting the maximum difference.

Constraints:
1 <= T <= 100
1 <= Number of edges <= 1000
0 <= Data of a node <= 1000

Example:
Input:
1
2
5 2 L 5 1 R

Output:
4

Explanation:
Testcase 1:

             5
           /    \
         2      1
The maximum difference we can get is 4, which is bewteen 5 and 1.
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

int maxDiff(Node *root);

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
    cout<<maxDiff(root)<<endl;
 }
  return 0;
}

/* Approach is same
Traverse tree in bottom up fashion
At every node return least of left value, right value and node value
Use this value to calculate maxdiff with current node and update maxdiff
 */
int diff_using_min(Node *root, int *maxDiff) {
    if (root == NULL)
        return INT_MAX;
    
    int lMin = diff_using_min(root->left, maxDiff);
    int rMin = diff_using_min(root->right, maxDiff);
    
    *maxDiff = max(root->data - min(lMin, rMin), *maxDiff);
    
    return min(min(lMin, rMin), root->data);
}

int maxDiff(Node* root)
{
    int maxDiff = INT_MIN;
    int m = diff_using_min(root, &maxDiff);
    return maxDiff;
}

// Time Complexity: O(n)
// Company Tags: Amazon