/* 
ZigZag Tree Traversal

Difficulty: Easy
Problem Statement

Given a binary tree of size N, your task is to complete the function zigZagTraversal(),
that prints the nodes of binary tree in ZigZag manner.

For Example:
For the below binary tree the zigzag order 
traversal will be 1 3 2 7 6 5 4.

Input:
The function takes a single argument as input, the reference pointer to the root of the binary tree.
There will be T testcases and for each test case the function will be called separately.

Output:
For each test case print on a new line space separated all the nodes of the tree in ZigZag manner.

Constraints:
1<=T<=500
1<=N<=1000

Example:

Input:
1
10

1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 4 8 L 5 9 R 6 10 L 7 11 R
Output:
1 3 2 4 5 6 7 11 10 9 8
*/


//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void zigZagTraversal(Node* root);

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
     struct Node *root = NULL;
     struct Node *child;
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
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     zigZagTraversal(root);
     cout << endl;
  }
  return 0;
}

/* We can print zig zag order traversal in O(n) time and O(n) space
The idea is to use two stacks
We use one stack to print from left to right
and one stack to print from right to left
In every iteration, we have nodes of one level in one of the stacks
We print the nodes and push nodes of next level in other stack*/
void zigZagTraversal(Node* root)
{
    stack<Node *> s1, s2;
    Node *temp;
    // we push the first level in s1
    s1.push(root);

    // keep printing while any of the stacks have any node
    while(!s1.empty() || !s2.empty()) {
        // print nodes of current level from s1 and push the next level in s2
        while(!s1.empty()) {
            temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
            // here we push left before right
            if (temp->left != NULL)
                s2.push(temp->left);
            if (temp->right != NULL)
                s2.push(temp->right);
        }
        // print nodes of current level from s2 and push next level in s1
        while(!s2.empty()) {
            temp = s2.top();
            s2.pop();
            // here we push left before right
            cout << temp->data << " ";
            if (temp->right != NULL)
                s1.push(temp->right);
            if (temp->left != NULL)
                s1.push(temp->left);
        }
    }
}

// Time Complexity: O(n) does simple level order traversal
// Space Complexity: O(n), uses 2 stack

// Company Tags: Amazon, Cisco, FaceSet, Hike, Snapdeal, Walmart
