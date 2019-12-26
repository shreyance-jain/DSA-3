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
    
// idea is similar to level order traversal, like level order traversal we need to put
// nodes at same horizontal distance together
// we do a level order traversal so that topmost node at a horizontal distance
// is visited before any other node of same horizontal distance below it
// hashing is used to check if a node at a given distance is seen or not
void topView(struct Node *root)
{   
    // key is hd (horizontal distance) and value will be the topmost element with hd as we do level order traversal
    map<int, int> m;

    // queue will contain node of tree and hd of the node w.r.t to root of tree
    queue<pair<Node *, int>> que;
    
    int hd = 0;
    // push root and its horizontal distance 0
    que.push(make_pair(root, hd));
    
    // level order traversal
    while(que.empty() == false) {
        // pop first item from queue
        pair<Node *, int> temp = que.front();
        que.pop();
        // get its hd
        hd = temp.second;
        Node *node = temp.first;
        
        // if node with this hd is not seen
        // it means it is topmost node of this hd
        // (which will be the part of ans)
        if (m.count(hd) == 0)
            m[hd] = node->data;
        
        // if left child exits, push it in queue with hd -1
        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));

        // if right child, push it in queue with hd + 1   
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }
    
    // iterate over map and print result
    for(auto i = m.begin(); i != m.end(); i++)
        cout << i->second << " ";
}

// Time Complexity: O(n)
// Space Compleity: Theta(widht) or O(n)

// Company Tags: Amazon, Ola Cabs, Paytm, Samsung, Walmart
