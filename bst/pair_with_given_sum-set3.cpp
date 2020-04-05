// Different style of writing the same function as in set 2

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key) {
    if (root == NULL)
        return new Node(j=key);
    if (root->key > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

bool findPair(Node *root, int sum);

int main() {
    int t;
    cin >> t;
    while(t--) {
         int n, x, val;
         Node *root;
         cin >> n;
         for(int i = 0; i < n; i++) {
             cin >> val;
             root = insert(root, val);
         }
         cin >> x;
         if (findPair(root, x))
             cout << "1" << endl;
         else
            cout << "0" << endl;
    }
    return 0;
}

bool findPair(Node *root, int sum) {
    // iterators for bst
    stack<Node *> it1, it2;

    // initialising forward iterator
    Node *c = root;
    while(c != NULL)
        it1.push(c), c = c->left;

    // initialising backward iterator
    c = root;
    while(c != NULL)
        it2.push(c), c = c->right;
    
    // TWO POINTER TECHNIQUE
    while(it1.top() != it2.top()) {
        // variables to store value at it1 and it2
        int v1 = it1.top()->data, v2 = it2.top()->data;

        // base case
        if (v1 + v2 == sum)
            return true;

        // moving forward iterator
        if (v1 + v2 < sum) {
            c = it1.top()->right;
            it1.pop();
            while(c != NULL)
                it1.push(c), c = c->left;
        } 
        // moving backward pointer
        else {
            c = it2.top()->left;
            it2.pop();
            while(c != NULL)
                it2.push(c), c = c->right;
        }
    }
    return false;
}
// .... see another style of writing the same funciton in set-3
// Time complexity: O(n)
// Space complexity: O(h), which will be logn in case the bst is balanced

// Company tags: VMWare
