/* 
Convert Level Order Traversal to BST

Difficulty: Medium
Problems

Given an array of size N containing level order traversal of a BST.
The task is to complete the function constructBst(),
that construct the BST (Binary Search Tree) from its given level order traversal.

Input:
First line of input contains number of testcases T.
For each testcase, first line contains number of elements and
next line contains n elements which is level order travesal of a BST.

Output:
For each test return the pointer to the root of the newly constructed BST.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
9
7 4 12 3 6 8 1 5 10
6
1 3 4 6 7 8

Output:
7 4 3 1 6 5 12 8 10
1 3 4 6 7 8

Explanation:
Testcase 1: After constructing BST, the preorder traversal of BST is 7 4 3 1 6 5 12 8 10.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}

// Structure formed to store details of the ancestor
struct NodeDetails {
  Node *node;
  int min, max;
  NodeDetails(Node *n, int mi, int mx) {
      node = n;
      min = mi;
      max = mx;
  }
};


/* Approach:
The idea is to make a struct element NodeDetails
which contains pointer to the node, minimum data and maximum data of the ancestor.
Now:
- Push the root node to the queue of type NodeDetails
- Extract NodeDetails of a node from the queue and compare them with minimum and maximum values
- Check whether there are more elements in arr[] and arr[i] can be the left child of 'temp.ptr' or not
- Check wheter there are more elements in arr[] and arr[i] can be the right child of 'temp.ptr' or not
- End the loop when the queue becomes empty
 */
Node* constructBst(int arr[], int n)
{
    if (n == 0)
        return NULL;
    
    queue<NodeDetails *> q;
    Node *root = new Node(arr[0]);
    // Node Details for root of bst
    NodeDetails *nodeDetails = new NodeDetails(root, INT_MIN, INT_MAX);
    
    Node *node = root;
    q.push(nodeDetails);
    
    // index variable to access array elements
    int i = 1;
    int min, max;
    // until there are no more elements in arr[]
    while(i < n) {
        // extracting node details of a node from the queue
        nodeDetails = q.front();
        q.pop();
        
        node = nodeDetails->node;
        min = nodeDetails->min;
        max = nodeDetails->max;
        
        Node *temp = new Node(arr[i]);
        NodeDetails *detail;
        
        // check whether arr[i] can be the left child of node
        if (arr[i] < node->data && arr[i] > min) {
            detail = new NodeDetails(temp, min, node->data);
            q.push(detail);
            node->left = temp;
            i++;
        }
        // check whether there are more elements in arr[] and arr[i] can be the right child of node
        if (i < n && arr[i] > node->data && arr[i] < max) {
            temp = new Node(arr[i]);
            detail = new NodeDetails(temp, node->data, max);
            q.push(detail);
            node->right = temp;
            i++;
        }
    }
    // root of the required BST
    return root;
}

// Time Complexity: O(n)
// Space Complexity: O(n), worst case in complete bst