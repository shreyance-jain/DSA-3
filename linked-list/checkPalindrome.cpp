/* 
Check if Linked List is Palindrome

Problem Statement

Given a singly linked list of size N of integers.
The task is to check if the given linked list is palindrome or not.

Input:
First line of input contains number of testcases T. For each testcase,
first line of input contains length of linked list N and
next line contains N integers as data of linked list.

Output:
For each test case output will be 1 if the linked list is a palindrome else 0.

Constraints:
1 <= T <= 103
1 <= N <= 50

Example(To be used only for expected output):
Input:
2
3
1 2 1
4
1 2 3 4

Output:
1
0

Explanation:
Testcase 1: 1 2 1, linked list is palindrome.
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


void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* check palindrome function decleration */
bool isPalindrome(Node *head);

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

/* Function to reverse the linked list, changes the head of the linked list */
void reverse(Node **head_ref) {
    Node *prev = NULL;
    Node *curr = *head_ref;
    while(curr != NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head_ref = prev;
}

bool compareList(Node *head1, Node *head2) {
    while(head1 && head2) {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1) return false;
    if (head2) return false;
    return true;
}

/* This approach to check palindrome does not use any data structure other than linked list
Approach: Takes O(n) time and O(1) extra space
1. Get the middle of the linked list.
2. Reverse the second half of the linked list
3. Check if first half and second half of the linked list is identical
4. Construct the original linked list by reversing the second half again and attching
it back to the first half
--
When number of nodes are even, the first and second half contain exactly half nodes
The challenging thing in this method is to handle the case when number of nodes are odd
We don't want the middle node as part of any of the lists as we are going to comapre them for equality
For odd case, we use a seperate variable 'middlenode'
 */
bool isPalindrome(Node *head)
{
    bool res = true; //  initialise result
    if (head != NULL && head->next != NULL) {
        Node *middle; // to handle odd size linked list
        Node *slow = head, *prev_of_slow = head;
        Node *fast = head;
        Node *second_half;
        
        // fast moves 1 3 5 7....(1 based indexing)
        // fast becomes null in case of even nodes
        while(fast != NULL && fast->next != NULL) {
            /* Get the middle of the linked list move the slow pointer by 1
            and the fast pointer by 2, slow_ptr will have the middle node */
            fast = fast->next->next;
            prev_of_slow = slow;
            slow = slow->next;
        }
        
        /* fast_ptr will become NULL when there are even number of elements
        And not NULL when number of elements in linked list is odd
        We need to skip the middle node for odd case and store it somewhere
        so we can restore the original linked list */
        if (fast != NULL) {
            // level both the odd and even no nodes linked lists
            // middle is seperated out and slow is moved to match no of nodes
            middle = slow;
            slow = slow->next;
        }
        // now reverse the second half and compare it with first half
        prev_of_slow->next = NULL; // NULL terminate first half
        second_half = slow;
        
        reverse(&second_half); // reverse the second half
        
        res = compareList(head, second_half); // compare
        
        // construct the original linked list back
        reverse(&second_half); // reverse the second half again
        
        // if there was a middle node(odd size case) which 
        // was not part of either first half or second half
        if (middle) {
            prev_of_slow->next = middle;
            middle->next = second_half;
        } else {
            prev_of_slow->next = second_half;
        }
    }
    return res;
}

// Comapany Tags: Accolite, Adobe, Amazon, KLA Tencor, Kritikal Solutions, Microsoft, Snapdeal, Yodlee Infotech