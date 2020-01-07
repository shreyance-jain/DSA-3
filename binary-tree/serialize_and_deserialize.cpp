/* 
Serialize and Deserialize a Binary Tree

Difficulty: Medium
Problem Statement

Serialization is to store a tree in an array so that it can be later restored and
Deserialization is reading tree back from the array.
Now your task is to complete the function serialize which stores the tree into an array A[ ]
and deSerialize which deserializes the array to tree and returns it.
Note: The structure of tree must be maintained.

Input Format:
The method serialize takes  two arguments,
the first is the root of Binary Tree and second argument is an array A[ ]
which stores the serialized tree.
The method deSerialize takes only one argument which is the serialized array A[]
and returns the deserialzed tree's root .
The struct Node has a data part which stores the data, pointer to left child and pointer to right child

Output Format:
The  output in the expected output will be the inorder traversal of the returned tree .

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 100

Example(To be used only for expected output):
Input
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
2 1 3
40 20 60 10 30 
 */


#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void serialize(Node *root,vector<int> &);
Node * deSerialize(vector<int> &);

/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     int N = n;
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    vector<int> A;
    A.clear();
    serialize(root,A);
  //  for(int i=0;i<A.size();i++)
    //    cout<<A[i]<<" ";
      //  cout<<endl;
    // inorder(root);
     //cout<<endl;
    Node *tree_made = deSerialize(A);
    inorder(tree_made);
    cout<<endl;
  }
  return 0;
}

/*this  function serializes 
the binary tree and stores 
it in the vector A*/
void serialize(Node *root,vector<int> &A)
{
    if (root == NULL) {
        A.push_back(-1);
        return;
    }
    
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}

void deser(Node **root, vector<int> &A, int *i, int n) {
    if (*i >= n)
        return;
    if (A[*i] == -1) {
        (*root)->left = NULL;
        (*i)++;
    } else {
        (*root)->left = new Node(A[*i]);
        (*i)++;
        deser(&((*root)->left), A, i, n);
    }
    if (A[*i] == -1) {
        (*root)->right = NULL;
        (*i)++;
    } else {
        (*root)->right = new Node(A[*i]);
        (*i)++;
        deser(&((*root)->right), A, i, n);
    }
}

/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
    Node *root = new Node(A[0]);
    int n = A.size();
    int i = 1;
    deser(&root, A, &i, n);
    return root;
}

// the code to deserialise can be optimised,
// see set-2 of this problem