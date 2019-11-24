/* 
Rotate a Linked List

Problem Statement

Given a singly linked list of size N.
The task is to rotate the linked list counter-clockwise by k nodes,
where k is a given positive integer smaller than or equal to length of the linked list.

Input Format:
First line of input contains number of testcases T. For each testcase,
first line of input contains length of linked list and
next line contains linked list elements and last line contains k,
by which linked list is to be rotated.

Output Format:
For each testcase, print the rotated linked list.

Constratints:
1 <= T <= 100
1 <= N <= 103
1 <= k <= 103

Example:
Input:
3
8
1 2 3 4 5 6 7 8
4
5
2 4 7 8 9
3
2
1 2
4

Output:
5 6 7 8 1 2 3 4
8 9 2 4 7
1 2

Explanation:
Testcase 1: After rotating the linked list by 4 elements (anti-clockwise), we reached to node 5, which is (k+1)th node from beginning, now becomes head and tail of the linked list is joined to the previous head. 
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

Node *rotate(struct Node *head, int k);

Node *insert() {
    int n, i, value;
    struct Node *temp, *head = NULL;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
    return head;
}

void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}

/* Drier program to test above function*/
int main(void) {
    int t, k;
    scanf("%d", &t);
    while (t--) {
        Node *head = insert(); // insert function to build linked list
        scanf("%d", &k);
        head = rotate(head, k); // rotate linked list anti-clockwise  by k nodes
        printList(head);        // print linked list after rotation
    }
    return (0);
}

/* Approach: Rotating the linked list will change the head and tail of it
Start traverse the linked list (freeze a pointer on head)
when we reach Kth node (1-based indexing), freeze a pointer on kth node
also move till tail of the node
*/
Node *rotate(Node *head, int k)
{
    if (k == 0)
        return head;
    Node *current = head;
    int count = 1; // 1 based indexing
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL) // implies k is greater than no of nodes in linked list
        return head;     // count < k and we have reached the end of linked list
    // else mark the kth node
    struct Node *kthNode = current;
    // traverse till end to get hold of tail, as tail->next will be modified
    while (current->next != NULL)
        current = current->next;
    // we now have kth node, head and current -> tail
    // modify the links
    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
    return head;
}

// Company tags: Accolite, Amazon, MakeMyTrip