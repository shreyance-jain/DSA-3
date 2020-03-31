// The idea is to use MORRIS TRAVERSAL

void printNearNodes(Node *root, int l, int h)
{
    // inorder traversal
    if (root == NULL)
        return;
    Node *current = root;
    Node *pre;
    
    while(current != NULL) {
        if (current->left == NULL) {
            if (current->data >= l && current->data <= h) {
                cout << current->data << " ";
            }
            current = current->right;
        } else {
            pre = current->left;
            while(pre->right != NULL && pre->right != current)
                pre = pre->right;
            
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                if (current->data >= l && current->data <= h) {
                    cout << current->data << " ";
                }
                current = current->right;
            }
        }
    }
}

// implements Morris Traveral which is inorder traversal in O(1) space
// and at time of printing the node
// prints only is node's data lie in given range