/* 
Delete without head pointer

Problem Statement

You are given a pointer/ reference to the node which is to be deleted
from the linked list of N nodes.
The task is to delete the node.
Pointer/ reference to head node is not given. 

Note: No head reference is given to you.

Input Format:
First line of input contains number of testcases T.
For each testcase, first line of input contains length of linked list and
next line contains the data of the linked list.
The last line contains the node to be deleted.

Output Format:
For each testcase, in a newline, print the linked list after deleting the given node.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
2
1 2
1
4
10 20 4 30
20

Output:
2
10 4 30

Explanation:
Testcase 1: After deleting 20 from the linked list, we have remaining nodes as 10, 4 and 30.
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
} *head; // global head in program

void insert() {
    int n, i, value;
    // maintaining a pointer at end of linked list to insert in constant time
    Node *temp;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

// function to print the ll
void printList(Node *node) {
    while(node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// function to find node with given data
Node *findNode(Node *head, int search_for) {
    Node *current = head;
    while(current != NULL) {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}

void deleteNode(Node *node);
// driver code
int main(void) {
    int t, k, n, value;
    cin >> t;
    while (t--) {
        insert();
        cin >> k;
        Node *del = findNode(head, k);
        // to ensure node to be deleted is not last node
        if (del != NULL && del->next != NULL) {
            deleteNode(del);
        }
        printList(head);
    }
    return 0;
}

/* The function may assume node to be deleted exists in ll and is not the last node of ll
    node: reference to the node which is to be deleted
 */
/* 
This is a trick question,
and code is very classy
suppose the linked list is as below and 30 needs to be deleted

input => 10-20-30-40-50-60-70-80-90
result=> 10-20-40-50-60-70-80-90

The approach is copy the value of next of node to be deleted
and the code is very classy because we not copy the values
we do not keep on repeating this till end by running a loop till end
but just copy the value of next of node and delete the next of node
the remaining linked list is just same
 */
void deleteNode(Node *node) {
    // get hold of next node as for freeing the memory in C++ in JAVA GC is automatic
    Node *temp = node->next;
    node->data = temp->data; // copy the data of next node
    node->next = temp->next; // delete the link to next node and link to remaing ll which will remain same
    delete(temp); // free memory
}

// Company tags: Amazon, Goldman Sachs, Kritikal Solutions, Microsoft, Samsung, Visa