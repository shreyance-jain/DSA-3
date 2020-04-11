/* 
Find the Closest Element in BST

Difficulty: Medium
Problem Statement

Given a BST with N nodes and a target node K.
The task is to find an integer having minimum absolute difference
with given target value K and return this difference.

Input Format:
The first line of input contains the number of test cases T.
For each test case, there will be only a single line of input which
is a string representing the tree as described below: 
The values in the string are in the order of level order traversal of the tree where,
numbers denote node values, and a character “N” denotes NULL child.
For example:
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N
Second-line is an integer represents K

Output Format:
The output for each test case will be the minimum absolute
difference of a node with a given target value K.

Constraints:
1 <= T <= 10
1 <= N <= 100000

Example:
Input:
2
10 2 11 1 5 N N N N 3 6 N 4
13
8 1 9 N 4 N 10 3
9

Output:
2
0

Explanation:

Testcase1:
K=13. The node that has value nearest to K is 11. so the answer is 2
Testcase2:
K=9. The node that has value nearest to K is 9. so the answer is 0.
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

int maxDiff(Node *root, int k);

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
       int k = stoi(s);
       // getline(cin, s);

       cout << maxDiff(root1, k);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}


/* Approaches:
Approach 1: A simple solution is to do a traversal: inorder, preorder, postorder or levelorder and compare key with
every element and maintain the diff and key with min diff and return the result
Time Complexity: O(n), Space Complexity: O(h)

Approach 2: Do Morris traversal instead of inorder traversal 
Time Complexity: O(n), Space Complexity: O(1)

Approach 3: Efficient solution Use BSTs property. Do height based traversal and get ciel and
floor values of the the key and return the min difference
Time Complexity: O(h), Space Complexity: O(1)

Approach 4: Efficient solution use BST property. Do a height based traversal and no need to maintain ciel and floor
as we will be moving down in one direction based on comparison with root node data
and maintain the res as we move down the tree*/

// code for approach 3:
int maxDiff(Node *root, int key)
{
    int floor = INT_MAX;
    int ciel = INT_MIN;
    if (root == NULL)
        return -1;
    Node *curr = root;
    while(curr != NULL) {
        if (curr->data == key)
            return 0;
        else if (curr->data > key) {
            ciel = curr->data;
            curr = curr->left;
        } else if (curr->data < key) {
            floor = curr->data;
            curr = curr->right;
        }
    }
    return min(key - floor, ciel - key);
}

// Time Complexity: O(h), where h is the height of the bst
// Space Complexity: O(1)

// Company Tags: Amazon, MAQ Software
