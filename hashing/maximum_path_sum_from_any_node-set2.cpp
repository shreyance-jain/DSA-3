/* 
Maximum path sum from any node

Difficulty: Medium
Problem Statement

Given a binary tree of N edges, where every node contains distinct data.
The task is to find the maximum path sum. The path may start and end at any node in the tree.

Input:
First line of input contains number of testcases T.
For each testcase, there will be two lines,
first of which containing the number of edges (between two nodes) in the tree.
Next line contains N pairs (considering a and b) with a
'L' (means node b on left of a) or 'R' (means node b on right of a) after a and b.

Output:
Print the maximum path sum in the binary tree.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
6
10 2 L 2 20 L 2 1 R 10 -25 R -25 3 L -25 4 R
3
10 2 L 10 5 R 5 -2 R

Output:
32
17

Explanation:
Testcase 2: Path in the given tree goes like 2, 10, 5, which gives the max sum as 17.
 */


// C/C++ program to find maximum path sum in Binary Tree
#include<bits/stdc++.h>
using namespace std;

// A binary tree node
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

int findMaxSum(Node*);

void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
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
        cout<<findMaxSum(root)<<endl;
        
    }
    return 0;
}

/* For each node there can be four ways that the max path goes through the node:
1. Node only
2. Max path throught Left Child + Node
3. Max path through Right Child + Node
4. Max path through Left Child + Max path trough right child

The idea is to keep track of four paths and pick the max one in end. An important thing to note is,
root of every subtree need to return maximum path sum such that at most one child of root is involved.
This is needed for parent function call*/
int getMaxSum(Node *root, int &maxSum) {
    // base case, taking reference from maxSum code
    if (root == NULL)
        return 0;
    
    // left and right store maximum path going through left and right
    // child respectively
    int left_sum = getMaxSum(root->left, maxSum);
    int right_sum = getMaxSum(root->right, maxSum);
    
    // max sum for parent call of root. This path must include at-most
    // one child of root
   int max_single = max(max(left_sum, right_sum) + root->data, root->data);
    
   // max top represents the sum when the node under consideration is the root of
   // max sum path and no ancestors of root are there in max sum path
   int max_top = max(max_single, left_sum + right_sum + root->data);
    
    maxSum = max(maxSum, max_top); // store the maxSum
    
    return max_single;
}

int findMaxSum(Node* root)
{ 
    if (root == NULL)
        return 0;
    
    int maxSum = 0;
    getMaxSum(root, maxSum);
    return maxSum;
}

// Time Complexity: O(n), simply traverse tree in preorder fashion and does constant work at every node
// Company Tags: Accolites