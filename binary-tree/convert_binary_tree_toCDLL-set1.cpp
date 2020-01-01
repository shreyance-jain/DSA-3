/* 
Binary Tree to CDLL

Difficulty: Medium
Problem Statement

Given a Binary Tree of N edges. =
The task is to convert this to a Circular Doubly Linked List(CDLL) in-place.
The left and right pointers in nodes are to be used as previous and next pointers
respectively in converted CDLL.
The order of nodes in CDLL must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.

Input Format:
First line of input contains number of testcases T. For each testcase,
there will be two lines, first of which containing the number of edges
(between two nodes) in the tree. Next line contains N pairs (considering a and b) with a 'L' 
(means node b on left of a) or 'R' (means node b on right of a) after a and b

Output Format:
For each testcase, in a new line, print the traversals of CDLL.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= Data of a node <= 104

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
Output:
3 1 2 
2 1 3
40 20 60 10 30 
30 10 60 20 40

Explanation:
Testcase 1: After converting tree to CDLL, when CDLL is is traversed
from head to tail and then tail to head, elements are displayed as in the output.
 */


#include<bits/stdc++.h>
using namespace std;

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

Node *bTreeToCList(Node *root);

/* Function to display circular linked list */
void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
	itr=itr->left;
	do{
		cout<<itr->data<<" ";
		itr=itr->left;
	}while(head!=itr);
	cout<<itr->data<<endl;
}

int main()
{
	int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
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
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    Node *head = bTreeToCList(root);
    displayCList(head); 
  }
    return 0;
}

/* This solution is simplest of all,
The idea is to do inorder traversal of binary tree. While doing inorder traversal,
keep track of previous visited node in a variable say prev
For every visited node, make it next of prev and previous of this node as prev */
void convert(Node *root, Node **head, Node **prev) {

    // base case
    if (root == NULL)
        return;
    
    // recursively convert left subtree
    convert(root->left, head, prev);
    
    // convert this node
    if (*prev == NULL) {
        *head = root; // this condition will only be true for leftmost node, udpate head
    } else {
        (*prev)->right = root;
        root->left = *prev;
    }
    
    // update prev
    *prev = root;
    
    // recur for right
    convert(root->right, head, prev);
    
}

/* Approach is same as to convert binay tree to circular linked list discussed in set -1 convert binary tree to dll
once converted, prev will be pointing to last node of linked list
just make circular link by linking prev(now at last node of linked list) and head(now atfirst node of linked list)
of created linked list */
Node *bTreeToCList(Node *root)
{
    Node *head = NULL;
    Node *prev = NULL;

    convert(root, &head, &prev);

    // set links between head and last node(pointed to by prev)
    prev->right = head;
    head->left = prev;
    return head;
}

// Time Complexity: The program does a simple inorder traversal, and at every node does constant work
// so time complexity is O(n), where n is the number of nodes

// Company Tags: Amazon, SAP Labs
