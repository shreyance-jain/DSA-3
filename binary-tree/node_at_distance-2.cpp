/* 
Node at distance

Difficulty: Medium
Problem Statement

Given a Binary Tree of N nodes and a positive integer k.
The task is to count all distinct nodes that are distance k from a leaf node.
Here, k distance from leaf means k levels higher than a leaf node.
For example, if k is more than height of Binary Tree, then nothing should be counted.

Input Format:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case contains an integer N denoting the number of edges.
The next line contains edges of the binary tree. The last line contains the value of k.

Output Format:
Count the distinct number of nodes that are at distance k from the leaf nodes.

Constraints:
1 <= T <= 100
1 <= N <= 102

Example:
Input:
2
7
1 2 L 2 4 L 2 5 R 1 3 R 3 6 L 6 8 R 3 7 R
2
5
1 3 L 3 5 L 5 7 L 5 8 R 8 9 R
4

Output:
2
1
 */


#include<bits/stdc++.h>
using namespace std;

#define MAX_HEIGHT 10000

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int printKDistantfromLeaf(Node* node, int k);
void getDistinctAtLevel(Node *root, int level, unordered_set<int> &s);
void getCount(Node *root, int path[], bool visited[], int pathLen, int &count, int k);

void insert(struct Node * root, int n1, int n2, char lr)
{
    if (root == NULL)
        return;
    if (root->key == n1)
    {
        switch (lr)
        {
        case 'L':
            root->left = new Node(n2);
            break;
        case 'R':
            root->right = new Node(n2);
            break;
        }
    }
    else
    {
        insert(root->left, n1, n2, lr);
        insert(root->right, n1, n2, lr);
    }
}

int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    cin>>k;
    cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}

/*  For an example in binary tree
                1
             /      \      Nodes at distance 1 from a leaf node are: 2, 6 and 3
            2        3
         /    \     /  \   
        4      5   6     7  Nodes at distance 2 from a leaf node are: 1 and 3
                    \
                     8

The idea is to traerse the tree. Keep storing all the ancestors till we hit a leaf node. When
we reach a leaf node, we print the ancestor at distance k. We also need to keep track
of nodes that are already printed as output. For that we use boolean visited[]*/
int printKDistantfromLeaf(Node* node, int k)
{
	int path[MAX_HEIGHT]; // we can take path[] to get node value
    bool visited[MAX_HEIGHT] = {false};
    int count = 0;
    getCount(node, path, visited, 0, count, k);
    return count;
}

/* This function prints or counts all nodes that are at distance k from a leaf node
path[] ---> store ancestors of a node
visited[] ---> stores true if nodes is already included in output. A node may be at distance k
from many leaf nodes, we want to count that as one or print it once
 */
void getCount(Node *root, int path[], bool visited[], int pathLen, int &count, int k){
    // base case
    if (root == NULL)
        return;
    
    // append this node to path array
    path[pathLen] = root->key;
    visited[pathLen] = false;
    pathLen++;
    
    if (root->left == NULL && root->right == NULL &&
        pathLen - k - 1 >= 0 && visited[pathLen - k - 1] == false) {
        count++;
        visited[pathLen - k - 1] = true;
        return;
    }
    
    // if not leaf node recur for left and right subtrees
    // important thing to note here is we don't use pointer to pathLen
    // we don't increment it linearly
    // so for a root at a given pathLen left child is store in left recursive call
    // and right child is store at that pathLen in right recursive call
    // and so are values of visited[] modified for that pathLen
    // this helps us to maintain path of one node at a time in path array and visited array
    // and through this we make our calculation for leaf node
    getCount(root->left, path, visited, pathLen, count, k);
    getCount(root->right, path, visited, pathLen, count, k);
}

// Time Complexity: O(n)
// Space Complexity: O(n) for function call stack

// Company Tags: Flipkart, Microsoft
