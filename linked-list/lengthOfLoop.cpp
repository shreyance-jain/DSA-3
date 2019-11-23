/* 
Find length of Loop

Problem Statement

Given a linked list of size N.
The task is to complete the function countNodesinLoop() that checks whether
a given Linked List contains loop or not and
if loop is present then
return the count of nodes in loop or else return 0.

Input(to be used for Expected Output Only):
First line of input contains number of testcases T. For each testcase,
first line of input contains length of linked list and
next line contains data of the linked list, and
the third line contains the position of the node from beginning (0 based indexing)
to which the last node will be connected to form a loop.
Note: If the input of the third line is zero then there is no loop.

Output:
For each testcase, there will be a single line of output containing
the length of loop in linked list, else print 0, if loop is not present in the linked list.

Constraints:
1 <= T <= 100
1 <= N <= 500

Example:
Input:
2
10
25 14 19 33 10 21 39 90 58 45
4
2
1 0
1
Output:
6
1

Explanation:
Testcase 1: The loop is 45->10. So length of loop is 10->21->39->90->58->45 = 6. The number 10 is connected to the last node to form the loop because according to the input the 4th node from the beginning(0 based index) will be connected to the last node for the loop.
Testcase2:  The length of loop is 1.
 */
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

/*Function to append node in a linked list without maintaining reference to tail pointer */
void append(struct Node** headRef, int data)
{
	struct Node* new_node = new Node (data);
	struct Node *last = *headRef;
	
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

void printList(struct Node *tmp){
    while(tmp){
        cout<<tmp->data<<' ';
        tmp=tmp->next;
    }
    cout<<endl;
}

int countNodesinLoop(struct Node *head);
/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, tmp;
        cin>>n;
        struct Node *head = NULL;
        struct Node* temp;
        struct Node *s;
        struct Node *t;
        cin>>tmp;
        append(&head, tmp);
        s=head;
        for(int i=1; i<n; i++){
            cin>>tmp;
            append(&head, tmp);
        }
        /* Create a loop for testing */
        // srand(time(NULL));
        int c;
        cin>>c;
        if(c>0){
            //c=c-1;
            temp=head;
            t = head;
            while(t->next)t=t->next;
            while(c--)temp=temp->next;
            t->next=temp;
            // s->next=temp;
        }
        //printList(head);
        cout<<countNodesinLoop(head)<<endl;
	}
    return 0;
}


/* Approach: Detect loop using floyd's cycle detection algorithm
From the point where fast_ptr and slow_ptr meet
we fix a pointer at that point and take a pointer and advance it till it
reaches the same point again */
int countNodesinLoop(struct Node *head)
{
    // loop detection using floyd's loop detection
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    // check if loop breaked becasue either fast or fast->next became NULL
    // if yes it implies no loop
    if (slow != fast)
        return 0;
    // count length of loop
    int count = 1; // taking the current node in count
    // we will keep a pointer at meeting point in this code say fast is kept as it is
    // and increment a pointer till we reach same poistion in this code we use slow for this
    while(slow->next != fast) {
        slow = slow->next;
        count++;
    }
    return count;
}
// Time Complexity: linear

// Company Tags: Adobe, Qualcomm