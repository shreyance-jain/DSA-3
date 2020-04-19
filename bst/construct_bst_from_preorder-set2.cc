/* 
Construct BST from given preorder traversal 

Given preorder traversal of a binary search tree, construct the BST.
For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be root of following tree.
     10
   /   \
  5     40
 /  \      \
1    7      50
 */

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int x)
  {
    data = x;
    left = right = NULL;
  }
};

Node *constructTree(int arr[], int n);
void printPostorder(Node *root);

int main()
{
  // construct bst from preorder
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Node *root = constructTree(arr, n);
    printPostorder(root);
    cout << endl;
  }
  return 0;
}

void printPostorder(Node *root)
{
  if (root != NULL)
  {
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
  }
}

/* Approach 1: (based on construct tree from preOrder and postOrder)
O(n) Time complexity
The trick is to set a range {min...max} for every node. Initialise the range as {INT_MIN, INT_MAX}
The first node will definitely be in the range, so create root node.
To construct left subtree, set the range as {INT_MIN, root->data}
If a value is the this range then the value if part of left subtree.
To construct right subtree, set the range as {root->data, INT_MAX}
 */
Node *constructTreeUtil(int pre[], int *preIndex, int min, int max, int size)
{
  if (*preIndex >= size)
    return NULL;

  Node *root = NULL;
  // if the value is in range then count it in tree and recur for its left and right
  if (pre[*preIndex] > min && pre[*preIndex] < max) {
    root = new Node(pre[*preIndex]);
    (*preIndex)++;
    if (*preIndex < size) { // improvisation to avoid extra fn call on edge case
      root->left = constructTreeUtil(pre, preIndex, min, root->data, size);
      root->right = constructTreeUtil(pre, preIndex, root->data, max, size);
    }
  }// if not in range return NULL

  return root;
}

Node *constructTree(int pre[], int n)
{
  int preIndex = 0;
  Node *root = constructTreeUtil(pre, &preIndex, INT_MIN, INT_MAX, n);
  return root;
}

// Time complexity: O(n)
