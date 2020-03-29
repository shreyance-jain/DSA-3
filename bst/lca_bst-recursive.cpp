/* 
Lowest Common Ancestor in a BST

Difficulty: Easy
Problem Statement

Given a Binary Search Tree of size N and 2 nodes value n1 and n2,
your task is to find the lowest common ancestor(LCA) of the two nodes .
Note: Duplicates are not inserted in the BST.

Input Format:
First line of input contains the number of test cases T. For each test case, there will be two line of input.
First line is a string representing the tree as described below and
second line contains two space seperated integers N1 and N2: 
The values in the string are in the order of level order traversal of the tree where,
numbers denotes node values, and a character “N” denotes NULL child.
For example:
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output Format:
For each testcase, in a new line, print the LCA of n1 and n2.

Constraints:
1 <= T <= 100
1 <= N <= 104
Example:
Input
2
5 4 6 3 N N 7 N N N 8
7 8
2 1 3
1 3
Output 
7
2

Explanation:
Testcase1:
The BST in above test case will look like
    5
   /  \ 
  4  6
 /      \
3        7
            \ 
             8
here the LCA of 7 and 8 is 7
 */
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

Node* LCA(Node * root , int l , int h);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        cout<<LCA(root ,  l ,  h)->data<<endl;
    }
    return 1;
}

/* 
If we are given a BST where every node has parent pointer,
then LCA can be easily determined by traversing up using
parent pointer and printing the first intersecting node.

We can solve this problem using BST properties. We can recursively traverse the BST from root.
The main idea of the solution is, while traversing from top to bottom,
the first node n we encounter with value between n1 and n2,
i.e., n1 < n < n2 or same as one of the n1 or n2, is LCA of n1 and n2 (assuming that n1 < n2).
So just recursively traverse the BST in,
if node’s value is greater than both n1 and n2 then our LCA lies in left side of the node,
if it’s is smaller than both n1 and n2, then LCA lies on right side.
Otherwise root is LCA (assuming that both n1 and n2 are present in BST)
 */
Node* LCA(Node *root, int n1, int n2)
{
    // this null check is not reachable as we are assuming both are present
    if (root == NULL)
        return NULL;
    // If both n1 and n2 are smaller than root, then LCA lies in left 
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    // If both n1 and n2 are greater than root, then LCA lies in right 
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    return root;
}

/* 
Following is definition of LCA from Wikipedia:
Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined
as the lowest node in T that has both n1 and n2 as descendants
(where we allow a node to be a descendant of itself).

The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root.
Computation of lowest common ancestors may be useful, for instance,
as part of a procedure for determining the distance between pairs of nodes in a tree:
the distance from n1 to n2 can be computed as the distance from the root to n1,
plus the distance from the root to n2,
minus twice the distance from the root to their lowest common ancestor.
 */

// Time Complexity: O(h)
// Auxiliary Space Complexity: O(h) for function call stack

// Company Tags: Accolite, Amazon, Flipkart, MAQ Software, Microsoft, Samsung, Synopsys
