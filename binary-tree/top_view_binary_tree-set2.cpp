/* 
Top View of Binary Tree

Difficulty: Medium
Problem Statement

Given below is a binary tree. The task is to print the top view of binary tree.
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Print from leftmost node to rightmost node.

Input Format:
The first line of the input contains a single integer T denoting the number of test cases.
T testcases follow.
Each testcase contains two lines of input.
The first line contains number of edges.
The second line contains relation between nodes.

Output Format:
For each test case, in a new line, print top view of the binary tree level wise.
The nodes should be separated by space.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

Output:
2 1 3
40 20 10 30

Explanation:
Testcase 1:

           1

        /     \

      2        3

For the above test case the top view is: 2 1 3
Test case 2:

            10

         /        \

     20          30

   /      \       /

40      60 90

TopView is: 40 20 10 30
 */


#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void topView(struct Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  cin >> t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin >> n;
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
     topView(root);
     cout << endl;
  }
  return 0;
}

// a node x is in output if x is the topmost node at its horizontal distance
    
// idea is similar to vertical order traversal, like level order traversal we need to put
// nodes at same horizontal distance together
// this approach does not require a queue. Here we use two variables, one for vertical distance
// of current node from root and other for the depth of current node from the root
// We use vertical distance for indexing. If one node with same vertical distance comes again
// we check if depth of new node is lower or higher with respect to current node with same
// vertical distance in map. If depth of new node is lower, then we replace it.
void fillMap(Node *root, int level, int hd, map<int, pair<int, int>> &m) {
    // base case
    if (root == NULL)
        return;

    // if hd is seen first time    
    if (m.count(hd) == 0)
        m[hd] = make_pair(root->data, level);
    // if hd is already seen, compare level(depth)
    else if (m[hd].second > level)
        m[hd] = make_pair(root->data, level);
    // recur left
    fillMap(root->left, level + 1, hd - 1, m);
    fillMap(root->right, level + 1, hd + 1, m);
}

void topView(struct Node *root)
{
    //solution without queue
    
    // we will maintain vertical as well as horizontal distance of node
    // when we encounter nodes with same horizontal distance
    // we will take the node with less vd
    
    // the queue was used just to ensure that we take topmost node wiht the horizontal distance
    
    // now we remove the queue and maintain vertical distance
    
    map<int, pair<int, int>> m;
    
    fillMap(root, 0, 0, m);

    
    for(auto i = m.begin(); i != m.end(); i++)
        cout << i->second.first << " ";
}

// Time Complexity: O(n)
// Space Compleity: Theta(height + 1) or O(height)

// Company Tags: Amazon, Ola Cabs, Paytm, Samsung, Walmart
