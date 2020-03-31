// INORDER TRAVERSAL WITHOUT RECURSION AND WITHOUT STACK BINARY TREE

/* 
Using Morris Traversal we can traverse the tree without using stack and recursion
The idea of Morris Tree is based on THREADED BINARY TREE, In this traversal we first
create links to Inorder successor and print the data using these links, and finally
revert the changes to restore original tree 
 */

/* Algo:
1. Initialise current as root
2. While current is not NULL
    If current does not have a right child
        a) Print current's data
        b) Go to right, i.e., current = current->right
    Else
        a) Make current node as right child of the rightmost node in current's left subtree
        b) Go to this left child, i.e., current = current->left
*/

#include <bits/stdc++.h>
using namespace std;

struct tNode {
    int data;
    tNode* left, right;
    tNode(int x) {
        data = x;
        left = right = NULL;
    }
}

void MorrisTraversal(tNode *root) {
    if (root == NULL)
        return;
    
    tNode *current = root;
    tNode *pre; // inorder predecessor whose suceesor would be current
    while(current != NULL) {
        // if left child is NULL, print current node and move to right child
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        } else {
            // find inorder predeccesor of current
            pre = current->left;
            while(pre->right != NULL && pre->right != current)
                pre = pre->right;
            
            // make current as right child of its inorder predecessor
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
            // revert the changes made in the 'if' part to restore the original tree
            // i.e., fix the right child of the predecessor
            else {
                // break created links
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } // end of if condition if pre->right == NULL
        } // end of if condition current->left == NULL
    } // end of while
}

int main() {
    struct tNode *root = new tNode(1);
    root->right = new tNode(3);
    root->left = new tNode(2);
    root->left->left = new tNode(4);
    root->left->right = new tNode(5);

    MorrisTraversal(root);
}

/* Time Complexity: O(n) If we take a closer look,  we can notice that every edge of the tree
is traversed at most two times.
And in the worst case, the same number of extra edges
(as input tree) are created and removed */