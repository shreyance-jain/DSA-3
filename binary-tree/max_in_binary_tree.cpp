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

// optimise this code (no of lines wise, code should be very pro)
// int getMax(Node *root) {
//     if (root == NULL) return INT_MIN;
//     return max(root->key, max(getMax(root->left), getMax(root->right)));
// }

int maxof3(int a, int b, int c) {
    int max = (a > b) ? ((a > c) ? a :c ) : ((b > c) ? b : c);
    return max; 
}

int getMax(Node *root) {
    if (root == NULL) return INT_MIN;
    int lm = getMax(root->left);
    int rm = getMax(root->right);
    return maxof3(root->key, lm, rm);
}

int main() {
    Node *root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(80);
    root->left->left = new Node(110);
    root->left->right = new Node(20);
    cout << getMax(root) << endl;
}