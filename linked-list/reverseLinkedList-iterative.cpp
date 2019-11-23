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
struct Node *reverseList(struct Node *head);

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
       head = reverseList(head);
       printList(head);
       cout << endl;
    }
    return 0;
}

Node* reverseList(Node *head)
{
  Node *prev = NULL, *curr = head;
  
  while(curr != NULL) {
      // get hold of the remaining linked list as we are going to change next of curr
      Node *next = curr->next;
      // change next of prev, assuming linked list till prev is reversed
      curr->next = prev;
      
      // update prev to curr because now linked list is reversed till this pointer
      prev = curr;
      // advance curr, which would in turn advance next pointer in next iteration
      curr = next;
  }
  // when curr becomes null we come out of loop
  // prev will now be pointing to last node of original
  // which will now be new head of linked list
  head = prev;
  return head;
}

// Time Complexity: O(n) works much faster as it just changes the links and no copying of data takes place
// Aux Space Complexity: O(1)

// Company Tags: Accolite, Adobe, Amazon, Cisco, Cognizant, D-E-Shaw, Goldman Sachs, IgniteWorld, Intuit,
// Mahindra Comviva, MakeMyTrip, Microsoft, Paytm, Qualcomm, Samsung, SAP Labs, Snapdeal, Tejas Networks,
// Teradata, VMWare, Walmart, Zoho