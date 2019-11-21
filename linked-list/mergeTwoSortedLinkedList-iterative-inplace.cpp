/* 
Merge two sorted linked lists

Problem Statement

Given two sorted linked lists consisting of N and M nodes respectively.
The task is to merge both of the list (in-place) and return head of the merged list.

Note: It is strongly recommended to do merging in-place using O(1) extra space.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains N and M,
and next two line contains N and M sorted elements in two lines for each.

Output:
For each testcase, print the merged list in sorted form.

User Task:
The task is to complete the function sortedMerge() which takes references
to the heads of two linked lists as the arguments and returns the head of merged linked list.

Constraints:
1 <= T <= 200
1 <= N, M <= 103
1 <= Node's data <= 103

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4 

Output:
2 3 5 10 15 20 40
1 1 2 4

Explanation:
Testcase 1: After merging the two linked lists, we have merged list as 2, 3, 5, 10, 15, 20, 40.
 */

#include<iostream>
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

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to append nodes in linked list, maitains ref to tail of linked list */
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1,n2,l,k;
    cin>>T;
    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;
        cin>>n1>>n2;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

/* 
Approach: Maintain two pointers on linked list 1 (whose data of first node is smaller)
curr1 and next1 and maintain one pointer on second linked list namely curr2
Now we just check if value at curr2 lies between curr1 and next1
if yes:
we insert it in between curr1 and next1 and advance curr2
if no:
we advance curr1 and next1
The reason to maintain two pointers in linked list 1 is for easy insertion of node from linked list2
 */
Node* mergeUtil(Node* head1, Node* head2){
    // if there is only one node in first list simply point its head to second list
    if (!head1->next) {
        head1->next = head2;
        return head1;
    }
    // initialise curr and next pointers for both lists
    // (Note: we will only maintain one pointer curr2 in second list for comparisons,
    // all the calculations will be done on curr2 from second list, next2 is just to advance curr2)
    Node *curr1 = head1, *next1 = head1->next;
    Node *curr2 = head2, *next2 = head2->next;
    
    while(next1 && curr2) {
        // if curr2 lies between curr1 and next1
        // then we do curr1->curr2->next1
        if (curr2->data >= curr1->data && curr2->data <= next1->data) {
            // imp: to note we dont access next2->next in code anywhere
            next2 = curr2->next; 
            curr1->next = curr2;
            curr2->next = next1;

            // now let curr1 and curr2 point to just next pointers
            curr1 = curr2;
            curr2 = next2;
        } else {
            // if more nodes in first list
            if (next1->next) {
                curr1 = next1;
                next1 = next1->next;
            }
            // else point the last node of first list to remaining nodes of second list
            else {
                next1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}

/* Merge two sorted linked lists inplace
This function compares head nodes and calls the above mergeUtil function */
Node* sortedMerge(Node* head1,   Node* head2)
{
    if (!head1) return head2;
    if (!head2) return head1;
    
    // start with linked list whose first node is of smaller value
    if (head1->data <= head2->data) {
        return mergeUtil(head1, head2);
    } else {
        return mergeUtil(head2, head1);
    }
}

// Company Tags: Accolite, Amazon, Belzabar, Brocade, FactSet, Flipkart, MakeMyTrip, Microsft
// OATS Systems, Oracle, Samsung, Synopsys, Zoho