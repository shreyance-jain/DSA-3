/* 

Count BST nodes that lie in a given range

Difficulty: Medium
Problem Statement

Given a Binary Search Tree (BST) and a range l-h(inclusive),
count the number of nodes in the BST that lie in the given range.

    The values smaller than root go to the left side
    The values greater and equal to the root go to the right side

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases.
Then 'T' test cases follow. Each test case consists of three lines. Description of  test cases is as follows:
The First line of each test case contains an integer 'N' which denotes the no of nodes in the BST.   .
The Second line of each test case contains 'N' space separated values of the nodes in the BST.
The Third line of each test case contains two space separated integers 'l' and 'h' denoting the range, where l < h

Output:
For each testcase, in a new line, output the number of nodes that lie in the range l-h.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= l < h < 103

Example:
Input:
2
6
10 5 50 1 40 100
5 45
5
5 6 7 4 3
2 8

Output:
3
5
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};


Node *insert(Node *root,int data)
{
    if(root==NULL)
    root=new Node(data);
    else if(data<root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);
    
    return root;
}
/* Approaches:
Approach 2: The idea is to traverse the given binary search tree starting from root. For every node being
visited, check if the node lies in the range, if yes, add 1 and recur for both the children.
If current node is smaller than the lower value of the range, then recur for right child
else recur for left child
 */
int getCountOfNode(Node *root, int l, int h)
{
  // base case
    if (root == NULL)
        return 0;
    
    // if current node is in range the include it in count 
    // and recur for left and right child of it
    if (root->data >= l && root->data <=h)
        return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);
    
    // if current node is smaller than low
    // then recur for right child
    else if (root->data < l)
        return getCountOfNode(root->right, l, h);
        
    else // recur for right child
        return getCountOfNode(root->left, l, h);
}

// driver code
int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=insert(root,arr[i]);
        }
        int l,h;
        cin>>l>>h;
        cout<<getCountOfNode(root,l,h)<<endl;
    
        
    }
	return 0;
}

// Time Complexity:
// Space Complexity:

// Company Tags: DE-Shaw, Google 
