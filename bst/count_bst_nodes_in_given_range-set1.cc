/* 
Count BST nodes that lie in a given range

Difficulty: Medium
Problem Statement
Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.
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

#include <iostream>
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

int getCountOfNode(Node *root, int l, int h);

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

/* Approaches:
Approach 1: Traverse every node of the tree and check if it lies in the range
For this:
a. Inorder Traversal: Time: O(n), Space: O(h)
b. Morris Traversal: Time: O(n), Space: O(1)
 */
// Below implementation: Based on Morris traversal
int getCountOfNode(Node *root, int l, int h)
{
  // morris traversal
  if (root == NULL)
    return 0;
  int count = 0;
  Node *curr = root;
  while(curr != NULL) {
      if (curr->left == NULL) {
          // print
          if (curr->data >= l && curr->data <=h)
            count++;
          curr = curr->right;
      } else {
          Node *pre = curr->left;
          
          while(pre->right != NULL && pre->right != curr)
            pre = pre->right;
          
          if (pre->right == NULL) {
              pre->right = curr;
              curr = curr->left;
          } else {
              pre->right = NULL;
              // print
              if (curr->data >= l && curr->data <=h)
                count++;
              curr = curr->right;
          }
      }
  }
  return count;
}

// set set-2
// Company Tags: DE-Shaw, Google
