/* 
Identical Linked Lists

Problem Statement

Given two Singly Linked List of N and M nodes respectively.
The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have same data and with same arrangement too.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked lists N and M and next line contains elements of the linked lists.

Output:
For each test the output will be 'Identical' if two list are identical else 'Not identical'.

User Task:
The task is to complete the function areIdentical() which takes head of both linked lists as arguments and returns True or False.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
6
1 2 3 4 5 6
4
99 59 42 20
5
1 2 3 4 5
5
1 2 3 4 5

Output:
Not identical
Identical

Explanation:
Testcase 1: Each element of first linked list is not equal to each elements of second linked list in the same order.
Testcase 2: Each element of first linked list is equal to each elements of second linked list in the same order.
 
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to push in linked list, insert at begin */
void push(struct Node** head_ref, int new_data);
bool areIdentical(struct Node *head1, struct Node *head2);

// driver code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n1, n2, temp;
        struct Node *a = NULL;
        struct Node *b = NULL;
        cin >> n1;
        while (n1--) {
            cin >> temp;
            push(&a, temp);
        }
        cin >> n2;
        while(n2 --) {
            cin >> temp;
            push(&b, temp);
        }
        areIdentical(a, b) ? cout << "Identical" << endl : cout << "Not identical" << endl;
    }
}

/* Function to push in linked list, insert at begin */
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* For linked lists to be identical
1. length should be same
2. data should be in same order
3. each corresponding node should have same data */
bool areIdentical(struct Node *head1, struct Node *head2) {
    // traverse both the linked list
    while(head1 != NULL && head2 != NULL) {
        // if both nodes data is not equal return false
        if (head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    // if both node reached end after same amount of traversal then only return true
    return (head1 == NULL && head2 == NULL);
}