/* 
Merge Sort on Doubly Linked List

Problem Statement

Given Pointer/Reference to the head of a doubly linked list of N nodes,
the task is to Sort the given doubly linked list using Merge Sort in
both non-decreasing and non-increasing order.

Input Format:
There are be multiple test cases, for each test case function mergeSort() will be called separately.
The only input to the function is the pointer/reference to the head of the doubly linked list.

Output Format:
For each test, print the sorted doubly linked list in both order i.e. in non-decreasing and non-increasing order.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
8
7 3 5 2 6 4 1 8
5
9 15 0 -1 0

Ouput:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
-1 0 0 9 15
15 9 0 0 -1

Explanation:
Testcase 1: After sorting the given linked list in both ways, resultant matrix will be as given in the first two line of output, where first line is the output for non-decreasing order and next line is for non-increasing order.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;
    Node (int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

/* Function to insert at the head of doubly linked list */
void insert(Node **head_ref, int new_data) {
    Node *temp = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = temp;
    } else {
        temp->next = *head_ref;
        (*head_ref)->prev = temp;
        *head_ref = temp;
    }
}

/* Function to print the linked list in forward and reverse direction */

void print(Node *head) {
    Node *temp = head;
    // maintain a pointer just before head, so when head reached NULL temp points to last node of linked list
    // then we have a pointer temp at the last node of the linked list and we move in prev direction from there
    // or what we can simply do is using one pointer only is to iterate till head->next not becomes null
    while(head) {
        cout << head->data << " ";
        temp = head;
        head = head->next;
    }

    cout << endl;

    while(temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

Node *sortDoubly(Node *head);
Node *split(Node *head);
Node *sortedMerge(Node *first, Node *second);

// driver program
int main() {
    long test;
    cin >> test;
    while(test--) {
        int n, temp;
        cin >> n;
        struct Node *head = NULL;
        while(n--) {
            cin >> temp;
            insert(&head, temp);
        }
        head = sortDoubly(head);
        print(head);
    }
    return 0;
}

Node *sortDoubly(Node *head) {
    
    if (head == NULL || head->next == NULL)
        return head;
    
    // split into two halves
    Node *second = split(head);

    // recur on two halves
    head = sortDoubly(head);
    second = sortDoubly(second);

    // merge two sorted halves
    return sortedMerge(head, second);
}

Node *split(Node *head) {
    // the point here is when there are 2 nodes then we should slpit it from middle
    // or in other words we should split from first middle node when even no of nodes
    Node *slow = head;
    Node *fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

Node *sortedMerge(Node *first, Node *second) {
    if (!first) return second;
    if (!second) return first;

    if (first->data <= second->data) {
        first->next = sortedMerge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = sortedMerge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}