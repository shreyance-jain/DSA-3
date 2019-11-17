/* 
Count nodes of linked list

Problem Statement

Given a singly linked list.
The task is to find the length of linked list,
where length is defined as number of nodes in the linked list.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains number of nodes N,
to be inserted into the linked list and next line contains data of N nodes.

Output:
There will be a single line of output for each testcase, which contains length of the linked list.

Constraints:
1 <= T <= 30
1 <= N <= 100
1 <= value <= 103

Example:
Input:
2
5
1 2 3 4 5
7
2 4 6 7 5 1 0

Output:
5
7

Explanation:
Testcase 1: Count of nodes in the linked list is 5, which is its length.
 */


#include <bits/stdc++.h>
using namespace std;

void push(struct Node** head_ref, int new_data);
int getCount(struct Node* head);

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

int main() {
    int T, i, n, l;
    cin >> T;
    while(T--) {
        struct Node* head = NULL;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> l;
            /* here we have two options:
            1. pass head to insertAtBegin i.e. push function and return the new head after inserting at beginning
               and and update the new head
               because, with pointer we can only change the value it is pointing to we cannot change where it is pointing to
            2. pass address of head, contain it in double pointer, i.e. pointer to pointer, add a new node and chnage
               where head is pointing to (chnage where pointer is pointing to   ) */
            // Here we are implementing the second approach, 
            // approach no.1 is used in linked list insertion.cpp
            push(&head, l);
        }
        // check the count function
        cout << getCount(head) << endl;
    }
}

void push(Node** head_ref, int new_data) {
    struct Node* new_node = new Node(new_data);
    new_node-> next = *head_ref;
    (*head_ref) = new_node;
}

int getCount(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head-> next;
    }
    return count;
}