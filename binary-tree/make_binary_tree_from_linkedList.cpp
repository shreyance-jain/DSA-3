/* 
Make Binary Tree From Linked List

Difficulty: Medium
Problem Statement

Given a Linked List Representation of Complete Binary Tree.
The task is to construct the Binary tree.

Note : The complete binary tree is represented as a linked list in a way where
if root node is stored at position i,
its left, and right children are stored at position 2*i+1, 2*i+2 respectively.


10 -> 12 -> 15 -> 25 -> 30 -> 36

        10
      /    \
    12     15
   /  \     /
  25  30   36

 

Input:
First line of input contains number of testcases T. For each testcase,
first line of input contains length of linked list and next line contains linked list elements.

Output:
Output of each test case will be the level order traversal of the the constructed binary tree.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= Ki <= 103

Example(To be used only for expected output ) :
Input
2
5
1 2 3 4 5
5
5 4 3 2 1

Output:
1 2 3 4 5
5 4 3 2 1
 
 */


#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

/* Function to insert a node at the beginning of linked list */
void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

/* Function to do level order traversal of queue */
void lvl(TreeNode *r) {
    if (r == NULL) return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left) q.push(j->left);
        if (j->right) q.push(j->right);
    }
}

/* Function to reverse a linked list by reversing links(iterative) */
void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;
    cin >> T;
    while (T--) {
        struct Node *head = NULL;
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) cout << "-1";
        lvl(root);
        cout << endl;
        // inorder(root);
        getchar();
    }
    return 0;
}

/* Task:
10 -> 12 -> 15 -> 25 -> 30 -> 36

        10
      /    \
    12     15
   /  \     /
  25  30   36

We take a look at linked list head as root we know next two nodes are left and right children of root
Idea:
1. Create an empty queue
2. Make the first node as root of binary tree, and enqueue it to the queue
3. Until we reach end of linked list, do:
    1. Dequeue first node from queue, this is current parent
    2. Traverse two nodes of linked list, add them as children of current parent
    3. Enqueue the two nodes in queue
We might also observe we are given level order travresal of binary tree 
*/
void convert(Node *head, TreeNode *&root) {
    // edge case
    if (head == NULL)
        return;
    
    // queue to store parent nodes
    queue<TreeNode *> q;

    // head of linked list is always be root
    root = new TreeNode(head->data);
    q.push(root);

    // advance pointer
    Node *curr = head->next;

    // until end of linked list is reached
    while(curr != NULL) {
        // take node from queue (current parent whose child nodes will be set
        // and then these child nodes will be pushed to queue), and remove it from queue as canbe marked processed
        TreeNode *p = q.front();
        q.pop();
        
        // Take next two nodes of linked list
        TreeNode *left_child = NULL, *right_child = NULL;

        left_child = new TreeNode(curr->data);
        // push left child in queue, as they will be parents to future nodes
        q.push(left_child);

        // advance current pointer of linked list to set right child if any
        curr = curr->next;
        
        if (curr != NULL) {
            // set right child
            right_child = new TreeNode(curr->data);
            // push right child to queue
            q.push(right_child);
    
            // advance curr pointer of linked list
            curr = curr->next;
        }
        // assign left and right child of parents
        p->left = left_child;
        p->right = right_child;
    }
}


// Time Complexity: O(n)
// Space Complexity:  Theta(width) which is O(n) case balanced tree 

// Company Tags: Amazon
