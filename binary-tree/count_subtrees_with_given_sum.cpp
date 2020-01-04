/* 
Count Number of SubTrees having given Sum

Difficulty: Medium
Problem Statement

Given a binary tree containing N+1 with N edges nodes and an integer X.
Your task is to complete the function countSubtreesWithSumX()
that returns the count of the number of subtress having total node’s data sum equal to a value X.

 Example: For the tree given below:            

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains number of edges in the tree.
Next line contains information as X Y L or X Y R which means
Y is on the left of X or Y is on the right of X respectively.
Last line contains sum.

Output:
For each test case count the number of subtrees with given sum.

Constraints:
1 <= T <= 103
1 <= N <= 103
-103 <= Node Value <= 103

Example:
Input:
2
6
5 -10 L 5 3 R -10 9 L -10 8 R 3 -4 L 3 7 R
7
2
1 2 L 1 3 R
5

Output:
2
0

Explanation:
Testcase 1: Subtrees with sum 7 are [9, 8, -10] and [7].
 */


//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

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

int countSubtreesWithSumX(Node* root, int x);

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     int x;
     cin>>x;
     cout << countSubtreesWithSumX(root, x)<<endl;
  }
  return 0;
}

/* We calculate sum in bottom up fashion
and at every root we check of sum is equal to given value increment count
 */
int count_using_sum(Node *root, int x, int *count) {
    if (root == NULL)
        return 0;
    
    int lsum = count_using_sum(root->left, x, count);
	int rsum = count_using_sum(root->right, x, count);
	
	int subtree_sum = lsum + rsum + root->data;
	
	if (subtree_sum == x)
	    (*count)++;
	    
	return subtree_sum;
}

int countSubtreesWithSumX(Node* root, int x)
{
	if (!root)
	    return 0;
	
	int count = 0;
	count_using_sum(root, x, &count);
	return count;
}

// Time Complexity: O(n)
// Company Tags: Microsoft