/* 
Reverse a linked list
   
Problem Statement

Given a linked list of N nodes. The task is to reverse this list.

    Input: Head of following linked list
    1->2->3->4->NULL
    Output: Linked list should be changed to,
    4->3->2->1->NULL

    Input: Head of following linked list
    1->2->3->4->5->NULL
    Output: Linked list should be changed to,
    5->4->3->2->1->NULL

    Input: NULL
    Output: NULL

    Input: 1->NULL
    Output: 1->NULL

Input:
First line of input contains number of testcases T.
For each testcase, first line contains length of linked list and
next line contains the elements of linked list.

Output:
Reverse the linked list and return head of the modified list.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
6
1 2 3 4 5 6
5
2 7 8 9 10

Output:
6 5 4 3 2 1
10 9 8 7 2

Explanation:
Testcase 1: After reversing the list, elements are as 6->5->4->3->2->1.
 */


#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

/* Function to append a node in linked list, maintains a reference/pointer to 
linked list head's and tail's pointer/reference */
void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    // if linked list is empty
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node *reverseList(struct Node *head, struct Node *prev);

/* Function to print a linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}
/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;
    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
       head = reverseList(head, NULL);
       printList(head);
       cout << endl;
    }
    return 0;
}

/* This approach is based on the iterative approach used for reversing the linked list
we have reversed the linked list till prev and head is at curr*/
Node* reverseList(Node *curr, Node *prev = NULL)
{
    // base case when curr reaches NULL return prev
    // which will be new head
    if (curr == NULL)
        return prev;
    // get hold of remaining linked list as next of curr will be changed
    Node *next = curr->next;
    // change the next of curr to prev
    // now linked list till prev is reversed
    curr->next = prev;
    
    // now next will be the head (head of un-reversed linked list)
    // curr will be sent in prev and now linked list till curr is reversed
    return reverseList(next, curr);
}

// Time Complexity: O(n)
// Aux Space Complexity: O(1)

// Company Tags: Accolite, Adobe, Amazon, Cisco, Cognizant, D-E-Shaw, Goldman Sachs, IgniteWorld, Intuit,
// Mahindra Comviva, MakeMyTrip, Microsoft, Paytm, Qualcomm, Samsung, SAP Labs, Snapdeal, Tejas Networks,
// Teradata, VMWare, Walmart, Zoho