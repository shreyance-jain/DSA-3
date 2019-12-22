/* 
Print a Binary Tree in Vertical Order

Difficulty: Medium
Problem Statement

You are given a binary tree for which you have to print its vertical order traversal.
your task is to complete the function verticalOrder which takes one argument the root
of the binary tree and prints the node of the binary tree in vertical order as shown below.
If there are multiple nodes passing through a vertical line, then they should printed as they
appear in level order traversal.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains 2 lines of input. The first line contains number of operations to insert the nodes.
The second line contains the nodes and their position during the insertion.

Output Format:
For each testcase, the vertical order traversal of the tree is to be printed.
The nodes' data are to be separated by spaces.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 5000

Example:
Input:
4
3
1 2 L 1 3 R 3 5 L
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
4
1 2 L 1 3 R 2 4 R 4 5 R

Output:
2 1 5 3
3 1 2
40 20 10 60 30
2 1 4 3 5

Explanation:
Testcase1:
         1
       /     \
    2         3
              /
         5
As it is evident from the above diagram that during vertical traversal 2 will come first,
then 1 and  5, and then 3. So output is 2 1 5 3

Testcase2:
         1
       /     \
     3       2
As it is evident from the above diagram that during vertical traversal 3 will come first,
then 1 and then 2. So output is 3 1 2 */


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

void verticalOrder(Node *root);

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
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}

/* The solution is set2 uses preorder traversal and hashmap to store nodes according
to horizontal distances. Since the above approach uses preorder traversal, nodes in vertical
line may not be printed in same order as they appear in tree.

If we use level order traversal we can make sure nodes appear in same
order as they appear in given tree */
void verticalOrder(Node *root)
{   
    // map to store vertical order
    map<int, vector<int>> m;
    int hd = 0;
    // queue to do level order traversal
    // every item of queue contains node and horizontal distance
    queue<pair<Node *, int>> que;
    que.push(make_pair(root, hd));
    while(que.empty() == false) {
        // pop from queue front
        pair<Node *, int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node *node = temp.first;
        // insert this node data in vector of hash
        m[hd].push_back(node->data);
        
        // push the left node, pass hd as hd of curr node -1
        if (node->left != NULL)
            que.push(make_pair(node->left, hd -1));
        // push the rigtht node, pass hd as hd of curr node +1
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }
    // traverse the map and print nodes at every horizontal distance
    map<int, vector<int>>::iterator it;
    for(it = m.begin(); it != m.end(); ++it) {
        for(int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
    }
}

// Time Complexity: Time complexity of the above implementation is O(nlogn)
// Note that the above implementaion uses map which is implemented using self-balancing BST

// We can reduce time complexity to O(n) using unordered_map. To print nodes in desired order
// we can haece 2 variables denoting min and max horizontal distance. We can simply iterate
// from min to max horizontal distance and get corresponding values from Map O(1), So it is O(n)

// Auxiliary Space : O(n)

// Company Tags: Accolite, Amazon, BrowserStack, Dell, Flipkart, Goefers
// MakeMyTrip, Netskope, Walmart