// INSERT IN AVL TREE
/* Algo:
1. Perform normal BST insert
2. Traverse all ancestors of the newly inserted node from the node to root
3. If find an unbalanced node, check for any of the cases below:
    a. left left
    b. right right
    c. left right
    d. right left
*/ // for conecpts on AVL tree see dsa notes
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int x) {
        key = x;
        left = right = NULL;
        height = 1; // new node is initially added at leaf
    }
};

// utility function to verify output of code
void levelorder(Node * node) {
    if (node == NULL)
        return;
    queue<Node *> q;
    q.push(node);
    while(!q.empty()) {
        int count = q.size();
        for(int i = 0; i < count; i++) {
            Node *temp = q.front();
            q.pop();
            cout << temp->key << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}

// utility function to get height of the tree rooted with node N
int height(Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

// utility function to get balance factor of a node N in AVL tree
int getBalance(Node *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

// utility function to left rotate subtree rooted with x    
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotations
    y->left = x;
    x->right = T2;

    // update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // return new node
    return y;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotations
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // return new node
    return x;
}

Node *insert(Node *node, int key) {
    // step 1 of algo: perform normal bst insert
    if (node == NULL)
        return new Node(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    // update height
    node->height = max(height(node->left), height(node->right)) + 1;

    // check for unbalance
    int balance = getBalance(node);

    // check various conditions

    // Left Left case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    
    // Right Right case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    
    // Left Right case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main() {
    int arr[] = {15, 5, 40, 20, 50, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node *root = NULL;
    for(int i = 0; i < n; i++)
        root = insert(root, arr[i]);
    levelorder(root);
    return 0;
}

