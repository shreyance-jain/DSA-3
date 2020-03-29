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

Node* LCA(Node *root, int n1, int n2)
{
    // assuming n1 is smaller than n2
    if (root == NULL)
        return NULL;
    if (n1 > n2)
        swap(n1, n2);
    Node *curr = root;
    while(curr != NULL) {
    if (curr->data > n1 && curr->data < n2)
        return curr;
    if (curr->data == n1 || curr->data == n2)
        return curr;
    if (curr->data > n2)
        curr = curr->left;
    if (curr->data < n1)
        curr = curr->right;
    }
    // assuming both are present
} // !! many if conditions, signs of naive programmer

// code refactoring
/* if i notice i am returning curr in two cases, clubuing the conditions logically
this can be elegantly handled as */
Node* LCARefactored(Node *root, int n1, int n2)
{
    // assuming n1 is smaller than n2
    if (n1 > n2)
        swap(n1, n2); // this can also be avoided and handled simply
    Node *curr = root;
    while(curr != NULL) {
    // If both n1 and n2 are are smaller than root, then LCA lies in left
    if (curr->data > n2)
        curr = curr->left;
    // If both n1 and n2 are greater than root, then LCA lies in right
    else if (curr->data < n1)
        curr = curr->right;
    else
        break;
    }
    return curr;
    // assuming both are present
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
// Auxiliary Space Complexity: O(1)

// Company Tags: Accolite, Amazon, Flipkart, MAQ Software, Microsoft, Samsung, Synopsys
