/* 
ZigZag Tree Traversal

Difficulty: Easy
Problem Statement

Given a binary tree of size N, your task is to complete the function zigZagTraversal(),
that prints the nodes of binary tree in ZigZag manner.

For Example:
For the below binary tree the zigzag order 
traversal will be 1 3 2 7 6 5 4.

Input:
The function takes a single argument as input, the reference pointer to the root of the binary tree.
There will be T testcases and for each test case the function will be called separately.

Output:
For each test case print on a new line space separated all the nodes of the tree in ZigZag manner.

Constraints:
1<=T<=500
1<=N<=1000

Example:

Input:
1
10

1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 4 8 L 5 9 R 6 10 L 7 11 R
Output:
1 3 2 4 5 6 7 11 10 9 8
*/


//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void zigZagTraversal(Node* root);

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
     struct Node *root = NULL;
     struct Node *child;
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
     zigZagTraversal(root);
     cout << endl;
  }
  return 0;
}

/* Recursive function to find height of binary tree */
int heightOfTree(Node *root) {
    if (root == NULL)
        return 0;
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    
    return max(lh, rh) + 1;
}

/* Recursive function to print nodes from left to right of a given level */
void printLeftToRight(Node *root, int level) {
    if (root == NULL)
        return;
    
    if (level == 1)
        cout << root->data <<  " ";
    
    printLeftToRight(root->left, level - 1);
    printLeftToRight(root->right, level - 1);
}

/* Recursive function to print nodes from right to left of a given level */
void printRightToLeft(Node *root, int level) {
    if (root == NULL)
        return;
    
    if (level == 1)
        cout << root->data << " ";
    printRightToLeft(root->right, level - 1);
    printRightToLeft(root->left, level -1);
}

/* Recursive Approach: The idea it to traverse the tree in a Level Order manner but in a
slighlty different manner
We will use the variable flag and initially set it's value to zero
As we complete the level order traversal of the tree, from right to left we will set
the value of flag as one, so that we can traverse the tree from left to right
and as we complete the traversal we will set it's value back to zero
We will repeat this process until we have traversed the binary tree completely   */
void zigZagTraversal(Node* root)
{
    // flag is used to mark change in level
    bool leftToRight = 1;

    // height of tree
    int height = heightOfTree(root);
    
    for(int i = 1; i <= height; i++) {
        // if flag set
        if (leftToRight)
            printLeftToRight(root, i);
        else
            printRightToLeft(root, i);
        
        // toggle flag
        leftToRight = !leftToRight;
    }
    cout << endl;
}

// Time Complexity: Theta(h * n), O(n ^ 2) in worst case if tree is skew
// Space Complexity: O(n) fn call stack

// Company Tags: Amazon, Cisco, FaceSet, Hike, Snapdeal, Walmart
