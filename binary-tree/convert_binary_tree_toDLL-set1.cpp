/* 
Binary Tree to DLL

Difficulty: Hard
Problem Statement

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place.
The left and right pointers in nodes are to be used as previous and next pointers
respectively in converted DLL.
The order of nodes in DLL must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

Input Format:
The input contains T, denoting number of testcases.
For each testcase there will be two lines. The first line contains number of edges.
The second line contains two nodes and a character separated by space.
The first node denotes data value, second node denotes where it will be
assigned to the previous node which will depend on character 'L' or 'R'
i.e. the 2nd node will be assigned as left child to the 1st node if character is 'L' and so on.
The first node of second line is root node.
The struct or class Node has a data part which stores the data,
pointer to left child and pointer to right child.
There are multiple test cases. For each test case, the function will be called individually.

Output Format:
For each testcase, in a new line, print front to end and back to end traversals of DLL.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

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
Testcase1: The tree is
        1
     /      \
   3       2
So, DLL would be 3<=>1<=>2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, DLL would be 40<=>20<=>60<=>10<=>30.
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

// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void bToDLL(Node *root, Node **head_ref);

/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}

/* Driver program to test size function*/
int main()
{
  int t;
  cin >> t;
  
  while (t--)
  {
    map<int, Node*> m;
    int n;
    cin >> n;
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
     Node *head = NULL;
     bToDLL(root, &head);
     printList(head);
  }
  return 0;
}

/* This solution is simplest of all, 
The idea is to inorder travrersal of binary tree. While doing inorder traversal,
keep track of previous visited node in a variable say prev.
For every visited node, make it next of prev and previous of this node as prev */
void convert(Node *root, Node **head_ref, Node **prev) {

    // base case
    if (root == NULL) return;
    
    // recur left
    convert(root->left, head_ref, prev);
    
    // convert this node
    if (*prev == NULL) { // this condition will only be true for the leftmost node, so update head
        *head_ref = root;
    } else {
        (*prev)->right = root;
        root->left = *prev;
    }
    
    // update prev
    *prev = root;
    
    // recur for left
    convert(root->right, head_ref, prev);
}

// to maintain prev pointer we update it with root every time
void bToDLL(Node *root, Node **head_ref)
{
    Node *prev = NULL;
    convert(root, head_ref, &prev);
}

// Time Complexity: The program does a simple inorder traversal, and at every node does constant work
// so time complexity is O(n), where n is the number of nodes

// Company Tags: Accolite, Amazon, Goldman Sachs, Microsoft, Morgan Stanley, Salesforce, Snapdeal
