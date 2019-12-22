/* 
Level order traversal in spiral form

Difficulty: Easy
Problem Statement

Complete the function to print spiral order traversal of a tree.

Input Format:
The task is to complete the method which takes one argument, root of the Tree.
The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called idividually.

Output Format:
The function should print level order traversal in spiral form .

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 3000
1 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 3 2
10 20 30 60 40

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the spiral level order would be 1 3 2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the spiral level order would be 10 20 30 60 40
 */


#include<bits/stdc++.h>
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

void printSpiral(struct Node *root);

/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    printSpiral(root);
    cout<<endl;
  }
    return 0;
}

/* We can print spiral order traversal in O(n) time and O(n) space
The idea is to use two stacks.
We use one stack to print from left to right
and one stack to print from right to left
In every iteration, we have nodes of one level in one of the stacks
We print the nodes and push nodes of next level in other stack */
void printSpiral(Node *root)
{
    stack<Node *> s1, s2;
    // we push first level in s1
    s1.push(root);

    // keep printing while any of the stacks have any node
    while(!s1.empty() || !s2.empty()) {
        // print nodes of current level from s1 and push nodes of next level in s2
        while(!s1.empty()) {
            Node *curr = s1.top();
            cout << curr->data << " ";
            s1.pop();
            // here we push right before left
            if (curr->right != NULL)
                s2.push(curr->right);
            if (curr->left != NULL)
                s2.push(curr->left);
            
        }
        // print nodes of current level from s2 and push nodes of next level in s1
        while(!s2.empty()) {
            Node *curr = s2.top();
            cout << curr->data << " ";
            s2.pop();
            // here we push left before right
            if (curr->left != NULL)
                s1.push(curr->left);
            if (curr->right != NULL)
                s1.push(curr->right);
        }
    }
}

// Company Tags: Accolite, Adobe, Amazon, Flipkart, Hike, Housing.com, MakeMyTrip, Microsoft
// Morgan Stanley, Ola Cabs, Payu, Teradata, Walmart 