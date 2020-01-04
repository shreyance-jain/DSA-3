/* 
Tree from Postorder and Inorder

Difficulty: Medium
Problem Statement

Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively.
The task is to construct the binary tree from these traversals.

For example,
if given inorder and postorder traversals are {4, 8, 2, 5, 1, 6, 3, 7} and {8, 4, 5, 2, 6, 7, 3, 1}  respectively,
then your function should construct below tree.

          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8

Input Format:
First line of input contains number of testcases T.
For each testcase, first line of input contains number of nodes in the tree,
and next two lines contains inorder and postorder respectively.

Output Format:
For each testcase, print the preorder traversal of tree.

Constraints:
1 <= T <= 30
1 <= N <= 103
1 <= in[i], post[i] <= 103

Example:
Input:
2
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1
5
9 3 2 5 4
5 9 3 4 2

Output:
1 2 4 8 5 3 6 7
2 9 5 4 3

Explanation:
Testcase 1:
          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8
 */

/* program to construct tree using inorder and postorder traversals */
#include<bits/stdc++.h>
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


/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node)
{
  if (node == NULL)
     return;
   /* then print the data of node */
  printf("%d ", node->data);
  /* first recur on left child */
  preOrder(node->left);
  /* now recur on right child */
  preOrder(node->right);
}

int search(int in[], int strt, int end, int value);
Node *buildTree(int in[], int post[], int n);


int main()
{
	int t,n;
	cin>>t;
	int in[1000], post[1000];
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>in[i];
		for(int i=0;i<n;i++)
			cin>>post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
		cout<<endl;
	}
	return 0;
}

/* Approach: is to see, construct some trees on paper using postorder and inorder traversals
and we would observe, how to construct the same
Let us see the process of constructing tree from in[] ={4, 8, 2, 5, 1, 6, 3, 7} and 
post[] = {8, 4, 5, 2, 6, 7, 3, 1}


Input : 
in[]   = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1} 

Output : Root of below tree
          1
       /     \
     2        3
   /    \   /   \
  4     5   6    7
    \
      8


1. We find the last node in post[]. The last node is 1, we know this value is root
as root always appear in the end of postorder traversal

2. We search 1 in in[], to find left and right subtrees of root. Everything on left of 1
in in[] is left subtree and everything on right is in right subtree
           1
         /    \
[4, 8, 2, 5]   [6, 3, 7] 

3. We recur the above process for the following two:
...b) Recur in in[] = {6, 3, 7} and post[] = {6, 7, 3}
.... Make the created tree as right child of root
….a) Recur for in[] = {4, 8, 2, 5} and post[] = {8, 4, 5, 2}.
…….Make the created tree as left child of root.

One important observation is, we recursively call for right subtree before
left subtree as we decrease index of postorder index when we create a new node

Basically we pick root from postorder one by one
we traverse the postorder[] from last, pick root
search it in inorder[] pick the next root from postorder[]
figure out from inorder[] whether it will be in left subtree or
right subtree for the current root
*/

/* Recursive function to construct binary tree of n nodes from 
inorder traversal in[] and postorder traversal post[].
Initial values of inStrt and inEnd be 0 and n-1.
The function doesn't to do any error checking for cases when inorder
and pre-order doesn't form a tree*/
Node *cTree(int in[], int post[], int inStrt, int inEnd, int *postIndex, unordered_map<int, int> &m) {

    // base case
    if (inStrt > inEnd) return NULL;
    
    // pick the current node from postorder traversal using postIndex
    // and decrement postIndex
    Node *root = new Node(post[*postIndex]);
    (*postIndex)--;
    
    // if this node has no children the return
    if (inStrt == inEnd)
        return root;

    // else find index of this node in Inorder traversal
    int inIndex  = m[root->data];
    
    // using index in inorder traversal, construct right and left subtrees
    root->right = cTree(in, post, inIndex + 1, inEnd, postIndex, m);    
    root->left = cTree(in, post, inStrt, inIndex - 1, postIndex, m);
    
    return root;
}


// This function mainly initialises index of root and calls buildUtil()
Node *buildTree(int in[], int post[], int n)
{
    int postIndex = n - 1;
    int is = 0, ie = n -1;

    // store index of inorder for node value, so we can quicky find later
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
        m[in[i]] = i;

    Node *head = cTree(in, post, is, ie, &postIndex, m);
    return head;
}


// Time Complexity: O(n)

// Company Tags: Adobe, Amazon, Hike
