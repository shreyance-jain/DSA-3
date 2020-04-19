/* 
Preorder to Postorder
Difficulty: Medium
            
Problem Statement
Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, the size of array. The second line of each test case contains N input as arr[i].

Output:
Postorder traversal of the given preorder traversal is printed.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= arr[i] <= 104

Example:
Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120

Output:
35 30 100 80 40
35 32 30 120 100 90 80 40
 */

#include<iostream>
#include<math.h>

using namespace std;

void convert(int arr[], int n);

int main()
 {
	// construct bst from preorder
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    convert(arr, n);
	    cout << endl;
	}
	return 0;
}

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

/* Efficient Approach:
An efficient approach is to find postorder traversal without constructing the tree.
The idea is to traverse the given preorder array and maintain a range in which
current element should lie. This is to ensure BST property is always satisfied.
Initially the range is set to {minval = INT_MIN, maxval = INT_MAX}.
In preorder traversal the first element is always the root and it will certainly
lie in initial range.
So store the first element of the preorder array.
In postorder traversal, first left and right subtrees are printed and then root data is printed.
So first recursive calls for left and right subtrees are performed and then the value of the 
root is printed.
For left subtree range is updated to {minval, root->data} and for right subtree range is updated to {root->data, maxval}.
If current preorder array element does not lie in the range specified for it, then it does not
belong to current subtree, return from recursive calls until correct position of that element
is not found.
 */
void construct(int arr[], int *preIndex, int key, int min, int max, int size) {
    if (*preIndex >= size)
        return;

    Node *root = NULL;
    
    if (key > min && key < max) {
        root = new Node(key);
        (*preIndex)++;
        if (*preIndex < size) {
            construct(arr, preIndex, arr[*preIndex], min, root->data, size);
            construct(arr, preIndex, arr[*preIndex], root->data, max, size);
        }
        cout << root->data << " ";
    }
}

void convert(int arr[], int n) {
    int preIndex = 0;
    construct(arr, &preIndex, arr[0], INT_MIN, INT_MAX, n);
    
}

// Another style of writng construct funtion
void findPostOrderUtil(int pre[], int n, int minval, int maxval, int &preIndex) {
  if (preIndex == n)
    return;
  
  if (pre[preIndex] < minval || pre[preIndex] > maxval)
    return;
  
  int val = pre[preIndex];
  preIndex++;

  findPostOrderUtil(pre, n, minval, val, preIndex);
  findPostOrderUtil(pre, n, val, maxval, preIndex);

  cout << val << " ";
}

// Time complexity: O(n)
// Space complexity: O(h) for function call stack

// Company tags: Amazon, LinkedIn
