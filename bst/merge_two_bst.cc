/* 
Merge two BST 's

Difficulty: Medium
Problem Statement
Given two BST, Return elements of both BSTs in sorted form.

Input Format:
The first line of input contains the number of test cases T.
For each test case, there will be only a single line of input which is a string representing the tree as described below: 
The values in the string are in the order of level order traversal of the tree where,
numbers denote node values, and a character “N” denotes NULL child.

For example:
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N
Second-line is a string which represents a BST

Output Format:
For each test case, in a new line, print the elements of both BSTs in sorted form.

Constraints:
1 <= T <= 10
1 <= Number of Nodes <= 100000

Example:
Input:
2
5 3 6 2 4
2 1 3 N N N 7 6
12 9 N 6 11
8 5 10 2

Output:
1 2 2 3 3 4 5 6 6 7
2 5 6 8 9 10 11 12
 */

// { Driver Code Starts
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>

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



vector<int> merge(Node *root1,Node *root2);

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
       Node* root2 = buildTree(s);
    
       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
/* 
Approach: Is to iterative inorder traversal
Pick the smaller node from a tree and advance only the picked pointer
 */
vector<int> merge(Node *root1, Node *root2)
{
   // iterative inorder traversal
   Node *curr1 = root1;
   Node *curr2 = root2;
   
   vector<int> res;
   
   stack<Node *> s1, s2;
   
   while(curr1 != NULL) {
       s1.push(curr1);
       curr1 = curr1->left;
   }
   
   while(curr2 != NULL) {
       s2.push(curr2);
       curr2 = curr2->left;
   }
   int key1, key2;
   while(!s1.empty() && !s2.empty()) {
       curr1 = s1.top();
       curr2 = s2.top();
       
       if (curr1->data < curr2->data) {
           s1.pop();
           res.push_back(curr1->data);
           curr1 = curr1->right;
           while(curr1 != NULL) {
               s1.push(curr1);
               curr1 = curr1->left;
           }
       } else if (curr1->data > curr2->data) {
           s2.pop();
           res.push_back(curr2->data);
           curr2 = curr2->right;
           while(curr2 != NULL) {
               s2.push(curr2);
               curr2 = curr2->left;
           }
       } else {
           s1.pop();
           res.push_back(curr1->data);
           curr1 = curr1->right;
           while(curr1 != NULL) {
               s1.push(curr1);
               curr1 = curr1->left;
           }
           s2.pop();
           res.push_back(curr2->data);
           curr2 = curr2->right;
           while(curr2 != NULL) {
               s2.push(curr2);
               curr2 = curr2->left;
           }
       }
       
   }
   
   while(!s1.empty()) {
       curr1 = s1.top();
       s1.pop();
       res.push_back(curr1->data);
       curr1 = curr1->right;
       while(curr1 != NULL) {
           s1.push(curr1);
           curr1 = curr1->left;
       }
   }
   
   while(!s2.empty()) {
       curr2 = s2.top();
       s2.pop();
       res.push_back(curr2->data);
       curr2 = curr2->right;
       while(curr2 != NULL) {
           s2.push(curr2);
           curr2 = curr2->left;
       }
   }
   
   return res;
   
}

// Time complexity: O(m + n), m and n are no of nodes in trees
// Space complexity: O(h1 + h2)

// Company Tags: Amazon, Google, Microsoft
