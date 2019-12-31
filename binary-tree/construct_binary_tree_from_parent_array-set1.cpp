/* 
Construct Binary Tree from Parent Array

Difficulty: Medium
Problem Statement

Given an array of size N that represents a Tree in such a way that array indexes
are values in tree nodes and array values give the parent node of that particular index (or node).
The value of the root node index would always be -1 as there is no parent for root.
Construct the standard linked representation of Binary Tree from this array representation.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases.
Then 'T' test cases follow. Each test case consists of two lines.
First line of each test case contains an integer N denoting the size of the tree array .
Second line of each test case consists of 'N' space separated integers denoting the elements of the array .

Output:
The Output will be the sorted level order traversal of the tree.

User Task:
The task is complete the function 

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
7
-1 0 0 1 1 3 5
5
-1 0 0 2 2   

Output:
0 1 2 3 4 5 6
0 1 2 3 4

Explanation:
Testcase 1: For the array parent[] = {-1, 0, 0, 1, 1, 3, 5}; the tree generated will have a sturcture like
         0
       /   \
      1     2
     / \
    3   4
   /
  5
/
6
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> result;

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

void printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        result.push_back(root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(struct Node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

void printLevelOrder(struct Node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++){
        result.clear();
        printGivenLevel(root, i);
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++)
            cout<<result[i]<<" ";
    }
}

Node *createTree(int parent[], int n);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;
/*reading input*/
    cin>>T;
    while(T--){
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)
        cin>>a[i];
        struct Node *res = createTree(a,N);
       printLevelOrder(res);
     cout<<endl;
    }
    return 0;
}

/* Approach: Use map, which maps node data value to a node
Algo:
Traverse the parent array
1. For a value at index i of parent array
  i is child node
  parent[i] is parent node
  Check if parent[i] i.e parent node is present in map
  if no,
    first create the parent node
  if yes,
    parent node is already present
  then set its child
  if left is null set left child first
  else set right child
  
2. if parent[i] == -1, check if that node exist in map
(it may exist if its child occur first and we have created it there)
  if yes, then set root to that node, else create a node, set root to it and continue
  */
Node *createTree(int parent[], int n)
{
    Node *root = NULL;
    // use map to create tree
    
    // map of node data value and node
    map<int, Node *> m;

    // traverse parent array
    for(int i = 0; i < n; i++) {
      // if parent[i] is -1, root node
        if (parent[i] == -1) {
          // if node is present, set root
            if (m.find(i) != m.end()) {
                root = m[i];
            } else { // else create and set root
                root = new Node(i);
                m[i] = root;
            }
            continue;
        }

        Node *p;
        // it parent is present
        if (m.find(parent[i]) != m.end()) {
            p = m[parent[i]];
        } else {
            // if parent is not present in the tree first, create the parent
            p = new Node(parent[i]);
            m[parent[i]] = p;
        }
        
        // if child node not present in map
        Node *child_node;
        if (m.find(i) == m.end()) {
            child_node = new Node(i);
            m[i] = child_node;
        }
        else
            child_node = m[i];
        
        // fill left child first if not present
        if (p->left == NULL)
            p->left = child_node;
        else // fill right child if left child is present
            p->right = child_node;
    }
    return root;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

// Company Tags: Amazon, Microsoft, Snapdeal
