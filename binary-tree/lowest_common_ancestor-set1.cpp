/* 
Lowest Common Ancestor in a Binary Tree

Difficulty: Easy
Problem Statement

Given a Binary Tree and two nodes value n1 and n2.
The task is to find the lowest common ancestor of the given two nodes.

Input Format:
The input contains T, denoting number of testcases.
For each testcase there will be third lines.
The first line contains number of edges.
The second line contains relation between nodes.
The second line contains two nodes and a character separated by space.
The first node denotes data value, second node denotes where it will be assigned to the
previous node which will depend on character 'L' or 'R' i.e.
the 2nd node will be assigned as left child to the 1st node if character is 'L' and so on.
The third line contains two nodes separated by space for which you have to compute LCA.
The first node of second line is root node. The struct or class Node has a data part
which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, the function will be called individually.

Output Format:
For each testcase, in a new line, print the Lowest Common Ancestor of the two nodes.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input
2
2
1 2 L 1 3 R
2 3
3
5 2 L 2 3 L 2 4 R
3 4
Output 
1
2

Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
The LCA of 2 and 3 is 1.
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

Node * lca(Node* ,int ,int );
bool find(Node *root, int n, vector<Node *> &v);

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
     int a,b;
     cin>>a>>b;
     Node * k = lca(root,a,b);
     cout<<k->data<<endl;
  
  }
  return 0;
}

/* 
Approach: By storing root to n1 and root to n2 path
O(n) algo/approach:
1. Find path from root to n1 and store it in a vector
2. Find path from root to n2 and store it in an another vector or array
3. Traverse both till values are same. Return common element just before mismatch
 */

// function retrun LCA if both nodes are present else retrun -1
Node * lca(Node* root ,int n1 ,int n2 )
{
    // to store path to nodes n1 and n2 from root
    vector<Node *> pn1;
    vector<Node *> pn2;
    
    // find path root to n1 and root to n2
    // if n1 or n2 is not present retrun -1
    if (!find(root, n2, pn2) || !find(root, n1, pn1))
        return new Node(-1);

    // compare path to return first different value 
    int i;
    for(i = 0; i < pn1.size() && i < pn2.size(); ++i)
        if (pn1[i] != pn2[i])
            break;

    return pn1[i-1];

}

// finds path of node from root and store it in vector
// return true if path exists else return false
bool find(Node *root, int n, vector<Node *> &v) {
    // base case
    if (root == NULL)
        return false;

    // store the node in path vector. node will be removed in not in path from root to node n    
    v.push_back(root);
    
    // see if n is same as root's key
    if (root->data == n)
        return true;
  
    // check if k is found or left or right subtree
    if (find(root->left, n, v) || find(root->right, n, v))
        return true;
    
    // if not present in subtree rooted with root
    // remove root from path and return false
    v.pop_back();
    return false;
}   

/* Note: Computation of lowest common ancestor(LCA) may be useful,
for instance, as part of a procedure for determining distance between pair of nodes in a tree
The distance from n1 to n2 can be computed as distance of n1 from root, plus
distance of n2 from root, minus double the distance of LCA from root */

// Time Complexity: O(n) two traversals of tree then path vectors are compared

// Company Tags: Accolite, Amazon, American Express, Cisco, Expedia, Flipkart, MakeMyTrip
// Microsoft, OYO Rooms, Paypal, Payu, Snapdeal, Times Internet, Twitter
