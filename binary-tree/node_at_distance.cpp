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
int heightOfTree(Node *root);

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

/* Here, the assumption is we take the deepest leaf node
and take count of distinct nodes at k level above this leaf node

Algo:
1. Get height of tree
2. Count no of distince nodes at level height - k*/
int printKDistantfromLeaf(Node* node, int k)
{
	int height = heightOfTree(node);
	
    // if k == height, the no of nodes in level k above height will be 0
	if (k >= height)
	    return 0;
	
	int level = height - k;
	
	unordered_set<int> s;
    // traverse the required level, get count of distinct nodes
	getDistinctAtLevel(node , level, s);
	return s.size();
}

/* Function to traverse nodes at a given level */
void getDistinctAtLevel(Node *root, int level, unordered_set<int> &s) {
    if (root == NULL)
        return;
    
    if (level == 1)
        s.insert(root->key);
    
    getDistinctAtLevel(root->left, level - 1, s);
    getDistinctAtLevel(root->right, level - 1, s);
}

/* Function to get height of a binary tree */
int heightOfTree(Node *root) {
    if (root == NULL)
        return 0;
    
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    
    return max(lh, rh) + 1;
}

// Time Complexity: O(n)
// Space Complexity: O(n) for function call stack

// Company Tags: Flipkart, Microsoft

// GeeksForGeeks solution implemented in set-2 