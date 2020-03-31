/* 
Print BST elements in given range

Difficulty: Easy
Problem Statement

Given a Binary Search Tree (BST) and a range, print all the numbers in the BST that lie in 
the given range l-h(inclusive) in non-decreasing order. If no such element exists, an empty line will be printed.
Note: Element greater than or equal to root go to the right side.

Input Format:
First line of input contains the number of test cases T. For each test case,
there will be two lines of input First line contains a string representing
the tree as described below and second line contains two space seperated
integers l and h denoting given range.
The values in the string are in the order of level order traversal of the tree where,
numbers denotes node values, and a character “N” denotes NULL child.
For example:
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output Format:
For each testcase, in a new line, print print all the numbers in the BST that
lie in the given range in non-decreasing order.

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= l < h < 105

Example:
Input:
2
17 4 18 2 9 
4 24
16 7 20 1 10 
13 23
Output:
4 9 17 18 
16 20 

Explanation:
Testcase 1: Elements which are in the range of 4 and 24(inclusive) are 4 9 17 18.
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

void printNearNodes(Node*root,int k1 , int k2);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k1 , k2;
        string s;
		getline(cin,s);
		scanf("%d ", &k1);
		scanf("%d " , &k2);
        Node* root = buildTree(s);
        printNearNodes(root, k1 ,  k2);
        cout<<endl;
    }
    return 1;
}

/* 
Approach: The idea is to use inorder traversal, as inorder traversal gives the keys in sorted order

Algorithm:
1. If value of root's key is greater than k1, then recursively call in left subtree
2. If value of the root's key is in range, then print root's key
3. If value of root's key is smaller than k2, then recusively call in right subtree
 */
void printNearNodes(Node *root, int l, int h)
{
    // base case
    if (root == NULL)
        return;
    // since the desired output is sorted, recur for left subtree first
    // if root->data is greater than left bound, then only we can get o/p keys in left subtree
    if (root->data > l)
        printNearNodes(root->left, l, h);
    // if root's data lie in range, then prints the root data
    if (root->data >= l && root->data <= h)
        cout << root->data << " ";
    // if root->data is smaller than upper bound, then only we can get o/p keys in right subtree
    if (root->data < h)
        printNearNodes(root->right, l, h);
}

// Time Complexity: O(n) where n is the total number of keys in tree
// Space Complexity: O(h)

// Company Tags: Amazon, Flipkart, Microsoft
