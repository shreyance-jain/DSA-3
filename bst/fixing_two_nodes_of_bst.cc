/* 
Fixing Two nodes of a BSTSubmissions: 11687   Accuracy: 50%   Difficulty: Hard   Marks: 8
Associated Course(s):   Interview Preparation   Geeks Classes More
              
Problems
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.

Input Format:
First line consists of T test cases. First line of every test case consists of N, denoting number of elements in BST. Second line of every test case consists 3*N elements 2 integers and a character

Note: It is guaranteed than the given input will form BST ,except for 2 nodes that will be wrong.

Output Format:
For each testcase, in a new line, print either 0 or 1.

Your Task:
You don't need to take any input. Just complete the function correctBst() that takes node as parameter. The corrected BST will then be checked internally.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
4
10 5 L 10 8 R  5 2 L 5 20 R
5
8 3 L 8 10 R 3 1 L 3 6 R 6 7 R

Output:
1
0 */

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

Node *NewNode(int data) {
  struct Node* Node = (struct Node *)malloc(sizeof(struct Node));
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  return (Node);
}

Node *correctBST(Node *);

void Inorder(Node *root) {
  if (root == NULL)
    return;
  Inorder(root->left);
  cout << root->data << " ";
  Inorder(root->right);
}

int flag = 1;
int c = 0;

void inorder(Node *temp, Node *root) {
  if (flag == 0)
    return;
  
  if (temp == NULL && root == NULL)
    return;
  
  if (root == NULL) {
    flag = 0;
    return;
  }

  if (temp == NULL) {
    flag = 0;
    return;
  }

  if (temp->data == root->data)
    c++;
  
  inorder(temp->left, root->left);
  inorder(temp->right, root->right);
}

void insert(Node *root, int a1, int a2, char lr) {
  if (root == NULL)
    return;
  
  if (root->data == a1) {
    switch (lr) {
      case 'L':
        root->left = NewNode(a2);
        break;
      case 'R':
        root->right = NewNode(a2);
    }
  }
  insert(root->left, a1, a2, lr);
  insert(root->right, a1, a2, lr);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    Node *root = NULL, *temp = NULL;
    int n;
    cin >> n;
    int m = n;
    while(n--) {
      int a1, a2;
      char lr;
      cin >> a1 >> a2 >> lr;
      if (root == NULL) {
        temp = NewNode(a1);
        root = NewNode(a1);
        switch (lr)
        {
        case 'L': root->left = NewNode(a2);
                  temp->left = NewNode(a2);
          break;
        case 'R': root->right = NewNode(a2);
                  temp->right = NewNode(a2);
          break;
        }
      } else {
        insert(root, a1, a2, lr);
        insert(temp, a1, a2, lr);
      }
    }
    flag = 1;
    c = 0;
    root = correctBST(root);
    inorder(temp, root);
    if (c + 1 == m) {
      cout << flag << endl;
    } else {
      cout << "0\n";
    }
  }
  return 0;
}


/* Approach:
We can solve this in O(n) time and with a single traversal of the given BST.
Since inorder traversal of BST is always a sorted array,
the problem can be reduced to a problem where two elements of a sorted array are swapped.

There arises two cases:
1. The swapped nodes are not adjacent in the inorder traversal of the BST.

 For example, Nodes 5 and 25 are swapped in {3 5 7 8 10 15 20 25}. 
 The inorder traversal of the given tree is 3 25 7 8 10 15 20 5 
If we observe carefully, during inorder traversal, we find node 7 is smaller than
the previous visited node 25.
Here save the context of node 25 (previous node).
Again, we find that node 5 is smaller than the previous node 20.
This time, we save the context of node 5 ( current node ).
Finally swap the two node’s values.

2. The swapped nodes are adjacent in the inorder traversal of BST.

  For example, Nodes 7 and 8 are swapped in {3 5 7 8 10 15 20 25}. 
  The inorder traversal of the given tree is 3 5 8 7 10 15 20 25 
Unlike case #1, here only one point exists where a node value is smaller
than previous node value. e.g. node 7 is smaller than node 8.
*/
void fixBST(Node *root, Node **prev, Node **first, Node **second) {
  if (root == NULL)
    return;
  fixBST(root->left, prev, first, second);
  if (*prev != NULL && root->data < (*prev)->data) {
    if (*first == NULL) {
      *first = *prev;
    }
    *second = root;
  }
  *prev = root;
  fixBST(root->right, prev, first, second);
}

Node *correctBST(Node *root) {
  Node *first = NULL, *second = NULL, *prev = NULL;
  fixBST(root, &prev, &first, &second);
  // bst is already correct
  if (first == NULL)
    return root;
  swap(first->data, second->data);
  return root;
}

// Time Complexity: Same as inorder, O(n)
// Space Complexity: Same as inorder, O(h)

// Company Tags: Amazon, BankBazaar, FactSet, Microsoft, Walmart
