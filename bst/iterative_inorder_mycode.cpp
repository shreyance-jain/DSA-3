/* Inorder Traversal without Recursion */

/*
Approach: Using stack is the obvious way to traverse tree without recursion

Algorithm:
1) Create an empty stack S
2) Initialise current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL
    a. pop the item from the stack
    b. print the popped item, set current = popped_item->right
if current is NULL and stack is empty we are done
 */

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int value)
{
    Node *temp=new Node;
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

Node *newNode(Node *root,int data)
{
    if(root==NULL)
    root=createNewNode(data);
    else if(data<root->data)
    root->left=newNode(root->left,data);
    else
    root->right=newNode(root->right,data);
    
    return root;
}

void pushnodes(Node *,stack<Node*> &s);
void popnodes(stack<Node*> &s);
void inOrder(Node *root);

int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=newNode(root,arr[i]);
        }
        
      
         inOrder(root);
         cout<<endl;
        
    }
	return 0;
}

void popnodes(stack<Node*> &s) {
    while(!s.empty()) {
        Node *curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right != NULL)
            pushnodes(curr->right, s);
    }
}

void pushnodes(Node *root, stack<Node*> &s) {
    while(root != NULL) {
        s.push(root);
        root = root->left;
    }
    popnodes(s);
}

void inOrder(Node *root) {
    Node *curr = root;
    stack<Node*> s;
    pushnodes(root, s);
}

// time complexity: O(n)
// aux space: O(h)