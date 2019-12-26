/* 
Bottom View of Binary Tree

Difficulty: Medium
Problem Statement

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root,
then print the later one in level traversal.
For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

Input Format:
The first line of input contains T denoting number of testcases. T testcases follow.
Each testcase contains two lines of input. The first line contains the number of edges.
The second line contains the relation between nodes.

Output Format:
The function should print nodes in bottom view of Binary Tree.
Your code should not print a newline, it is added by the caller code that runs your function.

Constraints:
1 <= T<= 30
0 <= Number of nodes <= 100
0 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 1 2
40 20 60 30

Explanation:
Testcase 1:  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus nodes of binary tree will be printed as such 3 1 2.
 */


#include<bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

// Method that prints the bottom view.
void bottomView(Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}

// A node x is there in ouput if x is the bottom most node at its horizontal distance

/* Approach 1 - Uses Queue
1. we put tree nodes in a queue for the level order traversal
2. Start with hd as 0 of root and keep adding left child wiht hd as hd -1 and right child wiht hd as hd + 1
3. Also, use treeMap which stores key value pair sorted on key
4. Every time, we encounter a new hd or existing hd put the node data for hd as key.
For the first time it will add to map, next time it will replace the value
This will make sure that the bottom most element for that horizontal distance is present in the map
and if we see the tree from beneath we will see that element
 */
void bottomView(Node *root)
{
   // using queue
   // horizontal distance as key
   // node data as value
   map<int, int> m;
   
   // pair of node and its hd
   // since we cannot make change in the structure of node
   // this is the way to maintain a hd of each node
   
   queue<pair<Node *, int>> que;
   int hd = 0;
   que.push(make_pair(root, hd));
   
   while(que.empty() == false) {
       pair<Node *, int> temp = que.front();
       que.pop();
       hd = temp.second;
       Node *node = temp.first;
       
       // update the map everytime
       m[hd] = node->data;
       
       // recur on left sub-tree, hd will be hd of root - 1
       if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
       // recur on right sub-tree, hd will be hd of root + 1
       if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
   }
   
   for(auto it = m.begin(); it != m.end(); it++)
        cout << it->second << " ";
}

// Time Complexity: Simple level order traversal O(n)
// Aux Space Complexity: O(n)
// Company Tags: Accolite, Amazon, CouponDunia, Flipkart, OYO Rooms, Paytm, Walmart