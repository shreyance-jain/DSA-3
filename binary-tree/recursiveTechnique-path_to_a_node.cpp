/* 
Suppose we are given a data value of a node in binary tree and a binary tree
What if we need to find (exact) path to this node
we can store the path in an array

For example:

        10
       /  \
      20  30
     / \
   40  60
  / \  /
70  80 90

So here let say :
1. value to be searched is 80
so path would be 10->20->40->80

2. value to be searched is 90
so path woule be 10->20->60->90

Note: exact path is required
So nodes traversed in preorder(or any other order per say) which do not lead to required node need not be present in path

=> which implies, in solution we need to omit the nodes which do not lead to result node [way to proceed for solution]
 */

#include <iostream> 
#include <vector> 
  
using namespace std; 
  
// A Binary Tree node 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
}

/*we use a boolean if path exists else false 
we use this to reject/remove the root/node from path vector
if it is not part of path from root to key*/
bool fillPath(Node *root, int key, vector<int> &path) {
    // base case
    if (root == NULL)
        return false;
    
    // store this node in path vector,
    // we will remove this node if not in path from root to key
    path.push_back(root->key);
    // compare
    if (root->key == key)
        return true;
    
    // need to check/know if current node leads to correct path
    if ((root->left && fillPath(root->left, key, path)) || 
        (root->right && fillPath(root->right, key, path)))
        return true;

    // if not present in subtree rooted with root,
    // remove root from path[] and return false
    path.pop_back();
    return false;
}

// wrapper around get path to a node (exact path)
void findPath(Node *root, int n) {
    vector<int> path;
    fillPath(root, n, path);
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
}

// Driver program to test above functions 
int main() 
{ 
    // Let us create the Binary Tree shown in above diagram. 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    /* 
                1
            2       3
        4      5 6      7
     */
    cout << "Path(5) = ";
    findPath(root, 5); 
    cout << "\nPath(6) = ";
    findPath(root, 6); 
    cout << "\nPath(3) = ";
    findPath(root, 3); 
    cout << "\nPath(2) = ";
    findPath(root, 2); 
    cout << "\nPath(4) = ";
    findPath(root, 4); 
    cout << "\nPath(7) = ";
    findPath(root, 7); 
    cout << endl;
    return 0; 
}

/* 
Output: (as seen on terminal)
Path(5) = 1 2 5 
Path(6) = 1 3 6 
Path(3) = 1 3 
Path(2) = 1 2 
Path(4) = 1 2 4 
Path(7) = 1 3 7 
 */