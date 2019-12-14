#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int x) {
        key = x;
        left = right = NULL;
    }
};

// optimised code(writing fashion wise)
/* instead of keeping a counter and checking if it equal to given k
we simple reduce k every time no extra variable to maintain count and
when k becomes 0 we do our execution */
// void printAtK(Node *root, int k) {
//     if (root == NULL) return;
//     if (k == 0) {
//         cout << root->key << " ";
//     }
//     else {
//         printAtK(root->left, k-1);
//         printAtK(root->right, k-1);
//     }
// }

void printAtK(Node *root, int k, int n = 0) {
    if (n > k || root == NULL) return;
    if (n < k) {
        printAtK(root->left, k, n+1);
        printAtK(root->right, k, n+1);
    } else {
        cout << root->key << " ";
    }
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(70);
    int k = 2;
    printAtK(root, k);
    cout << endl;
}