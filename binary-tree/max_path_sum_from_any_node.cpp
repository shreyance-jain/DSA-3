/* 
Maximum path sum from any node

Difficulty: Medium
Problem Statement

Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Input:
First line of input contains the number of test cases T.
For each test case, there will be only a single line of input which is a string
representing the tree as described below: 
The values in the string are in the order of level order traversal of the tree where,
numbers denotes node values, and a character “N” denotes NULL child.
For example:
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Print the maximum path sum in the binary tree.

User Task:
The task is to complete the findMaxSum() that takes root as input and returns max sum.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 103
1 <= |Data on node| <= 104

Example:
Input:
2
10 2 -25 20 1 3 4
10 2 5 N N N -2
Output:
32
17

Explanation:
Testcase 2: Path in the given tree goes like 2, 10, 5, which gives the max sum as 17.
 */

// { Driver Code Starts



#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// Driver code
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << findMaxSum(root) << "\n";

    }
    return 0;
}

/* Approach: For each node there can be four ways that the max path go through the node:
1. Node only
2. Max path through Left Child + Node
3. Max path through Right Child + Node
4. Max path through Left Child + Node + max path through Right Child

The idea is to keep trace of four paths and pick up the max one in the end.
An important thing to note is, root of every subtree need to return maximum path 
such that at most one child of root is involved. This is needed for parent function call
In the below code, this sum is stored in 'max_single' and is returned by the recursive function
*/
int findMaxUtil(Node *root, int &res) {
    // base case
    if (root == NULL)
        return 0;
    
    // l and r store max path sum going throught left 
    // and right child of root respectively
    int l = findMaxUtil(root->right, res);
    int r = findMaxUtil(root->left, res);

    // max path for parent call of root. This path must include
    // at-most one child of root
    int max_single = max(max(l, r) + root->data, root->data);

    // Max Top represents the sum when node under consideration is the root of maxSum path
    // and no ancestors of root are there in max sum path
    int max_top = max(max_single, l + r + root->data);

    res = max(res, max_top); // store the max result

    return max_single;
}

int findMaxSum(Node *root) {
    int res = 0;
    findMaxUtil(root, res);
    return res;
}

// Time complexity: O(n)