/* 

Check for BST

Difficulty: Medium
Problem Statement

Given a binary tree, return true if it is BST, else false.
For example, the following tree is not BST, because 11 is in the left subtree of 10.
The task is to complete the function isBST() which takes one argument, root of Binary Tree.

        10
     /     \
   7       39
     \
      11

The first line of input contains the number of test cases T.
Each test case contains a string representing the tree as described below: 
The values in the string are in the order of level order traversal of the tree where,
numbers denote node values, and a character “N” denotes NULL child.
For example:  
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should return 1 if BST else returns 0.

Constraints:
1 <= T <= 10
0 <= Number of edges <= 100000

Example:
Input:
2
2 1 3
2 N 7 N 6 N 5 N 9 N 2 N 6
Output:
1
0

Explanation:
Testcase 1: The given binary tree is a BST, hence the answer is 1.
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
   int data;
   Node* left;
   Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;

   return temp;
}



bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = newNode(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    cout << isBST(root) << endl;
   }
   return 0;
}

/* Approaches:
Approach 1: A simple but wrong approach
Do any traversal. For every node check if leftchild is smaller and rightchild is greater
This approach does not work as it simply check only for consecutive nodes and not for nodes
which are at a distance of 2 or more

Approach 2: Correct but inefficient
For every node,
1. Find the maximum in left subtree
2. Find the minimum in right subtree
3. Check if current node is greater than maximum and smaller than minimum
Time Complexity: O(n^2)

Approach 3: Interesting tricky and simple solution
- Pass a range for every node
- For root, range is INT_MIN to INT_MAX
- For left child of a node, in range, we change upper bound of the node's value
- For right child of a node, in range, we change lower bound to a node's value
 */
// APPROACH 3
/* So, the root has to follow this property and similarly,
recusively it has to be true for the left subtree and it has to be true for the right subtree
NOTE: 
When we call left  -> change max value
When we call right -> change min value*/
bool checkBST(Node *root, int min, int max) {
    if (root == NULL)
        return true;
    
    return root->data > min && 
            root->data < max &&
            checkBST(root->left, min, root->data) &&
            checkBST(root->right, root->data, max);
}

// default function defination is question, use it as a wrapper for required function
// by calling the function in it and passing the initial range values for root
bool isBST(Node* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}

/* Time Complexity: It simply traverses the tree O(n)
We can consider this kind of preorder traversal, check for root than for LST and RST
NOTE: The logical & opreator has short-circuiting so it is optimised automatically */
// Space Complexity: O(h) same as inorder traversal, where h is the height of given tree */

// Company Tags: Accolite, Adobe, Amazon, Boomerang Commerce, FactSet, Flipkart, Goldman Sachs,
// GreyOrange, Hike, LinkedIn, MakeMyTrip, MAQSoftware, Ola Cabs, OYO Rooms, Qualcomm, Samsung,
// Snapdeal, VMWare, Walmart, Wooker