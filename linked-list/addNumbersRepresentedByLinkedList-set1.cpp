/* 
Add two numbers represented by linked lists

Problem Statement

Given two numbers represented by two linked lists of size N and M.
The task is to return a sum list.
The sum list which is a linked list representation of addition of two input numbers.

Note: In this question linked list start from least significant digit
In set-2 linked list start with most significant digit

Input:
First line of input contains number of testcases T. For each testcase,
first line of input contains length of first linked list and
next line contains N elements of the linked list.
Again, next line contains M, and following line contains M elements of the linked list.

Output:
Output the resultant linked list.

Constraints:
1 <= T <= 100
1 <= N, M <= 100

Example:
Input:
2
2
4 5
3
3 4 5
2
6 3
1
7

Output:
0 9 3 
0 7

Explaination:
5->4 // linked list repsentation of 45.
5->4->3 // linked list representation of 345.
0->9 ->3 // linked list representation of 390 resultant linked list.
 */

#include <bits/stdc++.h>

using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* addTwoLists(struct Node* first, struct Node* second);

/* Function to insert node at beginning of linked list */
void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    cout << endl;
}

void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}

/* Adds two linked list wiht heads first and second and retruns the resultant list */
Node* addTwoLists(Node* first, Node* second) {
    Node *res = NULL; // head of the resultant linked list
    Node *last = NULL;
    int carry = 0;

    // while both list exists   
    while(first || second) {
        int sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        // update carry for next calculation
        carry = sum / 10;
        // update sum if greater than 10
        sum = sum % 10;
        Node *temp = new Node(sum);
        if (res == NULL) {
            res = temp;
            last = temp;
        } else { // if not the first node of the resultant list
            last->next = temp;
            last = last->next;
        }
        if (first) first = first->next;
        if (second) second = second->next;
    }
    if (carry) 
        last->next = new Node(carry);
    // return head of the resultant list
    return res;
}

// Time Complexity: O(n+m) where n and m are no of nodes in first and second linked list respectively