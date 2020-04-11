#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}

// Structure formed to store details of the ancestor
struct NodeDetails {
  Node *ptr;
  int min, max;
};


/* Approach:
The idea is to make a struct element NodeDetails
which contains pointer to the node, minimum data and maximum data of the ancestor.
Now:
- Push the root node to the queue of type NodeDetails
- Extract NodeDetails of a node from the queue and compare them with minimum and maximum values
- Check whether there are more elements in arr[] and arr[i] can be the left child of 'temp.ptr' or not
- Check wheter there are more elements in arr[] and arr[i] can be the right child of 'temp.ptr' or not
- End the loop when the queue becomes empty
 */

// SAME FUCNTION AS IN SET-2 WRITING STYLE IS DIFFERENT
Node* constructBst(int arr[], int n)
{
    if (n == 0)
        return NULL;
    
    queue<NodeDetails> q;
    // index variable to access array elements
    int i = 0;

    // node details for the root of the bst
    NodeDetails newNode;
    newNode.ptr = new Node(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);

    // getting the root of the bst
    Node *root = newNode.ptr;

    // until there are no more elements in arr[]
    while(i < n) {
        // extracting node details of a node from the queue
        NodeDetails temp = q.front();
        q.pop();
        
        // check whether arr[i] can be the left child of node
        if (arr[i] < temp.ptr->data && arr[i] > temp.min) {
            // create NodeDetails for the newNode 
            // and add it to the queue
            newNode.ptr = new Node(arr[i++]);
            newNode.min = temp.min;
            newNode.max = temp.ptr->data;
            q.push(newNode);

            // make this 'newNode' as left child of the 'temp.ptr'
            temp.ptr->left = newNode.ptr;
        }
        // check whether there are more elements in arr[] and
        // arr[i] can be the right child of node
        if (i < n && arr[i] > temp.ptr->data && arr[i] < temp.max) {
            // create NodeDetails for the newNode and add it to the queue
            newNode.ptr = new Node(arr[i++]);
            newNode.min = temp.ptr->data;
            newNode.max = temp.max;
            q.push(newNode);

            // make this 'newNode' as right child of 'temp.ptr'
            temp.ptr->right = newNode.ptr;
        }
    }
    // root of the required BST
    return root;
}

// Time Complexity: O(n)
// Space Complexity: O(n), worst case in complete bst.
