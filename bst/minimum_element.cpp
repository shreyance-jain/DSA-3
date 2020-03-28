/* 
Minimum element in BST

Difficulty: Basic
Problem Statement

Given an array of size N which represents the elements to be inserted into BST
(considering first element as root).
The task is to find the minimum element in this given BST.
If the tree is empty, there is no minimum elemnt, so print -1 in that case.

Input:
First line of input contains the number of test cases T. 
For each test case, there will be only a single line of input 
which is a string representing the tree as described below: 
The values in the string are in the order of level order traversal of the tree where, 
numbers denotes node values, and a character “N” denotes NULL child.
For example:
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase in new line, print the minimum element in BST.

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
6
5 4 3 6 7 1
3
9 10 11
Output:
1
9

Explanation:
Testcase 1: We construct the following BST by inserting given values one by one in an empty BST.
            5
          /     \
       4         6
     /              \
   3                7
   /
 1

The minimum value in the given BST is 1.
Testcase 2: We construct the following BST by inserting given values one by one in an empty BST.
             9
                \
                10
                    \
                    11
The minimum value in the given BST is 9.
 */

// Driver Code
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

int minValue(Node *root);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        cout <<minValue(root) << endl;
    }
    return 1;
}

// Function to find minimum value in a BST
int minValue(Node* root)
{
    // base case
    if (root == NULL)
        return -1;
    
    Node *curr = root;

    // go till left node is not equal to NULL
    while(curr->left != NULL)
        curr = curr->left;
        
    return curr->data;
}

// Time Complexity: O(h)
// Space Complexity: O(1)

// Company Tags: Microsoft
