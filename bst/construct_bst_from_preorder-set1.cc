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
O(n^2) complexity
The first element of preorder traversal will always be root. We first construct the root.
Then we find index of the first element greater than root. Let the index be 'i'.
The values between root and 'i' will be the part of left subtree, and 
the values between 'i+1' and 'n-1' will be part of right subtree

For example {10, 5, 1, 7, 40, 50}, 10 is the first element, so we make it root.
Now we look for the first element greater than 10, we find 40. So we structure of BST is as following
             10
           /    \
          /      \
  {5, 1, 7}       {40, 50}
We recursively follow above steps for subarrays {5,1 ,7} and {40, 50}, and get the complete tree
 */
Node *constructTreeUtil(int pre[], int *preIndex, int start, int end)
{
  if (start > end)
    return NULL;
  Node *root = new Node(pre[*preIndex]);

  int i;
  for (i = start + 1; i <= end; i++)
    if (pre[i] > pre[*preIndex])
      break;
  (*preIndex)++;
  root->left = constructTreeUtil(pre, preIndex, start + 1, i - 1);
  root->right = constructTreeUtil(pre, preIndex, i, end);
  return root;
}

Node *constructTree(int pre[], int n)
{
  int preIndex = 0;
  Node *root = constructTreeUtil(pre, &preIndex, 0, n - 1);
  return root;
}

// Time complexity: O(n^2), we traverse every value of array and search(for next greater element) takes n time

// improved complexity: O(n) - see in set-2
