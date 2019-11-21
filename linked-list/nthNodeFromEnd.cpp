/* 
Nth node from end of linked list

Problems

Given a linked list consisting of L nodes and given a number N.
The task is to find the Nth node from the end of the linked list.

Input:
First line of input contains number of testcase T. For each testcase,
first line of input contains number of nodes in the linked list and the number N.
Next line contains N nodes of linked list.

Output:
For each testcase, output the data of node which is at Nth distance from end.

User Task:
The task is to complete the function getNthFromLast() which takes two arguments:
reference to head and N and you need to return Nth from end.

Constraints:
1 <= T <= 200
1 <= L <= 103
1 <= N <= 103

Example:
Input:
2
9 2
1 2 3 4 5 6 7 8 9
4 5
10 5 100 5

Output:
8
-1

Explanation:
Testcase 1: In the first example, there are 9 nodes in linked list and we need to find 2nd node from end.  2nd node from end os 8.  
Testcase 2: In the second example, there are 4 nodes in linked list and we need to find 5th from end.  Since 'n' is more than number of nodes in linked list, output is -1.
 */

// C program to find n'th Node in linked list
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

/* Function to append nodes in linked list, maintains ref to tail of linked list */
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);


/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
    printf("%d", getNthFromLast(head, k));
    cout << endl;
    }
    return 0;
}


/* 
Naive Approach: Traverse the linked list and calculate its length
and the traverse till len-n+1 to print the nth node from last

Better Approach (single traversal of linked list):
Move a pointer say a, to nth node
Now when a reaches to nth node, initialise a new pointer, say b, to head
The distance between a and b is n-1 nodes
Now advance both a and b by one
Now when a will reach last node, b will be at nth node from last (len - (n-1)) = len - n + 1 // nth from last
because distance maintained between the was n-1
 */
int getNthFromLast(Node *head, int n)
{
    // initialse a temp node with head
    Node *curr = head;
    // move it till nth node from begining
    // if pointer becomes null in between break from loop and return -1, as n is greater than len in this case
    for(int i = 1; i < n && curr != NULL; i++) {
        curr = curr->next;
    }
    // return -1 if n is greater than lenght of linked list
    if (curr == NULL) return -1;
    // from this point advance both head nd curr by one, till curr reaches last node
    while(curr->next != NULL) {
        head = head->next;
        curr = curr->next;
    }
    // curr reached last node at this point head will be nth from last
    return head->data;
}

// Company Tags: Accolite, Adobe, Amazon, Citicorp, Epic Systems, FaceSet, Hike
// MAQ Software, Monotype Solutions, Morgan Stanley, OYO Rooms, Qualcomm, Samsung, Snapdeal