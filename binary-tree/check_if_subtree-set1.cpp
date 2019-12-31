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


/* Approach: Traverse the tree in pre-order fashion. For every visited node
see if subtree rooted with this node is identical to S */
bool isSubtree(Node* T1, Node* T2) {
    // base case
    if (T2 == NULL)
        return true;

    if (T1 == NULL)
        return false;
    // check the tree with root as current node
    if (areIdentical(T1, T2))
        return true;
    // if the tree with current node does not match
    // then try left and right subtree one by one
    return isSubtree(T1->left, T2) ||
        isSubtree(T1->right, T2);
}

// function to check if two trees wiht roots as root1 and root2
// are identical or not
bool areIdentical(Node *root1, Node *root2) {
    // base case
    if (root1 == NULL && root2 == NULL)
        return true;
    
    if (root1 == NULL || root2 == NULL)
        return false;
    
    // check if data of both roots is same and data of left and right
    // subtress are also same
    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}

// Time Complexity: O(m * n) where m and n are number of nodes in given two trees

// CAN BE OPTIMISED ON TIME
// Company Tags: Adobe, Amazon, Cavisson System, MakeMyTrip, Microsoft, Morgan Stanley, OYO Rooms, SAP Labs