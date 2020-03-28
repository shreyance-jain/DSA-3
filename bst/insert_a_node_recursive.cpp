/* 
Insert a node in a BST

Difficulty: Easy
Problem Statement

Given a BST and some keys, you need to insert the keys in the given BST.
Duplicates are not inserted (If a test case contains duplicate keys,
you need to consider the first occurrence and ignore duplicates).

Input:
The first line of input contains the number of test cases T. For each test case, there will two lines.
The first line of input is a string representing the tree as described below: 
The values in the string are in the order of level order traversal of the tree where,
numbers denote node values, and a character “N” denotes NULL child.
For example:  
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N
Second-line is an integer represents the key value which needs to be inserted

Output:
For each test case, in a new line, the inorder of the BST gets printed.

Constraints:
1 <= T <= 10
1 <= N <= 100000
1 <= K <= 1000000

Example:
Input:
2
2 1 3 
4
2 1 3 N N N 6 4
1
Output:
1 2 3 4
1 2 3 4 6

Explanation:
Testcase 1: After inserting the node 4 the tree will be
                                          2
                                      /        \
                                    1          3
                                                   \
                                                    4
Inorder traversal will be 1 2 3 4.
Testcase 2: After inserting the node 1 the tree will be 
                                         2
                                    /           \
                                  1            3
                                /     \       /     \
                              N     N     N     6
                                                   /
                                                 4
Inorder traversal of the above tree will be 1 2 3 4 6.
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node{
    int data;
    Node *left;
    Node *right;
};

// Note: structures support constructors
// or
// Utitlity function to create a new tree node
Node* newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* insert(Node *root, int data);

void inorder(Node* root, vector<int> &v) {
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

// Function to build tree
Node* buildTree(string str) {
    // corner case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    
    // creating vector of strings from input string
    // after splitting by space
    vector<string> ip;

    isstringstream iss(str);
    for(string str; iss >> str;)
        ip.push_back(str);
    
    // create root of the tree
    Node *root = newNode(stoi(ip[0]));

    // push the root to the queue
    queue<Node*> q;
    q.push(root);

    // starting from the second element
    int i = 1;
    while(!q.empty() && i < ip.size()) {
        // get and remove the front of the queue
        Node *currNode = q.front();
        q.pop();

        // get the current node's value from the string
        string currVal = ip[i];

        // if the left child is not NULL
        if (currVal != 'N') {
            // create the left child for the current node
            currNode->left = newNode(stoi(currVal));
            // push it to the queue
            q.push(currNode->left);
        }
        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // if the right child is not NULL
        if (currVal != 'N') {
            // create the right child of the current node
            currNode->right = newNode(stoi(currVal));
            // push it to the queue
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}

int main() {
    int t; // test cases
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while(t--) {
        // input sting representing level order traversal
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        // input the node value to insert
        getline(cin, s);
        int k = stoi(s);

        insert(root, k);
        vector<int> v;
        inorder(root, v);
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
}

// Function to insert a new node with given key
// returns root of the modified tree
// RECURSIVE IMPLEMENTATION
Node* insert(Node *root, int key) {
    if (root == NULL)
        return newNode(key);
    if (root->data > key) // this linking of the returned value is very important, special attention
        root->left = insert(root->left, key);
    if (root->data < key) // new node is linked, and existing links are re-linked
        root->right = insert(root->right, key);
    
    return root;
}
// Time Complexity: O(h), since we are going either left or right
// Aux Space: O(h), required for function call stack

// Note: Time and Space complexities are similar to search, we simply do search
// and then constant extra work to add node to the tree

// Company Tags: Accolite, Amazon, Microsoft, Paytm, Samsung
