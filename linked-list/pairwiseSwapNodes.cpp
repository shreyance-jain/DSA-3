/* 
Pairwise swap of nodes in LinkeList

Problem Statement

Given a linked list of N positive integers.
You need to swap elements pairwise.

Input Format:
The input line contains T, denoting the number of testcases.
Each testcase contains two lines,
the first line contains N(size of linked list).
The second line contains N elements of linked list separately.

Output Format:
For each testcase, in new line, print the modified linked list.

Constraint:
1 <= T <= 100
1 <= N <= 100
1 <= Node values <= 1000

Example:
Input:
2
7
1 2 3 4 5 6 7
6
1 2 3 4 5 6

Output:
2 1 4 3 6 5 7
2 1 4 3 6 5

Explanation:
Testcase 1: The linked list after swapping becomes: 1 2 3 4 5 6 7 -> 2 1 4 3 6 5 7.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void append(struct Node **head_ref, struct Node **tail_ref, int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", (node)->data);
        node = (node)->next;
    }
}

struct Node *pairwise_swap(struct Node *head);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l;
        cin >> n;
        struct Node *head = NULL;
        struct Node *tail = NULL;

        for (int i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }
        head = pairwise_swap(head);
        printList(head);
        cout << endl;
    }
}

/* Swaping the data is not a good option as data might not be as simple as integer in real scenrio
and copying the data is not a good option
 */
struct Node *pairwise_swap(struct Node *head)
{
    // if linked list is empty or only one node in linked list
    if (head == NULL || head->next == NULL)
        return head;

    // fix head and its next explcitly to avoid many if else in loop
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;

    // now fix all remaining nodes
    while (curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }

    prev->next = curr;

    return head;
}

// Time Complexity: Linear