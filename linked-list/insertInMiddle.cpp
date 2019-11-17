/* 
Insert in Middle of Linked List

Problem Statement

Given a linked list of size N and a key.
The task is to insert the key in the middle of the linked list.

Input Format:
First line of input contains number of testcases T.
For each testcase,
first line contains length of linked list N and
next line contains N elements to be inserted into the linked list and
the last line contains the element to be inserted to the middle.

Output Format:
For each testcase, there will be a single line of output containing the element of modified linked list.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
3
1 2 4
3
4
10 20 40 50
30

Output:
1 2 3 4
10 20 30 40 50

Explanation:
Testcase 1: The new element is inserted after the current middle element in the linked list.
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
};

void append(struct Node** head_ref, struct Node** tail_ref, int new_data);
void display(struct Node* head);
Node *insertAtMiddle(struct Node* head, int x);

// driver code
int main() {
    int n, k, T, l, x;
    cin >> T;
    while(T--) {
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> l;
            append(&head, &tail, l);
        }
        cin >> x;
        head = insertAtMiddle(head, x);
        display(head);
    }
    return 0;
}

/* Function to append in a linked list
We maintain a tail pointer to insert at the middle in O(1) time
because of frequent insertions at last 

We pass pointer to pointer since we will be modifying the value
where the tail pointer will be pointing to after every append*/
void append(struct Node** head_ref, struct Node** tail_ref, int new_data) {
    struct Node* new_node =  new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*tail_ref)->next = new_node;
    }
    *tail_ref = new_node;
}

void display(struct Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* 
Approach: get hold of middle node of the linked list
Technique to get pointer to middle node:
- Use two pointer slow and fast
- initialise slow from head
- initialise fast from head if you want to get hold of second middle element when no of elements are even
  or initialise fast by head->next if you want to get hold of first middle element when no of elements in ll are even
- Increment the slow pointer by 1 and fast pointer by 2
- when fast or fast->next becomes NULL, slow pointer is at middle element

Now problem simply reduces to add a node after a given node
 */
Node *insertAtMiddle(struct Node* head, int x) {
    // if list is empty
    if (head == NULL) return (new Node(x));

    // create a new node
    Node* newNode = new Node(x);

    // initialise slow pointer with head
    Node* slow = head;

    // initialise fast pointer with head->next since in question we want to add after first middle element
    // when number of nodes in ll is even
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;  // when fast will reach end, slow will be at the mid point
        fast = fast->next->next; // fast moves two nodes at a time
    }
    newNode->next = slow->next;
    slow->next = newNode;

    return head;
}

// Time Complexity: O(n), single traversal
// Space Complexity: O(1)