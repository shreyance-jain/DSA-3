/* 
Delete a node from BST

Difficulty: Medium
Problem Statement

Given a Binary Search Tree (BST) and a node no 'x', your task is to delete the node 'x' from the BST.
If no node with value x exists then, do not make any changes

Input Format:
The first line of input contains the number of test cases T. For each test case, there will two lines. 
First line of input is a string representing the tree as described below: 
The values in the string are in the order of level order traversal of the tree where,
numbers denote node values, and a character “N” denotes NULL child.
For example:
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N
Second-line is an integer represents K

Output Format:
For each test case, driver code will return the inorder traversal of the modified root.

Constraints:
1 <= T <= 10
1 <= N <= 100000

Example:
Input:
2
2 1 3 N N N N
12
1 N 2 N 8 5 11 4 7 9 12
9
Output:
1 2 3
1 2 4 5 7 8 11 12

Note: The Input/Output format and Example are given are used for the system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.
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



struct Node* deleteNode(struct Node* root, int key);

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
    Node* root1 = buildTree(s);
    getline(cin, s);
    int k = stoi(s);
    root1  = deleteNode(root1, k);
    vector<int> v;
    inorder(root1, v);
    for(auto i:v)
        cout << i << " ";
    cout << endl;
   }
   return 0;
}

/* Approach:
When we delete a node, three possibilities arise.
1) Node to be deleted is leaf: Simply remove from the tree.

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80

2) Node to be deleted has only one child: Copy the child to the node and delete the child

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70 
            \    /  \                          /  \ 
            40  60   80                       60   80

3) Node to be deleted has two children: Find inorder successor of the node.
Copy contents of the inorder successor to the node and delete the inorder successor.
Note that inorder predecessor can also be used.
              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70 
                 /  \                            \ 
                60   80                           80
 */

// this function will give the required result
// as we are confirmed the root has a right child
Node *getInorderSuccessor(Node *root) {
    Node *curr = root->right;
    while(curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node *deleteNode(Node *root,  int x)
{
    // base case
    if (root == NULL)
        return root;
    
    // if key to be deleted is smaller than root
    // it lies in left subtree
    if (root->data > x)
        root->left = deleteNode(root->left, x);
    // if key is greater than root, it lies in right subtree
    else if (root->data < x)
        root->right = deleteNode(root->right, x);
    // if key is same as root's key, this is the node to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // node with two children
        else { 
            // get the inorder successor:
            // (smallest in right subtree or in other words left most child of root's right child)
            Node *succ = getInorderSuccessor(root);
            // copy successor data in root
            root->data = succ->data;
            // call delete for sucessor in right subtree which would be a leaf node
            // as inorder successor in this case (right child exists)
            // would be the left most node of the right child
            root->right = deleteNode(root->right, succ->data);
        }
    }
    // if not returning from else part to do linking/make back links
    return root;
}

/*Time Complexity: Time complexity of delete operation is O(h) where h is height of binary tree
In worst case we may have to travel from root to deepest leaf node
The height of the skewed tree may become n and the compelxity of delete operation may become O(n)*/

// Company Tags: Accolite, Adobe, Amazon, Qualcomm, Samsung
