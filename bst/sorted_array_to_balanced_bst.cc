/* 
Sorted Array to Balanced BST
Given a sorted array.
Write a function that creates a Balanced Binary Search Tree using array elements.
Examples:

Input:  Array {1, 2, 3}
Output: A Balanced BST
     2
   /  \
  1    3 

Input: Array {1, 2, 3, 4}
Output: A Balanced BST
      3
    /  \
   2    4
 /
1
 */

/* Approach:
If we have all the elements before hand construction of BST is pretty simple
We can sort the elements, pick the middle element, the elements to left of middle lies in LST
and the elements to the right of this middle element lie in the RST
Then we can recur similarly in left half and right half

Algo:
1. Get the middle element of the array and make it the root
2. Recusively do same for the left and right half
  a) Get the middle element of the left half and make it left child of the root created in step 1
  b) Get the middle element of the right half and make it right child of the root created in step 1
 */

#include <iostream>
using namespace std;

/* A Binary Tree node */
class TNode {
  public:
  int data;
  TNode *left;
  TNode *right;
};

/* Helper function that allocates a new node  
with the given data and NULL left and right  
pointers. */
TNode* newNode(int data)  
{  
    TNode* node = new TNode(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
  
    return node;  
} 

/* A utility function to print 
preorder traversal of BST */
void preorder(TNode *node) {
  if (node == NULL)  
        return;  
    cout << node->data << " ";  
    preorder(node->left);  
    preorder(node->right);  
}

TNode *sortedArrayToBalancedBST(int arr[], int start, int end) {
  // base case
  if (start > end)
    return NULL;
  
  /* Get the middle element and make it root */
  int mid = (start + end) / 2;
  TNode *root = newNode(arr[mid]);

  /* Recursively construct the left subtree  
    and make it left child of root */
  root->left = sortedArrayToBalancedBST(arr, start, mid-1);

  /* Recursively construct the right subtree  
    and make it right child of root */
  root->right = sortedArrayToBalancedBST(arr, mid+1, end);

  return root;
}

// Driver Code
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
      cin >> arr[i];
    TNode *root = sortedArrayToBalancedBST(arr, 0, n-1);
    preorder(root);
    cout << endl;
  }
  return 0;
}


/*
Time Complexity: O(n)
Space Complexity: O(logn) as h is logn for balanced bst, required for function call stack
Following is the recurrence relation for sortedArrayToBST
  T(n) = 2T(n/2) + C
  T(n) ---> Time taken for an array of size n
  C --> Constant(Finding middle of the array and linking root to left and right subtrees takes constant time)
 */

// Company Tags: Amazon, Cisco, Snapdeal, VMWare
