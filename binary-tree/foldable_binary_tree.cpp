/* 
Foldable Binary Tree

Difficulty: Medium
Problem Statement

Given a binary tree, check if the tree can be folded or not.
A tree can be folded if left and right subtrees of the tree are structure wise same.
An empty tree is considered as foldable.
Consider the below trees:
(a) and (b) can be folded.
(c) and (d) cannot be folded.

(a)
       10
     /    \
    7      15
     \    /
      9  11
(b)
        10
       /  \
      7    15
     /      \
    9       11
(c)
        10
       /  \
      7   15
     /    /
    5   11
(d)
         10
       /   \
      7     15
    /  \    /
   9   10  12

Input:
First line of input contains number of testcases T. For each testcase,
there will be two lines, first of which containing the number of edges (between two nodes) in the tree.
Next line contains N pairs (considering a and b) with
a 'L' (means node b on left of a) or 'R' (means node b on right of a) after a and b.

Output Format:
Print "Yes" (without quotes) if the tree is foldable and "No" ( without quotes) if it is unfoldable.

Constraints:
1 <= T <= 100
1 <= n <= 103
1 <= data of node <= 104

Example:
Input:
2
4
10 7 L 7 9 R 10 15 R 15 11 L
4
10 7 L 7 5 L 10 15 R 15 11 L

Output:
Yes
Nos
 */


#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};

/* converts a tree to its mrror image */
void mirror(struct node* node);

/* returns true if structure of two trees a and b is same
Only structure is considered for comparison, not data! */
bool isStructSame(struct node *a, struct node *b);

/* Returns true if the given tree is foldable */
bool isFoldable(struct node *root);

/* UTILITY FUNCTIONS */
/* Change a tree so that the roles of the left and
	right pointers are swapped at every node.
	See http://www.geeksforgeeks.org/?p=662 for details */
void mirror(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        struct node *temp;
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new node(n2);
                    break;
          case 'R': root->right=new node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
}

/* Driver program to test mirror() */
int main(void)
{
/* The constructed binary tree is
		1
	/ \
	2	 3
	\ /
	4 5
*/
int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new node(n1);
            switch(lr){
                    case 'L': root->left=new node(n2);
                    break;
                    case 'R': root->right=new node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    if (isFoldable(root) == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    getchar();
    }
    return 0;
}

/* Approach here is:
If left of node is present then right of node should be present for tree to be foldable
If left of left node is present then right of right node should be present 
Similarly, if right of left node is present then left of right node should be present


And we will recur, so if we think on root level if left of root is present then right should be present
and it should be tree from left as well as right node/subtree

Now technically: what we are doing above can be written as
We check if left and right subtree are structure wise mirror then tree is foldable

Algo:
There are mainly two functions:

// check if tree can be folded or not
isFoldable(root) 
1. If tree is empty return true
2. Else check if left and right subtree are structure wise mirrors of each other
Use utility function isFoldableUtil(root->left, root->right) for this.

// check if n1 and n2 are mirror of each other
1. If both trees are empty then return true
2. If one of them is empty and other is not return false
3. Return true if following conditions are met
    a. n1->left is mirror of n2->right
    b. n1->right is mirror of n2-left
*/

/* A utlity function which checks if trees with roots n1 and n2
are mirrors of each other */
bool isFoldUtility(node *left, node *right) {
    // if left is present in lst
    // the right should be present in rst
    
    // if both left and right subtrees are NULL return true
    if (left == NULL && right == NULL)
        return true;
        
    // instead of thinking on child level now
    // think on root level
    // if one of these trees in NULL and other is not return false
    if (left == NULL || right == NULL)
        return false;
    
    // otherwise check is left and right subtrees are structurally mirror of their counterparts
    return (isFoldUtility(left->left, right->right) &&
            isFoldUtility(left->right, right->left));
}    

/* Returns true if given tree can be folded */
bool isFoldable(struct node *root)
{
    // base cases
    
    // if both are NULL
    if (root == NULL)
        return true;
    
    // if left present then right should be present and vice versa
    return isFoldUtility(root->left, root->right);
        
}