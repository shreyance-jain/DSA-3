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

/* Approach: Efficeint O(n) time by using extra space
An array created[0...n-1] is used to keep track of created nodes

createTree(parent[], n)
1. Create an array of pointers say created[0...n-1]. The value of created[i] is NULL
if node for index i is not created, else value is pointer to created node
2. Do the following for every index i of given array
    createNode(parent, i, created)

createNde(parent[], i, created[])
1. if created[i] is not NULL, the node is already created, so return
2. Create a new node with value i
3. If parent[i] is -1(i is root), make created node as root and return
4. Check if parent[i] is created, recur for parent and create the parent first
5. Let the pointer to parent be p. If p->left is NULL, then make the new node
as left child, else make the new node as right child of parent
  */
void create(int parent[], int i, Node *created[], Node **root) {
    // If this node is already created
    if (created[i] != NULL)
        return;
    
    // Imp create the node first and then recur, beacuse this might be parent for some nodes on recurrence
    created[i] = new Node(i); // create a new node and set created[i]

    // if i is root, change pointer and return
    if (parent[i] == -1) {
        *root = created[i];
        return;
    }
    // if parent node is not created, create parent first recur for parent
    if (created[parent[i]] == NULL) {
        create(parent, parent[i], created, root);
    }
    
    // find the parent pointer
    Node *p = created[parent[i]];
    
    // if first child of parent
    if (p->left == NULL)
        p->left = created[i];
    else // if second child
        p->right = created[i];
}

// create tree from parent[0...n-1] and return root of created tree    
Node *createTree(int parent[], int n)
{
    // create an array created to keep track of created nodes,
    Node* created[n];
    // initialise all entries as NULL
    for(int i = 0; i < n; i++)
        created[i] = NULL;
    
    Node *root = NULL;
    for(int i = 0; i < n; i++) {
        create(parent, i, created, &root);
    }
    
    return root;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

// Company Tags: Amazon, Microsoft, Snapdeal
