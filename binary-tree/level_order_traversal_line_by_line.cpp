/* 
Level order traversal Line by Line

Difficulty: Easy
Problem Statement

Given a Binary Tree, your task is to print its level order traversal such that each level is separated by $.
For the below tree the output will be 1 $ 2 3 $ 4 5 6 7 $ 8 $.

          1
       /     \
     2        3
   /    \     /   \
  4     5   6    7
    \
     8

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow.
Each testcase contains two lines of input. The first line of input contains number of edges.
The second line contains relation between nodes.

Output Format:
For each testcase, in a new line, print the output in required format.

Constraints:
1 <= T<= 100
1 <= Number of edges <= 1000
1 <= Data of a node <= 100

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 $ 3 2  $
10 $ 20 30 $ 40 60 $

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the level order would be 1 $ 3 2 $
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the level order would be 10 $ 20 30 $ 40 60 $
 */


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

void levelOrder(struct Node* node);

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
     levelOrder(root);
     cout << endl;
  }
  return 0;
}

//You are required to complete this method
void levelOrder(Node* node) {
    queue<Node *> q;
    q.push(node);
    while (q.empty() == false) {
        int count = q.size();
        for (int i = 0; i < count; i++) {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << "$ ";
    }
}