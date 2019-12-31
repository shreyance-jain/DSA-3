/* 
Check if subtree

Difficulty: Medium
Problem Statement

Given two binary trees with head reference as T and S having at most N nodes.
The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example:

S:          10
              /   \
            4     6
                 /
             30

T:                  26
                      /   \
                    10   3
                   /   \     \

               4       6     3
                       /
                    30

In above example S is subtree of T.

Please note that subtree has to be having same leaves non leaves.

   10
  /
20

For example, above tree is not subtree of

         10
       /     \
    20     50
   /   \
30   40

But a subtree of

         30
       /     \
    10     50
   /  
20  

Input Format:
First line of input contains number of testcases T. For each testcase, there will be 4 lines, first of which containing the number of edges (between two nodes) in the S tree. Next line contains N pairs (considering a and b) with a 'L' (means node b on left of a) or 'R' (means node b on right of a) after a and b. The next two lines of every test case contain details of tree T

Output Format:
For each testcase, there will be a single line containing 0 or 1, depending on the input.

Your Task:
Complete the function isSubtree() that takes two nodes as parameter and returns true or false.

ConstAssociated Course(s):   DSA-Self Paced with Doubt Assistance   Data Structures and Algorithms Moreraints:
1 <=    T <= 30
1 <=              N <= 103
 
Example:
Input    :
3
1
3 4 L
3
1 2 L 1 3 R 3 4 L
5
26 10 L 10 20 L 10 30 R 20 40 L 20 60 R
5
26 10 L 10 20 L 10 30 R 20 40 L 20 60 R
3
10 4 L 10 6 R 4 30 R
6
26 10 L 26 3 R 10 4 L 10 6 R 6 25 R 3 3 R

Output:
1
1
0

Explanation:
Testcase 3:
Structure of tree:
10 4 L 10 6 R 4 30 R
10 is root node of tree. Left child of 10 is 4 and right child of 10 is 6. Right child of 4 is 30. 
 */


#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define MAX 1000
// Structure of a tree node

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

bool isSubtree(Node *T, Node *S);
void storeInorder(Node *, char[], int &);
void storePreOrder(Node *, char[], int &);
bool areIdentical(Node *root1, Node *root2);

// Driver program to test above function
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        struct Node *child = NULL;
        map<int, Node *> m;
        int n;
        scanf(" %d", &n);
        struct Node *t2 = NULL;
        while (n--) {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end()) {
                parent = new Node(n1);
                m[n1] = parent;
                if (t2 == NULL) t2 = parent;
            } else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        struct Node *child1;
        map<int, Node *> m1;
        int nodes;
        scanf("%d", &nodes);
        struct Node *t1 = NULL;
        while (nodes--) {
            Node *parent1;
            char lr1;
            int n3, n4;
            scanf("%d %d %c", &n3, &n4, &lr1);
            if (m1.find(n3) == m1.end()) {
                parent1 = new Node(n3);
                m1[n3] = parent1;
                if (t1 == NULL) t1 = parent1;
            } else
                parent1 = m1[n3];
            child = new Node(n4);
            if (lr1 == 'L')
                parent1->left = child;
            else
                parent1->right = child;
            m1[n4] = child;
        }
        cout << isSubtree(t1, t2);
        cout << endl;
    }
}

// function to stroe inorder
void storeInorder(Node *root, char ch[], int& i) {
    // to handle cases as mentioned below
    if (root == NULL) {
        ch[i++] = '$';
        return;
    }
    storeInorder(root->left, ch, i);
    ch[i++] = root->data;
    storeInorder(root->right, ch, i);
}

// function to store preorder
void storePreOrder(Node *root, char ch[], int& i) {
    // to handle cases as mentioned below
    if (root == NULL) {
        ch[i++] = '$';
        return;
    }
    ch[i++] = root->data;
    storePreOrder(root->left, ch, i);
    storePreOrder(root->right, ch, i);
}


/* Idea is based on the fact that inorder and preorder/postorder
uniquely identify a tree

Algo:
1. find inorder of the two trees and store them in in1[], in2[]
2. find preorder of two trees and store them in pr1[], pr2[]
3. if in2[] is a subarray of in1[] and pr2[] is subarray of pr1[], the tree 2 is subtree of tree1 else not


The above algorithm doesn't work for cases where a tree is present
in another tree, but not as a subtree. Consider the following example.

        Tree1
          x 
        /    \
      a       b
     /        
    c         


        Tree2
          x 
        /    \
      a       b
     /         \
    c            d

The above algorithm can be extended by adding a special character whenever we encounter a NULL in inorder
and preorder traversals
*/
bool isSubtree(Node* T1, Node* T2) {
    // base cases
    if (T2 == NULL)
        return true;

    if (T1 == NULL)
        return false;

    // store inorder in in1[0..m-1] and in2[0..n-1]
    char in1[MAX], in2[MAX], pr1[MAX], pr2[MAX];

    int m = 0, n = 0;

    storeInorder(T1, in1, m);
    storeInorder(T2, in2, n);

    in1[m] = '\0', in2[n] = '\0';

    // if in2 is not substr of in1 retrun false
    if (strstr(in1, in2) == NULL)
        return false;
    
    // store preorder in pr1[0..m-1] and pr2[0..n-1]
    m = 0, n = 0;
    storePreOrder(T1, pr1, m);
    storePreOrder(T2, pr2, n);
    pr1[m] = '\0', pr2[n] = '\0';
    
    // if pr2 is substr of pr1 retrun true, else false
    return (strstr(pr1, pr2) != NULL);
}
// OPTIMISED
// Company Tags: Adobe, Amazon, Cavisson System, MakeMyTrip, Microsoft, Morgan Stanley, OYO Rooms, SAP Labs